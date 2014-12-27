//  $Id: encode.cpp,v 1.5 2013/02/08 04:27:05 axm3244 Exp axm3244 $

/*  SUMMARY
 *
 *
 *  REVISION HISTORY
 *    $Log: encode.cpp,v $
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


# include "encode.h"

using namespace std;


void generateEncodedByte(int* rawBinaryData1, 
int* rawBinaryData2, int* encodedByte)
{
   int parityCheck;

   encodedByte[2] =  rawBinaryData1[0];
   encodedByte[4] =  rawBinaryData1[1];
   encodedByte[5] =  rawBinaryData1[2];
   encodedByte[6] =  rawBinaryData1[3];
   encodedByte[8] =  rawBinaryData1[4];
   encodedByte[9] =  rawBinaryData1[5];
   encodedByte[10] = rawBinaryData1[6];
   encodedByte[11] = rawBinaryData1[7];
	
   encodedByte[14] =  rawBinaryData2[0];
   encodedByte[16] =  rawBinaryData2[1];
   encodedByte[17] =  rawBinaryData2[2];
   encodedByte[18] =  rawBinaryData2[3];
   encodedByte[20] =  rawBinaryData2[4];
   encodedByte[21] =  rawBinaryData2[5];
   encodedByte[22] = rawBinaryData2[6];
   encodedByte[23] = rawBinaryData2[7];
	

	
   parityCheck = encodedByte[2] + encodedByte[4] + 
   encodedByte[6] + encodedByte[8] + encodedByte[10];
   encodedByte[0] = parityCheck % 2;

   parityCheck = encodedByte[2] + encodedByte[5] + 
   encodedByte[6] + encodedByte[9] + encodedByte[10];
   encodedByte[1] = parityCheck % 2;
        
   parityCheck = encodedByte[4] + encodedByte[5] + 
   encodedByte[6] + encodedByte[11];
   encodedByte[3] = parityCheck% 2; 
        
   parityCheck = encodedByte[8] + encodedByte[9] + 
   encodedByte[10] + encodedByte[11];
   encodedByte[7] = parityCheck % 2;


   parityCheck = encodedByte[14] + encodedByte[16] + 
   encodedByte[18] + encodedByte[20] + encodedByte[22];
   encodedByte[12] = parityCheck % 2;

   parityCheck = encodedByte[14] + encodedByte[17] +
   encodedByte[18] + encodedByte[21] + encodedByte[22];
   encodedByte[13] = parityCheck % 2;
        
   parityCheck = encodedByte[16] + encodedByte[17] + 
   encodedByte[18] + encodedByte[23];
   encodedByte[15] = parityCheck % 2; 
        
   parityCheck = encodedByte[20] + encodedByte[21] + 
   encodedByte[22] + encodedByte[23];
   encodedByte[19] = parityCheck % 2;

}





void generateBinary(char byte, int* rawBinaryData)
{
   for(int i = 0; i < RAW_BIT_SIZE; i++)
   {
       rawBinaryData[7-i] = byte&(1 << i)? 1 : 0;
   }
}





void encode()
{
   char output[3];

   char byte;
   char outbyte;
   int encodedByte[ENCODED_BIT_SIZE];
   int rawBinaryData1[RAW_BIT_SIZE];
   int rawBinaryData2[RAW_BIT_SIZE];

   int binaryData[RAW_BIT_SIZE];
   int val;
   char sendByte[2];
   int iter;
   int exponent;
   int multiplier;
   int value= 0;


   while(fread(&byte,1,1,stdin))
   {
    	if(byte == '\n' )
           break;

    	generateBinary(byte,rawBinaryData1);

    	/* Reading second Byte */
    	if(fread(&byte,1,1,stdin))
    	{
	    generateBinary(byte,rawBinaryData2);

    	}

    	/* Adding 0 bit to additional byte in case of odd bytes */
    	else
    	{
	    for(int i =0 ; i<RAW_BIT_SIZE; i++)
	    rawBinaryData2[i]= 0 ;
       }

       generateEncodedByte(rawBinaryData1, rawBinaryData2, encodedByte);

       for(int i=0; i < 3; ++i)
       {
	   iter = i*8;
	   value= 0;

	   for(int j=0; j < RAW_BIT_SIZE; ++j)
	   {
	       exponent = RAW_BIT_SIZE-j-1;
	       multiplier = pow(2.00,exponent);
	       value = value + encodedByte[j+iter]*multiplier;	
	   }

	   outbyte = value;
	   fwrite(&outbyte,1,1,stdout);
       }
   }
}





int main(int argc,char *argv[]){

    encode();
    return 0;
}
