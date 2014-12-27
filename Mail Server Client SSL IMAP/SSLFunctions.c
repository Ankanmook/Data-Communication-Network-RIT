//  $Id: SSLFunctions.c,v 1.3 2013/01/12 03:28:07 axm3244 Exp axm3244 $

/*  SUMMARY
 *  C++ File to establish Keyboard Interactive Authentication
 *  and execute remote command
 *  SSHFunctions.cpp
 *
 *
 *  REVISION HISTORY
 *    $Log: SSLFunctions.c,v $
 *    Revision 1.3  2013/01/12 03:28:07  axm3244
 *    Added Logout
 *
 *    Revision 1.2  2013/01/12 00:26:49  axm3244
 *    Added Reading Email Functionality
 *    Selecting Email functionality
 *
 *    Revision 1.1  2013/01/11 00:40:58  axm3244
 *    Initial revision
 *
 *    Revision 1.4  2013/01/11 00:38:55  axm3244
 *    Added Log In Functionality
 *    Authentication
 *
 *    Revision 1.3  2013/01/07 15:32:52  axm3244
 *    Certification
 *    TCP connection Successful
 *
 *    Revision 1.2  2013/01/03 01:19:08  axm3244
 *    Added Few Functionalities
 *    TCP Connection
 *    Socket Creation
 *    Context Creation
 *
 *    Revision 1.1  2012/12/30 02:44:03  axm3244
 *    Initial revision
 *
 *
 *    Author : Ankan Mookherjee
 *
 */


// Referencing library and header file for pre-processing

#include "SSLFunctions.h"

using namespace std;



/*
 * Initialize Context
 *
 * Initializing Context method by taking
 * by SSL library initializing , reporting of error string
 * and creating a BIO object for SSL Encryption
 *
 * @praram  takes keyfile and password as argument
 * @returns pointer to SSL_CTX (ssl context object)
 */
SSL_CTX * initialize_Context()
{
    SSL_CTX * ctx;

    /* Set up the library */
    ERR_load_BIO_strings();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();
    SSL_library_init();


    /* Set up the SSL context */
    ctx = SSL_CTX_new(SSLv23_client_method());

    /* Load the certificate from the location in Unix Systems */
    if(! SSL_CTX_load_verify_locations(ctx,NULL,"/etc/ssl/certs"))
    {
        fprintf(stderr, "Error loading trust store\n");
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        exit(0);
    }
    
    return ctx;

}


/*
 * Check TCP connection
 *
 * Checks the connection between client and IMAP server
 *
 * @praram  takes hostname and port number as argument
 * @returns void
 */
void check_Connection(BIO * bio,SSL_CTX *ctx)
{
    if(BIO_do_connect(bio) <= 0)
    {
        fprintf(stderr, "Error attempting to connect\n");
        ERR_print_errors_fp(stderr);
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        exit(0);
    }
    
}




/*
 * Checks SSL certificate
 *
 * Checks SSL certificate during handshaking
 *
 * @praram  SSL pointer, SSL context pointer, host name, Bio pointer
 * @returns 1 on success 0 on failure
 */
int checkSSLCertificate(SSL * ssl,SSL_CTX *ctx, BIO *bio)
{
    if(SSL_get_verify_result(ssl) != X509_V_OK)
    {
        fprintf(stderr, "Certificate verification error: %ld\n", 
	 SSL_get_verify_result(ssl));
        
	 BIO_free_all(bio);
        SSL_CTX_free(ctx);
        return 0;
    }
    else
    {	
     return 1;
    }
}

/*
 * Read Write Imap
 *
 * Writes command into IMAP server and reads from response
 *
 * @praram  BIO **, character pointer
 * @returns void
 */

void writeReadImap(BIO **bio,const char* msg){
   char buf[1024];int p;char *normalpos;
   char * BadErrorpos;char * Logoutpos;
   BIO_write(*bio, msg, strlen(msg));
   
   for(;;){
       p = BIO_read(*bio, buf, 1024);
       buf[p] = 0;
       printf("%s", buf);
       
       normalpos = strstr (buf,"OK Fetch completed.");
       if(normalpos != NULL){
           printf("%s","=======================\n ");
           break;
       }
	BadErrorpos= strstr(buf,"BAD Error");
	if(BadErrorpos!= NULL){
           printf("%s","XXXXXXXXXXXXX\n");
           break;
       }

	Logoutpos = strstr(buf,"Logout");
	if(Logoutpos != NULL){
	    printf("%s"," EXIT \n");
           break;
	}
   }
}



/*
 * Run Imap Commands and Options
 *
 * @praram  BIO **, character pointer
 * @returns void
 */

