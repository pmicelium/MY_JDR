#include "jdr.h"

static void add_msg_to_log(t_my_net *net)
{
    // je sais pas si c'est tres rapide tout ca
    strcat(net->log, net->name);
    strcat(net->log, " : ");
    strcat(net->log, net->message);
    strcat(net->log, "\n");
}

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
                    while(str[i][j] != ' ')
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

void get_str_from_keybord(t_my_net *net, SDL_Event event, bool caps, t_sdl *sdl, t_perso *perso)
{
    char c;
    int help;

    if (net->i == 0)
    {
        net->message[net->i] = '|';
        net->message[net->i + 1] = '\0';
    }

    switch (event.key.keysym.sym)
    {

    // ENTER
    case SDLK_RETURN:
    {
        if (net->i != 0)
        {
            if (net->i < MAXLEN)
                net->message[net->i] = '\0';
            printf("%s : %s\n", net->name, net->message);
            if (net->message[0] == '/')
                help = check_command(perso, net);
            if (net->i != 0 && help != -1)
            {
                fprintf(net->log_fd, "%s : %s\n", net->name, net->message);
                // print_log(net, sdl);
            }
            add_msg_to_log(net);
            net->i = 0;
            ft_strclr(net->message);
        }
        break;
    }
    case SDLK_KP_ENTER:
    {
        if (net->i != 0)
        {
            if (net->i < MAXLEN)
                net->message[net->i] = '\0';
            printf("%s : %s\n", net->name, net->message);
            if (net->message[0] == '/')
                check_command(perso, net);
            if (net->i != 0)
                fprintf(net->log_fd, "%s : %s\n", net->name, net->message);
            add_msg_to_log(net);
            net->i = 0;
            ft_strclr(net->message);
            break;
        }
    }
    // AlphaNum
    case SDLK_a:
    {
        c = 'a';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_b:
    {
        c = 'b';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_c:
    {
        c = 'c';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_d:
    {
        c = 'd';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_e:
    {
        c = 'e';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_f:
    {
        c = 'f';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_g:
    {
        c = 'g';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_h:
    {
        c = 'h';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_i:
    {
        c = 'i';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_j:
    {
        c = 'j';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_k:
    {
        c = 'k';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_l:
    {
        c = 'l';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_m:
    {
        c = 'm';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_n:
    {
        c = 'n';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_o:
    {
        c = 'o';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_p:
    {
        c = 'p';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_q:
    {
        c = 'q';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_r:
    {
        c = 'r';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_s:
    {
        c = 's';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_t:
    {
        c = 't';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_u:
    {
        c = 'u';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_v:
    {
        c = 'v';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_w:
    {
        c = 'w';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_x:
    {
        c = 'x';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_y:
    {
        c = 'y';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_z:
    {
        c = 'z';
        if (caps)
            c -= 32;
        net->message[net->i] = c;
        net->i++;
        break;
    }
    case SDLK_1:
    {
        net->message[net->i] = '1';
        net->i++;
        break;
    }
    case SDLK_2:
    {
        net->message[net->i] = '2';
        net->i++;
        break;
    }
    case SDLK_3:
    {
        net->message[net->i] = '3';
        net->i++;
        break;
    }
    case SDLK_4:
    {
        net->message[net->i] = '4';
        net->i++;
        break;
    }
    case SDLK_5:
    {
        net->message[net->i] = '5';
        net->i++;
        break;
    }
    case SDLK_6:
    {
        net->message[net->i] = '6';
        net->i++;
        break;
    }
    case SDLK_7:
    {
        net->message[net->i] = '7';
        net->i++;
        break;
    }
    case SDLK_8:
    {
        net->message[net->i] = '8';
        net->i++;
        break;
    }
    case SDLK_9:
    {
        net->message[net->i] = '9';
        net->i++;
        break;
    }
    case SDLK_0:
    {
        net->message[net->i] = '0';
        net->i++;
        break;
    }

    // OTHER
    case SDLK_SPACE:
    {
        net->message[net->i] = ' ';
        net->i++;
        break;
    }
    case SDLK_BACKSPACE:
    {
        net->message[net->i] = '|';
        if (net->i > 0)
            net->i--;
        break;
    }
    case SDLK_EXCLAIM:
    {
        net->message[net->i] = '!';
        net->i++;
        break;
    }
    case SDLK_QUOTEDBL:
    {
        net->message[net->i] = '\"';
        net->i++;
        break;
    }
    case SDLK_HASH:
    {
        net->message[net->i] = '#';
        net->i++;
        break;
    }
    case SDLK_DOLLAR:
    {
        net->message[net->i] = '$';
        net->i++;
        break;
    }
    case SDLK_AMPERSAND:
    {
        net->message[net->i] = '&';
        net->i++;
        break;
    }
    case SDLK_QUOTE:
    {
        net->message[net->i] = '\'';
        net->i++;
        break;
    }
    case SDLK_LEFTPAREN:
    {
        net->message[net->i] = '(';
        net->i++;
        break;
    }
    case SDLK_RIGHTPAREN:
    {
        net->message[net->i] = ')';
        net->i++;
        break;
    }
    case SDLK_ASTERISK:
    {
        net->message[net->i] = '*';
        net->i++;
        break;
    }
    case SDLK_PLUS:
    {
        net->message[net->i] = '+';
        net->i++;
        break;
    }
    case SDLK_COMMA:
    {
        net->message[net->i] = ',';
        net->i++;
        break;
    }
    case SDLK_MINUS:
    {
        net->message[net->i] = '-';
        net->i++;
        break;
    }
    case SDLK_PERIOD:
    {
        net->message[net->i] = '.';
        net->i++;
        break;
    }
    case SDLK_SLASH:
    {
        net->message[net->i] = '/';
        net->i++;
        break;
    }
    case SDLK_COLON:
    {
        net->message[net->i] = ':';
        net->i++;
        break;
    }
    case SDLK_SEMICOLON:
    {
        net->message[net->i] = ';';
        net->i++;
        break;
    }
    case SDLK_LESS:
    {
        net->message[net->i] = '<';
        net->i++;
        break;
    }
    case SDLK_EQUALS:
    {
        net->message[net->i] = '=';
        net->i++;
        break;
    }
    case SDLK_GREATER:
    {
        net->message[net->i] = '>';
        net->i++;
        break;
    }
    case SDLK_QUESTION:
    {
        net->message[net->i] = '?';
        net->i++;
        break;
    }
    case SDLK_AT:
    {
        net->message[net->i] = '@';
        net->i++;
        break;
    }
    case SDLK_LEFTBRACKET:
    {
        net->message[net->i] = '[';
        net->i++;
        break;
    }
    case SDLK_BACKSLASH:
    {
        net->message[net->i] = '\\';
        net->i++;
        break;
    }
    case SDLK_RIGHTBRACKET:
    {
        net->message[net->i] = ']';
        net->i++;
        break;
    }
    case SDLK_CARET:
    {
        net->message[net->i] = '^';
        net->i++;
        break;
    }
    case SDLK_UNDERSCORE:
    {
        net->message[net->i] = '_';
        net->i++;
        break;
    }
    case SDLK_BACKQUOTE:
    {
        net->message[net->i] = '`';
        net->i++;
        break;
    }

    // keypads
    case SDLK_KP_0:
    {
        net->message[net->i] = '0';
        net->i++;
        break;
    }
    case SDLK_KP_1:
    {
        net->message[net->i] = '1';
        net->i++;
        break;
    }
    case SDLK_KP_2:
    {
        net->message[net->i] = '2';
        net->i++;
        break;
    }
    case SDLK_KP_3:
    {
        net->message[net->i] = '3';
        net->i++;
        break;
    }
    case SDLK_KP_4:
    {
        net->message[net->i] = '4';
        net->i++;
        break;
    }
    case SDLK_KP_5:
    {
        net->message[net->i] = '5';
        net->i++;
        break;
    }
    case SDLK_KP_6:
    {
        net->message[net->i] = '6';
        net->i++;
        break;
    }
    case SDLK_KP_7:
    {
        net->message[net->i] = '7';
        net->i++;
        break;
    }
    case SDLK_KP_8:
    {
        net->message[net->i] = '8';
        net->i++;
        break;
    }
    case SDLK_KP_9:
    {
        net->message[net->i] = '9';
        net->i++;
        break;
    }
    case SDLK_KP_PERIOD:
    {
        net->message[net->i] = '.';
        net->i++;
        break;
    }
    case SDLK_KP_DIVIDE:
    {
        net->message[net->i] = '/';
        net->i++;
        break;
    }
    case SDLK_KP_MULTIPLY:
    {
        net->message[net->i] = '*';
        net->i++;
        break;
    }
    case SDLK_KP_MINUS:
    {
        net->message[net->i] = '-';
        net->i++;
        break;
    }
    case SDLK_KP_PLUS:
    {
        net->message[net->i] = '+';
        net->i++;
        break;
    }
    }

    static int tmp;
    if (net->i != tmp)
    {
        tmp = net->i;
        net->message[net->i] = '|';
        net->message[net->i + 1] = '\0';
    }
}