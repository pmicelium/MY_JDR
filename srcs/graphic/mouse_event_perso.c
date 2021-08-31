#include "jdr.h"

static void event_levelup(t_jdr *jdr, t_perso *perso, int x, int y)
{
    // carac

}

void mouse_event_perso(t_jdr *jdr, t_perso *perso, int x, int y)
{

    if (x > 175 && x < 360 && y > 980 && y < 1005)
    {
        perso->levelup = LEVELUP_O;
        jdr->need2draw = true;
    }
    if (perso->levelup == LEVELUP_O)
    {
        // event_levelup(jdr, perso, x, y);
        if (x > 35 && x < 195 && y > 980 && y < 1005)
        {
            perso->levelup = LEVELUP_R;
            printf("retour\n");
            perso->levelup = LEVELUP;
            jdr->need2draw = true;
        }
        if (x > 335 && x < 500 && y > 980 && y < 1005)
        {
            perso->levelup = LEVELUP_V;
            printf("valider\n");
            perso->levelup = LEVELUP;
            jdr->need2draw = true;
        }
    }
}