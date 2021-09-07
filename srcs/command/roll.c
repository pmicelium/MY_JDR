#include "jdr.h"

void my_roll(t_my_net *net, int nb_d, int face, int win, bool ire)
{
    int roll;
    int nb_win = 0;
    int total = 0;

    if (nb_d > 100 || face > 1000)
        return - 1;
    int d = 0;
    strcat(net->message, "\n==========================\n[");
    while (d < nb_d)
    {
        roll = (rand() % face) + 1;
        if (roll == face && ire == true)
            nb_d++;
        if (roll > win)
            nb_win++;
        total += roll;
        strcat(net->message, ft_itoa(roll));
        strcat(net->message, "] ");
        if (d < nb_d - 1)
            strcat(net->message, "[");
        d++;
    }

    strcat(net->message, "\nTOTAL : ");
    strcat(net->message, ft_itoa(total));
    strcat(net->message, "\n");

    if (win > 0 && win < face)
    {
        strcat(net->message, "\n");
        strcat(net->message, ft_itoa(nb_win));
        if (nb_win == 1)
            strcat(net->message, " reussite !\n");
        else
            strcat(net->message, " reussites !\n");
    }

    strcat(net->message, "==========================");
}

// peut etre envoyer que net->essage
void command_roll(t_my_net *net)
{
    int roll = 0;
    int j = 1;
    char re = '`';
    char **word = ft_strsplit(net->message, ' ');
    int nb_word = 0;
    int win = -1;

    while (word[nb_word])
        nb_word++;

    char *face_str = strchr(word[j], 'd');

    if (face_str == NULL)
        face_str = strchr(word[j], 'D');
    if (face_str)
    {
        int nb_d = atoi(word[1]);
        int face = ft_atoi(face_str);
        if (nb_word >= 3)
            win = ft_atoi(word[2]);
        if (strchr(face_str, re))
            my_roll(net, nb_d, face, win, true);
        else
            my_roll(net, nb_d, face, win, false);
    }
    j = 0;
    while (word[j])
    {
        free(word[j]);
        j++;
    }
}