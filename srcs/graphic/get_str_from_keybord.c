#include "jdr.h"

void get_str_from_keybord(t_my_net *net, SDL_Event event, bool caps, t_sdl *sdl)
{
    char c;
    static unsigned int i = 0;

    if (i == 0)
    {
        net->message[i] = '|';
        net->message[i+1] = '\0';
    }

    switch (event.key.keysym.sym)
    {

    // ENTER
    case SDLK_RETURN:
    {
        if (i < MAXLEN)
            net->message[i + 1] = '\0';
        printf("%s : %s\n", net->name, net->message);
        i = 0;
        ft_strclr(net->message);
        break;
    }
    case SDLK_KP_ENTER:
    {
        if (i < MAXLEN)
            net->message[i + 1] = '\0';
        printf("%s : %s\n", net->name, net->message);
        i = 0;
        ft_strclr(net->message);
        break;
    }
    // AlphaNum
    case SDLK_a:
    {
        c = 'a';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_b:
    {
        c = 'b';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_c:
    {
        c = 'c';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_d:
    {
        c = 'd';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_e:
    {
        c = 'e';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_f:
    {
        c = 'f';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_g:
    {
        c = 'g';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_h:
    {
        c = 'h';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_i:
    {
        c = 'i';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_j:
    {
        c = 'j';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_k:
    {
        c = 'k';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_l:
    {
        c = 'l';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_m:
    {
        c = 'm';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_n:
    {
        c = 'n';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_o:
    {
        c = 'o';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_p:
    {
        c = 'p';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_q:
    {
        c = 'q';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_r:
    {
        c = 'r';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_s:
    {
        c = 's';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_t:
    {
        c = 't';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_u:
    {
        c = 'u';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_v:
    {
        c = 'v';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_w:
    {
        c = 'w';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_x:
    {
        c = 'x';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_y:
    {
        c = 'y';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_z:
    {
        c = 'z';
        if (caps)
            c -= 32;
        net->message[i] = c;
        i++;
        break;
    }
    case SDLK_1:
    {
        net->message[i] = '1';
        i++;
        break;
    }
    case SDLK_2:
    {
        net->message[i] = '2';
        i++;
        break;
    }
    case SDLK_3:
    {
        net->message[i] = '3';
        i++;
        break;
    }
    case SDLK_4:
    {
        net->message[i] = '4';
        i++;
        break;
    }
    case SDLK_5:
    {
        net->message[i] = '5';
        i++;
        break;
    }
    case SDLK_6:
    {
        net->message[i] = '6';
        i++;
        break;
    }
    case SDLK_7:
    {
        net->message[i] = '7';
        i++;
        break;
    }
    case SDLK_8:
    {
        net->message[i] = '8';
        i++;
        break;
    }
    case SDLK_9:
    {
        net->message[i] = '9';
        i++;
        break;
    }
    case SDLK_0:
    {
        net->message[i] = '0';
        i++;
        break;
    }

    // OTHER
    case SDLK_SPACE:
    {
        net->message[i] = ' ';
        i++;
        break;
    }
    case SDLK_BACKSPACE:
    {
        net->message[i] = '|';
        if (i > 0)
            i--;
        break;
    }
    case SDLK_EXCLAIM:
    {
        net->message[i] = '!';
        i++;
        break;
    }
    case SDLK_QUOTEDBL:
    {
        net->message[i] = '\"';
        i++;
        break;
    }
    case SDLK_HASH:
    {
        net->message[i] = '#';
        i++;
        break;
    }
    case SDLK_DOLLAR:
    {
        net->message[i] = '$';
        i++;
        break;
    }
    case SDLK_AMPERSAND:
    {
        net->message[i] = '&';
        i++;
        break;
    }
    case SDLK_QUOTE:
    {
        net->message[i] = '\'';
        i++;
        break;
    }
    case SDLK_LEFTPAREN:
    {
        net->message[i] = '(';
        i++;
        break;
    }
    case SDLK_RIGHTPAREN:
    {
        net->message[i] = ')';
        i++;
        break;
    }
    case SDLK_ASTERISK:
    {
        net->message[i] = '*';
        i++;
        break;
    }
    case SDLK_PLUS:
    {
        net->message[i] = '+';
        i++;
        break;
    }
    case SDLK_COMMA:
    {
        net->message[i] = ',';
        i++;
        break;
    }
    case SDLK_MINUS:
    {
        net->message[i] = '-';
        i++;
        break;
    }
    case SDLK_PERIOD:
    {
        net->message[i] = '.';
        i++;
        break;
    }
    case SDLK_SLASH:
    {
        net->message[i] = '/';
        i++;
        break;
    }
    case SDLK_COLON:
    {
        net->message[i] = ':';
        i++;
        break;
    }
    case SDLK_SEMICOLON:
    {
        net->message[i] = ';';
        i++;
        break;
    }
    case SDLK_LESS:
    {
        net->message[i] = '<';
        i++;
        break;
    }
    case SDLK_EQUALS:
    {
        net->message[i] = '=';
        i++;
        break;
    }
    case SDLK_GREATER:
    {
        net->message[i] = '>';
        i++;
        break;
    }
    case SDLK_QUESTION:
    {
        net->message[i] = '?';
        i++;
        break;
    }
    case SDLK_AT:
    {
        net->message[i] = '@';
        i++;
        break;
    }
    case SDLK_LEFTBRACKET:
    {
        net->message[i] = '[';
        i++;
        break;
    }
    case SDLK_BACKSLASH:
    {
        net->message[i] = '\\';
        i++;
        break;
    }
    case SDLK_RIGHTBRACKET:
    {
        net->message[i] = ']';
        i++;
        break;
    }
    case SDLK_CARET:
    {
        net->message[i] = '^';
        i++;
        break;
    }
    case SDLK_UNDERSCORE:
    {
        net->message[i] = '_';
        i++;
        break;
    }
    case SDLK_BACKQUOTE:
    {
        net->message[i] = '`';
        i++;
        break;
    }

    // keypads
    case SDLK_KP_0:
    {
        net->message[i] = '0';
        i++;
        break;
    }
    case SDLK_KP_1:
    {
        net->message[i] = '1';
        i++;
        break;
    }
    case SDLK_KP_2:
    {
        net->message[i] = '2';
        i++;
        break;
    }
    case SDLK_KP_3:
    {
        net->message[i] = '3';
        i++;
        break;
    }
    case SDLK_KP_4:
    {
        net->message[i] = '4';
        i++;
        break;
    }
    case SDLK_KP_5:
    {
        net->message[i] = '5';
        i++;
        break;
    }
    case SDLK_KP_6:
    {
        net->message[i] = '6';
        i++;
        break;
    }
    case SDLK_KP_7:
    {
        net->message[i] = '7';
        i++;
        break;
    }
    case SDLK_KP_8:
    {
        net->message[i] = '8';
        i++;
        break;
    }
    case SDLK_KP_9:
    {
        net->message[i] = '9';
        i++;
        break;
    }
    case SDLK_KP_PERIOD:
    {
        net->message[i] = '.';
        i++;
        break;
    }
    case SDLK_KP_DIVIDE:
    {
        net->message[i] = '/';
        i++;
        break;
    }
    case SDLK_KP_MULTIPLY:
    {
        net->message[i] = '*';
        i++;
        break;
    }
    case SDLK_KP_MINUS:
    {
        net->message[i] = '-';
        i++;
        break;
    }
    case SDLK_KP_PLUS:
    {
        net->message[i] = '+';
        i++;
        break;
    }
    }

    static int tmp;
    if (i != tmp)
    {
        tmp = i;
        net->message[i] = '|';
        net->message[i+1] = '\0';
    }
}