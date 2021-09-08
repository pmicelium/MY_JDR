#include "jdr.h"

void init_ttf_font(t_sdl *sdl)
{
    // TAB
    sdl->font.tab = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_TAB_SIZE);

    // PERSO
    sdl->font.skill_groupe = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_SKILL_G_SIZE);
    sdl->font.skill = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_SKILL_SIZE);
    sdl->font.carac_titre = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_CARAC_T_SIZE);
    sdl->font.carac = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_CARAC_SIZE);
    sdl->font.plus = TTF_OpenFont(FONT_SF_OUT_PATH, FONT_PLUS_SIZE);

    // CHAT
    sdl->font.message = TTF_OpenFont(FONT_NASA, FONT_CHAT_SIZE);
    sdl->font.log = TTF_OpenFont(FONT_NASA, FONT_LOG_SIZE);
}

void init_jdr(t_jdr *jdr)
{
    jdr->perso = false;
    jdr->sdl = false;
    jdr->ttf = false;
    jdr->tab = TAB_MAP;
}

void destroy_all(t_jdr *jdr, t_my_net *net, t_sdl *sdl)
{
    if (jdr->sdl == true)
        SDL_Quit();
    if (jdr->ttf == true)
        TTF_Quit();
    if (jdr->net == true)
        SDLNet_Quit();
    if (jdr->log == true)
        fclose(net->log_fd);

    list_del(sdl->hst);
}