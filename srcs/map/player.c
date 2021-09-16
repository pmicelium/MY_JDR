#include "jdr.h"

static void list_insert_pp(t_list *liste, char *str, SDL_Surface *pp)
{
	/* Création du nouvel élément */
	t_element *nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->str = strdup(str);
    nouveau->pp = pp;

	/* Insertion de l'élément au début de la liste */
	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
}

void add_player(t_map *map, char *name, SDL_Surface *pp)
{
    list_insert_pp(map->player, name, pp);
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