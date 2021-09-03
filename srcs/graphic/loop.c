#include "jdr.h"

int loop(t_sdl *sdl, t_jdr *jdr, t_perso *perso, t_my_net *net)
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
    int y_tab = 9;
    //          MAP
    SDL_Surface *tab_MAP = TTF_RenderText_Solid(sdl->font.tab, "CARTE", MyGreen);
    SDL_Rect MAP_rect;
    MAP_rect.x = 110;
    MAP_rect.y = y_tab;
    MAP_rect.w = 300;
    MAP_rect.h = 30;
    //          INVENTAIRE
    SDL_Surface *tab_INV = TTF_RenderText_Solid(sdl->font.tab, "INVENTAIRE", MyGreen);
    SDL_Rect INV_rect;
    INV_rect.x = 400;
    INV_rect.y = y_tab;
    INV_rect.w = 300;
    INV_rect.h = 30;
    //          PERSO
    SDL_Surface *tab_PERSO = TTF_RenderText_Solid(sdl->font.tab, "PERSO", MyGreen);
    SDL_Rect PERSO_rect;
    PERSO_rect.x = 735;
    PERSO_rect.y = y_tab;
    PERSO_rect.w = 300;
    PERSO_rect.h = 30;
    //          NAME DISPLAY
    SDL_Surface *tab_NAME = TTF_RenderText_Solid(sdl->font.tab, "JDR des French Retards", MyGreen);
    SDL_Rect NAME_rect;
    NAME_rect.x = 1200;
    NAME_rect.y = y_tab;
    NAME_rect.w = 300;
    NAME_rect.h = 30;

    bool keepWindow = true;
    Uint32 mouse;
    Uint8 const *keys;
    int x;
    int y;
    // int numready;

    while (keepWindow)
    {
        while (SDL_PollEvent(&sdl->event) > 0)
        {
            switch (sdl->event.type)
            {
            // if prog end;
            case SDL_QUIT:
            {
                keepWindow = false;
                destroy_window(sdl);
                destroy_all(jdr);
            }
            break;

            //
            // MOUSE EVENT
            //
            case SDL_MOUSEBUTTONDOWN:
            {
                mouse = SDL_GetMouseState(&x, &y);
                // LEFT BUTTON
                if ((mouse & SDL_BUTTON_LMASK) != 0)
                {
                    my_mouse_event(jdr, perso, x, y);
                }
                break;
            }
            //
            // KEY EVENT
            //
            case SDL_KEYDOWN:
            {
                keys = SDL_GetKeyboardState(NULL);
                // quit prog;
                if (keys[SDL_SCANCODE_ESCAPE] == 1)
                {
                    keepWindow = false;
                    destroy_window(sdl);
                    destroy_all(jdr);
                }
                // MAP
                if (keys[SDL_SCANCODE_F1] == 1)
                    jdr->tab = TAB_MAP;

                // inventaire
                else if (keys[SDL_SCANCODE_F2] == 1)
                    jdr->tab = TAB_INV;

                // Perso
                else if (keys[SDL_SCANCODE_F3] == 1)
                {
                    if (jdr->tab != TAB_PERSO)
                        perso->levelup = LEVELUP;
                    jdr->tab = TAB_PERSO;
                }
                else if (keys[SDL_SCANCODE_LSHIFT] == 1 || keys[SDL_SCANCODE_RSHIFT] == 1)
                    get_str_from_keybord(net, sdl->event, true, sdl);

                // Chat
                else
                    get_str_from_keybord(net, sdl->event, false, sdl);
            }
            break;
            }
        }

        if (keepWindow == true)
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
            if (jdr->tab == TAB_PERSO)
                display_perso(sdl, perso); //need to center name
            // else if (jdr->tab == TAB_INV)
            //     display_inv(sdl);
            // else
            //     display_map(sdl);

            // display chat
            display_message(net->message, sdl);
        }
        //
        // CLIENT LOOP
        //
        // numready = SDLNet_CheckSockets(net->set, 100);
        // if (numready == -1)
        // {
        //     printf("SDLNet_CheckSockets: %s\n", SDLNet_GetError());
        //     break;
        // }

        // /* check to see if the server sent us data */
        // if (numready && SDLNet_SocketReady(net->sock))
        // {
        //     /* getMsg is in tcputil.h, it gets a string from the socket */
        //     /* with a bunch of error handling */
        //     if (!getMsg(net->sock, &net->str))
        //         break;
        //     /* post it to the screen */
        //     printf("%s\n", net->str);
        // }

        // update window
        SDL_UpdateWindowSurface(sdl->window);
    }
    return 1;
}