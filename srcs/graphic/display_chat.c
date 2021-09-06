#include "jdr.h"

FILE *init_log(t_my_net *net)
{
    char str[LOG_LEN];
    FILE *fd = fopen(LOG_PATH, "a+");
    while (fgets(str, LOG_LEN - 1, fd))
        strcat(net->log, str);
    return (fd);
}

void display_log(t_sdl *sdl, t_my_net *net)
{
    SDL_Color color = MY_GREEN;
    SDL_Rect rect;
    SDL_Rect scroll;
    static int tmp;

    rect.x = 1640;
    rect.y = 45;

    rect.h = 950;

    SDL_Surface *log = TTF_RenderText_Blended_Wrapped(sdl->font.log, net->log, color, 269);

    if (net->log_whell == -100)
        net->log_whell = net->max_log;
    if (log->h - 930 != net->max_log)
    {
        net->max_log = log->h - 930;
        net->log_whell = net->max_log;   
    }

    scroll.x = 0;
    scroll.y = net->log_whell;
    scroll.h = 930;
    scroll.w = 269;

    SDL_BlitSurface(log, &scroll, sdl->window_surface, &rect);
    SDL_FreeSurface(log);
}

void display_message(t_sdl *sdl, t_my_net *net)
{
    SDL_Color color = MY_GREEN;
    SDL_Rect rect;
    SDL_Rect scroll;

    rect.x = 1640;
    rect.y = 995;
    rect.h = 40;
    SDL_Surface *str_to_display = TTF_RenderText_Blended_Wrapped(sdl->font.message, net->message, color, 269);

    if (str_to_display->h > 75)
        scroll.y = str_to_display->h - 75;

    scroll.x = 0;
    scroll.h = 75;
    scroll.w = 269;
    SDL_BlitSurface(str_to_display, &scroll, sdl->window_surface, &rect);
    SDL_FreeSurface(str_to_display);
}