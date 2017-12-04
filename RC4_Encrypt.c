/******************************************************************************
 * File: RC4_Encrypt.c
 * Author: Bean 
 * Email: notrynohigh@outlook.com
 * Every one can use this file free !
 ******************************************************************************/
 /** Include -----------------------------------------------------------------*/
#include "stdio.h"
#include "RC4_Encrypt.h"

/** global variable ----------------------------------------------------------*/
static RC4_U8 gSBox[256];

/** static functions ---------------------------------------------------------*/
static void RC4_SwapByte(RC4_U8 *byte1, RC4_U8 *byte2)
{
	RC4_U8 temp;
	temp = byte2;
	byte2 = byte1;
	byte1 = temp;
}

RC4_ErrorCode_t RC4_InitSBox(RC4_U8 *key, RC4_U32 keylen)
{
	RC4_U16 i = 0;
	RC4_U8  j = 0;
	if(gSBox == RC4_NULL || key == RC4_NULL || keylen == 0)
	{
		return RC4_ERROR;
	}
	for(i = 0;i < 256;i++)
	{
		gSBox[i] = (RC4_U8)i;
	}

	for(i = 0;i < 256;i++)
	{
		j += gSBox[i] + key[i % keylen];
		RC4_SwapByte(&gSBox[i], &gSBox[j]);
	}
	return RC4_SUCCESS;
}


RC4_ErrorCode_t RC4_EncryptDecrypt(RC4_U8 *text, RC4_U8 *result, RC4_U32 text_len)
{
	RC4_U32 i = 0;
	RC4_U8  j = 0, k = 0, t = 0;
	if(gSBox == RC4_NULL || text == RC4_NULL || result == RC4_NULL || text_len == 0)
	{
		return RC4_ERROR;
	}
	for(i = 0;i < text_len;i++)
	{
		j++;
		k = gSBox[j];
		RC4_SwapByte(&gSBox[j], &gSBox[k]);

		t = gSBox[j] + gSBox[k];
		result[i] = gSBox[t] ^ text[i];
	}
	return RC4_SUCCESS;
}

/******************************************************************************
* end !
******************************************************************************/




