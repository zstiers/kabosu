#include "kabosu/kabosu.h"

#include <wchar.h>
#include <Windows.h>

KABOSU_C_BLOCK_BEGIN

void kabosu_initialize () {
    // Windows doesn't need this
}

void kabosu_terminate () {
    // Windows doesn't need this
}

kabosu_handle kabosu_open (const char * name) {
    kabosu_handle ret = { 0 };
    wchar_t ws[128];

    swprintf(ws, 128, L"%hs", name);
    ws[127] = L'\0';
    ret.platformData = LoadLibraryExW(ws, NULL, 0);

    ret.platformData = GetModuleHandleW(ws);

    return ret;
}

void kabosu_close (kabosu_handle handle) {
    FreeLibrary(handle.platformData);
}

void * kabosu_sym (kabosu_handle handle, const char * name) {
    return GetProcAddress(handle.platformData, name);
}

KABOSU_C_BLOCK_END