#include "jdr.h"

static void list_insert_pp(t_list *liste, char *str, SDL_Surface *pp, int r, int g, int b)
{
    /* Création du nouvel élément */
    t_element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->str = strdup(str);
    nouveau->pp = pp;
    nouveau->r = r;
    nouveau->g = g;
    nouveau->b = b;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void add_player(t_map *map, char *name, SDL_Surface *pp, int r, int g, int b)
{
    int i = 0;
    t_element *tmp = map->player->premier;
    while (name[i])
    {
        if (name [i] == '$')
            name[i] = '\0';
        i++;
    }
    i = 0;
    while (i < map->nb_player)
    {
        if (strcmp(tmp->str, name) == 0)
        {
            map->nb_player--;
            return;
        }
        tmp = tmp->suivant;
        i++;
    }
    list_insert_pp(map->player, name, pp, r, g, b);
    list_print(map->player);
}

void remove_player(t_map *map, char *name)
{
    // return;
    int i = 0;

    t_element *tmp = map->player->premier;

    while (i < map->nb_player)
    {
        // printf("name in tmp : %s\n", tmp->str);
        if (strcmp(tmp->str, name) == 0)
        {
            list_del_first(map->player);
        }
        else if (tmp->suivant != NULL)
        {
            if (strcmp(tmp->suivant->str, name) == 0)
            {
                printf("%s is gonna be deleted\n", tmp->suivant->str);
                tmp->suivant = tmp->suivant->suivant;
                break;
            }
        }
        tmp = tmp->suivant;
        i++;
    }
}