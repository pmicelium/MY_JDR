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

    // TAB
    SDL_Color MyGreen = MY_GREEN;
    int y_tab = 9;
    // map
    SDL_Surface *tab_MAP = TTF_RenderText_Blended(sdl->font.tab, "CARTE", MyGreen);
    SDL_Rect MAP_rect;
    MAP_rect.x = 110;
    MAP_rect.y = y_tab;
    MAP_rect.w = 300;
    MAP_rect.h = 30;
    // inv
    SDL_Surface *tab_INV = TTF_RenderText_Blended(sdl->font.tab, "INVENTAIRE", MyGreen);
    SDL_Rect INV_rect;
    INV_rect.x = 400;
    INV_rect.y = y_tab;
    INV_rect.w = 300;
    INV_rect.h = 30;
    // perso
    SDL_Surface *tab_PERSO = TTF_RenderText_Blended(sdl->font.tab, "PERSO", MyGreen);
    SDL_Rect PERSO_rect;
    PERSO_rect.x = 735;
    PERSO_rect.y = y_tab;
    PERSO_rect.w = 300;
    PERSO_rect.h = 30;
    // name
    SDL_Surface *tab_NAME = TTF_RenderText_Blended(sdl->font.tab, "JDR des French Retards", MyGreen);
    SDL_Rect NAME_rect;
    NAME_rect.x = 1200;
    NAME_rect.y = y_tab;
    NAME_rect.w = 300;
    NAME_rect.h = 30;

    // MESSAGE AND LOG
    get_str_from_keybord(net, sdl->event, sdl, perso, false, 0);
    net->log_fd = init_log(net);
    net->log_whell = -100;
    jdr->log = true;
    sdl->hst = list_init();
    SDL_StartTextInput();
    // CLIENT
    SDLNet_SocketSet set;
    int numready;
    char *str = NULL;

    set = SDLNet_AllocSocketSet(1);
    if (!set)
    {
        printf("SDLNet_AllocSocketSet: %s\n", SDLNet_GetError());
        SDLNet_Quit();
        SDL_Quit();
        return -1;
    }

    if (SDLNet_TCP_AddSocket(set, net->sock) == -1)
    {
        printf("SDLNet_TCP_AddSocket: %s\n", SDLNet_GetError());
        SDLNet_Quit();
        SDL_Quit();
        return -1;
    }

    // LOOP
    bool keepWindow = true;
    Uint32 mouse;
    Uint8 const *keys;
    int x;
    int y;

    /* TO DO

    // essential

    - map
    - inventory
    - Little leaks in perso (not much but maybe strong if running 3h), can't see it thought, maybe sdl
    - support long ass perso_name
    - Add chimie to skill or just to power ??
    - support lunch without serv lunch 
    - escape = option. 
    - optional : add shell prog, lunchable directly in the prog 
    - check path before start 
    - /GM et /GMRoll not supported

    // optional 

    - Change Perso skill font 
    - better handling of /quit (maybe quit prog )
    - cursor in message with left and right arrow (ttf status je crois)
    - get time and date for LOG (1 / months or 1 / sessions ?? )
    - remove limit in roll => make the output plusieurs messages ==> finsh print_log
    - auto-completion
    - command pm & pv (not sure yet), if not remove form help
    - add color and shit like that in log if possible 
    - make text look nice in display_perso with ttf rt blended
    - add custom command on the bottom of the screen (visible in map ?)

    // to make prog clean 

    - check for doublon or not essential var in struct
    - make debug mode with printf of all fonction.
    - check if prog protected if log > 40.000 of message > 10.240
    - check error handling, and if prog quit proprelly
    - check all comment, maybe some idea to implement.

    */
    while (keepWindow)
    {
        while (SDL_PollEvent(&sdl->event) > 0)
        {
            switch (sdl->event.type)
            {
            // if prog end;
            case SDL_QUIT:
            {
                SDL_StopTextInput();
                keepWindow = false;
                destroy_window(sdl);
                destroy_all(jdr, net, sdl);
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
                    my_mouse_event(jdr, perso, x, y);
                break;
            }
            case SDL_MOUSEWHEEL:
            {
                // scroll up
                mouse = SDL_GetMouseState(&x, &y);
                if (sdl->event.wheel.y > 0)
                {
                    if (x > 1625 && y > 30 && y < 985)
                    {
                        if (net->log_whell > WHEEL_SPEED)
                            net->log_whell = net->log_whell - WHEEL_SPEED;
                    }
                }
                // scroll down
                else if (sdl->event.wheel.y < 0)
                {
                    if (x > 1625 && y > 30 && y < 985)
                    {
                        if (net->log_whell != net->max_log)
                            net->log_whell = net->log_whell + WHEEL_SPEED;
                    }
                }
                break;
            }
            //
            // KEY EVENT
            //
            case SDL_KEYDOWN:
            {
                keys = SDL_GetKeyboardState(NULL);
                // quit
                if (keys[SDL_SCANCODE_ESCAPE] == 1)
                {
                    keepWindow = false;
                    destroy_window(sdl);
                    destroy_all(jdr, net, sdl);
                }
                // Map
                if (keys[SDL_SCANCODE_F1] == 1)
                    jdr->tab = TAB_MAP;

                // Inv
                else if (keys[SDL_SCANCODE_F2] == 1)
                    jdr->tab = TAB_INV;

                // Perso
                else if (keys[SDL_SCANCODE_F3] == 1)
                {
                    if (jdr->tab != TAB_PERSO)
                        perso->levelup = LEVELUP;
                    jdr->tab = TAB_PERSO;
                }
                // Chat
                get_str_from_keybord(net, sdl->event, sdl, perso, false, 0);
            }
            break;
            case SDL_TEXTINPUT:
            {
                get_str_from_keybord(net, sdl->event, sdl, perso, true, sdl->event.text.text[0]);
                break;
            }
            }
        }
        //
        // CLIENT LOOP
        //
        numready = SDLNet_CheckSockets(set, 0);
        if (numready == -1)
        {
            printf("SDLNet_CheckSockets: %s\n", SDLNet_GetError());
            break;
        }

        /* check to see if the server sent us data */
        if (numready && SDLNet_SocketReady(net->sock))
        {
            if (!getMsg(net->sock, &str))
            {
                char *errstr = SDLNet_GetError();
                printf("getMsg: %s\n", strlen(errstr) ? errstr : "Server disconnected");
                break;
            }
            /* post it to the screen */
            // need to check for /join et / quit 
            strcat(net->log, str);
            strcat(net->log, "\n");
            fprintf(net->log_fd, "%s\n", str);
            printf("%s\n", str);
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
                display_perso(sdl, perso);
            // else if (jdr->tab == TAB_INV)
            //     display_inv(sdl);
            // else
            //     display_map(sdl);

            // display message and log
            display_message(sdl, net);
            display_log(sdl, net);
        }

        // update window
        SDL_UpdateWindowSurface(sdl->window);
    }
    return 1;
}