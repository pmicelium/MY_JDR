#include "jdr.h"

void move_stick(double time, t_sdl_image *image)
{
    image->pos_x = image->pos_x + (5 * time);
    image->position.x = image->pos_x;
}

int loop(t_sdl *sdl)
{

    t_sdl_image background;
    background.position.x = 0;
    background.position.y = 0;
    if (!(background.image = SDL_LoadBMP(BACKGROUND_PATH)))
    {
        ft_putendl("load background fail");
        return -1;           
    }

    bool keepWindow = true;
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
                    SDL_Quit();
                }
                break;
                case SDL_KEYDOWN:
                {
                    if(keys[SDL_SCANCODE_ESCAPE]== 1) //keeped for testing;
                    {
                        keepWindow = false;
                        destroy_window(sdl);
                        SDL_Quit();
                    }
                    // if(keys[SDL_SCANCODE_I] == 1)
                    // insert inventaire
                    // if (keys[SDL_SCANCODE_P] == 1)
                    // insert Perso
                    // if (keys[SDL_SCANCODE_K] == 1)
                    // insert competence   
                }
                break;
            }
        }
        if (keepWindow == true)
        {
            SDL_FillRect(sdl->window_surface, NULL, SDL_MapRGB(sdl->window_surface->format, 0, 0, 0));
            SDL_BlitSurface(background.image, NULL, sdl->window_surface, &background.position);
            SDL_UpdateWindowSurface(sdl->window);    //update la fenetre
        }
    }
    return 1;
}

int WinMain(int argc, char* argv[])
{
   t_perso     perso;
    if (init_perso(&perso) == -1)
        return exit_char("Impossible de charger le perso", -1);
    ft_putendl("init_perso done !");
    t_sdl       sdl;

    sdl.tabs = MAP;

//  initialisation de la fenetre;

    if (init_window(&sdl) == -1)
        return -1;
    ft_putendl("init_window done !");


    ft_putendl("TTF_init done !");
    
    if (loop(&sdl)== -1)
        return-1;
// */
    return 0;
}
