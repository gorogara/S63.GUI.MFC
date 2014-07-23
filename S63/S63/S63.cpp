#include "S63.h"
#include "../Blowfish/Blowfish.h"
#include "../CRC32/CRC32.h"
#include <iostream>

char* CreateUserPermit(char* HW_ID, char* M_KEY, char* M_ID)
{
	// Blowfish √ ±‚»≠
	BLOWFISH_CTX ctx;
	Blowfish_Init(&ctx, (unsigned char*)M_KEY, 5);

	unsigned int len_HW_ID = 5;
	unsigned int len_EncryptedHW_ID = 0;

	// Encrypt HW_ID
	char* EncryptedHWID = nullptr;
	Blowfish_Encrypt(&ctx, (unsigned char*)HW_ID, len_HW_ID, (unsigned char**)&EncryptedHWID, &len_EncryptedHW_ID);

	// Encrypted HW_ID to Hex
	char* EncHWID_Hex = new char[16 + 1];
	memset(EncHWID_Hex, 0, 16 + 1);
	sprintf(EncHWID_Hex, "%02X%02X%02X%02X%02X%02X%02X%02X", (unsigned char)EncryptedHWID[0],
												             (unsigned char)EncryptedHWID[1],
												             (unsigned char)EncryptedHWID[2],
												             (unsigned char)EncryptedHWID[3],
												             (unsigned char)EncryptedHWID[4],
												             (unsigned char)EncryptedHWID[5],
												             (unsigned char)EncryptedHWID[6],
												             (unsigned char)EncryptedHWID[7]);

	// Get CRC
	unsigned int uiCRC = crc32(0, EncHWID_Hex, 16);
	char* CRC = new char[8 + 1];
	memset(CRC, 0, 8 + 1);
	sprintf(CRC, "%08X", uiCRC);

	// Set Userpermit	
	char* userpermit = new char[28 + 1];
	memset(userpermit, 0, 28 + 1);
	strcpy(userpermit, EncHWID_Hex);
	strcpy(userpermit + 16, CRC);
	strcpy(userpermit + 16 + 8, M_ID);

	delete[] EncryptedHWID;
	delete[] EncHWID_Hex;	
	delete[] CRC;

	return userpermit;
}