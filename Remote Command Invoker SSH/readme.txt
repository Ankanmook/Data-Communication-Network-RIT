AUTHOR : Ankan Mookherjee
Id: axm3244

-------------------------------------------------------------------------------
DEVELOPMENT

The package contains 5 files apart from this file.
1)remoteCMD.cpp contains main function.
 
2)SSHFunctions.h contains header files and signatures of methods in 
SSHFunctions.cpp. This file links SSHFunctions.cpp to remoteCMD.cpp.

3)SSHFunctions.cpp contains methods to enable SSH.

4)Makefile for code execution

5)remoteCMD which is the executable file

The main function accepts command line argument. However the total number
of arguments accepted has be exactly equal to 2. 
The first one is the host-name followed by the command to be executed in
double quotes.

After thes session was extablished in session_run method. Hostname 
was passed to it.Initially I hardcoded to check its correct functioning.
However later in the development phase, I used parameters from the 
command line argument to be sent dynamically to the method.

Port number and command line were also sent in the same fasion. Owing to 
the signature which was const char* . I faced some issues but it got resolved
by matching the signatures of the parameters I used for accepting and passing
the variables.

Now while authentication, I tried with remote authentication however it did not
work. After looking at the error message which required KEYBOARD INTERACTIVE
AUTHENTICATION I coded for keyboard interactive authentication.
After successful connection via Keyboard Interactive Authentication I used
remote_request_exec() to pass on the command and reader function to read output.

Overall the development was procedural and few logical problems which came 
on the way got resolved with testing and passing hardcoding and later 
replacing them with variables along the way. 

Error Mechanism was gradually added although command line specification and
incorrect or incomplete command implementation was added to the program in
the end phase of the development.

-------------------------------------------------------------------------------
MANUAL EXECUTION OF CODE
$ g++ -o remoteCMD remoteCMD.cpp SSHFunctions.cpp -lssh
OUTPUT REDERCTION
$ g++ -o remoteCMD remoteCMD.cpp SSHFunctions.cpp -lssh >> readme.txt

-------------------------------------------------------------------------------
MAKE FILE
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
remoteCMD output generated.
-------------------------------------------------------------------------------
Version Controlling 
I used RCS version controlling. This is what I did check in and check out files.

I used this command to check in my versions.

//Make an RCS directory to store the checked in files
$ mkdir RCS

$ ci remoteCMD.cpp SSHFunctions.cpp SSHFunctions.h
>> Enter Comments and Lock with a single '.'
>> .
Done
Revision Version Locked


I used this command to check out my version.
It used to revert to the last version I had checked in.

$ co -l remoteCMD.cpp SSHFunctions.cpp SSHFunctions.h
Unlock the version.
Lock it for others to use.

If I checked it in with the help of ci command i used to get saved as my most recent version.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

Test Cases Delivered with Output Redirection.

Test Case 1:

$ ./remoteCMD idaho "ls -l" 


total 20
drwx------  3 axm3244 ugrad  512 Dec  6 02:46 AI
-rw-rw-rw-  1 axm3244 ugrad 6038 Nov  7 20:23 C:\nppdf32Log\debuglog.txt
drwx------  3 axm3244 ugrad  512 Dec  8 22:37 CPP
drwx------  2 axm3244 ugrad  512 Dec  6 17:41 CPPLecture
drwx------  2 axm3244 ugrad  512 Aug 29 17:07 Courses
drwxr-xr-x  2 axm3244 ugrad  512 Nov 13 16:20 Desktop
drwx------  2 axm3244 ugrad  512 Nov 13 16:12 Documents
drwx------  2 axm3244 ugrad  512 Dec  6 02:46 Downloads
drwx------ 16 axm3244 ugrad  512 Nov 13 16:17 Library
drwx------  2 axm3244 ugrad  512 Nov 13 16:12 Movies
drwx------  2 axm3244 ugrad  512 Nov 13 16:12 Music
drwx------  2 axm3244 ugrad  512 Nov 13 16:12 Pictures
drwxr-xr-x  3 axm3244 ugrad  512 Nov 13 16:12 Public
drwx------  2 axm3244 ugrad  512 Dec 11 09:19 SSHApplication
drwxr-xr-x  2 axm3244 ugrad  512 Aug 29 17:07 public_html


-------------------------------------------------------------------------------

Test Case 2:

$ ./remoteCMD vermont "man grep" 

GREP(1)                                                                GREP(1)



NAME
       grep, egrep, fgrep, rgrep - print lines matching a pattern

SYNOPSIS
       grep [OPTIONS] PATTERN [FILE...]
       grep [OPTIONS] [-e PATTERN | -f FILE] [FILE...]

DESCRIPTION
       grep  searches the named input FILEs (or standard input if no files are
       named, or if a single hyphen-minus (-) is given as file name) for lines
       containing  a  match to the given PATTERN.  By default, grep prints the
       matching lines.

       In  addition,  three  variant  programs  egrep,  fgrep  and  rgrep  are
       available.   egrep  is  the  same  as  grep -E.   fgrep  is the same as
       grep -F.  rgrep is the same as grep -r.  Direct  invocation  as  either
       egrep  or  fgrep  is  deprecated,  but  is provided to allow historical
       applications that rely on them to run unmodified.

