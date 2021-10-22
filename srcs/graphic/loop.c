#include "jdr.h"

int loop(t_sdl *sdl, t_jdr *jdr, t_perso *perso, t_my_net *net)
{
    // background MAP
    t_sdl_image map_background;
    map_background.position.x = 0;
    map_background.position.y = 0;
    if (!(map_background.image = SDL_LoadBMP(MAP_BACKGROUND_PATH)))
    {
        ft_putendl("load map background fail");
        return -1;
    }
    // background PERSO
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
    // tab map
    SDL_Surface *tab_MAP = TTF_RenderText_Blended(sdl->font.tab, "CARTE", MyGreen);
    SDL_Rect MAP_rect;
    MAP_rect.x = 110;
    MAP_rect.y = 9;
    MAP_rect.w = 300;
    MAP_rect.h = 30;
    // tab inv
    SDL_Surface *tab_INV = TTF_RenderText_Blended(sdl->font.tab, "INVENTAIRE", MyGreen);
    SDL_Rect INV_rect;
    INV_rect.x = 400;
    INV_rect.y = 9;
    INV_rect.w = 300;
    INV_rect.h = 30;
    // tab perso
    SDL_Surface *tab_PERSO = TTF_RenderText_Blended(sdl->font.tab, "PERSO", MyGreen);
    SDL_Rect PERSO_rect;
    PERSO_rect.x = 735;
    PERSO_rect.y = 9;
    PERSO_rect.w = 300;
    PERSO_rect.h = 30;
    // tab name
    SDL_Surface *tab_NAME = TTF_RenderText_Blended(sdl->font.tab, "JDR des French Retards", MyGreen);
    SDL_Rect NAME_rect;
    NAME_rect.x = 1200;
    NAME_rect.y = 9;
    NAME_rect.w = 300;
    NAME_rect.h = 30;

    // MESSAGE AND LOG
    get_str_from_keybord(net, sdl->event, sdl, perso, false, 0);
    net->log_fd = init_log(net);
    net->log_whell = -100;
    net->hst = list_init();
    jdr->log = true;
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

    // MAP
    t_map map;
    map.player = list_init();
    map.nb_player = 0;

    if (!(map.player_img = SDL_LoadBMP(PLAYER_PATH)))
    {
        ft_putendl("load player fail");
        return -1;
    }
    // make all white pixel transparent
    SDL_SetColorKey(map.player_img, SDL_TRUE, SDL_MapRGB(map.player_img->format, 255, 255, 255));
    SDL_Surface *main_player_pp = SDL_LoadBMP(PERSO_PP_PATH);

    if (!(map.map_grid = SDL_LoadBMP(MAP_GRID_PATH)))
    {
        ft_putendl("load map grid fail");
        return -1;
    }
    if (!(map.token = SDL_LoadBMP(TOKEN_PATH)))
    {
        ft_putendl("load token fail");
        return -1;
    }
    // make all white pixel transparent
    SDL_SetColorKey(map.token, SDL_TRUE, SDL_MapRGB(map.token->format, 255, 255, 255));

    /* TO DO

    // essential

    - map
    - inventory
    - Little leaks in perso (not much but maybe strong if running 3h)
    - support long ass perso_name
    - support lunch without serv lunch 
    - escape = option. 
    - check path before start 
    - send and received player pp via TCP

    // optional 

    - optional : add shell prog, lunchable directly in the prog 
    - add cursor in skill (+)
    - explicatif text for skill
    - Change Perso skill font 
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

    // LOOP
    bool keepWindow = true;
    Uint32 mouse;
    Uint8 const *keys;
    int x;
    int y;

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
            case SDL_MOUSEMOTION:
            {
                mouse = SDL_GetMouseState(&x, &y);
                SDL_SetCursor(sdl->cursor.arrow);
                if (y < 30)
                {
                    if (x < 940)
                        SDL_SetCursor(sdl->cursor.hand);
                    else if (x > 1885)
                        SDL_SetCursor(sdl->cursor.hand);
                }
                if (jdr->tab == TAB_PERSO)
                {
                    if (change_cursor_perso(perso, x, y) == 1)
                        SDL_SetCursor(sdl->cursor.hand);
                }
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                mouse = SDL_GetMouseState(&x, &y);
                // LEFT BUTTON
                if ((mouse & SDL_BUTTON_LMASK) != 0)
                    my_mouse_event(jdr, perso, &map, x, y);
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
            if (str[0] == '$')
            {
                if (str[1] == 'j')
                {
                    printf("new player detected !\n");
                    //insertion du nouveau player
                    map.nb_player++;
                    char **tab = ft_strsplit(str, '$');
                    add_player(&map, &str[3], main_player_pp, ft_atoi(tab[1]), ft_atoi(tab[2]), ft_atoi(tab[3]));
                    printf("player %s has joined !\n\n\n", &str[3]);
                }
                else if (str[1] == 'q')
                {
                    remove_player(&map, &str[3]);
                    map.nb_player--;
                    list_print(map.player);
                    printf("player %s has quit !\n\n\n", &str[3]);
                }
            }
            else
            {
                strcat(net->log, str);
                strcat(net->log, "\n");
                fprintf(net->log_fd, "%s\n", str);
                printf("%s\n", str);
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
                display_perso(sdl, perso);
            else if (jdr->tab == TAB_MAP)
            {
                display_map(sdl, &map);
                display_player(sdl, &map);
            }
            // else if (jdr->tab == TAB_INV)
            //     display_inv(sdl);

            // display message and log
            display_message(sdl, net);
            display_log(sdl, net, &map);
        }
        // update window
        SDL_UpdateWindowSurface(sdl->window);
    }
    return 1;
}