#include "jdr.h"

void display_help(t_my_net *net)
{
    strcat(net->message, " ================================= \
/help : montre ce message.      \
/roll xdy (z) : lance x des a y face, z (optionel) est le taux de reussite.                             \
/gmroll xdy (z) : pareil que /r mais le jet n'es visible que par le lancer et le MJ.                    \
/gm : envois un message uniquement au MJ.                            \
/localisation : lance un des de localisation.                       \
/{caracteristique} (z): lance un jet de caracteristique pur, (z) est le taux de reussite, il est de 6 par defaut                            \
/pv : ajoute ou retire des pv a votre perso                                 \
/pm : ajoute ou retire des pm a votre perso \
 ================================= ");
}

void check_command(t_perso *perso, t_my_net *net)
{
    printf("in command\n");

    char str[LOG_LEN];
    int i = 0;

    if (strstr(net->message, "/help"))
        display_help(net);
    while (net->message[i] != ' ' && net->message[i] != '\0')
    {
        str[i] = net->message[i];
        i++;
    }
    if (strstr(str, "/roll") || strstr(str, "/r"))
        command_roll(net, i);
    else if (strstr(str, "/localisation") || strstr(str, "/l") || strstr(str, "/loca"))
        command_loca(net);
    else if (strstr(str, "/carrure") || strstr(str, "/ca"))
        command_carr(perso, net);
}
