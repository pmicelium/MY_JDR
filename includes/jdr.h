#ifndef JDR_H
# define JDR_H

// SDL2 include
# include "SDL2\SDL.h"
# include "SDL2\SDL_ttf.h"

// system include 
# include  <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>


// window size define 
# define WIN_X 1920
# define WIN_Y 1080
// # define WIN_X 1080
// # define WIN_Y 720

// t_sdl.tabs define 
# define MAP 1
# define PERSO 2
# define INV 3

// ressource path
# define PERSO_PATH "ressource/Perso"
# define BACKGROUND_PATH "ressource/image/background.bmp"

typedef struct      s_sdl
{
    int             tabs;

    SDL_Window      *window;
    SDL_Surface     *window_surface;
    SDL_Event       event;
}                   t_sdl;

typedef struct      s_sdl_image
{
    SDL_Surface     *image;
    SDL_Rect        position;
    double          pos_x;
    double          pos_y;
}                   t_sdl_image;

typedef struct      s_skill
{
    // caracteristique
    int             carrure;
    int             charisme;
    int             coordination;
    int             education;
    int             perception;
    int             reflexe;
    int             sang_froid;

    // groupe pilote
    int             vehicule_terrestre;
    int             pilotage_Leger;
    int             pilotage_combat;
    int             pilotage_Lourd;
    int             tourelle;

    // groupe explo
    int             discretion;
    int             fouille;
    int             informatique;
    int             piratage;
    int             decryptage;
    int             premier_secour;

    // groupe physique
    int             athle;
    int             acrobatie;
    int             escalade;
    int             endurence;

    // groupe communication
    int             eloquence;
    int             intimidation;
    int             bluff;
    int             psyco;

    // groupe crafting
    int             brico;
    int             metal;
    int             reparation;
    int             cuisine;
    int             survie;

    // groupe arme
    int             epaule;
    int             pompe;
    int             sniper;
    int             poing;
    int             contact;
    int             lourde;
    int             CAC;
    int             lancer;
    int             explosif;

    // experience
    int             exp;

    // groupe pouvoir
    int             pouvoir1;
    int             pouvoir2;
    int             pouvoir3;
    int             pouvoir4;
    int             pouvoir5;
    int             pouvoir6;
    int             pouvoir7;
    int             pouvoir8;
    int             pouvoir9;

    char*           power1;
    char*           power2;
    char*           power3;
    char*           power4;
    char*           power5;
    char*           power6;
    char*           power7;
    char*           power8;
    char*           power9;
}                   t_skill;

typedef struct      s_perso
{
    char*           name;
    t_skill         skill;
    t_sdl_image     profile_pict;
}                   t_perso;


int init_window(t_sdl *sdl);
int init_perso(t_perso *perso);

void destroy_window(t_sdl *sdl);
void destroy_perso(t_perso *perso);

void print_perso(t_perso *perso);

// libft //

void	            ft_putchar(char c);
void	            ft_putstr(char const *str);
void	            ft_putendl(char const *s);
void	            ft_putnbr(int nb);
void	            ft_putnbr_endl(int nb);
int                 exit_char(char* str, int i);
int				    gnl(int fd, char **line);

// gnl //

# define GNL_EOL 1
# define GNL_EOF 0
# define GNL_ERR -1

# define GNL_BUFF_SIZE 40000

typedef struct		s_reader
{
	int				ret;
	int				eof;
	char			*bgn;
	char			*end;
	char			buf[GNL_BUFF_SIZE];
}					t_reader;

#endif
