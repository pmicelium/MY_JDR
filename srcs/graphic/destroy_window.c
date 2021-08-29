#include "jdr.h"


void destroy_window(t_sdl *sdl)
{
    SDL_FreeSurface(sdl->window_surface);
    SDL_DestroyWindow(sdl->window);
}
