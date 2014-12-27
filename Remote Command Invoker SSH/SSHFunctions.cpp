//  $Id: SSHFunctions.cpp,v 1.6 2012/12/14 02:21:53 axm3244 Exp axm3244 $

/*  SUMMARY
 *  C++ File to establish Keyboard Interactive Authentication
 *  and execute remote command
 *  SSHFunctions.cpp
 *
 *
 *  REVISION HISTORY
 *    $Log: SSHFunctions.cpp,v $
 *    Revision 1.6  2012/12/14 02:21:53  axm3244
 *    Adding some error handling functionality
 *    Commenting in some places in SSHFunctions.cpp
 *
 *    Revision 1.5  2012/12/14 00:55:43  axm3244
 *    Added run session method to SSHFunctions.cpp and
 *    signature to SSHFunctions.h
 *    Correction in main method Changed hostname keyword
 *
 *    Revision 1.4  2012/12/13 23:14:00  axm3244
 *    Changed code in SSHFunctions.cpp and SSHFunctions.h
 *    Added another method to run session
 *    Removed code from main method
 *
 *    Revision 1.3  2012/12/13 07:05:56  axm3244
 *    Function capable of opening session and doing password authentication
 *
 *    Revision 1.2  2012/12/13 06:40:09  axm3244
 *    Added Keyboard Authentication Method
 *    Added Remote Command Execution Method
 *
 *    Revision 1.1  2012/12/13 06:06:10  axm3244
 *    Initial revision
 *
 *
 *    Author : Ankan Mookherjee
 *
 */


// Referencing library and header file for pre-processing

#include "SSHFunctions.h"

using namespace std;



/*
 * Run Session
 *
 * Opens a session and sets host name and assigns port
 * for communication for user during an ssh session
 * Makes call to keyboard interactive method and show remote files
 * method
 *
 * @praram  takes const char * Hostname , const char* Command
 * as argument
 * @returns void
 */

void run_session(const char* hostname, const char* command){

    //declaring variables
    ssh_session my_ssh_session ;
    int verbosity = SSH_LOG_PROTOCOL;
    int port = 22;
    int rc;
    char *password;

    //opening a new session
    my_ssh_session = ssh_new();

    //verifying that the allocation succeeded
    if (my_ssh_session == NULL)
    exit(-1);

    //setting the options to the session host to the host name
    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, hostname);

    //setting the session transaction to be
    //carried through the default port 22
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, &port);


    //connecting to the server
    rc= ssh_connect(my_ssh_session);
    if(rc !=SSH_OK){
         cerr<<"Error connecting to localhost:"
         <<ssh_get_error(my_ssh_session)<<endl;
         exit(-1);

   }


    // Keyboard-Interactive Authentication
    rc = authenticate_kbdint(my_ssh_session);

    //If the authentication is not successfull
    if (rc != SSH_AUTH_SUCCESS){
    cerr<<"Error authenticating with password:"
        <<ssh_get_error(my_ssh_session)<<endl;
    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
    exit(-1);
    }
    //For successfull authentication
    else{
    rc = show_remote_files(my_ssh_session, command);
    }

    //diconnecting session from server
    ssh_disconnect(my_ssh_session);

    //deallocating the session
    ssh_free(my_ssh_session);

}



/*
 * Keyboard Interactive Authentication
 *
 * Using Keyboard interactive method by taking
 * spontaneous direct input from the user to authenticate
 * user during an ssh session
 *
 * @praram  takes ssh_session as argument
 * @returns int
 */

int authenticate_kbdint(ssh_session session){

    //declaring variables
    int rc;
    const char *name, *instruction;
    int nprompts, iprompt;

    rc = ssh_userauth_kbdint(session, NULL, NULL);
    while(rc == SSH_AUTH_INFO){

    name = ssh_userauth_kbdint_getname(session);
    instruction = ssh_userauth_kbdint_getinstruction(session);
    nprompts =  ssh_userauth_kbdint_getnprompts(session);

    if(strlen(name) >0)
       cout<<name<<endl;
    if(strlen(instruction)>0)
       cout<<instruction<<endl;

    for (iprompt = 0; iprompt < nprompts; iprompt++){
       const char *prompt;
       char echo;

       prompt = ssh_userauth_kbdint_getprompt(session, iprompt, &echo);
       if(echo){
          char buffer[128], *ptr;
          cout<<prompt;

          if(fgets(buffer, sizeof(buffer), stdin)==NULL)
              return SSH_AUTH_ERROR;

          buffer[sizeof(buffer) -1] = '\0';

          if ((ptr = strchr(buffer, '\n')) != NULL)
              *ptr = '\0';

          if (ssh_userauth_kbdint_setanswer(session, iprompt, buffer) < 0)
              return SSH_AUTH_ERROR;

              memset(buffer, 0, strlen(buffer));
          }

          else{
              char *ptr;

              ptr = getpass(prompt);
              if(ssh_userauth_kbdint_setanswer(session, iprompt, ptr) < 0)
                  return SSH_AUTH_ERROR;
              }
          }
          rc = ssh_userauth_kbdint(session, NULL, NULL);
     }
  return rc;
}


/*
 * Opening of a Shell Session and Displaying remote command
 * on local computer
 *
 * Using ssh_channel to open a channel in remote shell
 * Use this remote to open an ssh_session
 * displays result of a command interpreter on the remote computer
 *
 * @praram  takes ssh_channel and command as argument
 * @returns int
 */

int show_remote_files(ssh_session session, const char* command){

    ssh_channel channel;
    int rc;
    char buffer[256];
    unsigned int nbytes;
    channel = ssh_channel_new(session);

    if (channel == NULL) return SSH_ERROR;

    rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK){
       ssh_channel_free(channel);
       return rc;
    }

    //remote executing command
    rc = ssh_channel_request_exec(channel, command);
    if (rc != SSH_OK){
       if( rc ==SSH_ERROR || rc == SSH_AGAIN)
           cout<<"Incorrect Command or Nonblocking mode"
               <<"Please try again"<<endl;

       ssh_channel_close(channel);
       ssh_channel_free(channel);
       return rc;
    }

    //reading our execution of command
    nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);

    //if nothing is read. Command is incomplete or wrong
    if(nbytes ==0){
    cout<<"Please check your entered command again."<<endl;
    cout<<"It is either incomplete or it is incorrect. "<<endl;
    }

    while (nbytes > 0){
       if (fwrite(buffer, 1, nbytes, stdout) != nbytes){
       ssh_channel_close(channel);
       ssh_channel_free(channel);
       return SSH_ERROR;
       }
       nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    }
    if (nbytes < 0){
       ssh_channel_close(channel);
       ssh_channel_free(channel);
       return SSH_ERROR;
    }

    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    return SSH_OK;

}

