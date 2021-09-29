#include "jdr.h"

void display_map(t_sdl *sdl, t_map *map)
{
    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.h = 750;
    rect.w = 750;
    SDL_BlitScaled(map->map_grid, NULL, sdl->window_surface, &rect);
    rect.x = 33;
    rect.y = 200;
    rect.h = 13;
    rect.w = 22;
    SDL_BlitScaled(map->token, NULL, sdl->window_surface, &rect);
}