OPTIONS
   Generic Program Information
       --help Print a usage message  briefly  summarizing  these  command-line
              options and the bug-reporting address, then exit.

       -V, --version
              Print  the version number of grep to the standard output stream.
              This version number should be included in all bug  reports  (see
              below).

   Matcher Selection
       -E, --extended-regexp
              Interpret  PATTERN  as  an extended regular expression (ERE, see
              below).  (-E is specified by POSIX.)

       -F, --fixed-strings
              Interpret PATTERN as a  list  of  fixed  strings,  separated  by
              newlines,  any  of  which is to be matched.  (-F is specified by
              POSIX.)

       -G, --basic-regexp
              Interpret PATTERN  as  a  basic  regular  expression  (BRE,  see
              below).  This is the default.

       -P, --perl-regexp
              Interpret  PATTERN  as  a  Perl  regular  expression  (PCRE, see
              below).  This is highly experimental and grep  -P  may  warn  of
              unimplemented features.

   Matching Control
       -e PATTERN, --regexp=PATTERN
              Use  PATTERN  as  the  pattern.   This  can  be  used to specify
              multiple search patterns, or to protect a pattern beginning with
              a hyphen (-).  (-e is specified by POSIX.)

       -f FILE, --file=FILE
              Obtain  patterns  from  FILE,  one  per  line.   The  empty file
              contains zero patterns, and therefore matches nothing.   (-f  is
              specified by POSIX.)

       -i, --ignore-case
              Ignore  case  distinctions  in  both  the  PATTERN and the input
              files.  (-i is specified by POSIX.)

       -v, --invert-match
              Invert the sense of matching, to select non-matching lines.  (-v
              is specified by POSIX.)

       -w, --word-regexp
              Select  only  those  lines  containing  matches  that form whole
              words.  The test is that the matching substring must  either  be
              at  the  beginning  of  the  line,  or  preceded  by  a non-word
              constituent character.  Similarly, it must be either at the  end
              of  the  line  or  followed by a non-word constituent character.
              Word-constituent  characters  are  letters,  digits,   and   the
              underscore.

       -x, --line-regexp
              Select  only  those  matches  that exactly match the whole line.
              (-x is specified by POSIX.)

       -y     Obsolete synonym for -i.

   General Output Control
       -c, --count
              Suppress normal output; instead print a count of matching  lines
              for  each  input  file.  With the -v, --invert-match option (see
              below), count non-matching lines.  (-c is specified by POSIX.)

       --color[=WHEN], --colour[=WHEN]
              Surround  the  matched  (non-empty)  strings,  matching   lines,
              context  lines,  file  names,  line  numbers,  byte offsets, and
              separators (for fields and groups of context lines) with  escape
              sequences  to display them in color on the terminal.  The colors
              are  defined  by  the  environment  variable  GREP_COLORS.   The
              deprecated  environment  variable GREP_COLOR is still supported,
              but its setting does not have priority.  WHEN is never,  always,
              or auto.

       -L, --files-without-match
              Suppress  normal  output;  instead  print the name of each input
              file from which no output would normally have been printed.  The
              scanning will stop on the first match.

       -l, --files-with-matches
              Suppress  normal  output;  instead  print the name of each input
              file from which output would normally have  been  printed.   The
              scanning  will  stop  on  the  first match.  (-l is specified by
              POSIX.)

       -m NUM, --max-count=NUM
              Stop reading a file after NUM matching lines.  If the  input  is
              standard  input  from a regular file, and NUM matching lines are
              output, grep ensures that the standard input  is  positioned  to
              just  after the last matching line before exiting, regardless of
              the presence of trailing context lines.  This enables a  calling
              process  to resume a search.  When grep stops after NUM matching
              lines, it outputs any trailing context lines.  When  the  -c  or
              --count  option  is  also  used,  grep  does  not output a count
              greater than NUM.  When the -v or --invert-match option is  also
              used, grep stops after outputting NUM non-matching lines.

       -o, --only-matching
              Print  only  the  matched  (non-empty) parts of a matching line,
              with each such part on a separate output line.

       -q, --quiet, --silent
              Quiet;  do  not  write  anything  to  standard   output.    Exit
              immediately  with  zero status if any match is found, even if an
              error was detected.  Also see the -s  or  --no-messages  option.
              (-q is specified by POSIX.)

       -s, --no-messages
              Suppress  error  messages about nonexistent or unreadable files.
              Portability note: unlike GNU grep, 7th Edition Unix grep did not
              conform to POSIX, because it lacked -q and its -s option behaved
              like GNU grep's -q option.  USG-style grep also  lacked  -q  but
              its  -s  option  behaved  like GNU grep.  Portable shell scripts
              should avoid both -q and -s and  should  redirect  standard  and
              error output to /dev/null instead.  (-s is specified by POSIX.)

   Output Line Prefix Control
       -b, --byte-offset
              Print  the 0-based byte offset within the input file before each
              line of output.  If -o (--only-matching) is specified, print the
              offset of the matching part itself.

       -H, --with-filename
              Print  the  file  name for each match.  This is the default when
              there is more than one file to search.

       -h, --no-filename
              Suppress the prefixing of file names on  output.   This  is  the
              default  when there is only one file (or only standard input) to
              search.

       --label=LABEL
              Display input actually  coming  from  standard  input  as  input
              coming   from  file  LABEL.   This  is  especially  useful  when
              implementing tools like zgrep, e.g.,  gzip  -cd  foo.gz  |  grep
              --label=foo -H something.  See also the -H option.

       -n, --line-number
              Prefix  each  line of output with the 1-based line number within
              its input file.  (-n is specified by POSIX.)

       -T, --initial-tab
              Make sure that the first character of actual line  content  lies
              on a tab stop, so that the alignment of tabs looks normal.  This
              is useful with options that prefix their output  to  the  actual
              content:  -H,-n,  and  -b.   In order to improve the probability
              that lines from a single file will all start at the same column,
              this also causes the line number and byte offset (if present) to
              be printed in a minimum size field width.

       -u, --unix-byte-offsets
              Report Unix-style byte offsets.   This  switch  causes  grep  to
              report  byte offsets as if the file were a Unix-style text file,
              i.e., with  CR  characters  stripped  off.   This  will  produce
              results  identical  to  running  grep  on  a Unix machine.  This
              option has no effect unless -b option is also used;  it  has  no
              effect on platforms other than MS-DOS and MS-Windows.

       -Z, --null
              Output  a  zero  byte  (the  ASCII NUL character) instead of the
              character that normally follows a file name.  For example,  grep
              -lZ  outputs  a  zero  byte  after each file name instead of the
              usual newline.  This option makes the output  unambiguous,  even
              in the presence of file names containing unusual characters like
              newlines.  This option can  be  used  with  commands  like  find
              -print0,  perl  -0,  sort  -z, and xargs -0 to process arbitrary
              file names, even those that contain newline characters.

   Context Line Control
       -A NUM, --after-context=NUM
              Print NUM  lines  of  trailing  context  after  matching  lines.
              Places   a  line  containing  a  group  separator  (--)  between
              contiguous groups of matches.  With the  -o  or  --only-matching
              option, this has no effect and a warning is given.

       -B NUM, --before-context=NUM
              Print  NUM  lines  of  leading  context  before  matching lines.
              Places  a  line  containing  a  group  separator  (--)   between
              contiguous  groups  of  matches.  With the -o or --only-matching
              option, this has no effect and a warning is given.

       -C NUM, -NUM, --context=NUM
              Print NUM lines of output context.  Places a line  containing  a
              group separator (--) between contiguous groups of matches.  With
              the -o or --only-matching option,  this  has  no  effect  and  a
              warning is given.

   File and Directory Selection
       -a, --text
              Process  a binary file as if it were text; this is equivalent to
              the --binary-files=text option.

       --binary-files=TYPE
              If the first few bytes of a file indicate that the file contains
              binary  data, assume that the file is of type TYPE.  By default,
              TYPE is binary, and grep  normally  outputs  either  a  one-line
              message  saying  that  a  binary  file matches, or no message if
              there is no match.  If TYPE is without-match, grep assumes  that
              a  binary  file  does  not  match;  this is equivalent to the -I
              option.  If TYPE is text, grep processes a binary file as if  it
              were  text;  this is equivalent to the -a option.  Warning: grep
              --binary-files=text might output binary garbage, which can  have
              nasty  side  effects  if  the  output  is  a terminal and if the
              terminal driver interprets some of it as commands.

       -D ACTION, --devices=ACTION
              If an input file is a device, FIFO  or  socket,  use  ACTION  to
              process  it.   By  default,  ACTION  is  read,  which means that
              devices are read just as if they were ordinary files.  If ACTION
              is skip, devices are silently skipped.

       -d ACTION, --directories=ACTION
              If  an  input file is a directory, use ACTION to process it.  By
              default, ACTION is read, which means that directories  are  read
              just  as  if  they  were  ordinary  files.   If  ACTION is skip,
              directories are silently skipped.  If ACTION  is  recurse,  grep
              reads  all  files  under  each  directory,  recursively; this is
              equivalent to the -r option.

       --exclude=GLOB
              Skip  files  whose  base  name  matches  GLOB  (using   wildcard
              matching).   A  file-name  glob  can  use  *,  ?,  and [...]  as
              wildcards, and \ to quote  a  wildcard  or  backslash  character
              literally.

       --exclude-from=FILE
              Skip  files  whose  base name matches any of the file-name globs
              read from FILE  (using  wildcard  matching  as  described  under
              --exclude).

       --exclude-dir=DIR
              Exclude  directories  matching  the  pattern  DIR from recursive
              searches.

       -I     Process a binary file as if it did not  contain  matching  data;
              this is equivalent to the --binary-files=without-match option.

       --include=GLOB
              Search  only  files whose base name matches GLOB (using wildcard
              matching as described under --exclude).

       -R, -r, --recursive
              Read all  files  under  each  directory,  recursively;  this  is
              equivalent to the -d recurse option.

   Other Options
       --line-buffered
              Use  line  buffering  on  output.   This can cause a performance
              penalty.

       --mmap If possible, use the mmap(2) system call to read input,  instead
              of  the default read(2) system call.  In some situations, --mmap
              yields better performance.  However, --mmap can cause  undefined
              behavior  (including  core dumps) if an input file shrinks while
              grep is operating, or if an I/O error occurs.

       -U, --binary
              Treat the file(s) as binary.  By default, under MS-DOS  and  MS-
              Windows,  grep  guesses the file type by looking at the contents
              of the first 32KB read from the file.  If grep decides the  file
              is  a  text  file, it strips the CR characters from the original
              file contents (to make regular expressions with  ^  and  $  work
              correctly).  Specifying -U overrules this guesswork, causing all
              files to be read and passed to the matching mechanism  verbatim;
              if  the  file is a text file with CR/LF pairs at the end of each
              line, this will cause some regular expressions  to  fail.   This
              option  has  no  effect  on  platforms other than MS-DOS and MS-
              Windows.

       -z, --null-data
              Treat the input as a set of lines, each  terminated  by  a  zero
              byte  (the  ASCII NUL character) instead of a newline.  Like the
              -Z or --null option, this option can be used with commands  like
              sort -z to process arbitrary file names.

