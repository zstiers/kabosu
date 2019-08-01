#include "kabosu/kabosu.h"

int main () {
    kabosu_handle handle = kabosu_open("SDL2");
    void * symbol = kabosu_sym(handle, "SDL_Init");
    kabosu_close(handle);
    return 0;
}