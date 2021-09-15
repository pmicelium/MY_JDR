#include "jdr.h"

/*
static void add_msg_to_log(t_my_net *net)
{
    // je sais pas si c'est tres rapide tout ca
    strcat(net->log, net->name);
    strcat(net->log, " : ");
    strcat(net->log, net->message);
    strcat(net->log, "\n");
}
// */

/*
void print_log(t_my_net *net, t_sdl *sdl)
{
    char **str = ft_strsplit(net->message, '\n');
    int i = 0;
    int j = 0;
    char tmp[LOG_LEN];
    int nl;
    fprintf(net->log_fd, "%s :", net->name);
    int w, h, k, l;

    while (str[i])
    {
        printf("str[%d] = %s\n", i, str[i]);
        TTF_SizeText(sdl->font.log, str[i], &w, &h);
        printf("w : %d\n", w);
        if (w < 269)
            fprintf(net->log_fd, "%s\n", str[i]);
        else
        {
            k = 0;
            j = 0;
            while (str[i][j])
            {
                if (str[i][j] = ' ')
                {
                    while (str[i][j] != ' ')
                        j++;
                }
                else
                    fputc(str[i][j], net->log_fd);
                j++;
            }
        }
        i++;
    }
}
// */

void get_str_from_keybord(t_my_net *net, SDL_Event event, t_sdl *sdl, t_perso *perso, bool charb, char c)
{
    int help;
    static int j = 0;
    static int k = 0;
    static bool print = false;

    if (net->i == 0)
    {
        net->message[net->i] = '|';
        net->message[net->i + 1] = '\0';
    }

    if (charb)
    {
        net->message[net->i] = c;
        net->i++;
    }
    switch (event.key.keysym.sym)
    {

    // ENTER
    case SDLK_KP_ENTER:
    case SDLK_RETURN:
    {
        if (net->i != 0)
        {
            if (net->i < MAXLEN)
                net->message[net->i] = '\0';
            list_insert(sdl->hst, net->message);
            k++;
            j = 0;
            print = true;

            if (net->message[0] == '/')
                help = check_command(perso, net);
            if (net->i != 0 && help != -1)
            {
                // fprintf(net->log_fd, "in print %s : %s\n", net->name, net->message);
                //check if message > LENMAX = error or not;
                putMsg(net->sock, net->message);

                // print_log(net, sdl);
            }
            // add_msg_to_log(net);

            net->i = 0;
            ft_strclr(net->message);
        }
        break;
    }
    case SDLK_BACKSPACE:
    {
        net->message[net->i] = '|';
        if (net->i > 0)
            net->i--;
        break;
    }
    case SDLK_UP:
    {
        int i = k - j;
        if (j < k)
        {
            j++;

            t_element *actuel = sdl->hst->premier;

            while (i < k && i != 0)
            {
                actuel = actuel->suivant;
                i++;
            }

            ft_strclr(net->message);
            strcpy(net->message, actuel->str);
            net->i = strlen(net->message);
        }
        break;
    }
    case SDLK_DOWN:
    {

        if (j > 1 && print == true)
        {
            j--;
            int i = 0;

            t_element *actuel = sdl->hst->premier;

            while (i < j - 1)
            {
                actuel = actuel->suivant;
                i++;
            }

            ft_strclr(net->message);
            strcpy(net->message, actuel->str);
            net->i = strlen(net->message);
        }
        else
        {
            j = 0;
            net->i = 0;
            ft_strclr(net->message);
        }
        break;
    }
    }

    net->message[net->i] = '|';
    net->message[net->i + 1] = '\0';
}