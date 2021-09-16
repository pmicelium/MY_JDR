#include "jdr.h"

void display_player(t_sdl *sdl, t_map *map)
{
    SDL_Rect rect;
    int i = 0;
    SDL_Color my_green = MY_GREEN;
    t_element *player = map->player->premier;
    while (i != map->nb_player)
    {
        // player background
        rect.x = 55 + (165 * i);
        rect.y = 840;
        rect.h = 190;
        rect.w = 110;
        SDL_BlitScaled(map->player_img, NULL, sdl->window_surface, &rect);
        // player pp
        rect.x = 60 + (165 * i);
        rect.y = 845;
        rect.h = 147;
        rect.w = 100;
        SDL_BlitScaled(player->pp, NULL, sdl->window_surface, &rect);
        // player name 
        rect.x = 65 + (165 * i);
        rect.y = 1000;
        rect.h = 30;
        rect.w = 50;
        display_str_blended(sdl, player->str, &rect, my_green, sdl->font.player);
        player = player->suivant;
        i++;
    }
}