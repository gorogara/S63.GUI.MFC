#pragma once

#ifdef _DEBUG
#pragma comment(lib, "..\\Debug\\CRC32.lib")
#pragma comment(lib, "..\\Debug\\Blowfish.lib")
#else
#pragma comment(lib, "..\\Release\\CRC32.lib")
#pragma comment(lib, "..\\Release\\Blowfish.lib")
#endif 

#define LENGTH_HW_ID 5
#define LENGTH_M_KEY 5
#define LENGTH_M_ID  2

char* CreateUserPermit(char* HW_ID, char* M_KEY, char* M_ID);