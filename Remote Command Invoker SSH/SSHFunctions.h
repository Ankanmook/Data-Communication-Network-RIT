//  $Id: SSHFunctions.h,v 1.6 2012/12/14 00:55:43 axm3244 Exp axm3244 $

/*  SUMMARY
 *  Header file to include all the required libraries and
 *  link remoteCMD.cpp which houses main function and
 *  SSHFunctions.cpp which houses SSH functions.
 *

 *
 *
 *  REVISION HISTORY
 *    $Log: SSHFunctions.h,v $
 *    Revision 1.6  2012/12/14 00:55:43  axm3244
 *    Added run session method to SSHFunctions.cpp and
 *    signature to SSHFunctions.h
 *    Correction in main method Changed hostname keyword
 *
 *    Revision 1.5  2012/12/13 23:14:00  axm3244
 *    Changed code in SSHFunctions.cpp and SSHFunctions.h
 *    Added another method to run session
 *    Removed code from main method
 *
 *    Revision 1.4  2012/12/13 15:55:41  axm3244
 *    Added Command Line argument in main file
 *    Added const char* in Functions.cpp
 *
 *    Revision 1.3  2012/12/13 07:05:56  axm3244
 *    Function capable of opening session and doing password authentication
 *
 *    Revision 1.2  2012/12/13 06:41:07  axm3244
 *    Added Required Library Files
 *
 *    Revision 1.1  2012/12/13 06:05:22  axm3244
 *    Initial revision
 *
 *
 *    Author : Ankan Mookherjee
 *
 */


// Referencing library and header files for pre-processing

#ifndef SSHFUNCTIONS_H
#define SSHFUNCTIONS_H

#include <libssh/libssh.h>
#include<iostream>
#include <cstdlib>
#include <termios.h>
#include<cstring>
#include <unistd.h>
#include<stdio.h>


//Declaring Prototype functions to be implemented in SSHFunctions.cpp


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

void run_session(const char* hostname, const char* command);



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

int authenticate_kbdint(ssh_session session);



/*
 * Interactive Opening of a Shell Session
 *
 * Using ssh_channel to open a channel in remote shell
 * Use this remote to open an ssh_session
 * Starts a command interpreter on the remote computer
 *
 * @praram  takes ssh_channel and command as argument
 * @returns int
 */

int show_remote_files(ssh_session session, const char* command);


#endif
