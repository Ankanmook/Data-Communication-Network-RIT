AUTHOR : Ankan Mookherjee
Id: axm3244

-------------------------------------------------------------------------------
DEVELOPMENT

The package contains 5 files apart from this file.
1)imap.c contains main function.
 
2)SSLFunctions.h contains header files and signatures of methods in 
SSLFunctions.c. This file links SSLFunctions.cpp to imap.c.

3)SSLFunctions.c contains methods to enable SSL Connection.

4)Makefile for code execution

5)imap which is the executable file

The main function accepts no command line argument. It connects to 
p740-01e@cs.rit.edu and password Ankan_Mookherjee

After thes session was extablished in session_run method. Hostname 
was passed to it.Initially I hardcoded to check its correct functioning.
However later in the development phase,

Port number and command line were also sent in the same fasion. Owing to 
the signature which was const char* . I faced some issues but it got resolved
by matching the signatures of the parameters I used for accepting and passing
the variables.
There were some issues convereting integer variables to char* to be 
concatenated and passed to IMAP server. 

In the end after DOVCOT login message was successfully recieved we ended up
a do while loop to run the user options to view the emails. Initial
screen had 10 emails. Later one can view each email by their number.
Implementing this potion was not a problem although testing imap command was.
I had  run_Imap function to run the client and write_Read_Imap() send 
and read commands to IMAP server.

Overall the development was procedural and few logical problems which came 
on the way got resolved with testing and passing hardcoding and later 
replacing them with variables along the way. 

Error Mechanism was gradually added although command line specification and
incorrect or incomplete command implementation was added to the program in
the end phase of the development.

-------------------------------------------------------------------------------
EXECUTION OF CODE
Type the following command to Execute the code
$ ./imap

Now client should read and display a list of up to 10 message headers.
After the list of headers there are following commands to read messages.

1. r# where # is a number from 1 through 10 - read (display) the requested message.
2. n - display the next 10 message headers.
3. p - display the previous 10 message headers.
4. q - logout.

Follow the instructions and have a look into the messages in the email.
Email it connects to is : p740-01e@cs.rit.edu
Password for Authentication : Ankan_Mookherjee


-------------------------------------------------------------------------------
BUILDING OF CODE (MANUALLY)
$ g++ -o imap imap.c SSLFunctions.c SSLFunctions.h -lssl
OUTPUT REDERCTION
$ g++ -o imap imap.c SSLFunctions.c SSLFunctions.h -lssl >> readme.txt

-------------------------------------------------------------------------------
BULIDING OF CODE (MAKE FILE)
Instructions :
Type gmakemake > Makefile inside Project directory.
Make sure the Project houses all the required files to be compiled.
 
$ gmakemake > Makefile
pico Makefile :
In makefile Alter 
CLIBFLAGS= -lm -lssh
CCLIBFLAGS= -lssh 
Save the file 

Now run make
$ make
imap output generated.
-------------------------------------------------------------------------------
Version Controlling 
I used RCS version controlling. This is what I did check in and check out files.

I used this command to check in my versions.

//Make an RCS directory to store the checked in files
$ mkdir RCS

$ ci imap.c SSLFunctions.c SSLFunctions.h
>> Enter Comments and Lock with a single '.'
>> .
Done
Revision Version Locked


I used this command to check out my version.
It used to revert to the last version I had checked in.

$ co -l imap.c SSLFunctions.c SSLFunctions.h
Unlock the version.
Lock it for others to use.

If I checked it in with the help of ci command i used to get saved as my most recent version.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
Test Case 1:

1 OK [CAPABILITY IMAP4rev1 LITERAL+ SASL-IR LOGIN-REFERRALS ID ENABLE SORT SORT=DISPLAY THREAD=REFERENCES THREAD=REFS MULTIAPPEND UNSELECT IDLE CHILDREN NAMESPACE UIDPLUS LIST-EXTENDED I18NLEVEL=1 CONDSTORE QRESYNC ESEARCH ESORT SEARCHRES WITHIN CONTEXT=SEARCH] Logged in
* FLAGS (\Answered \Flagged \Deleted \Seen \Draft)
* OK [PERMANENTFLAGS (\Answered \Flagged \Deleted \Seen \Draft \*)] Flags permitted.
* 22 EXISTS
* 0 RECENT
* OK [UIDVALIDITY 1357858371] UIDs valid
* OK [UIDNEXT 24] Predicted next UID
* OK [HIGHESTMODSEQ 1] Highest
2 OK [READ-WRITE] Select completed.
* 1 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:02 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
1 OK Fetch completed.
=======================
 * 2 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:37 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
3 OK Fetch completed.
=======================
 * 3 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {118}
