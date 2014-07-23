/*
	original code : blowfish_original.h
*/

#ifndef BLOWFISH_H
#define BLOWFISH_H

typedef struct 
{
	unsigned long P[16 + 2];
	unsigned long S[4][256];
} BLOWFISH_CTX;


void Blowfish_Init(BLOWFISH_CTX *ctx, unsigned char *key, int keyLen);
void Blowfish_Encrypt(BLOWFISH_CTX *ctx, unsigned char* data, unsigned int lenData, unsigned char** out, unsigned int* lenOut);
void Blowfish_Decrypt(BLOWFISH_CTX *ctx, unsigned char* data, unsigned int lenData, unsigned char** out, unsigned int* lenOut);

#endif