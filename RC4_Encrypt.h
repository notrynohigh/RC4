/******************************************************************************
 * File: RC4_Encrypt.h
 * Author: Bean 
 * Email: notrynohigh@outlook.com
 * Every one can use this file free !
 ******************************************************************************/
 
#ifndef __RC4_ENCRYPT_H__
#define __RC4_ENCRYPT_H__

/******************************************************************************
 *  basic data type
 ******************************************************************************/
typedef unsigned char  RC4_U8;
typedef signed char    RC4_S8;
typedef unsigned short RC4_U16;
typedef signed short   RC4_S16;
typedef unsigned int   RC4_U32;
typedef signed int     RC4_S32;

#define RC4_NULL    ((void *)0)
/******************************************************************************
 *  define
 ******************************************************************************/
#define RC4_DEBUG_ENABLE      1

#if RC4_DEBUG_ENABLE
#define RC4_DEBUG(...)    printf(__VA_ARGS__)
#else
#define RC4_DEBUG(...) 
#endif

/******************************************************************************
 *  typedef enum
 ******************************************************************************/
typedef enum
{
	RC4_ERROR,
	RC4_SUCCESS,
	RC4_MEMORY_ERROR,
	RC4_OTHERS
}RC4_ErrorCode_t;

/******************************************************************************
 * public functions
 ******************************************************************************/
RC4_ErrorCode_t RC4_InitSBox(RC4_U8 *key, RC4_U32 keylen);
RC4_ErrorCode_t RC4_EncryptDecrypt(RC4_U8 *text, RC4_U8 *result, RC4_U32 text_len);



#endif
/******************************************************************************
 *  Reserved !
 ******************************************************************************/
