Date: Thu, 10 Jan 2013 19:08:13 -0500
Subject: Hi How are you
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 4 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {123}
Date: Thu, 10 Jan 2013 19:08:45 -0500
Subject: This is a new email
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 5 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {137}
Date: Thu, 10 Jan 2013 19:09:30 -0500
Subject: Please Don't Change Your Password
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* 6 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {126}
Date: Thu, 10 Jan 2013 19:10:10 -0500
Subject: Password Not Protected
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
1 OK Fetch completed.
=======================
 * 7 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:06:30 -0500
Subject: MAIL 5
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
3 OK Fetch completed.
=======================
 * 8 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:06:58 -0500
Subject: MAIL 6
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 9 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:07:22 -0500
Subject: MAIL 8
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 10 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:07:43 -0500
Subject: MAIL 9
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* 11 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:03 -0500
Subject: MAIL 10
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
1 OK Fetch completed.
=======================
 * 12 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:20 -0500
Subject: MAIL 11
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
3 OK Fetch completed.
=======================
 * 13 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:43 -0500
Subject: MAIL 12
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 14 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:09:02 -0500
Subject: MAIL 13
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 15 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:09:25 -0500
Subject: MAIL 14
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

-41 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
3 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
5 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
7 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
9 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX


Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* BYE Logging out
1 OK Logout completed. EXIT 

-------------------------------------------------------------------------------
Test Case : 2
1 OK [CAPABILITY IMAP4rev1 LITERAL+ SASL-IR LOGIN-REFERRALS ID ENABLE SORT SORT=DISPLAY THREAD=REFERENCES THREAD=REFS MULTIAPPEND UNSELECT IDLE CHILDREN NAMESPACE UIDPLUS LIST-EXTENDED I18NLEVEL=1 CONDSTORE QRESYNC ESEARCH ESORT SEARCHRES WITHIN CONTEXT=SEARCH] Logged in
* FLAGS (\Answered \Flagged \Deleted \Seen \Draft)
* OK [PERMANENTFLAGS (\Answered \Flagged \Deleted \Seen \Draft \*)] Flags permitted.
* 22 EXISTS
* 0 RECENT
* OK [UIDVALIDITY 1357858371] UIDs valid
* OK [UIDNEXT 24] Predicted next UID
* OK [HIGHESTMODSEQ 1] Highest
2 OK [READ-WRITE] Select completed.
* 1 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:02 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
1 OK Fetch completed.
=======================
 * 2 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:37 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
3 OK Fetch completed.
=======================
 * 3 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {118}
Date: Thu, 10 Jan 2013 19:08:13 -0500
Subject: Hi How are you
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 4 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {123}
Date: Thu, 10 Jan 2013 19:08:45 -0500
Subject: This is a new email
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 5 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {137}
Date: Thu, 10 Jan 2013 19:09:30 -0500
Subject: Please Don't Change Your Password
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* 6 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {126}
Date: Thu, 10 Jan 2013 19:10:10 -0500
Subject: Password Not Protected
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
1 OK Fetch completed.
=======================
 * 7 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:06:30 -0500
Subject: MAIL 5
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
3 OK Fetch completed.
=======================
 * 8 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:06:58 -0500
Subject: MAIL 6
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 9 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:07:22 -0500
Subject: MAIL 8
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 10 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:07:43 -0500
Subject: MAIL 9
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* 11 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:03 -0500
Subject: MAIL 10
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
1 OK Fetch completed.
=======================
 * 12 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:20 -0500
Subject: MAIL 11
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
3 OK Fetch completed.
=======================
 * 13 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:43 -0500
Subject: MAIL 12
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 14 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:09:02 -0500
Subject: MAIL 13
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 15 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:09:25 -0500
Subject: MAIL 14
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

Email Id : 5* 5 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {137}
Date: Thu, 10 Jan 2013 19:09:30 -0500
Subject: Please Don't Change Your Password
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
1 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

-41 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
3 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
5 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
7 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
9 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX


Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* BYE Logging out
2 OK Logout completed.
 EXIT 
-------------------------------------------------------------------------------
Test Case 3:

1 OK [CAPABILITY IMAP4rev1 LITERAL+ SASL-IR LOGIN-REFERRALS ID ENABLE SORT SORT=DISPLAY THREAD=REFERENCES THREAD=REFS MULTIAPPEND UNSELECT IDLE CHILDREN NAMESPACE UIDPLUS LIST-EXTENDED I18NLEVEL=1 CONDSTORE QRESYNC ESEARCH ESORT SEARCHRES WITHIN CONTEXT=SEARCH] Logged in
* FLAGS (\Answered \Flagged \Deleted \Seen \Draft)
* OK [PERMANENTFLAGS (\Answered \Flagged \Deleted \Seen \Draft \*)] Flags permitted.
* 22 EXISTS
* 0 RECENT
* OK [UIDVALIDITY 1357858371] UIDs valid
* OK [UIDNEXT 24] Predicted next UID
* OK [HIGHESTMODSEQ 1] Highest
2 OK [READ-WRITE] Select completed.
* 1 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:02 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
1 OK Fetch completed.
=======================
 * 2 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:37 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
