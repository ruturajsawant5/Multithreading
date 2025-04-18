#ifndef __UTILS__
#define __UTILS__

#include <stdint.h>

typedef enum {

	FALSE,
	TRUE
} bool_t;

#define IS_BIT_SET(n, pos) ((n & (1 << (pos))) != 0)
#define TOGGLE_BIT(n, pos) (n = n ^ (1 << (pos)))
#define COMPLEMENT(num) (num = num ^ 0xFFFFFFFF)
#define UNSET_BIT(n, pos) (n = n & ((1 << pos) ^ 0xFFFFFFFF))
#define SET_BIT(n, pos) (n = n | 1 << pos)

void apply_mask(char *prefix, char mask, char *str_prefix);

void layer2_fill_with_broadcast_mac(char *mac_array);

#define IS_MAC_BROADCAST_ADDR(mac)                             \
	(mac[0] == 0xFF && mac[1] == 0xFF && mac[2] == 0xFF && \
	 mac[3] == 0xFF && mac[4] == 0xFF && mac[5] == 0xFF)

#define TLV_OVERHEAD_SIZE 2

/*Macro to Type Length Value reply
 * unsigned char * - start_ptr, IN
 * unsigned char - type, OUT
 * unsigned char - length, OUT
 * unsigned char * - tlv_ptr, OUT
 * unsigned int - total_size(excluding first 8 bytes), IN
 * */
#define ITERATE_TLV_BEGIN(start_ptr, type, length, tlv_ptr, tlv_size)         \
	{                                                                     \
		unsigned int _len	      = 0;                            \
		unsigned char _tlv_value_size = 0;                            \
		type			      = 0;                            \
		length			      = 0;                            \
		tlv_ptr			      = NULL;                         \
		for(tlv_ptr = (unsigned char *)start_ptr + TLV_OVERHEAD_SIZE; \
		    _len < tlv_size;                                          \
		    _len += _tlv_value_size + TLV_OVERHEAD_SIZE,              \
		tlv_ptr = (tlv_ptr + TLV_OVERHEAD_SIZE + length)) {           \
			type = *(tlv_ptr - TLV_OVERHEAD_SIZE);                \
			_tlv_value_size =                                     \
			    (unsigned char)(*(tlv_ptr - TLV_OVERHEAD_SIZE +   \
					      sizeof(unsigned char)));        \
			length = _tlv_value_size;

#define ITERATE_TLV_END(start_ptr, type, length, tlv_ptr, tlv_size) \
	}                                                           \
	}

char *tlv_buffer_get_particular_tlv(
    char *tlv_buff,	    /*Input TLV Buffer*/
    uint32_t tlv_buff_size, /*Input TLV Buffer Total Size*/
    uint8_t tlv_no,	    /*Input TLV Number*/
    uint8_t *tlv_data_len); /*Output TLV Data len*/

char *tlv_buffer_insert_tlv(char *tlv_buff, uint8_t tlv_no, uint8_t data_len,
			    char *data);

char *tcp_ip_covert_ip_n_to_p(uint32_t ip_addr, char *output_buffer);

uint32_t tcp_ip_covert_ip_p_to_n(char *ip_addr);

uint32_t get_new_ifindex();
#endif /* __UTILS__ */