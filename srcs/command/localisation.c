#include "jdr.h"

void command_loca(t_my_net *net)
{
    int loca = (rand() % 10) + 1;
    strcat(net->message, " \n================================= \n[");
    strcat(net->message, ft_itoa(loca));
    strcat(net->message, "]\n");

    switch (loca)
    {
    case 1:
    {
        strcat(net->message, "Jambe gauche !\n");
        break;
    }
    case 2:
    {
        strcat(net->message, "Jambe droite !\n");
        break;
    }
    case 3:
    {
        strcat(net->message, "Ventre !\n");
        break;
    }
    case 4:
    {
        strcat(net->message, "Ventre !\n");
        break;
    }
    case 5:
    {
        strcat(net->message, "Arme !\n");
        break;
    }
    case 6:
    {
        strcat(net->message, "Torse !\n");
        break;
    }
    case 7:
    {
        strcat(net->message, "Torse !\n");
        break;
    }
    case 8:
    {
        strcat(net->message, "Bras gauche !\n");
        break;
    }
    case 9:
    {
        strcat(net->message, "Bras droit !\n");
        break;
    }
    case 10:
    {
        strcat(net->message, "Tete !\n");
        break;
    }
    }
    strcat(net->message, "================================= \n");
}