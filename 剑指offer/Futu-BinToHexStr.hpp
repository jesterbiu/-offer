#pragma once
#include <iostream>
int BinToHexStr(const unsigned char* pData, int nDataLen, char* pBuf, int nBufLen)
{
	static const char gs_HexStr[] = { "0123456789ABCDEF" };

	//未转换的长度
	int nToConvLen = nDataLen;

	//转换
	while (nToConvLen > 0)
	{
		*pBuf++ = gs_HexStr[*pData >> 4];
		*pBuf++ = gs_HexStr[*pData & 0b00001111];
		pData++;
		nToConvLen--;
	}

	//...


	return (nDataLen * 2);
}

void test_BinTo_HexStr()
{
	char str_test[] = "futo";
	char str_dest[128] = { 0 };
	int sz = BinToHexStr((unsigned char*)str_test, strlen(str_test), str_dest, 128);
	for (int i = 0; i < sz; i++)
	{
		std::cout << str_dest[i++];
		std::cout << str_dest[i] << " ";
	}
	std::cout << str_dest;
}