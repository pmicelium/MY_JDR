#include "jdr.h"

void command_loca(t_my_net *net)
{
    int loca = (rand() % 10) + 1;
    strcat(net->message, " ================================= [");
    strcat(net->message, ft_itoa(loca));
    strcat(net->message, "]                                                  ");

    switch (loca)
    {
    case 1:
    {
        strcat(net->message, "Jambe gauche !");
        break;
    }
    case 2:
    {
        strcat(net->message, "Jambe droite !");
        break;
    }
    case 3:
    {
        strcat(net->message, "Ventre !");
        break;
    }
    case 4:
    {
        strcat(net->message, "Ventre !");
        break;
    }
    case 5:
    {
        strcat(net->message, "Arme !");
        break;
    }
    case 6:
    {
        strcat(net->message, "Torse !");
        break;
    }
    case 7:
    {
        strcat(net->message, "Torse !");
        break;
    }
    case 8:
    {
        strcat(net->message, "Bras gauche !");
        break;
    }
    case 9:
    {
        strcat(net->message, "Bras droit !");
        break;
    }
    case 10:
    {
        strcat(net->message, "Tete !");
        break;
    }
    }
    strcat(net->message, " ================================= ");
}