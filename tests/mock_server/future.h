#ifndef FUTURE_H
#define FUTURE_H

#include <bson.h>

#include "future-value.h"
#include "mongoc-thread-private.h"

/**************************************************
 *
 * Generated by build/generate-future-functions.py.
 *
 * DO NOT EDIT THIS FILE.
 *
 *************************************************/

typedef struct
{
   bool             resolved;
   future_value_t   return_value;
   int              argc;
   future_value_t  *argv;
   mongoc_cond_t    cond;
   mongoc_mutex_t   mutex;
   mongoc_thread_t  thread;
} future_t;

future_t *future_new (future_value_type_t return_type, int argc);

future_value_t *future_get_param (future_t *future, int i);

void future_start (future_t *future,
                   void *(*start_routine)(void *));

void future_resolve (future_t *future, future_value_t return_value);

bool future_wait (future_t *future);

void future_get_void (future_t *future);


bool
future_get_bool (future_t *future);

char_ptr
future_get_char_ptr (future_t *future);

char_ptr_ptr
future_get_char_ptr_ptr (future_t *future);

int64_t
future_get_int64_t (future_t *future);

uint32_t
future_get_uint32_t (future_t *future);

const_char_ptr
future_get_const_char_ptr (future_t *future);

bson_error_ptr
future_get_bson_error_ptr (future_t *future);

bson_ptr
future_get_bson_ptr (future_t *future);

const_bson_ptr
future_get_const_bson_ptr (future_t *future);

const_bson_ptr_ptr
future_get_const_bson_ptr_ptr (future_t *future);

mongoc_bulk_operation_ptr
future_get_mongoc_bulk_operation_ptr (future_t *future);

mongoc_client_ptr
future_get_mongoc_client_ptr (future_t *future);

mongoc_collection_ptr
future_get_mongoc_collection_ptr (future_t *future);

mongoc_cursor_ptr
future_get_mongoc_cursor_ptr (future_t *future);

mongoc_database_ptr
future_get_mongoc_database_ptr (future_t *future);

mongoc_insert_flags_t
future_get_mongoc_insert_flags_t (future_t *future);

mongoc_query_flags_t
future_get_mongoc_query_flags_t (future_t *future);

mongoc_server_description_ptr
future_get_mongoc_server_description_ptr (future_t *future);

mongoc_ss_optype_t
future_get_mongoc_ss_optype_t (future_t *future);

mongoc_topology_ptr
future_get_mongoc_topology_ptr (future_t *future);

const_mongoc_read_prefs_ptr
future_get_const_mongoc_read_prefs_ptr (future_t *future);

const_mongoc_write_concern_ptr
future_get_const_mongoc_write_concern_ptr (future_t *future);


void future_destroy (future_t *future);

#endif /* FUTURE_H */