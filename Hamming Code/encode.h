
/*  SUMMARY
 *
 *
 *  REVISION HISTORY
 *    $Log: encode.h,v $
 *    Revision 1.5  2013/02/08 04:27:05  axm3244
 *    Removed Unecessary Commenting
 *    and Print Statements
 *
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


/* Referencing library and header files for pre-processing */

# ifndef ENCODE_H
# define ENCODE_H


# include<cstdlib>
# include<iostream>
# include<stdlib.h>
# include<math.h>
# include<cstdio>

/* Const member variables */
const int ENCODED_BIT_SIZE = 24;
const int RAW_BIT_SIZE = 8;




/*
 * Generates Integer Array of Binary Bit
 *
 * Converts character input to Binary bit of integer array
 * If no error is found then decodes and generates the original
 * sent data
 *
 *
 * @praram  takes char and int* word
 * @returns void
 */
void generateBinary(char byte, int* rawBinaryData);



/*
 * Generates Encoded 3 Byte Array from 2 Bytes of Input Data 
 *
 * Converts character input of Two Binary bytes of 12 size into
 * a single array of 24 size of integer which will be sent as
 * encoded data
 *
 *
 * @praram  takes char and int* rawBinaryData1 and int* rawBinaryData1 
 * which is unites to create int* encodedByte
 * @returns void
 */
void generateEncodedByte(int* rawBinaryData1, int* rawBinaryData2, 
     int* encodedByte);




/*
 * Encodes
 *
 * Encodes the input passed to it by stdin
 * uses 2 bytes of input to encode 3 bytes of data
 * 
 * @praram  takes None
 * @returns void
 */
void encode();




/*
 * Main Function
 * Program execution begins here and runs the command and passes
 * arguments in encode.cpp
 * @param takes two command line argumnet
 * @return int
 */
int main(int argc,char *argv[]);



# endif