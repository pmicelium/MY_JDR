#include "jdr.h"

void move_stick(double time, t_sdl_image *image)
{
    image->pos_x = image->pos_x + (5 * time);
    image->position.x = image->pos_x;
}

int WinMain(int argc, char* argv[])
{
    t_jdr       jdr;
    init_jdr(&jdr);

//  initialisation de perso
    t_perso     perso;
    if (init_perso(&perso) == -1)
        return exit_char("Impossible de charger le perso", -1);
    ft_putendl("init_perso done !");
    jdr.perso = true;

//  initialisation de la fenetre;
    t_sdl       sdl;
    sdl.tabs = MAP;
    if (init_window(&sdl) == -1)
        return -1;
    jdr.sdl = true;
    ft_putendl("init_window done !");

//  initialisation de tff
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE); 
    }
    jdr.ttf = true;
    sdl.font = TTF_OpenFont(FONT_PATH, FONT_SIZE);
    ft_putendl("TTF_init done !");
    
// loop sdl
    if (loop(&sdl, &jdr)== -1)
        return-1;

    return 0;
}
