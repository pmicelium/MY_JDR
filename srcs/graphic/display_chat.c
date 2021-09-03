#include "jdr.h"

void display_message(char *message, t_sdl *sdl)
{
    SDL_Color color = MY_GREEN;
    SDL_Rect rect;

    rect.x = 1640;
    rect.y = 1005;
    
    SDL_Surface *str_to_display = TTF_RenderText_Solid(sdl->font.message, message, color);
    SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    SDL_FreeSurface(str_to_display);
}