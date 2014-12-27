//  $Id: remoteCMD.cpp,v 1.6 2012/12/14 00:55:43 axm3244 Exp axm3244 $

/*  SUMMARY
 *  Program to  establish an SSH connection to a DCS computer
 *  and perform operation(s) on that computer
 *  remoteCMD.cpp
 *
 *
 *  REVISION HISTORY
 *    $Log: remoteCMD.cpp,v $
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
 *    Changes in main functions in remoteCMD.cpp
 *    Added termios.h Library in SSHFunctions.h
 *    Added functionality in keyboard interactive authentication
 *    Added remote exec in SSHFunctions.cpp
 *
 *    Revision 1.2  2012/12/13 06:39:01  axm3244
 *    Main File Session opening and closing written
 *    Added Header and Prepossessing Files
 *
 *    Revision 1.1  2012/12/13 06:04:13  axm3244
 *    Initial revision
 *
 *
 *
 *    Author : Ankan Mookherjee
 */

// Referencing library and header files for pre-processing

#include "SSHFunctions.h"


using namespace std;



/*
 * Main Function
 * Program execution begins here and runs the command and passes
 * arguments into run_session in SSHFunction.cpp
 * @param takes two command line argumnet
 * @return int
 */
int main(int argc,char *argv[]){

    const char* hostname;
    const char* command;

    // Check the value of argc to be 1 and
    // inform the user of how to use the program
    if ((argc < 3)&&(argc >0 )) {
        cout << "Usage is remoteCMD host-name \"command\"  ";
        cin.get();
        exit(0);
    }

    hostname = argv[1];
    command = argv[2];

    //runs the remote SSH session client
    run_session(hostname, command);

    return 0;
}



