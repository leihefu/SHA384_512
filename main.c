#include "sha384_512.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char string[62] = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

int main(void)
{
	char clear_text[32];
	uint8_t sha384_digest[SHA384_DIGEST_LEN] = { 0 };
	uint8_t sha512_digest[SHA512_DIGEST_LEN] = { 0 };

	srand((uint16_t)time(NULL));

	printf("clear_text:\r\n");
	for (uint8_t i = 0; i < sizeof(clear_text); i++)
	{
		clear_text[i] = string[rand() % 62];
		printf("%C", clear_text[i]);
	}
	printf("\r\n");


	sha384(clear_text, sizeof(clear_text), sha384_digest);
	for (uint8_t i = 0; i < SHA384_DIGEST_LEN; i++)
	{
		printf("%02X ", sha384_digest[i]);
		if (i % 16 >= 15)
		{
			printf("\r\n");
		}
	}

	sha512(clear_text, sizeof(clear_text), sha512_digest);
	printf("sha512_digest:\r\n");
	for (uint8_t i = 0; i < SHA512_DIGEST_LEN; i++)
	{
		printf("%02X ", sha512_digest[i]);
		if (i % 16 >= 15)
		{
			printf("\r\n");
		}
	}
	return 0;
}