#include "jdr.h"

void display_help(t_my_net *net)
{
    strcat(net->message, " ================================= \
/help : montre ce message.      \
/roll xdy(!) (z) : lance x des a y face, ajouter un \"!\" relance automatiquement les des ayant la valeur max, z (optionel) est le taux de reussite.                             \
/gmroll xdy (z) : pareil que /r mais le jet n'est visible que par le lancer et le MJ.                    \
/gm : envois un message uniquement au MJ.                            \
/localisation : lance un des de localisation.                       \
/{caracteristique} (z): lance un jet de caracteristique pur, (z) est le taux de reussite, il est de 6 par defaut                            \
/pv : ajoute ou retire des pv a votre perso                                 \
/pm : ajoute ou retire des pm a votre perso \
 ================================= ");
}

int check_command(t_perso *perso, t_my_net *net)
{
    int i = 0;

    char **word = ft_strsplit(net->message, ' ');

    if (strcmp(word[0], "/help") == 0)
    {
        display_help(net);
        while (word[i])
        {
            free(word[i]);
            i++;
        }
        return -1;
    }
    if (strcmp(word[0], "/roll") == 0 || strcmp(word[0], "/r") == 0)
        command_roll(net);
    else if (strcmp(word[0], "/localisation") == 0 || strcmp(word[0], "/l") == 0 || strcmp(word[0], "/loca") == 0)
        command_loca(net);
    else if (strcmp(word[0], "/carrure") == 0 || strcmp(word[0], "/ca") == 0 || strcmp(word[0], "/carr") == 0)
        my_roll(net, perso->skill.carrure, 10, 6, true);
    else if (strcmp(word[0], "/charisme") == 0 || strcmp(word[0], "/ch") == 0 || strcmp(word[0], "/char") == 0)
        my_roll(net, perso->skill.charisme, 10, 6, true);
    else if (strcmp(word[0], "/coordination") == 0 || strcmp(word[0], "/co") == 0 || strcmp(word[0], "/coor") == 0)
        my_roll(net, perso->skill.coordination, 10, 6, true);
    else if (strcmp(word[0], "/education") == 0 || strcmp(word[0], "/ed") == 0 || strcmp(word[0], "/educ") == 0)
        my_roll(net, perso->skill.education, 10, 6, true);
    else if (strcmp(word[0], "/perception") == 0 || strcmp(word[0], "/pe") == 0 || strcmp(word[0], "/perc") == 0)
        my_roll(net, perso->skill.perception, 10, 6, true);
    else if (strcmp(word[0], "/reflexe") == 0 || strcmp(word[0], "/re") == 0 || strcmp(word[0], "/refl") == 0)
        my_roll(net, perso->skill.reflexe, 10, 6, true);
    else if (strcmp(word[0], "/sang_froid") == 0 || strcmp(word[0], "/sf") == 0 || strcmp(word[0], "/sang") == 0)
        my_roll(net, perso->skill.sang_froid, 10, 6, true);

    while (word[i])
    {
        free(word[i]);
        i++;
    }
    return 0;
}
