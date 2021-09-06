#include "jdr.h"

void command_roll(t_my_net *net, int i)
{
    int roll = 0;
    int j = 0;
    char str[LOG_LEN];
    bool find_d = false;

    int nb_d = atoi(&net->message[i]);
    while (net->message[i] != 'd' && i < LOG_LEN)
    {
        i++;
    }
    if (find_d)
    {
        printf("]%s[\n", &net->message[i]);
        int face = atoi(&net->message[++i]);
        printf("face : %d\n", face);
        strcat(net->message, " ================================= [");
        while (j < nb_d)
        {
            roll = (rand() % face) + 1;
            strcat(net->message, ft_itoa(roll));
            strcat(net->message, "] ");
            if (j < nb_d - 1)
                strcat(net->message, "[");
            j++;
        }
        strcat(net->message, " ================================= ");
    }
}