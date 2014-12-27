//  $Id: flipper.cpp,v 1.4 2013/02/08 03:40:20 axm3244 Exp axm3244 $

/*  SUMMARY
 *
 *
 *  REVISION HISTORY
 *    $Log: flipper.cpp,v $
 *    Revision 1.4  2013/02/08 03:40:20  axm3244
 *    Final Testing and
 *    Functionality Refinement
 *
 *    Revision 1.3  2013/02/07 18:49:52  axm3244
 *    Added Empty Check Function
 *
 *    Revision 1.2  2013/02/07 18:04:20  axm3244
 *    Added Bit Decoding and Reading of Bit
 *
 *    Revision 1.1  2013/01/30 02:32:17  axm3244
 *    Initial revision
 *
 *
 *
 *
 *    Author : Ankan Mookherjee
 */



#include<cstdlib>
#include<math.h>
#include<time.h>
#include<cstdio>
#include<iostream>


using namespace std;
const int RAW_BIT_SIZE= 8;


/*
 * Main Function
 * Program execution begins here. 
 * Reads one byte at a time from input stream
 * and writes into stdout stream
 *
 * @param takes None
 * @return int
 */
int main(){
    char byte;
    int rnd;
    /* Using time as random seed*/
    srand (time(0));

    while(fread(&byte, 1, 1, stdin))
    {
	 /* Probability of flipping a bit is 1 percent */
        if((rnd = rand()%800)< RAW_BIT_SIZE)
	 {

	     /* Flipping one random bit using XOR gate */
            byte ^=(1<<rnd);
        }
        fwrite(&byte, 1, 1, stdout);
    }        
}
