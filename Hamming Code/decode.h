/*  SUMMARY
 *
 *
 *  REVISION HISTORY
 *    $Log: decode.h,v $
 *    Revision 1.6  2013/02/08 04:27:05  axm3244
 *    Removed Unecessary Commenting
 *    and Print Statements
 *
 *    Revision 1.5  2013/02/08 03:40:20  axm3244
 *    Final Testing and
 *    Functionality Refinement
 *
 *    Revision 1.4  2013/02/07 18:49:52  axm3244
 *    Added Empty Check Function
 *
 *    Revision 1.3  2013/02/07 18:13:02  axm3244
 *    Adding Padding for unencoded bytes
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

# ifndef DECODE_H
# define DECODE_H

# include<cstdlib>
# include<iostream>
# include<stdlib.h>
# include<math.h>
# include<cstdio>


/* Const member variables */
const int ENCODED_BIT_SIZE = 12;
const int FULL_SIZE = 24;
const int RAW_BIT_SIZE = 8;
const double TWO = 2.00;


/*
 * Decodes
 *
 * Decodes the input passed to it by stdin
 * it calls correctHammingBit to correct the hamming bit
 * 
 *
 * @praram  takes const char * word
 * as argument
 * @returns void
 */


/*
 * Join Bit
 *
 * Joins the 3 input bytes and creates 2 bytes of hamming 
 * encoded data to be passed for decoding and error correction
 *
 *
 * @praram  takes int* binaryData1,int* binaryData2, int* binaryData3,
 *  which is unites to create int* encodedword1 , int* encodedword2 as argument
 * @returns void
 */
void joinBits(int* binaryData1,int* binaryData2, int* binaryData3, int* encodedword1 , int* encodedword2 );


/*
 * Check if unencoded byte is Empty
 *
 * Checks if the word sent is empty string or not
 *
 * @praram  takes int* word
 * @returns boolean
 */
bool checkEmpty(int *word);



/*
 * Correct Hamming Bit
 *
 * Finds and corrects hamming bit in encoded block of data
 * If no error is found then decodes and generates the original
 * sent data
 *
 *
 * @praram  takes int* word
 *  which is unites to create int* encodedword1 , int* encodedword2 as argument
 * @returns void
 */
void correctHammingBit(int * word);


/*
 * Generates Integer Array of Binary Bit
 *
 * Converts character input to Binary bit of integer array
 * If no error is found then decodes and generates the original
 * sent data
 *
 *
 * @praram  takes char and int* word
 *  which is unites to create int* encodedword1 , int* encodedword2 as argument
 * @returns void
 */
void generateInt(char byte, int* rawBinaryData);



/*
 * Main Function
 * Program execution begins here and runs the command and passes
 * arguments in Decode.cpp
 * @param takes two command line argumnet
 * @return int
 */
int main(void);



# endif
