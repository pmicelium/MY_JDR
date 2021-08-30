#include "jdr.h"

static void     display_str(t_sdl *sdl, char *str, SDL_Rect *rect, SDL_Color Color, TTF_Font *font)
{
    SDL_Surface     *str_to_display = TTF_RenderText_Solid(font, str, Color);
    SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, rect);
    SDL_FreeSurface(str_to_display);
    
}

static void     display_carac_stat(t_sdl *sdl, t_perso *perso)
{
    SDL_Color       MyGreen = MY_GREEN;
    SDL_Rect        rect;

    rect.x = 425;
    rect.y = 485;
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
}

static void     display_carac(t_sdl *sdl, t_perso *perso)
{
    SDL_Color       MyGreen = MY_GREEN;
    SDL_Rect        rect;

    // rect.x = 110;
    // rect.y = 395;
    // display_str(sdl, "CARACTERISTIQUE", &rect, MyGreen, sdl->font.carac_titre);
    rect.x = 125;
    rect.y = 487;
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
    
    display_carac_stat(sdl, perso);
}  

static void     display_skill_stat(t_sdl *sdl, t_perso *perso, SDL_Color MyGreen, int nl)
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
    rect.y = 500;
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
    // Experience
    rect.y = 940;
    display_str(sdl, ft_itoa(perso->skill.exp), &rect, MyGreen, sdl->font.skill_groupe);
    // Groupe Communication
    rect.x = 420;
    rect.y = 878;
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

static void     display_skill(t_sdl *sdl, t_perso *perso)
{
    SDL_Color       MyGreen = MY_GREEN;
    SDL_Rect        rect;
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
    display_str(sdl, "Endurence (CARRURE)", &rect, MyGreen, sdl->font.skill);
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
    rect.y = 505;
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
    // Experience
    rect.y = 945;
    display_str(sdl, "Points d'experience", &rect, MyGreen, sdl->font.skill);
    // Groupe Com
    rect.x = 125;
    rect.y = 883;
    display_str(sdl, "Eloquence (CHARISME)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Intimidation (CHARISME)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Bluff (CHARISME)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    display_str(sdl, "Psycologie (CHARISME)", &rect, MyGreen, sdl->font.skill);
    rect.y = rect.y + nl;
    
    display_skill_stat(sdl, perso, MyGreen, nl);     
}

void            display_pp(t_sdl *sdl, t_perso *perso)
{
    t_sdl_image     perso_pp;

    perso_pp.position.x = 130;
    perso_pp.position.y = 130;
    
    if (!(perso_pp.image = SDL_LoadBMP(PERSO_PP_PATH)))
    {
        ft_putendl("load perso background fail");
        return ;            
    }

    SDL_Rect rect;
    rect.x = 177;
    rect.y = 131;
    rect.h = 322;
    rect.w = 227;
    SDL_BlitScaled(perso_pp.image, NULL, sdl->window_surface, &rect);
}

void            display_name(t_sdl *sdl, t_perso *perso)
{
    SDL_Rect rect;
    SDL_Color       MyGreen = MY_GREEN;

    rect.x = 98;
    rect.y = 85;
    rect.w = 385;
    rect.h = 30;
    SDL_Surface     *str_to_display = TTF_RenderText_Solid(sdl->font.carac_titre, perso->name, MyGreen);
    // printf("name  h : %d\nname w:  %d\n", str_to_display->h, str_to_display->w);
    SDL_BlitSurface(str_to_display, NULL, sdl->window_surface, &rect);
    SDL_FreeSurface(str_to_display);
}

void            display_perso(t_sdl *sdl, t_perso *perso)
{
    display_name(sdl, perso);
    display_carac(sdl, perso);
    display_skill(sdl, perso);
    display_pp(sdl, perso);
}