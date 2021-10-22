#include "jdr.h"

FILE *init_log(t_my_net *net)
{
    char str[LOG_LEN];
    FILE *fd = fopen(LOG_PATH, "a+");
    while (fgets(str, LOG_LEN - 1, fd))
        strcat(net->log, str);
    char hello[112] = "=======\n\
Nouvelle Session\n\n\
Entrer \"/help \" pour voir tout les commandes.\n\n\
Bon jeu !\n\
=======\n";
    strcat(net->log, hello);
    printf("log ok \n");
    return (fd);
}

static char *ParseLineForName(char *line)
{
    char *name;
    int i = 0;
    while (line[i] != ':')
        i++;

    if (!(name = (char *)malloc(sizeof(char) * i + 1)))
        return (NULL);

    i = 0;
    while (line[i] != ':')
    {
        name[i] = line[i];
        i++;
    }
    name[i-1] = '\0';

    return (name);
}

static SDL_Color GetColorFromPlayer(t_map *map, char *name)
{
    t_element *actuel = map->player->premier;
    SDL_Color color;
    int i = 0;

    while (i < map->nb_player)
    {
        // printf("name : |%s| %d\nstr  : |%s| %d\n", name, strlen(name), actuel->str, strlen(actuel->str));
        if (ft_strcmp(name, actuel->str) == 0)
        {
            color.r = actuel->r;
            color.g = actuel->g;
            color.b = actuel->b;
            color.a = 255;
            return (color);
        }
        i++;
        actuel = actuel->suivant;
    }
    color.r = 0;
    color.g = 0;
    color.b = 255;
    color.a = 255;
    return (color);
}

// le name deconne quelque fois
void display_log(t_sdl *sdl, t_my_net *net, t_map *map)
{
    SDL_Color p1;
    SDL_Color color = MY_GREEN;
    SDL_Rect rect;
    SDL_Rect scroll;
    SDL_Rect tmpRect;

    int fd;
    char *line;
    int LineSkip = TTF_FontLineSkip(sdl->font.log);
    int w, h;
    char *name;

    rect.x = 1640;
    rect.y = 45;
    rect.h = 950;
    

    if ((fd = open(LOG_PATH, O_RDONLY)) < 0)
        return exit_char("cannot open perso_skill", -1);
    int i = 0;

    rect.h = 950;
    rect.x = 1640;

    SDL_Surface *log = SDL_CreateRGBSurface(0, 269, 930, 8, 0, 0, 0, 0);

    while (gnl(fd, &line))
    {
        name = ParseLineForName(line);
        p1 = GetColorFromPlayer(map, name);

        // display the log
        SDL_Surface *line_s = TTF_RenderText_Blended_Wrapped(sdl->font.log, line, color, 269);

        // display the name in diff color
        SDL_Surface *name_s = TTF_RenderText_Blended_Wrapped(sdl->font.log, name, p1, 269);
        // need to hide the name in log
        SDL_Surface *cache = SDL_CreateRGBSurface(0, name_s->w, name_s->h, 32, 0, 0, 0, 0);
        SDL_FillRect(cache, NULL, SDL_MapRGB(cache->format, 19, 19, 19));

        TTF_SizeText(sdl->font.log, line, &w, &h);

        // printf("ligne : %d => %d\n", i, w);

        SDL_BlitSurface(line_s, NULL, sdl->window_surface, &rect);
        SDL_BlitSurface(cache, NULL, sdl->window_surface, &rect);
        SDL_BlitSurface(name_s, NULL, sdl->window_surface, &rect);

        rect.y += line_s->h;

        SDL_FreeSurface(line_s);
        SDL_FreeSurface(name_s);
        SDL_FreeSurface(cache);
        if (name)
            free(name);
        i++;
    }

    close(fd);
    return;

    printf("i = %d\n", i);

    // SDL_Surface *log = TTF_RenderText_Blended_Wrapped(sdl->font.log, net->log, color, 269);

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
    SDL_Surface *str_to_display = TTF_RenderText_Blended_Wrapped(sdl->font.message,
                                                                 net->message, color, 269);

    if (str_to_display->h > 75)
        scroll.y = str_to_display->h - 75;

    scroll.x = 0;
    scroll.h = 75;
    scroll.w = 269;
    SDL_BlitSurface(str_to_display, &scroll, sdl->window_surface, &rect);
    SDL_FreeSurface(str_to_display);
}