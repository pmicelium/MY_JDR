#include "jdr.h"

static void display_str(t_sdl *sdl, char *str, SDL_Rect *rect, SDL_Color Color, TTF_Font *font)
{
    SDL_Surface *str_to_display = TTF_RenderText_Solid(font, str, Color);
    SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, rect);
    SDL_FreeSurface(str_to_display);
}

static void display_carac_stat(t_sdl *sdl, t_perso *perso)
{
    SDL_Color MyGreen = MY_GREEN;
    SDL_Rect rect;

    rect.x = 405;
    rect.y = 530;
    display_str(sdl, ft_itoa(perso->skill.carrure), &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, ft_itoa(perso->skill.charisme), &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, ft_itoa(perso->skill.coordination), &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, ft_itoa(perso->skill.education), &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, ft_itoa(perso->skill.perception), &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, ft_itoa(perso->skill.reflexe), &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, ft_itoa(perso->skill.sang_froid), &rect, MyGreen, sdl->font.carac);
    // Experience
    rect.y = 928;
    rect.x = 435;
    display_str(sdl, ft_itoa(perso->skill.exp), &rect, MyGreen, sdl->font.skill_groupe);
}

static void display_carac(t_sdl *sdl, t_perso *perso)
{
    SDL_Color MyGreen = MY_GREEN;
    SDL_Rect rect;

    // rect.x = 110;
    // rect.y = 395;
    // display_str(sdl, "CARACTERISTIQUE", &rect, MyGreen, sdl->font.carac_titre);
    rect.x = 100;
    rect.y = 530;
    display_str(sdl, "Carrure", &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, "Charisme", &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, "Coordination", &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, "Education", &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, "Perception", &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, "Reflexe", &rect, MyGreen, sdl->font.carac);
    rect.y = rect.y + 50;
    display_str(sdl, "Sang Froid", &rect, MyGreen, sdl->font.carac);
    // Experience
    rect.y = 935;
    rect.x = 50;
    display_str(sdl, "Points d'experience", &rect, MyGreen, sdl->font.skill);

    display_carac_stat(sdl, perso);
}

static void display_skill_stat(t_sdl *sdl, t_perso *perso, SDL_Color MyGreen, int nl)
{
    SDL_Rect rect;

    char *str;
    // Groupe Pilote
    rect.x = 980;
    rect.y = 90;
    str = ft_strjoin(ft_itoa(perso->skill.vehicule_terrestre), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.pilotage_Leger), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.pilotage_combat), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.pilotage_Lourd), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.tourelle), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    // Groupe physique
    rect.y = 337;
    str = ft_strjoin(ft_itoa(perso->skill.athle), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.acrobatie), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.escalade), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.endurence), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    // Groupe Exploration
    rect.y = 545;
    str = ft_strjoin(ft_itoa(perso->skill.discretion), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.fouille), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.informatique), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.piratage), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.decryptage), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.premier_secour), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    // Groupe Crafting
    rect.y = 840;
    str = ft_strjoin(ft_itoa(perso->skill.brico), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.reparation), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.metal), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.cuisine), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.survie), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    //
    // Groupe Arme
    //
    rect.x = 1510;
    rect.y = 90;
    str = ft_strjoin(ft_itoa(perso->skill.poing), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.epaule), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.pompe), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.sniper), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.lourde), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.explosif), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.lancer), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.CAC), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.contact), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    // Groupe Pouvoir
    rect.y = 495;
    if (perso->skill.pouvoir1 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir1), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir2 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir2), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir3 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir3), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir4 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir4), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir5 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir5), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir6 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir6), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir7 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir7), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir8 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir8), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir9 != 0)
    {
        str = ft_strjoin(ft_itoa(perso->skill.pouvoir9), "+");
        display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    }
    // Groupe Communication
    rect.y = 890;
    nl = 38;
    str = ft_strjoin(ft_itoa(perso->skill.eloquence), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.intimidation), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.bluff), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;
    str = ft_strjoin(ft_itoa(perso->skill.psyco), "+");
    display_str(sdl, str, &rect, MyGreen, sdl->font.skill_groupe);
    rect.y = rect.y + nl;

    // free str
    free(str);
}

