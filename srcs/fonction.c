#include "jdr.h"

// PERSO

void MakeSurfaceTransparent(SDL_Surface *surface, int r, int g, int b)
{
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b));
}

char *myformat(char *format, ...)
{
	va_list ap;
	Uint32 len = 0;
	static char *str = NULL;
	char *p, *s;
	char c;
	int d;
	unsigned int u;

	if (str)
	{
		free(str);
		str = NULL;
	}
	if (!format)
		return (NULL);
	va_start(ap, format);
	for (p = format; *p; p++)
	{
		switch (*p)
		{
		case 's': /* string */
			s = va_arg(ap, char *);
			str = (char *)realloc(str, ((len + strlen(s) + 4) / 4) * 4);
			sprintf(str + len, "%s", s);
			break;
		case 'c': /* char */
			c = (char)va_arg(ap, int);
			str = (char *)realloc(str, len + 4);
			sprintf(str + len, "%c", c);
			break;
		case 'd': /* int */
			d = va_arg(ap, int);
			str = (char *)realloc(str, ((len + 64) / 4) * 4);
			sprintf(str + len, "%d", d);
			break;
		case 'u': /* unsigned int */
			u = va_arg(ap, unsigned int);
			str = (char *)realloc(str, ((len + 64) / 4) * 4);
			sprintf(str + len, "%u", u);
			break;
		}
		/* set len to the new string length */
		if (str)
			len = strlen(str);
		else
			len = 0;
	}
	va_end(ap);
	return (str);
}

// LIBFT //

int		ft_strcmp(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != 0)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int exit_char(char *str, int i)
{
	printf(str);
	return i;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char const *str)
{
	write(1, str, strlen(str));
}

void ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void ft_putnbr(int nb)
{
	if (nb == -2147483647 - 1)
		ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			nb = nb % 10;
			ft_putchar(nb + '0');
		}
		else
			ft_putchar(nb + '0');
	}
}

void ft_putnbr_endl(int nb)
{
	ft_putnbr(nb);
	ft_putchar('\n');
}

static char *ft_get_after(char **line, char *after)
{
	if (strchr(after, '\n'))
	{
		*strchr(after, '\n') = '\0';
		*line = after;
		return (&after[strlen(after) + 1]);
	}
	return (NULL);
}

int gnl(int fd, char **line)
{
	int ret;
	char buff[GNL_BUFF_SIZE + 1];
	static char *after;

	if (fd <= 0 || fd >= FOPEN_MAX)
		return (-1);
	while ((ret = read(fd, buff, GNL_BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		after = buff;
		if (strchr(after, '\n'))
			break;
	}
	if ((after = ft_get_after(line, after)))
		return (1);
	return (0);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int ft_atoi(char const *str)
{
	int val;
	int i;
	int sign;

	i = 0;
	val = 0;
	while (ft_isdigit(str[i]) == 0)
		i++;
	sign = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		val = val * 10 + (str[i++] - '0');
	return (sign * val);
}

char *ft_strcpy(char *dest, char const *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void *ft_memset(void *s, int k, size_t n)
{
	size_t i;
	unsigned char *c;

	c = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = k;
		i++;
	}
	s = c;
	return (s);
}

void *ft_memalloc(size_t size)
{
	void *mem;

	if (size == 0)
		return (NULL);
	if (!(mem = (void *)malloc(size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}

char *ft_strnew(size_t size)
{
	char *new;

	new = ft_memalloc(size + 1);
	return (new);
}

size_t ft_intlen(int nb)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nb)
{
	int i;
	char *s;

	i = ft_intlen(nb);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	if (nb == 0)
	{
		s[0] = 48;
		return (s);
	}
	if (nb == -2147483647 - 1)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		s[--i] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (s);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *new;
	size_t i;
	size_t k;
	size_t l;
	size_t len;

	len = strlen(s1);
	l = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	i = strlen(s1) + strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (i) + 1)))
		return (NULL);
	while (k < len)
		new[k++] = s1[l++];
	l = 0;
	while (k < i)
	{
		new[k] = s2[l];
		l++;
		k++;
	}
	new[k] = '\0';
	return (new);
}

char *ft_strdup(char const *src)
{
	char *src2;
	int i;

	i = 0;
	while (src[i])
		i++;
	if (!(src2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (i == 0)
	{
		src2[0] = '\0';
		return (src2);
	}
	ft_strcpy(src2, src);
	src2[i] = '\0';
	return (src2);
}

void ft_strclr(char *s)
{
	size_t i;
	size_t j;

	i = 0;
	if (s == NULL)
		return;
	j = strlen(s);
	while (i < j)
	{
		s[i] = '\0';
		i++;
	}
}

int ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

static size_t ft_count_words(char *str, char c)
{
	size_t i;
	size_t m;

	i = 0;
	m = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			m++;
		i++;
	}
	return (m);
}

static char **ft_malloc_words(char *str, char c, char **p)
{
	size_t i;
	size_t m;
	size_t t;

	i = 0;
	m = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
			{
				if (!(p[m++] = ft_strnew(sizeof(char) * (t + 1))))
					return (NULL);
				t = 0;
			}
			t++;
		}
		i++;
	}
	return (p);
}

static char **ft_fill_words(char *str, char c, char **p)
{
	size_t i;
	size_t m;
	size_t t;

	i = 0;
	m = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] != c)
			p[m][t++] = str[i];
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			t = 0;
			m++;
		}
		i++;
	}
	return (p);
}

char **ft_strsplit(char const *s, char c)
{
	char *str;
	char **p;

	if (s == NULL)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	if (!(p = (char **)malloc(sizeof(char *) * (ft_count_words(str, c) + 1))))
		return (NULL);
	p[ft_count_words(str, c)] = NULL;
	if (!(p = ft_malloc_words(str, c, p)))
		return (NULL);
	p = ft_fill_words(str, c, p);
	free(str);
	return (p);
}

t_list *list_init()
{
	t_list *liste = malloc(sizeof(*liste));
	t_element *element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}

	element->str = strdup("FIRST");
	element->suivant = NULL;
	liste->premier = element;

	return liste;
}

void list_insert(t_list *liste, char *str)
{
	/* Création du nouvel élément */
	t_element *nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->str = strdup(str);

	/* Insertion de l'élément au début de la liste */
	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
}

// /*
void list_print(t_list *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    t_element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("-%s- -> ", actuel->str);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
// */

void list_del(t_list *liste)
{
	t_element *actuel = liste->premier;

	while (actuel != NULL)
	{
		t_element *aSupprimer = actuel;
		actuel = actuel->suivant;
		free(aSupprimer);
	}
	liste = NULL;
}

void list_del_first(t_list *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
    	t_element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}