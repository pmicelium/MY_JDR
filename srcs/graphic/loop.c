#include "jdr.h"

int         loop(t_sdl *sdl, t_jdr *jdr, t_perso *perso)
{
    // load background
    // MAP
    t_sdl_image map_background;
    map_background.position.x = 0;
    map_background.position.y = 0;
    if (!(map_background.image = SDL_LoadBMP(MAP_BACKGROUND_PATH)))
    {
        ft_putendl("load map background fail");
        return -1;           
    }
    // PERSO
    t_sdl_image perso_background;
    perso_background.position.x = 0;
    perso_background.position.y = 0;
    if (!(perso_background.image = SDL_LoadBMP(PERSO_BACKGROUND_PATH)))
    {
        ft_putendl("load perso background fail");
        return -1;           
    }

    // load tab_name
    SDL_Color MyGreen = MY_GREEN;
    int         y_tab = 9;
    //          MAP
    SDL_Surface     *tab_MAP = TTF_RenderText_Solid(sdl->font.tab, "CARTE", MyGreen);
    SDL_Rect        MAP_rect;
    MAP_rect.x = 110;
    MAP_rect.y = y_tab;
    MAP_rect.w = 300;
    MAP_rect.h = 30;
    //          INVENTAIRE
    SDL_Surface     *tab_INV = TTF_RenderText_Solid(sdl->font.tab, "INVENTAIRE", MyGreen);
    SDL_Rect        INV_rect;
    INV_rect.x = 400;
    INV_rect.y = y_tab;
    INV_rect.w = 300;
    INV_rect.h = 30;
    //          PERSO
    SDL_Surface     *tab_PERSO = TTF_RenderText_Solid(sdl->font.tab, "PERSO", MyGreen);
    SDL_Rect        PERSO_rect;
    PERSO_rect.x = 735;
    PERSO_rect.y = y_tab;
    PERSO_rect.w = 300;
    PERSO_rect.h = 30;
    //          NAME DISPLAY
    SDL_Surface     *tab_NAME = TTF_RenderText_Solid(sdl->font.tab, "JDR des French Retards", MyGreen);
    SDL_Rect        NAME_rect;
    NAME_rect.x = 1200;
    NAME_rect.y = y_tab;
    NAME_rect.w = 300;
    NAME_rect.h = 30;


    bool keepWindow = true;
    bool need2draw = true;
    Uint8 const *keys = SDL_GetKeyboardState(NULL);

    while (keepWindow)
    {
        while (SDL_PollEvent(&sdl->event) > 0)
        {
            switch(sdl->event.type)                  //check le type d'event.
            {
                case SDL_QUIT:                      // croix rouge 
                {
                    keepWindow = false;
                    destroy_window(sdl);
                    destroy_all(jdr);
                }
                break;
                case SDL_KEYDOWN:
                {
                    if(keys[SDL_SCANCODE_ESCAPE]== 1) //keeped for testing;
                    {
                        keepWindow = false;
                        destroy_window(sdl);
                        destroy_all(jdr);
                    }
                    if(keys[SDL_SCANCODE_I] == 1)
                    {
                        if (jdr->tab != TAB_INV)
                            need2draw = true;
                        jdr->tab = TAB_INV;
                    }
                    // insert inventaire
                    if (keys[SDL_SCANCODE_P] == 1)
                    {
                        if (jdr->tab != TAB_PERSO)
                            need2draw = true;
                        jdr->tab = TAB_PERSO;
                        
                    }
                    // insert Perso
                    if (keys[SDL_SCANCODE_M] == 1)
                    {
                        if (jdr->tab != TAB_MAP)
                            need2draw = true;
                        jdr->tab = TAB_MAP;
                    }
                    // insert competence   
                }
                break;
            }
        }
        if (keepWindow == true)
        {
            if(need2draw == true)
            {
                // clear window
                SDL_FillRect(sdl->window_surface, NULL, SDL_MapRGB(sdl->window_surface->format, 0, 0, 0));
                // put background
                if (jdr->tab == TAB_MAP)
                    SDL_BlitSurface(map_background.image, NULL, sdl->window_surface, &map_background.position);
                else if (jdr->tab == TAB_PERSO)
                    SDL_BlitSurface(perso_background.image, NULL, sdl->window_surface, &perso_background.position);
                else 
                    SDL_BlitSurface(map_background.image, NULL, sdl->window_surface, &map_background.position);
                // put tabs names
                SDL_BlitSurface(tab_MAP, NULL, sdl->window_surface, &MAP_rect);
                SDL_BlitSurface(tab_INV, NULL, sdl->window_surface, &INV_rect);
                SDL_BlitSurface(tab_PERSO, NULL, sdl->window_surface, &PERSO_rect);
                SDL_BlitSurface(tab_NAME, NULL, sdl->window_surface, &NAME_rect);

                // display tabs
                if(jdr->tab == TAB_PERSO)
                    display_perso(sdl, perso);
                // else if (jdr->tab == TAB_INV)
                //     display_inv(sdl);
                // else
                //     display_map(sdl);

            }
            // update window
            need2draw = false;
            SDL_UpdateWindowSurface(sdl->window);
        }
    }
    return 1;
}