static void display_skill(t_sdl *sdl, t_perso *perso)
{
    SDL_Color MyGreen = MY_GREEN;
    SDL_Rect rect;
    int nl = 41;

    rect.x = 565;
    rect.y = 95;
    // Groupe Pilote
    display_str(sdl, "Conduite Vehicule terrestre (COOR)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Pilotage de vaisseau leger (COOR)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Manoeuvre de combat (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Pilotage de vaisseau lourd (COOR)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Tourelle (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    // Groupe physique
    rect.y = 342;
    display_str(sdl, "Athletisme (CARRURE)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Acrobatie (REFLEXE)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Escalade (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Endurance (CARRURE)", &rect, MyGreen, sdl->font.skill);
    // Groupe Exploration
    rect.y = 550;
    display_str(sdl, "Discretion (SANG FROID)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Fouille (PERCEPTION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Informatique (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Piratage (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Decryptage (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Premier secours (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    // Groupe Crafting
    rect.y = 845;
    display_str(sdl, "Bricolage (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Reparation (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Metallurgie (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Cuisine (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Survie", &rect, MyGreen, sdl->font.skill);
    //
    // Groupe Arme
    //
    rect.x = 1110;
    rect.y = 95;
    display_str(sdl, "Arme de poing (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Arme d'epaule' (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Arme a pompe (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Arme de sniper (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Arme lourde (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Explosif (EDUCATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Arme de lancer (COORDINATION)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Corps a corps (CARRURE)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Arme de contact (CARRURE)", &rect, MyGreen, sdl->font.skill);
    // Groupe Pouvoir
    rect.y = 500;
    if (perso->skill.pouvoir1 != 0)
        display_str(sdl, perso->skill.power1, &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir2 != 0)
        display_str(sdl, perso->skill.power2, &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir3 != 0)
        display_str(sdl, perso->skill.power3, &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir4 != 0)
        display_str(sdl, perso->skill.power4, &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir5 != 0)
        display_str(sdl, perso->skill.power5, &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir6 != 0)
        display_str(sdl, perso->skill.power6, &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir7 != 0)
        display_str(sdl, perso->skill.power7, &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir8 != 0)
        display_str(sdl, perso->skill.power8, &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    if (perso->skill.pouvoir9 != 0)
        display_str(sdl, perso->skill.power9, &rect, MyGreen, sdl->font.skill);

    // Groupe Com
    rect.y = 895;
    nl = 38;
    display_str(sdl, "Eloquence (CHARISME)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Intimidation (CHARISME)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Bluff (CHARISME)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Psycologie (CHARISME)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    nl = 41;
    display_skill_stat(sdl, perso, MyGreen, nl);
}

static void display_pp(t_sdl *sdl, t_perso *perso)
{
    t_sdl_image perso_pp;

    if (!(perso_pp.image = SDL_LoadBMP(PERSO_PP_PATH)))
    {
        ft_putendl("load perso background fail");
        return;
    }

    SDL_Rect rect;
    rect.x = 138;
    rect.y = 123;
    rect.h = 371;
    rect.w = 262;
    SDL_BlitScaled(perso_pp.image, NULL, sdl->window_surface, &rect);
}

static void display_name(t_sdl *sdl, t_perso *perso)
{
    SDL_Rect rect;
    SDL_Color MyGreen = MY_GREEN;

    rect.x = 98;
    rect.y = 85;
    rect.w = 385;
    rect.h = 30;
    SDL_Surface *str_to_display = TTF_RenderText_Solid(sdl->font.carac_titre, perso->name, MyGreen);
    SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    SDL_FreeSurface(str_to_display);
}

static void display_levelup_plus(t_sdl *sdl, t_perso *perso)
{
    SDL_Rect rect;
    SDL_Color MyGreen = MY_GREEN;
    SDL_Surface *str_to_display;
    int nl = 50;

    // CARACT
    rect.x = 470;
    rect.y = 515;
    if ((perso->skill.exp >= perso->skill.carrure * 6) && (perso->skill.carrure < 6))
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= perso->skill.charisme * 6) && (perso->skill.charisme < 6))
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= perso->skill.coordination * 6) && (perso->skill.coordination < 6))
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= perso->skill.education * 6) && (perso->skill.education < 6))
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= perso->skill.perception * 6) && (perso->skill.perception < 6))
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= perso->skill.reflexe * 6) && (perso->skill.reflexe < 6))
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= perso->skill.sang_froid * 6) && (perso->skill.sang_froid < 6))
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    // Pilotage
    rect.x = 1055;
    rect.y = 75;
    nl = 41;
    if ((perso->skill.exp >= (10 - perso->skill.vehicule_terrestre) * 2) && perso->skill.vehicule_terrestre > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.pilotage_Leger) * 2) && perso->skill.pilotage_Leger > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.pilotage_combat) * 2) && perso->skill.pilotage_combat > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if (((perso->skill.exp >= (10 - perso->skill.pilotage_Lourd) * 2) && (perso->skill.pilotage_Leger <= 6 || perso->skill.pilotage_Lourd < 9)) && perso->skill.pilotage_Lourd > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.tourelle) * 2) && perso->skill.tourelle > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }

    // physique
    rect.y = 322;
    if ((perso->skill.exp >= (10 - perso->skill.athle) * 2) && perso->skill.athle > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.acrobatie) * 2) && perso->skill.acrobatie > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.escalade) * 2) && perso->skill.escalade > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.endurence) * 2) && perso->skill.endurence > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }

    // groupe explo
    rect.y = 533;
    if ((perso->skill.exp >= (10 - perso->skill.discretion) * 2) && perso->skill.discretion > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.fouille) * 2) && perso->skill.fouille > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.informatique) * 2) && perso->skill.informatique > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if (((perso->skill.exp >= (10 - perso->skill.piratage) * 2) && (perso->skill.informatique <= 6 || perso->skill.piratage < 9)) && perso->skill.piratage > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if (((perso->skill.exp >= (10 - perso->skill.decryptage) * 2) && (perso->skill.informatique <= 6 || perso->skill.decryptage < 9)) && perso->skill.decryptage > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.premier_secour) * 2) && perso->skill.premier_secour > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }

    // groupe Crafting
    rect.y = 825;
    if ((perso->skill.exp >= (10 - perso->skill.brico) * 2) && perso->skill.brico > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.reparation) * 2) && perso->skill.reparation > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if (((perso->skill.exp >= (10 - perso->skill.metal) * 2) && (perso->skill.brico <= 6 || perso->skill.metal < 9)) && perso->skill.metal > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.cuisine) * 2) && perso->skill.cuisine > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.survie) * 2) && perso->skill.survie > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }

    // groupe Arme
    rect.x = 1580;
    rect.y = 75;
    if ((perso->skill.exp >= (10 - perso->skill.poing) * 2) && perso->skill.poing > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.epaule) * 2) && perso->skill.epaule > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.pompe) * 2) && perso->skill.pompe > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if (((perso->skill.exp >= (10 - perso->skill.sniper) * 2) && (perso->skill.epaule <= 6 || perso->skill.sniper < 9)) && perso->skill.sniper > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.lourde) * 2) && perso->skill.lourde > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.explosif) * 2) && perso->skill.explosif > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.lancer) * 2) && perso->skill.lancer > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.CAC) * 2) && perso->skill.CAC > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.contact) * 2) && perso->skill.contact > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }

    //groupe pouvoir
    rect.y = 480;
    if ((perso->skill.pouvoir1 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir1) * 2)) && perso->skill.pouvoir1 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.pouvoir2 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir2) * 2)) && perso->skill.pouvoir2 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.pouvoir3 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir3) * 2)) && perso->skill.pouvoir3 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.pouvoir4 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir4) * 2)) && perso->skill.pouvoir4 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.pouvoir5 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir5) * 2)) && perso->skill.pouvoir5 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.pouvoir6 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir6) * 2)) && perso->skill.pouvoir6 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.pouvoir7 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir7) * 2)) && perso->skill.pouvoir7 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.pouvoir8 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir8) * 2)) && perso->skill.pouvoir8 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.pouvoir9 != 0 && (perso->skill.exp >= (10 - perso->skill.pouvoir9) * 2)) && perso->skill.pouvoir9 > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }

    // groupe Comm
    rect.y = 875;
    nl = 38;
    if ((perso->skill.exp >= (10 - perso->skill.eloquence) * 2) && perso->skill.eloquence > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.intimidation) * 2) && perso->skill.intimidation > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.bluff) * 2) && perso->skill.bluff > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
    rect.y = rect.y + nl;
    if ((perso->skill.exp >= (10 - perso->skill.psyco) * 2) && perso->skill.psyco > 2)
    {
        str_to_display = TTF_RenderText_Solid(sdl->font.plus, "+", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    }
}

static void display_levelup(t_sdl *sdl, t_perso *perso)
{
    SDL_Rect rect;
    SDL_Color MyGreen = MY_GREEN;
    int x = 175;
    rect.x = x;
    rect.y = 980;
    SDL_Surface *str_to_display;
    if (perso->levelup == LEVELUP)
        str_to_display = TTF_RenderText_Solid(sdl->font.carac_titre, "LEVEL UP", MyGreen);
    else
    {
        rect.x = x - 140;
        str_to_display = TTF_RenderText_Solid(sdl->font.carac_titre, "RETOUR", MyGreen);
        SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
        rect.x = x + 160;
        str_to_display = TTF_RenderText_Solid(sdl->font.carac_titre, "VALIDER", MyGreen);
        display_levelup_plus(sdl, perso);
    }
    SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    SDL_FreeSurface(str_to_display);
}

void display_perso(t_sdl *sdl, t_perso *perso)
{
    display_name(sdl, perso);
    display_carac(sdl, perso);
    display_skill(sdl, perso);
    display_pp(sdl, perso);
    display_levelup(sdl, perso);
}