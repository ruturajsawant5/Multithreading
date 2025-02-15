#ifndef __NOTIF__
#define __NOTIF__

#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "glthread/glthread.h"

#define MAX_KEY_SIZE 64
#define MAX_NFC_NAME 64
#define offset(struct_name, fld_name) \
	(unsigned int)&(((struct_name *)0)->fld_name)

typedef enum {
	NFC_UNKNOWN,
	NFC_ADD,
	NFC_MOD,
	NFC_DEL,
} nfc_op_t;

typedef enum { FALSE, TRUE } bool_t;

typedef void *(*nfc_app_cb)(void *, size_t, nfc_op_t, size_t);

typedef struct notif_chain_ {
	char nfc_name[MAX_NFC_NAME];
	glthread_t notif_chain_head;
} notif_chain_t;

typedef struct notif_chain_element_ {
	char key[MAX_KEY_SIZE];
	size_t key_size;
	size_t subs_id;
	bool_t is_key_set;
	nfc_app_cb app_cb;
	glthread_t glue;
} notif_chain_elem_t;

GLTHREAD_TO_STRUCT(glthread_glue_to_notif_chain_elem, notif_chain_elem_t, glue);

notif_chain_t *nfc_create_new_notif_chain(char *notif_chain_name);

void nfc_register_notif_chain(notif_chain_t *nfc, notif_chain_elem_t *nfce);

void nfc_invoke_notif_chain(notif_chain_t *nfc, void *arg, size_t arg_size,
			    char *key, size_t key_size, nfc_op_t nfc_op_code);

void nfc_delete_all_nfce(notif_chain_t *nfc);

#endif	//__NOTIF__