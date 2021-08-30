#include "jdr.h" 

/*
// initialisation et creation de la fenetre
// Return 1 ok ; -1 erreur 
*/

int init_window(t_sdl *sdl)
{
//  initialisation de sdl
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
        return exit_char("Failed to initialize the SDL2 library", -1);

//  creation de la fenetre 
    sdl->window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, 
    //SDL_WINDOW_RESIZABLE);
    SDL_WINDOW_FULLSCREEN_DESKTOP);
    // SDL_WINDOW_BORDERLESS);
    // 0);
     if(!sdl->window)
        return exit_char("fail to create window", -1);

//  creation de la structure surface sdl
    sdl->window_surface = SDL_GetWindowSurface(sdl->window); 
    if(!sdl->window_surface)
        return exit_char("Failed to get the surface from the window", -1);

    return 1;
}