#include "jdr.h"

void mouse_event_map(t_jdr *jdr, t_map *map, int x, int y)
{
    if (x > 33 && x < 55)
    {
        if (y > 77 && y < 99)
            printf("free hand draw\n");
        else if (y > 120 && y < 144)
            printf("draw rectangle\n");
        else if (y > 160 && y < 188)
            printf("loupe\n");
        else if (y > 200 && y < 213)
            printf("token\n");
    }
}
