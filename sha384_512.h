/*  SHA384��SHA512�ǹ���һ�׺���Դ��ʵ��
    ֻ����������������һ��is_384�ı�����
    ��ʶ��ִ��SHA384���㻹��SHA512����     */
#ifndef __SHA384_512_H__
#define __SHA384_512_H__

#include <stdint.h>

#define SHA384_DIGEST_LEN 48         	// SHA384 outputs a 48 byte digest
#define SHA512_DIGEST_LEN 64         	// SHA512 outputs a 64 byte digest

typedef struct _sha384_512_ctx_t {
    uint64_t 	total[2];          		/*!< number of bytes processed  */
    uint64_t 	state[8];          		/*!< intermediate digest state  */
    uint8_t 	buffer[128];  			/*!< data block being processed */
    int32_t		is_384;             	/*!< 0 => SHA-512, else SHA-384 */
} sha384_512_ctx_t;

void sha384(const uint8_t* message, uint32_t len, uint8_t* digest);
void sha512(const uint8_t* message, uint32_t len, uint8_t* digest);
#endif   // __SHA384_512_H__
