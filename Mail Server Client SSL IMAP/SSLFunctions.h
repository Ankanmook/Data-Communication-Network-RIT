//  $Id: SSLFunctions.h,v 1.7 2013/01/12 03:28:07 axm3244 Exp axm3244 $

/*  SUMMARY
 *  Header file to include all the required libraries and
 *  link remoteCMD.cpp which houses main function and
 *  SSHFunctions.cpp which houses SSH functions.
 *

 *
 *
 *  REVISION HISTORY
 *    $Log: SSLFunctions.h,v $
 *    Revision 1.7  2013/01/12 03:28:07  axm3244
 *    Added Logout
 *
 *    Revision 1.6  2013/01/12 00:26:49  axm3244
 *    Added Reading Email Functionality
 *    Selecting Email functionality
 *
 *    Revision 1.5  2013/01/11 00:51:13  axm3244
 *    Added IMAP command Sending Procedure
 *    Currently For Fetching Mailbox
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


// Referencing library and header files for pre-processing

#ifndef SSHFUNCTIONS_H
#define SSHFUNCTIONS_H

#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

#include <stdio.h>
#include <string.h>


extern BIO *bio_err;


//Declaring Prototype functions to be implemented in SSHFunctions.cpp


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
SSL_CTX * initialize_Context();


/*
 * Check TCP connection
 *
 * Checks the connection between client and IMAP server
 *
 * @praram  takes hostname and port number as argument
 * @returns void
 */
void check_Connection(BIO * bio,SSL_CTX *ctx);


/*
 * Checks SSL certificate
 *
 * Checks SSL certificate during handshaking
 *
 * @praram  SSL context pointer, host name
 * @returns 1 on success 0 on failure
 */
int checkSSLCertificate(SSL * ssl,SSL_CTX *ctx, BIO *bio);

/*
 * Read Write Imap
 *
 * Writes command into IMAP server and reads from response
 *
 * @praram  BIO **, character pointer
 * @returns void
 */

void writeReadImap(BIO **bio,const char* msg);




/*
 * Run Imap Commands and Options
 *
 * @praram  BIO **, character pointer
 * @returns void
 */

void run_Imap(BIO * bio);


/*
 * Destroy SSL context object
 * and frees the connection after its use
 *
 * @praram  SSL context pointer, BIO pointer
 * @returns void
 */

void destroy_ctx(SSL_CTX *ctx, BIO *bio);


#endif
