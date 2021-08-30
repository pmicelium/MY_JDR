#include "jdr.h"

void    init_jdr(t_jdr *jdr)
{
    jdr->perso = false;
    jdr->sdl = false;
    jdr->ttf = false;
    jdr->tab = TAB_MAP;
}

void    destroy_all(t_jdr *jdr)
{
    if (jdr->sdl == true)
        SDL_Quit();
    if (jdr->ttf == true)
        TTF_Quit();
}