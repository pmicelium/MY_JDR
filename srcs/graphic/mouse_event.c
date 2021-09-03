#include "jdr.h"

void my_mouse_event(t_jdr *jdr, t_perso *perso, int x, int y)
{
    printf("cursor at %d / %d\n", x, y);
    // TAB
    if (y < 30)
    {
        if (x < 315)
            jdr->tab = TAB_MAP;
        else if (x < 625)
            jdr->tab = TAB_INV;
        else if (x < 940)
        {
            if (jdr->tab != TAB_PERSO)
                perso->levelup = LEVELUP;
            jdr->tab = TAB_PERSO;
        }
        else if (x > 1885)
            printf("OPTION\n");
    }
    if (jdr->tab == TAB_PERSO)
        mouse_event_perso(jdr, perso, x, y);
}