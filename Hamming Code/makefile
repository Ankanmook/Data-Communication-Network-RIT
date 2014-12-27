#
# Created by gmakemake (Ubuntu Sep  7 2011) on Thu Feb  7 22:25:30 2013
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Default flags (redefine these with a header.mak file if desired)
CXXFLAGS =	-ggdb
CFLAGS =	-ggdb
CLIBFLAGS =	-lm
CCLIBFLAGS =	
########## End of default flags


CPP_FILES =	decode.cpp encode.cpp flipper.cpp
C_FILES =	
PS_FILES =	
S_FILES =	
H_FILES =	decode.h encode.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	

#
# Main targets
#

all:	decode encode flipper 

decode:	decode.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o decode decode.o $(OBJFILES) $(CCLIBFLAGS)

encode:	encode.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o encode encode.o $(OBJFILES) $(CCLIBFLAGS)

flipper:	flipper.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o flipper flipper.o $(OBJFILES) $(CCLIBFLAGS)

#
# Dependencies
#

decode.o:	decode.h
encode.o:	encode.h
flipper.o:	

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm $(OBJFILES) decode.o encode.o flipper.o core 2> /dev/null

realclean:        clean
	-/bin/rm -rf decode encode flipper 
