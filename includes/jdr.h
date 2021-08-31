#ifndef JDR_H
# define JDR_H

// SDL2 include
# include "SDL2\SDL.h"
# include "SDL2\SDL_ttf.h"

// system include 
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>


// window size define 
# define WIN_X      2048
# define WIN_Y      1080


// t_jdr.tabs define 
# define TAB_MAP    1
# define TAB_INV    2
# define TAB_PERSO  3

// t_perso levelup define
# define LEVELUP    1
# define LEVELUP_O  2
# define LEVELUP_R  3
# define LEVELUP_V  4

// ressource path
# define PERSO_PATH "ressource/Perso"

// image path 
# define MAP_BACKGROUND_PATH "ressource/image/map_background.bmp"
# define PERSO_BACKGROUND_PATH "ressource/image/perso_background.bmp"
# define PERSO_PP_PATH "ressource/image/perso_pp.bmp"

// font 
# define FONT_SF_OUT_PATH "ressource/font/sf-distant-galaxy.outline.ttf"
# define FONT_SF_R_PATH "ressource/font/sf-distant-galaxy.regular.ttf"

# define FONT_TAB_SIZE 24

# define FONT_CARAC_SIZE 30
# define FONT_CARAC_T_SIZE 35

# define FONT_SKILL_G_SIZE 30
# define FONT_SKILL_SIZE 16

# define FONT_PLUS_SIZE 70

// SDL COLOR
# define MY_GREEN {45, 206, 69}


//
// STRUCT
// 

//  font struct
typedef struct      s_font
{
    TTF_Font        *tab;
    TTF_Font        *skill_groupe;
    TTF_Font        *skill;
    TTF_Font        *carac_titre;
    TTF_Font        *carac;
    TTF_Font        *plus;
}                   t_font;

// sdl struct
typedef struct      s_sdl
{
    SDL_Window      *window;
    SDL_Surface     *window_surface;
    SDL_Event       event;

    t_font          font;
}                   t_sdl;



// sdl image struct
typedef struct      s_sdl_image
{
    SDL_Surface     *image;
    SDL_Rect        position;
    double          pos_x;
    double          pos_y;
}                   t_sdl_image;

// perso skill
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

// perso struct
typedef struct      s_perso
{
    char*           name;
    t_skill         skill;
    t_sdl_image     profile_pict;
    int             levelup;
}                   t_perso;

// main struct
typedef struct      s_jdr 
{
    int             tab;
    bool            perso;
    bool            sdl;
    bool            ttf;
    bool            need2draw;
}                   t_jdr;

//
// JDR 
//
// init struc jdr 
void init_jdr(t_jdr *jdr);
// free and quit all 
void destroy_all(t_jdr *jdr);

//
// GRAPHIC
// 
// create a window
int init_window(t_sdl *sdl);
// destroy a window 
void destroy_window(t_sdl *sdl);
// main event loop
int loop(t_sdl *sdl, t_jdr *jdr, t_perso *perso);
// display perso tab on screen 
void display_perso(t_sdl *sdl, t_perso *perso);
// manage mouse event 
void mouse_event(t_jdr *jdr, t_perso *perso, int x, int y);
// manage mouse event in perso tab
void mouse_event_perso(t_jdr *jdr, t_perso *perso, int x, int y);

// 
// PERSO 
// 
// get perso intel 
int init_perso(t_perso *perso);
// destroy t_perso
void destroy_perso(t_perso *perso);
// update ressource perso
void print_perso(t_perso *perso);
// copy t_perso struct
t_skill copy_skill(t_skill *skill);
// free t_skill char
void    free_skill(t_skill *skill);

// 
// LIBFT 
// 
void	            ft_putchar(char c);
void	            ft_putstr(char const *str);
void	            ft_putendl(char const *s);
void	            ft_putnbr(int nb);
void	            ft_putnbr_endl(int nb);
int                 exit_char(char* str, int i);
int				    gnl(int fd, char **line);
int		            ft_atoi(char const *str);
char	            *ft_itoa(int nb);
char	            *ft_strjoin(char const *s1, char const *s2);
char                *ft_strdup(char const *src);
// gnl 
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