3 OK Fetch completed.
=======================
 * 3 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {118}
Date: Thu, 10 Jan 2013 19:08:13 -0500
Subject: Hi How are you
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 4 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {123}
Date: Thu, 10 Jan 2013 19:08:45 -0500
Subject: This is a new email
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 5 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {137}
Date: Thu, 10 Jan 2013 19:09:30 -0500
Subject: Please Don't Change Your Password
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

Email Id : 3* 3 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {118}
Date: Thu, 10 Jan 2013 19:08:13 -0500
Subject: Hi How are you
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
1 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

Email Id : 8* 8 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:06:58 -0500
Subject: MAIL 6
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
2 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

-141 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
3 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
5 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
7 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
9 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX


Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

1 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
3 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
5 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
7 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX
9 BAD Error in IMAP command FETCH: Invalid messageset
XXXXXXXXXXXXX


Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* BYE Logging out
3 OK Logout completed.
 EXIT 
-------------------------------------------------------------------------------
Test Case 4 :
1 OK [CAPABILITY IMAP4rev1 LITERAL+ SASL-IR LOGIN-REFERRALS ID ENABLE SORT SORT=DISPLAY THREAD=REFERENCES THREAD=REFS MULTIAPPEND UNSELECT IDLE CHILDREN NAMESPACE UIDPLUS LIST-EXTENDED I18NLEVEL=1 CONDSTORE QRESYNC ESEARCH ESORT SEARCHRES WITHIN CONTEXT=SEARCH] Logged in
* FLAGS (\Answered \Flagged \Deleted \Seen \Draft)
* OK [PERMANENTFLAGS (\Answered \Flagged \Deleted \Seen \Draft \*)] Flags permitted.
* 22 EXISTS
* 0 RECENT
* OK [UIDVALIDITY 1357858371] UIDs valid
* OK [UIDNEXT 24] Predicted next UID
* OK [HIGHESTMODSEQ 1] Highest
2 OK [READ-WRITE] Select completed.
* 1 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:02 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
1 OK Fetch completed.
=======================
 * 2 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:37 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
3 OK Fetch completed.
=======================
 * 3 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {118}
Date: Thu, 10 Jan 2013 19:08:13 -0500
Subject: Hi How are you
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 4 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {123}
Date: Thu, 10 Jan 2013 19:08:45 -0500
Subject: This is a new email
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 5 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {137}
Date: Thu, 10 Jan 2013 19:09:30 -0500
Subject: Please Don't Change Your Password
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 



Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

Email Id : 1* 1 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {131}
Date: 11 Jan 2013 00:07:02 -0000
From: MAILER-DAEMON@pony-express.cs.rit.edu
To: p740-01e@cs.rit.edu
Subject: failure notice

)
1 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

Email Id : 6* 6 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {126}
Date: Thu, 10 Jan 2013 19:10:10 -0500
Subject: Password Not Protected
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
2 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* 6 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {126}
Date: Thu, 10 Jan 2013 19:10:10 -0500
Subject: Password Not Protected
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
1 OK Fetch completed.
=======================
 * 7 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:06:30 -0500
Subject: MAIL 5
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
3 OK Fetch completed.
=======================
 * 8 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:06:58 -0500
Subject: MAIL 6
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 9 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:07:22 -0500
Subject: MAIL 8
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 10 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {110}
Date: Thu, 10 Jan 2013 20:07:43 -0500
Subject: MAIL 9
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* 11 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:03 -0500
Subject: MAIL 10
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
1 OK Fetch completed.
=======================
 * 12 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:20 -0500
Subject: MAIL 11
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
3 OK Fetch completed.
=======================
 * 13 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:08:43 -0500
Subject: MAIL 12
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
5 OK Fetch completed.
=======================
 * 14 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:09:02 -0500
Subject: MAIL 13
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
7 OK Fetch completed.
=======================
 * 15 FETCH (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)] {111}
Date: Thu, 10 Jan 2013 20:09:25 -0500
Subject: MAIL 14
From: p740-01e@cs.rit.edu
To: p740-01e@cs.rit.edu

)
9 OK Fetch completed.
=======================
 

Options :

Read Mail - r#
Next 10 Mail Headers - n
Previous 10 Mail Headers - p
Logout - q

Please Select Your Option : 

* BYE Logging out
3 OK Logout completed.
 EXIT 
