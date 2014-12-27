//  $Id: imap.c,v 1.2 2013/01/12 00:26:49 axm3244 Exp axm3244 $

/*  SUMMARY
 *  Program to  establish an SSL connection to a DCS computer
 *  and perform operation(s) on that computer
 *  imap.cpp
 *
 *
 *  REVISION HISTORY
 *    $Log: imap.c,v $
 *    Revision 1.2  2013/01/12 00:26:49  axm3244
 *    Added Reading Email Functionality
 *    Selecting Email functionality
 *
 *    Revision 1.1  2013/01/11 00:40:58  axm3244
 *    Initial revision
 *
 *    Revision 1.3  2013/01/11 00:38:55  axm3244
 *    Added Log In Functionality
 *    Authentication
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
 *
 *    Author : Ankan Mookherjee
 */

// Referencing library and header files for pre-processing

#include "SSLFunctions.h"

using namespace std;


/*
 * Main Function
 * Program execution begins here and runs the command and passes
 * arguments into run_session in SSLFunctions.cpp
 * @param takes two command line argumnet
 * @return int
 */

int main()
{
   
    /*Declaring Variables*/
    BIO * bio;
    SSL * ssl;
    SSL_CTX * ctx;

    int p;
    int check;

    /* Initializing the context */	
    ctx = initialize_Context();
 
    /* Setup the connection */
    bio = BIO_new_ssl_connect(ctx);

    /* Set the SSL_MODE_AUTO_RETRY flag */
    BIO_get_ssl(bio, & ssl);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    /* Create and setup the connection */
    BIO_set_conn_hostname(bio, "mailhost.cs.rit.edu:993");
		
    check_Connection(bio,ctx);

    /* Check the certificate */
    check = checkSSLCertificate(ssl,ctx, bio);
    if (check ==0) return 0;

    run_Imap(bio);

    /* Close the connection and free the context */	
    destroy_ctx(ctx,bio);

    return 0;
}
