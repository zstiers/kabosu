#pragma once

#ifdef __cplusplus
#   define KABOSU_C_BLOCK_BEGIN extern "C" {
#   define KABOSU_C_BLOCK_END   }
#else
#   define KABOSU_C_BLOCK_BEGIN
#   define KABOSU_C_BLOCK_END
#endif

KABOSU_C_BLOCK_BEGIN

typedef struct { void * platformData; } kabosu_handle;

void kabosu_initialize ();
void kabosu_terminate ();

kabosu_handle kabosu_open (const char * name);
void kabosu_close (kabosu_handle handle);
void * kabosu_sym (kabosu_handle handle, const char * name);

KABOSU_C_BLOCK_END