REGULAR EXPRESSIONS
       A  regular  expression  is  a  pattern that describes a set of strings.
       Regular  expressions  are   constructed   analogously   to   arithmetic
       expressions, by using various operators to combine smaller expressions.

       grep understands three different versions of regular expression syntax:
       "basic" (BRE), "extended" (ERE) and "perl" (PRCE). In  GNU grep,  there
       is  no difference in available functionality between basic and extended
       syntaxes.  In other implementations, basic regular expressions are less
       powerful.   The  following  description  applies  to  extended  regular
       expressions; differences for basic regular expressions  are  summarized
       afterwards.   Perl  regular  expressions give additional functionality,
       and are documented in pcresyntax(3) and pcrepattern(3), but may not  be
       available on every system.

       The  fundamental building blocks are the regular expressions that match
       a single character.  Most characters, including all letters and digits,
       are regular expressions that match themselves.  Any meta-character with
       special meaning may be quoted by preceding it with a backslash.

       The period . matches any single character.

   Character Classes and Bracket Expressions
       A bracket expression is a list of characters enclosed by [ and  ].   It
       matches  any  single  character in that list; if the first character of
       the list is the caret ^ then it matches any character not in the  list.
       For  example,  the  regular  expression [0123456789] matches any single
       digit.

       Within a  bracket  expression,  a  range  expression  consists  of  two
       characters separated by a hyphen.  It matches any single character that
       sorts  between  the  two  characters,  inclusive,  using  the  locale's
       collating  sequence  and  character set.  For example, in the default C
       locale, [a-d] is equivalent to [abcd].  Many locales sort characters in
       dictionary   order,  and  in  these  locales  [a-d]  is  typically  not
       equivalent to [abcd]; it might be equivalent to [aBbCcDd], for example.
       To  obtain  the  traditional interpretation of bracket expressions, you
       can use the C locale by setting the LC_ALL environment variable to  the
       value C.

       Finally,  certain  named  classes  of  characters are predefined within
       bracket expressions, as follows.  Their names are self explanatory, and
       they   are   [:alnum:],  [:alpha:],  [:cntrl:],  [:digit:],  [:graph:],
       [:lower:], [:print:], [:punct:], [:space:], [:upper:], and  [:xdigit:].
       For  example,  [[:alnum:]]  means  the  character  class of numbers and
       letters in the current locale. In the C locale and ASCII character  set
       encoding,  this is the same as [0-9A-Za-z].  (Note that the brackets in
       these class names are part of the symbolic names, and must be  included
       in  addition  to the brackets delimiting the bracket expression.)  Most
       meta-characters lose their special meaning inside bracket  expressions.
       To  include  a  literal  ]  place  it first in the list.  Similarly, to
       include a literal ^ place it anywhere but first.  Finally, to include a
       literal - place it last.

   Anchoring
       The caret ^ and the dollar sign $ are meta-characters that respectively
       match the empty string at the beginning and end of a line.

   The Backslash Character and Special Expressions
       The symbols \< and \>  respectively  match  the  empty  string  at  the
       beginning and end of a word.  The symbol \b matches the empty string at
       the edge of a word, and \B matches the empty string provided  it's  not
       at  the edge of a word.  The symbol \w is a synonym for [[:alnum:]] and
       \W is a synonym for [^[:alnum:]].

   Repetition
       A regular expression may be  followed  by  one  of  several  repetition
       operators:
       ?      The preceding item is optional and matched at most once.
       *      The preceding item will be matched zero or more times.
       +      The preceding item will be matched one or more times.
       {n}    The preceding item is matched exactly n times.
       {n,}   The preceding item is matched n or more times.
       {n,m}  The  preceding  item  is  matched at least n times, but not more
              than m times.

   Concatenation
       Two regular expressions may  be  concatenated;  the  resulting  regular
       expression  matches  any  string formed by concatenating two substrings
       that respectively match the concatenated expressions.

   Alternation
       Two regular expressions may be joined by  the  infix  operator  |;  the
       resulting   regular  expression  matches  any  string  matching  either
       alternate expression.

   Precedence
       Repetition takes precedence over concatenation,  which  in  turn  takes
       precedence  over  alternation.   A  whole expression may be enclosed in
       parentheses  to  override   these   precedence   rules   and   form   a
       subexpression.

   Back References and Subexpressions
       The back-reference \n, where n is a single digit, matches the substring
       previously matched  by  the  nth  parenthesized  subexpression  of  the
       regular expression.

   Basic vs Extended Regular Expressions
       In  basic  regular expressions the meta-characters ?, +, {, |, (, and )
       lose their special meaning; instead use the  backslashed  versions  \?,
       \+, \{, \|, \(, and \).

       Traditional  egrep did not support the { meta-character, and some egrep
       implementations support \{ instead, so portable scripts should avoid  {
       in grep -E patterns and should use [{] to match a literal {.

       GNU grep -E attempts to support traditional usage by assuming that { is
       not  special  if  it  would  be  the  start  of  an  invalid   interval
       specification.   For example, the command grep -E '{1' searches for the
       two-character string {1 instead of reporting  a  syntax  error  in  the
       regular  expression.  POSIX.2 allows this behavior as an extension, but
       portable scripts should avoid it.

ENVIRONMENT VARIABLES
       The  behavior  of  grep  is  affected  by  the  following   environment
       variables.

       The  locale  for  category  LC_foo  is specified by examining the three
       environment variables LC_ALL, LC_foo, LANG, in that order.   The  first
       of  these  variables that is set specifies the locale.  For example, if
       LC_ALL is not set, but LC_MESSAGES is set to pt_BR, then the  Brazilian
       Portuguese  locale  is used for the LC_MESSAGES category.  The C locale
       is used if none of these environment variables are set, if  the  locale
       catalog  is  not  installed,  or if grep was not compiled with national
       language support (NLS).

       GREP_OPTIONS
              This variable specifies default options to be placed in front of
              any   explicit   options.    For  example,  if  GREP_OPTIONS  is
              '--binary-files=without-match --directories=skip', grep  behaves
              as   if   the   two   options  --binary-files=without-match  and
              --directories=skip  had  been  specified  before  any   explicit
              options.   Option specifications are separated by whitespace.  A
              backslash escapes the next character,  so  it  can  be  used  to
              specify an option containing whitespace or a backslash.

       GREP_COLOR
              This  variable  specifies  the  color  used to highlight matched
              (non-empty) text.  It is deprecated in favor of GREP_COLORS, but
              still supported.  The mt, ms, and mc capabilities of GREP_COLORS
              have priority over it.  It can only specify the  color  used  to
              highlight  the  matching  non-empty text in any matching line (a
              selected line when the -v command-line option is omitted,  or  a
              context line when -v is specified).  The default is 01;31, which
              means a bold red  foreground  text  on  the  terminal's  default
              background.

       GREP_COLORS
              Specifies  the  colors  and  other  attributes used to highlight
              various parts of the output.  Its  value  is  a  colon-separated
              list       of       capabilities      that      defaults      to
              ms=01;31:mc=01;31:sl=:cx=:fn=35:ln=32:bn=32:se=36  with  the  rv
              and  ne  boolean  capabilities omitted (i.e., false).  Supported
              capabilities are as follows.

              sl=    SGR substring for whole selected  lines  (i.e.,  matching
                     lines when the -v command-line option is omitted, or non-
                     matching lines when -v is  specified).   If  however  the
                     boolean  rv capability and the -v command-line option are
                     both specified, it  applies  to  context  matching  lines
                     instead.   The  default  is  empty  (i.e., the terminal's
                     default color pair).

              cx=    SGR substring for whole context lines (i.e., non-matching
                     lines  when  the  -v  command-line  option is omitted, or
                     matching lines when -v is  specified).   If  however  the
                     boolean  rv capability and the -v command-line option are
                     both specified, it applies to selected non-matching lines
                     instead.   The  default  is  empty  (i.e., the terminal's
                     default color pair).

              rv     Boolean value that reverses (swaps) the meanings  of  the
                     sl=  and cx= capabilities when the -v command-line option
                     is specified.  The default is false (i.e., the capability
                     is omitted).

              mt=01;31
                     SGR substring for matching non-empty text in any matching
                     line (i.e., a selected  line  when  the  -v  command-line
                     option   is  omitted,  or  a  context  line  when  -v  is
                     specified).  Setting this is equivalent to  setting  both
                     ms=  and mc= at once to the same value.  The default is a
                     bold  red  text  foreground   over   the   current   line
                     background.

              ms=01;31
                     SGR  substring  for matching non-empty text in a selected
                     line.  (This is only used when the -v command-line option
                     is  omitted.)   The  effect  of  the  sl=  (or cx= if rv)
                     capability  remains  active  when  this  kicks  in.   The
                     default  is  a  bold red text foreground over the current
                     line background.

              mc=01;31
                     SGR substring for matching non-empty text  in  a  context
                     line.  (This is only used when the -v command-line option
                     is specified.)  The effect of the  cx=  (or  sl=  if  rv)
                     capability  remains  active  when  this  kicks  in.   The
                     default is a bold red text foreground  over  the  current
                     line background.

              fn=35  SGR  substring for file names prefixing any content line.
                     The  default  is  a  magenta  text  foreground  over  the
                     terminal's default background.

              ln=32  SGR  substring  for  line  numbers  prefixing any content
                     line.  The default is a green text  foreground  over  the
                     terminal's default background.

              bn=32  SGR  substring  for  byte  offsets  prefixing any content
                     line.  The default is a green text  foreground  over  the
                     terminal's default background.

              se=36  SGR  substring  for  separators that are inserted between
                     selected line fields (:), between  context  line  fields,
                     (-),  and  between  groups of adjacent lines when nonzero
                     context is specified (--).  The default is  a  cyan  text
                     foreground over the terminal's default background.

              ne     Boolean  value  that prevents clearing to the end of line
                     using Erase in Line (EL) to Right  (\33[K)  each  time  a
                     colorized  item  ends.   This  is  needed on terminals on
                     which EL is not supported.  It  is  otherwise  useful  on
                     terminals  for  which  the back_color_erase (bce) boolean
                     terminfo capability  does  not  apply,  when  the  chosen
                     highlight colors do not affect the background, or when EL
                     is too slow or causes too much flicker.  The  default  is
                     false (i.e., the capability is omitted).

              Note  that  boolean  capabilities  have no =...  part.  They are
              omitted (i.e., false) by default and become true when specified.

              See  the  Select  Graphic  Rendition  (SGR)   section   in   the
              documentation  of  the  text terminal that is used for permitted
              values  and  their  meaning  as  character  attributes.    These
              substring  values are integers in decimal representation and can
              be concatenated with semicolons.  grep takes care of  assembling
              the  result  into  a  complete  SGR sequence (\33[...m).  Common
              values to concatenate include 1 for bold, 4 for underline, 5 for
              blink,  7 for inverse, 39 for default foreground color, 30 to 37
              for foreground colors, 90 to 97  for  16-color  mode  foreground
              colors,  38;5;0  to  38;5;255  for  88-color and 256-color modes
              foreground colors, 49 for default background color, 40 to 47 for
              background  colors,  100  to  107  for  16-color mode background
              colors, and 48;5;0 to 48;5;255 for 88-color and 256-color  modes
              background colors.

       LC_ALL, LC_COLLATE, LANG
              These  variables specify the locale for the LC_COLLATE category,
              which determines the collating sequence used to interpret  range
              expressions like [a-z].

       LC_ALL, LC_CTYPE, LANG
              These  variables  specify  the locale for the LC_CTYPE category,
              which determines the type of characters, e.g., which  characters
              are whitespace.

       LC_ALL, LC_MESSAGES, LANG
              These variables specify the locale for the LC_MESSAGES category,
              which determines the language that grep uses for messages.   The
              default C locale uses American English messages.

       POSIXLY_CORRECT
              If  set,  grep  behaves  as  POSIX.2  requires;  otherwise, grep
              behaves more like other GNU  programs.   POSIX.2  requires  that
              options that follow file names must be treated as file names; by
              default, such options are permuted to the front of  the  operand
              list  and  are  treated as options.  Also, POSIX.2 requires that
              unrecognized options be diagnosed as "illegal", but  since  they
              are  not  really against the law the default is to diagnose them
              as      "invalid".       POSIXLY_CORRECT      also      disables
              _N_GNU_nonoption_argv_flags_, described below.

       _N_GNU_nonoption_argv_flags_
              (Here  N is grep's numeric process ID.)  If the ith character of
              this environment variable's value is 1, do not consider the  ith
              operand  of  grep to be an option, even if it appears to be one.
              A shell can put  this  variable  in  the  environment  for  each
              command  it  runs,  specifying which operands are the results of
              file name wildcard expansion and therefore should not be treated
              as  options.   This  behavior  is  available only with the GNU C
              library, and only when POSIXLY_CORRECT is not set.

EXIT STATUS
       The exit status is 0 if selected lines are found, and 1 if  not  found.
       If an error occurred the exit status is 2.  (Note: POSIX error handling
       code should check for '2' or greater.)

COPYRIGHT
       Copyright 1998-2000, 2002, 2005-2011 Free Software Foundation, Inc.

       This is free software; see the source for copying conditions.  There is
       NO  warranty;  not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR
       PURPOSE.

BUGS
   Reporting Bugs
       Email bug reports to <bug-grep@gnu.org>, a mailing list whose web  page
       is  <http://lists.gnu.org/mailman/listinfo/bug-grep>.   grep's Savannah
       bug tracker is located at <http://savannah.gnu.org/bugs/?group=grep>.

   Known Bugs
       Large repetition counts in the {n,m} construct may cause  grep  to  use
       lots of memory.  In addition, certain other obscure regular expressions
       require exponential time and space, and may cause grep to  run  out  of
       memory.

       Back-references are very slow, and may require exponential time.

SEE ALSO
   Regular Manual Pages
       awk(1),  cmp(1),  diff(1),  find(1), gzip(1), perl(1), sed(1), sort(1),
       xargs(1),   zgrep(1),   mmap(2),   read(2),   pcre(3),   pcresyntax(3),
       pcrepattern(3), terminfo(5), glob(7), regex(7).

   POSIX Programmer's Manual Page
       grep(1p).

   TeXinfo Documentation
       The  full documentation for grep is maintained as a TeXinfo manual.  If
       the info and grep programs are properly installed  at  your  site,  the
       command

              info grep

       should give you access to the complete manual.

NOTES
       GNU's not Unix, but Unix is a beast; its plural form is Unixen.



User Commands                    GNU grep 2.10                         GREP(1)

-------------------------------------------------------------------------------
Test Case 2:

$ ./remoteCMD california "ps aux" 


USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.0  0.0  10420  3328 ?        Ss   Nov20   0:01 /sbin/init
root         2  0.0  0.0      0     0 ?        S    Nov20   0:00 [kthreadd]
root         3  0.0  0.0      0     0 ?        S    Nov20   0:18 [ksoftirqd/0]
root         6  0.0  0.0      0     0 ?        S    Nov20   0:04 [migration/0]
root         7  0.0  0.0      0     0 ?        S    Nov20   0:04 [watchdog/0]
root         8  0.0  0.0      0     0 ?        S    Nov20   0:03 [migration/1]
root        10  0.0  0.0      0     0 ?        S    Nov20   0:13 [ksoftirqd/1]
root        12  0.0  0.0      0     0 ?        S    Nov20   0:03 [watchdog/1]
root        13  0.0  0.0      0     0 ?        S    Nov20   0:02 [migration/2]
root        15  0.0  0.0      0     0 ?        S    Nov20   0:13 [ksoftirqd/2]
root        16  0.0  0.0      0     0 ?        S    Nov20   0:03 [watchdog/2]
root        17  0.0  0.0      0     0 ?        S    Nov20   0:03 [migration/3]
root        19  0.0  0.0      0     0 ?        S    Nov20   0:11 [ksoftirqd/3]
root        20  0.0  0.0      0     0 ?        S    Nov20   0:03 [watchdog/3]
root        21  0.0  0.0      0     0 ?        S<   Nov20   0:00 [cpuset]
root        22  0.0  0.0      0     0 ?        S<   Nov20   0:00 [khelper]
root        23  0.0  0.0      0     0 ?        S    Nov20   0:00 [kdevtmpfs]
root        24  0.0  0.0      0     0 ?        S<   Nov20   0:00 [netns]
root        26  0.0  0.0      0     0 ?        S    Nov20   0:02 [sync_supers]
root        27  0.0  0.0      0     0 ?        S    Nov20   0:00 [bdi-default]
root        28  0.0  0.0      0     0 ?        S<   Nov20   0:00 [kintegrityd]
root        29  0.0  0.0      0     0 ?        S<   Nov20   0:00 [kblockd]
root        30  0.0  0.0      0     0 ?        S<   Nov20   0:00 [ata_sff]
root        31  0.0  0.0      0     0 ?        S    Nov20   0:00 [khubd]
root        32  0.0  0.0      0     0 ?        S<   Nov20   0:00 [md]
root        34  0.0  0.0      0     0 ?        S    Nov20   0:00 [khungtaskd]
root        35  0.0  0.0      0     0 ?        S    Nov20   0:00 [kswapd0]
root        36  0.0  0.0      0     0 ?        SN   Nov20   0:00 [ksmd]
root        37  0.0  0.0      0     0 ?        SN   Nov20   0:00 [khugepaged]
root        38  0.0  0.0      0     0 ?        S    Nov20   0:00 [fsnotify_mark]
root        39  0.0  0.0      0     0 ?        S    Nov20   0:00 [ecryptfs-kthrea]
root        40  0.0  0.0      0     0 ?        S<   Nov20   0:00 [crypto]
root        48  0.0  0.0      0     0 ?        S<   Nov20   0:00 [kthrotld]
root        50  0.0  0.0      0     0 ?        S    Nov20   0:00 [scsi_eh_0]
root        51  0.0  0.0      0     0 ?        S    Nov20   0:00 [scsi_eh_1]
root        52  0.0  0.0      0     0 ?        S    Nov20   0:00 [scsi_eh_2]
root        53  0.0  0.0      0     0 ?        S    Nov20   0:00 [scsi_eh_3]
root        54  0.0  0.0      0     0 ?        S    Nov20   0:00 [scsi_eh_4]
root        55  0.0  0.0      0     0 ?        S    Nov20   0:00 [scsi_eh_5]
root        58  0.0  0.0      0     0 ?        S    Nov20   0:00 [kworker/u:5]
root        59  0.0  0.0      0     0 ?        S    Nov20   0:00 [kworker/u:6]
root        79  0.0  0.0      0     0 ?        S<   Nov20   0:00 [devfreq_wq]
root       254  0.0  0.0      0     0 ?        S    Nov20   0:07 [jbd2/sda1-8]
root       255  0.0  0.0      0     0 ?        S<   Nov20   0:00 [ext4-dio-unwrit]
root       352  0.0  0.0   2836   604 ?        S    Nov20   0:00 upstart-udev-bridge --daemon
root       355  0.0  0.0   3520  1708 ?        Ss   Nov20   0:00 /sbin/udevd --daemon
root       543  0.0  0.0      0     0 ?        S<   Nov20   0:00 [kpsmoused]
root       559  0.0  0.0      0     0 ?        S    Nov20   0:00 [irq/47-mei]
root       652  0.0  0.0      0     0 ?        S<   Nov20   0:00 [rpciod]
root       653  0.0  0.0      0     0 ?        S<   Nov20   0:00 [nfsiod]
root       681  0.0  0.0      0     0 ?        S    Nov20   0:09 [flush-8:0]
syslog     708  0.0  0.0  31064  1752 ?        Sl   Nov20   1:17 rsyslogd -c5
root       713  0.0  0.0   2912   640 ?        Ss   Nov20   0:00 rpc.idmapd
root       724  0.0  0.0      0     0 ?        S<   Nov20   0:00 [hd-audio0]
root       735  0.0  0.0   2848   368 ?        S    Nov20   0:00 upstart-socket-bridge --daemon
root       740  0.0  0.0      0     0 ?        S<   Nov20   0:00 [hd-audio1]
root       764  0.0  0.0   2700   980 ?        Ss   Nov20   0:01 rpcbind -w
root       800  0.0  0.0      0     0 ?        Z    Nov26   0:00 [lightdm] <defunct>
102        917  0.0  0.0  11428  3224 ?        Ss   Nov20   0:17 dbus-daemon --system --fork --activation=upstart
root       936  0.0  0.0   4744  1612 ?        Ss   Nov20   0:00 /usr/sbin/bluetoothd
root       946  0.0  0.0      0     0 ?        S<   Nov20   0:00 [krfcommd]
avahi      961  0.0  0.0  11268  4020 ?        S    Nov20   1:43 avahi-daemon: running [vermont.local]
avahi      966  0.0  0.0  10188  1072 ?        S    Nov20   0:00 avahi-daemon: chroot helper
root      1064  0.0  0.0   2928   824 ?        Ss   Nov20   0:00 dhclient3 -e IF_METRIC=100 -pf /var/run/dhclient.eth0.pid -lf /var/lib/dhcp/dhclient.eth0.leases -1 eth0
root      1108  0.0  0.0   6684  2312 ?        Ss   Nov20   0:00 /usr/sbin/sshd -D
root      1408  0.0  0.0   4632   860 tty4     Ss+  Nov20   0:00 /sbin/getty -8 38400 tty4
root      1415  0.0  0.0   4632   864 tty5     Ss+  Nov20   0:00 /sbin/getty -8 38400 tty5
root      1463  0.0  0.0   4632   852 tty2     Ss+  Nov20   0:00 /sbin/getty -8 38400 tty2
root      1464  0.0  0.0   4632   864 tty3     Ss+  Nov20   0:00 /sbin/getty -8 38400 tty3
root      1466  0.0  0.0   4632   856 tty6     Ss+  Nov20   0:00 /sbin/getty -8 38400 tty6
root      1489  0.0  0.0   2176   704 ?        Ss   Nov20   0:00 acpid -c /etc/acpi/events -s /var/run/acpid.socket
root      1490  0.0  0.0   2620   904 ?        Ss   Nov20   0:01 cron
daemon    1491  0.0  0.0   2472   348 ?        Ss   Nov20   0:00 atd
root      1499  0.0  0.0      0     0 ?        Z    Nov26   0:00 [lightdm] <defunct>
root      1505  0.0  0.0  40588  4572 ?        Ssl  Nov20   0:00 lightdm
root      1506  0.0  0.0   3604   636 ?        Ss   Nov20   2:49 /usr/sbin/irqbalance
root      1516  0.0  0.0  34288  3072 ?        Ssl  Nov20   0:38 /usr/sbin/automount
whoopsie  1526  0.0  0.0  26212  5608 ?        Ssl  Nov20   0:53 whoopsie
root      1575  0.0  0.0   4580  1452 ?        Ss   Nov20   0:03 /usr/lib/postfix/master
postfix   1588  0.0  0.0  11532  2624 ?        S    Nov20   0:00 qmgr -l -t fifo -u
root      1599  0.0  0.0      0     0 ?        S<   Nov20   0:00 [iprt]
root      1666  0.0  0.0  17916 10912 ?        S    Nov20  20:10 /usr/bin/python /usr/bin/landscape-client --daemon --pid-file /var/run/landscape/landscape-client.pid
120       1677  0.0  0.1  55204 19496 ?        Sl   Nov20  13:18 /usr/bin/python /usr/bin/landscape-broker --ignore-sigint --quiet
120       1678  0.0  0.0  23268 15812 ?        S    Nov20   9:12 /usr/bin/python /usr/bin/landscape-monitor --ignore-sigint --quiet
root      1679  0.0  0.0  18952 14148 ?        S    Nov20   5:40 /usr/bin/python /usr/bin/landscape-manager --ignore-sigint --quiet
root      1750  0.0  0.0  22680  5092 ?        Sl   Nov20   0:17 /usr/lib/accountsservice/accounts-daemon
root      1754  0.0  0.0  31944  5216 ?        Sl   Nov20   0:03 /usr/lib/policykit-1/polkitd --no-debug
ntp       1824  0.0  0.0  12428  3200 ?        Ss   Nov20   0:52 /usr/sbin/ntpd -p /var/run/ntpd.pid -g -u 115:124
root      1877  0.0  0.0   4632   852 tty1     Ss+  Nov20   0:00 /sbin/getty -8 38400 tty1
root      1892  0.0  0.0  34304  3532 ?        Sl   Nov20   0:03 /usr/sbin/console-kit-daemon --no-daemon
root      2017  0.0  0.0  28424  3768 ?        Sl   Nov20   0:01 /usr/lib/upower/upowerd
root      2020  0.0  0.0      0     0 ?        S    18:54   0:01 [kworker/2:0]
root      2132  0.0  0.0  11076  3520 ?        Ss   Dec06   0:00 /usr/sbin/cupsd -F
colord    2137  0.0  0.0  53584 10448 ?        Sl   Nov20   0:00 /usr/lib/i386-linux-gnu/colord/colord
rtkit     2160  0.0  0.0  21332  1264 ?        SNl  Nov20   0:08 /usr/lib/rtkit/rtkit-daemon
statd     2266  0.0  0.0   3248  1680 ?        Ss   Nov20   0:00 rpc.statd --no-notify
root      2267  0.0  0.0      0     0 ?        S    Nov20   0:00 [lockd]
root      2325  0.0  0.2  58532 41420 tty7     Ss+  19:02   0:06 /usr/bin/X :0 -auth /var/run/lightdm/root/:0 -nolisten tcp vt7 -novtswitch
root      2329  0.0  0.0      0     0 ?        S    19:02   0:00 [kworker/0:0]
root      2332  0.0  0.0  22928  4492 ?        Sl   19:02   0:00 lightdm --session-child 236 239
lightdm   2355  0.0  0.0   2236   544 ?        Ss   19:02   0:00 /bin/sh /usr/lib/lightdm/lightdm-greeter-session /usr/sbin/unity-greeter
lightdm   2360  0.0  0.0  10624  1708 ?        Ss   19:02   0:00 //bin/dbus-daemon --fork --print-pid 5 --print-address 7 --session
lightdm   2361  0.0  0.0 185116 15892 ?        Sl   19:02   0:01 /usr/sbin/unity-greeter
lightdm   2367  0.0  0.0  44364  2996 ?        Sl   19:02   0:00 /usr/lib/at-spi2-core/at-spi-bus-launcher
lightdm   2374  0.0  0.0   9992  2744 ?        S    19:02   0:00 /bin/dbus-daemon --config-file=/etc/at-spi2/accessibility.conf --nofork --print-address 3
lightdm   2379  0.0  0.0  17000  3056 ?        Sl   19:02   0:00 /usr/lib/at-spi2-core/at-spi2-registryd --use-gnome-session
lightdm   2381  0.0  0.0   6356  2088 ?        S    19:02   0:00 /usr/lib/gvfs/gvfsd
lightdm   2383  0.0  0.0  33736  2556 ?        Sl   19:02   0:00 /usr/lib/gvfs//gvfs-fuse-daemon -f /var/lib/lightdm/.gvfs
lightdm   2391  0.0  0.0  33516  2384 ?        Sl   19:02   0:00 /usr/lib/dconf/dconf-service
lightdm   2397  0.0  0.0  57784  9072 ?        Sl   19:02   0:00 /usr/lib/gnome-settings-daemon/gnome-settings-daemon
root      2406  0.0  0.0  11988  2708 ?        S    19:02   0:00 lightdm --session-child 19 239
lightdm   2411  0.0  0.0  76460  4876 ?        Sl   19:02   0:00 /usr/lib/indicator-session/indicator-session-service
lightdm   2413  0.0  0.0  71376  5988 ?        Sl   19:02   0:00 /usr/lib/indicator-datetime/indicator-datetime-service
lightdm   2424  0.0  0.0 123484  4764 ?        Sl   19:02   0:00 /usr/lib/indicator-sound/indicator-sound-service
root      2425  0.0  0.0      0     0 ?        Z    Nov26   0:00 [lightdm] <defunct>
lightdm   2434  0.0  0.0   7980  2364 ?        S    19:02   0:00 /usr/lib/geoclue/geoclue-master
lightdm   2436  0.0  0.0   7220  2728 ?        S    19:02   0:00 /usr/lib/i386-linux-gnu/gconf/gconfd-2
lightdm   2440  0.0  0.0  21288  4308 ?        S    19:02   0:00 /usr/lib/ubuntu-geoip/ubuntu-geoip-provider
lightdm   2441  0.0  0.0 106440  4932 ?        S<l  19:02   0:00 /usr/bin/pulseaudio --start --log-target=syslog
lightdm   2448  0.0  0.0  14104  2492 ?        S    19:02   0:00 /usr/lib/pulseaudio/pulse/gconf-helper
root      2501  0.0  0.0      0     0 ?        Z    Nov26   0:00 [lightdm] <defunct>
root      2502  0.0  0.0      0     0 ?        Z    Nov26   0:00 [lightdm] <defunct>
gxv7682   3329  0.0  0.0  22736  3656 ?        Sl   Dec11   0:00 /usr/lib/deja-dup/deja-dup/deja-dup-monitor
postfix   4282  0.0  0.0  11332  2592 ?        S    20:11   0:00 pickup -l -t fifo -u -c
root      4334  0.0  0.0  15240  4496 ?        Ss   Dec11   0:00 sshd: dgl2311 [priv]
root      4385  0.0  0.0      0     0 ?        S    20:46   0:00 [kworker/0:1]
root      4387  0.0  0.0  15240  4456 ?        Ss   20:47   0:00 sshd: sds1011 [priv]
dgl2311   4488  0.0  0.0  15240  2440 ?        S    Dec11   0:01 sshd: dgl2311@pts/2 
dgl2311   4489  0.0  0.0  13092  5948 pts/2    Ss   Dec11   0:00 -bash
sds1011   4541  0.0  0.0  15240  2444 ?        S    20:47   0:00 sshd: sds1011@pts/7 
sds1011   4542  0.0  0.0  13060  5888 pts/7    Ss   20:47   0:00 -bash
dgl2311   4587  0.0  0.0  92140  4612 pts/2    S+   Dec11   0:00 /usr/lib/gcl-2.6.7/unixport/saved_gcl -dir /usr/lib/gcl-2.6.7/unixport/ -libdir /usr/lib/gcl-2.6.7/ -eval (setq si::*allow-gzipped-file* t) -eval (setq si::*tk-library* "/usr/lib/tk8.4")
root      4606  0.0  0.0  15240  4452 ?        Ss   20:47   0:00 sshd: sds1011 [priv]
sds1011   4734  0.0  0.0  15240  2448 ?        S    20:47   0:00 sshd: sds1011@pts/8 
sds1011   4735  0.0  0.0  13060  5888 pts/8    Ss+  20:47   0:00 -bash
sds1011   4802  0.0  0.0  17224  5172 pts/7    S+   20:48   0:00 vim linkedlist.c
root      4815  0.0  0.0      0     0 ?        S    20:50   0:00 [flush-0:26]
root      4827  0.0  0.0      0     0 ?        S    20:51   0:00 [kworker/0:2]
jdh7273   4849  0.0  0.0  17332  5024 pts/6    S+   20:55   0:00 vim ssh.c
root      4863  0.0  0.0      0     0 ?        S    20:55   0:00 [flush-0:29]
root      5154  0.0  0.0  15212  4324 ?        Ss   20:58   0:00 sshd: axm3244 [priv]
axm3244   5282  0.0  0.0  15360  2388 ?        S    20:58   0:00 sshd: axm3244@notty 
axm3244   5283  0.0  0.0   9728  2560 ?        Rs   20:58   0:00 ps aux
root      5635  0.0  0.0      0     0 ?        S    Dec11   0:08 [kworker/3:2]
root     13297  0.0  0.0      0     0 ?        Z    Nov27   0:00 [lightdm] <defunct>
root     14374  0.0  0.0      0     0 ?        Z    Nov27   0:00 [lightdm] <defunct>
root     14608  0.0  0.0  15240  4504 ?        Ss   Nov27   0:00 sshd: nxz3937 [priv]
nxz3937  14765  0.0  0.0  15736  2712 ?        S    Nov27   3:49 sshd: nxz3937@pts/0 
nxz3937  14766  0.0  0.0  13160  6068 pts/0    Ss   Nov27   0:00 -bash
root     18316  0.0  0.0      0     0 ?        S<   Nov30   0:00 [xfs_mru_cache]
root     18317  0.0  0.0   3516  1280 ?        S    Nov30   0:00 /sbin/udevd --daemon
root     18318  0.0  0.0      0     0 ?        S<   Nov30   0:00 [xfslogd]
root     18319  0.0  0.0      0     0 ?        S<   Nov30   0:00 [xfsdatad]
root     18320  0.0  0.0      0     0 ?        S<   Nov30   0:00 [xfsconvertd]
root     18321  0.0  0.0   3516  1260 ?        S    Nov30   0:00 /sbin/udevd --daemon
root     18324  0.0  0.0      0     0 ?        S    Nov30   0:00 [jfsIO]
root     18325  0.0  0.0      0     0 ?        S    Nov30   0:00 [jfsCommit]
root     18326  0.0  0.0      0     0 ?        S    Nov30   0:00 [jfsCommit]
root     18327  0.0  0.0      0     0 ?        S    Nov30   0:00 [jfsCommit]
root     18328  0.0  0.0      0     0 ?        S    Nov30   0:00 [jfsCommit]
root     18329  0.0  0.0      0     0 ?        S    Nov30   0:00 [jfsSync]
root     22015  0.0  0.0      0     0 ?        Z    Nov28   0:00 [lightdm] <defunct>
nxz3937  23266  0.0  0.0   2408   704 pts/0    S+   Dec05   0:00 script
nxz3937  23267  0.0  0.0   3432  1392 pts/0    S+   Dec05   2:34 script
nxz3937  23268  0.0  0.0  10548  3412 pts/1    Ss+  Dec05   0:00 bash -i
root     23698  0.0  0.0      0     0 ?        Z    Nov28   0:00 [lightdm] <defunct>
root     29582  0.0  0.0      0     0 ?        S    11:55   0:04 [kworker/2:3]
root     29756  0.0  0.0  25272  3656 ?        Sl   Nov26   0:19 /usr/lib/udisks/udisks-daemon
root     29757  0.0  0.0   6556   728 ?        S    Nov26   0:00 udisks-daemon: not polling any devices
root     31142  0.0  0.0  15240  4468 ?        Ss   16:11   0:00 sshd: jdh7273 [priv]
jdh7273  31271  0.0  0.0  15392  2560 ?        S    16:11   0:00 sshd: jdh7273@pts/3 
jdh7273  31272  0.0  0.0  13160  6068 pts/3    Ss+  16:11   0:00 -bash
jcm2734  31962 99.6  0.0   3372   872 ?        R    Dec06 10450:52 /home/stu12/s9/jcm2734/lab2/lab2-sol
jcm2734  31965 99.6  0.0   3372   872 ?        R    Dec06 10451:06 /home/stu12/s9/jcm2734/lab2/lab2-sol
jcm2734  31969 99.6  0.0   3372   872 ?        R    Dec06 10450:44 /home/stu12/s9/jcm2734/lab2/lab2-sol
jcm2734  31980 99.6  0.0   3372   868 ?        R    Dec06 10450:39 /home/stu12/s9/jcm2734/lab2/lab2-sol
root     32261  0.0  0.0      0     0 ?        S    16:59   0:02 [kworker/1:2]
root     32419  0.0  0.0      0     0 ?        S    17:03   0:03 [kworker/3:1]
root     32496  0.0  0.0      0     0 ?        S    17:15   0:00 [kworker/1:0]
root     32582  0.0  0.0  15240  4468 ?        Ss   17:27   0:00 sshd: jdh7273 [priv]
jdh7273  32739  0.0  0.0  15240  2432 ?        S    17:27   0:00 sshd: jdh7273@pts/6 
jdh7273  32740  0.0  0.0  13156  6064 pts/6    Ss   17:27   0:00 -bash

-------------------------------------------------------------------------------
Test Case 4:

$ ./remoteCMD glados "ant" 

Buildfile: build.xml does not exist!

-------------------------------------------------------------------------------
END OF FILE