//  $Id: decode.cpp,v 1.6 2013/02/08 04:27:05 axm3244 Exp axm3244 $

/*  SUMMARY
 *
 *
 *  REVISION HISTORY
 *    $Log: decode.cpp,v $
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


# include "decode.h"
using namespace std;





void generateInt(char byte, int* rawBinaryData)
{
    int val = byte  ;
    for(int i = 0; i < RAW_BIT_SIZE; i++)
    {
       rawBinaryData[7-i] = byte&(1<< i)?1:0;
    }
}






bool checkEmpty(int *word)
{
	bool flag = true;
	for(int i=0; i < 12; i++)
	{
		if (word[i] != 0)
		{
		   flag = false;
		   break;
		}	
	}

	return flag;
}






void joinBits(int* binaryData1,int* binaryData2, 
int* binaryData3, int* encodedword1 , int* encodedword2 )
{
    int totalWord[24];

    for(int i=0; i < RAW_BIT_SIZE; i++)
    {
	totalWord[i] = binaryData1[i];
    }

    for(int i=8; i < 2 * RAW_BIT_SIZE ; i++)
    {
	totalWord[i] = binaryData2[i- RAW_BIT_SIZE];
    }

    for(int i=16; i < FULL_SIZE; i++)
    {
	totalWord[i] = binaryData3[i- 2 * RAW_BIT_SIZE];
    }

    /* Splitting Word into 2 parts of encoding*/
    for(int i=0; i < ENCODED_BIT_SIZE; i++)
    {
	encodedword1[i] = totalWord[i];
    }

    for(int i=12; i < FULL_SIZE; i++)
    {
	encodedword2[i-ENCODED_BIT_SIZE] = totalWord[i];
    }

}








void correctHammingBit(int * hammingbit)
{
    char outbyte;
    int errorposition[4];
    int finalErrorBit;
    int iter;
    int exponent;
    int multiplier;
    int value= 0;

    int orgininalword[8];

    /* checking parity of the Position 1 */
    int position1 = hammingbit[0]+hammingbit[2]+
    hammingbit[4]+hammingbit[6]+hammingbit[8]+hammingbit[10]; 

    int position2 = hammingbit[1]+hammingbit[2]+
    hammingbit[5]+hammingbit[6]+hammingbit[9]+hammingbit[10]; 

    int position3 = hammingbit[3]+hammingbit[4]+
    hammingbit[5]+hammingbit[6]+hammingbit[11];

    int position4 = hammingbit[7]+hammingbit[8]+
    hammingbit[9]+hammingbit[10]+hammingbit[11];



    if (position1 %2 != 0)
	errorposition[0] = 1;
    else
	errorposition[0] = 0;

    if (position2 %2 != 0)
	errorposition[1] = 2;
    else
	errorposition[1] = 0;

    if (position3 %2 != 0)
	errorposition[2] = 4;
    else
	errorposition[2] = 0;

    if (position4 %2 != 0)
	errorposition[3] = 8;
    else
	errorposition[3] = 0;

    finalErrorBit = errorposition[0] + errorposition[1]+
    errorposition[2] +errorposition[3] ;

    /* Correcting the code */
    if (finalErrorBit == 0)
       std::cout<<"";
    else
    {
	if (hammingbit[finalErrorBit-1] ==0)
	   hammingbit[finalErrorBit-1] = 1;
	else
	   hammingbit[finalErrorBit-1] = 0;
    }

    orgininalword[0] = hammingbit[2];
    orgininalword[1] = hammingbit[4];
    orgininalword[2] = hammingbit[5];
    orgininalword[3] = hammingbit[6];
    orgininalword[4] = hammingbit[8];
    orgininalword[5] = hammingbit[9];
    orgininalword[6] = hammingbit[10];
    orgininalword[7] = hammingbit[11];

    for(int j=0; j < RAW_BIT_SIZE; ++j)
    {
	exponent = RAW_BIT_SIZE-j-1;
	multiplier = pow(TWO ,exponent);
	value = value + orgininalword[j]*multiplier;	
    }
       outbyte = value;
       fwrite(&outbyte,1,1,stdout);		    
}







int main(void)
{
    char byte1;
    char byte2;
    char byte3;
    int binaryData1[8];
    int binaryData2[8];
    int binaryData3[8];

    int encodedword1[12];
    int encodedword2[12];
    while(fread(&byte1,1,1,stdin))
    {
	generateInt(byte1,binaryData1);
    
       if(fread(&byte2,1,1,stdin))
       {
	   generateInt(byte2,binaryData2);
       }

       if(fread(&byte3,1,1,stdin))
       {
	   generateInt(byte3,binaryData3);
       }
	
       joinBits(binaryData1, binaryData2, binaryData3,
       encodedword1 , encodedword2);
	

       correctHammingBit(encodedword1);

       correctHammingBit(encodedword2);
    }

    std::cout<<endl;
    return 0;
}



