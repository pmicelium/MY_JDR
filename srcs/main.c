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

    // NEED TO CHECK PATH BEFORE ALL //

//  initialisation de perso
    t_perso     perso;
    if (init_perso(&perso) == -1)
        return exit_char("Impossible de charger le perso", -1);
    ft_putendl("init_perso done !");
    jdr.perso = true;

//  initialisation de la fenetre;
    t_sdl       sdl;

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
    ft_putendl("TTF_init done !");
    jdr.ttf = true;
    sdl.font.tab = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_TAB_SIZE);

    sdl.font.skill_groupe = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_SKILL_G_SIZE);
    sdl.font.skill = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_SKILL_SIZE);

    sdl.font.carac_titre = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_CARAC_T_SIZE);
    sdl.font.carac = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_CARAC_SIZE);
    sdl.font.plus = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_PLUS_SIZE);
    ft_putendl("TTF font done !");
    
// loop sdl
    if (loop(&sdl, &jdr, &perso)== -1)
        return-1;

    return 0;
}