void run_Imap(BIO * bio){

    char * request;
    char r[1024];

    int flag;
    int counter = 1;
    int mailNumber;
    int mhNum = 1;
    char *mailID;
    char *mhReqPrefix = " fetch " ;
    char *mhReqSuffix = " (body[header.fields (from to subject date)])\r\n";
    char *mreadReqPrefix = " fetch " ;
    char *mreadReqSuffix = " body[text]\r\n";
    char option[3];

    /* Login and Authentication */ 
    char requestIDString[256];
    sprintf( requestIDString , "%d", counter );
    request = requestIDString;
    
    char *loginReq = " login p740-01e Ankan_Mookherjee\r\n2 select INBOX\r\n";
    strcat(request, loginReq);
    BIO_write(bio, request, strlen(request));
    flag = BIO_read(bio, r, 1023);

    /* Retrieve first 10 mail headers */
    for(int counter = 1; counter <= 10; counter++)
    {
        char requestIDString[256];
        sprintf( requestIDString , "%d", counter);
        request = requestIDString;
        counter++;
        
        char mailIdString[32];
        sprintf( mailIdString , "%d", mhNum );
        mailID = mailIdString;
        mhNum++;
    
        /* Create the header read request */ 
        strcat(request, mhReqPrefix);
        strcat(request, mailID);        
        strcat(request, mhReqSuffix); 
        
        /* Execute request */
        writeReadImap(&bio,request);
    }




    /* Options for User */
    do
    {
        printf("\n\nOptions :\n");
        printf("\nRead Mail - r#");
        printf("\nNext 10 Mail Headers - n");
        printf("\nPrevious 10 Mail Headers - p");
        printf("\nLogout - q");
        printf("\n\nPlease Select Your Option : " );
        scanf("%s", option);
        printf("\n\n");
        
        if(option[0] == 'r' )
        {
            /* recover mail number */
            int mailNumber = option[1] - '0';
            printf("Email Id : %d", mailNumber);
            
            /* construct request */
            char requestIDString[256];
            sprintf( requestIDString , "%d", counter );
            request = requestIDString;
            counter++;
            
            char mailIdString[32];
            sprintf( mailIdString , "%d", mailNumber );
            mailID = mailIdString;
        
            /* Create the header read request */  
            strcat(request, mhReqPrefix);
            strcat(request, mailID);
            strcat(request, mhReqSuffix); 
            
            /* Execute request */
            writeReadImap(&bio,request);                  
        }
        
        if(option[0] == 'n' )
        {
            for(int counter = 1; counter <= 10; counter++)
            {
                /* construct request */
                char requestIDString[256];
                sprintf( requestIDString , "%d", counter );
                request = requestIDString;
                counter ++;
                
                char mailIdString[32];
                sprintf( mailIdString , "%d", mhNum );
                mailID = mailIdString;
                mhNum++;
            
                /* Create the header read request */ 
                strcat(request, mhReqPrefix);
                strcat(request, mailID);
                strcat(request, mhReqSuffix); 
                
                /* Execute request */
                writeReadImap(&bio,request);
            }
        }
        
        if(option[0] == 'p' )
        {
            if(mhNum == 10)
            {
                printf("\nNo previous mails exist");
            }
            else
            {
                mhNum = mhNum - 20;
                printf("%d",mhNum);
                for(int counter = 1; counter <= 10; counter++)
                {
                    /* construct request */
                    char requestIDString[256];
                    sprintf( requestIDString , "%d", counter );
                    request = requestIDString;
                    counter++;
                    
                    char mailIdString[32];
                    sprintf( mailIdString , "%d", mhNum );
                    mailID = mailIdString;
                    mhNum++;
                
                    /* Create the header read request */ 
                    strcat(request, mhReqPrefix);
                    strcat(request, mailID);
                    strcat(request, mhReqSuffix); 
                    
                    /* Execute request */
                    writeReadImap(&bio,request);
                }
            }
        }
        
    }while(option[0] != 'q');


    /* Logout of session */
    char reqIDString[256];
    int retVal;
    sprintf( reqIDString , "%d", counter );
    request = reqIDString;
    char *logoutRequestSuffix = " LOGOUT\r\n";
    strcat(request, logoutRequestSuffix); 
    writeReadImap(&bio,request);
}


/*
 * Destroy SSL context object
 * and frees the connection after its use
 *
 * @praram  SSL context pointer, BIO pointer
 * @returns void
 */

void destroy_ctx(SSL_CTX *ctx, BIO *bio)
{
    BIO_free_all(bio);
    SSL_CTX_free(ctx);
}

