#include "jdr.h"

static void display_help(t_my_net *net)
{
    strcat(net->log, " ==========================\n\
/help : montre ce message.\n\
/roll xdy(!) (z) : lance x des a y face, ajouter un \"!\" relance automatiquement les des ayant la valeur max, z (optionel) est le taux de reussite.\n\
/localisation : lance un des de localisation.\n\
/{caracteristique} (z): lance un jet de caracteristique pur, (z) est le taux de reussite, il est de 6 par defaut\n\
/gmroll xdy (z) : pareil que /r mais le jet n'est visible que par le lancer et le MJ.\n\
/gm {caract || loca} (z): envois un message uniquement au MJ ou un jet de caracteristique | localisation\n\
 ==========================");
}

int check_command(t_perso *perso, t_my_net *net)
{
    int i = 0;

    char **word = ft_strsplit(net->message, ' ');

    if (strcasecmp(word[0], "/help") == 0)
    {
        display_help(net);
        while (word[i])
        {
            free(word[i]);
            i++;
        }
        return -1;
    }
    if (strcasecmp(word[0], "/quit") == 0)
        return -1;
    if (strcasecmp(word[0], "/roll") == 0 || strcasecmp(word[0], "/r") == 0)
        command_roll(net);
    else if (strcasecmp(word[0], "/localisation") == 0 || strcasecmp(word[0], "/l") == 0 || strcasecmp(word[0], "/loca") == 0)
        command_loca(net);
    else if (strcasecmp(word[0], "/carrure") == 0 || strcasecmp(word[0], "/ca") == 0 || strcasecmp(word[0], "/carr") == 0)
        my_roll(net, perso->skill.carrure, 10, 6, true);
    else if (strcasecmp(word[0], "/charisme") == 0 || strcasecmp(word[0], "/ch") == 0 || strcasecmp(word[0], "/char") == 0)
        my_roll(net, perso->skill.charisme, 10, 6, true);
    else if (strcasecmp(word[0], "/coordination") == 0 || strcasecmp(word[0], "/co") == 0 || strcasecmp(word[0], "/coor") == 0)
        my_roll(net, perso->skill.coordination, 10, 6, true);
    else if (strcasecmp(word[0], "/education") == 0 || strcasecmp(word[0], "/ed") == 0 || strcasecmp(word[0], "/educ") == 0)
        my_roll(net, perso->skill.education, 10, 6, true);
    else if (strcasecmp(word[0], "/perception") == 0 || strcasecmp(word[0], "/pe") == 0 || strcasecmp(word[0], "/perc") == 0)
        my_roll(net, perso->skill.perception, 10, 6, true);
    else if (strcasecmp(word[0], "/reflexe") == 0 || strcasecmp(word[0], "/re") == 0 || strcasecmp(word[0], "/refl") == 0)
        my_roll(net, perso->skill.reflexe, 10, 6, true);
    else if (strcasecmp(word[0], "/sang_froid") == 0 || strcasecmp(word[0], "/sf") == 0 || strcasecmp(word[0], "/sang") == 0)
        my_roll(net, perso->skill.sang_froid, 10, 6, true);

    else if (strcasecmp(word[0], "/gmroll") == 0 || strcasecmp(word[0], "/gmr") == 0 || strcasecmp(word[0], "/gr") == 0)
    {
        if (strcasecmp(word[1], "/localisation") == 0 || strcasecmp(word[1], "/l") == 0 || strcasecmp(word[1], "/loca") == 0)
            command_loca(net);
        else if (strcasecmp(word[1], "/carrure") == 0 || strcasecmp(word[1], "/ca") == 0 || strcasecmp(word[1], "/carr") == 0)
            my_roll(net, perso->skill.carrure, 10, 6, true);
        else if (strcasecmp(word[1], "/charisme") == 0 || strcasecmp(word[1], "/ch") == 0 || strcasecmp(word[1], "/char") == 0)
            my_roll(net, perso->skill.charisme, 10, 6, true);
        else if (strcasecmp(word[1], "/coordination") == 0 || strcasecmp(word[1], "/co") == 0 || strcasecmp(word[1], "/coor") == 0)
            my_roll(net, perso->skill.coordination, 10, 6, true);
        else if (strcasecmp(word[1], "/education") == 0 || strcasecmp(word[1], "/ed") == 0 || strcasecmp(word[1], "/educ") == 0)
            my_roll(net, perso->skill.education, 10, 6, true);
        else if (strcasecmp(word[1], "/perception") == 0 || strcasecmp(word[1], "/pe") == 0 || strcasecmp(word[1], "/perc") == 0)
            my_roll(net, perso->skill.perception, 10, 6, true);
        else if (strcasecmp(word[1], "/reflexe") == 0 || strcasecmp(word[1], "/re") == 0 || strcasecmp(word[1], "/refl") == 0)
            my_roll(net, perso->skill.reflexe, 10, 6, true);
        else if (strcasecmp(word[1], "/sang_froid") == 0 || strcasecmp(word[1], "/sf") == 0 || strcasecmp(word[1], "/sang") == 0)
            my_roll(net, perso->skill.sang_froid, 10, 6, true);
        else
            command_roll(net);
    }
    while (word[i])
    {
        free(word[i]);
        i++;
    }
    return 0;
}
