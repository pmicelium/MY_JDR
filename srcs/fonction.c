#include "jdr.h"

// LIBFT //

int exit_char(char* str, int i)
{
    printf (str);
    return i;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *str)
{
	write(1, str, strlen(str));
}

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483647 -1)
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

void	ft_putnbr_endl(int nb)
{
	ft_putnbr(nb);
	ft_putchar('\n');
}

static char		*ft_get_after(char **line, char *after)
{
	if (strchr(after, '\n'))
	{
		*strchr(after, '\n') = '\0';
		*line = after;
		return (&after[strlen(after) + 1]);
	}
	return (NULL);
}

int				gnl(int fd, char **line)
{
	int				ret;
	char			buff[GNL_BUFF_SIZE + 1];
	static char		*after;

	if (fd <= 0 || fd >= FOPEN_MAX)
		return (-1);
	while ((ret = read(fd, buff, GNL_BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		after = buff;
		if (strchr(after, '\n'))
			break ;
	}
	if ((after = ft_get_after(line, after)))
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi(char const *str)
{
	int		val;
	int		i;
	int		sign;

	i = 0;
	val = 0;
	while (ft_isdigit(str[i]) == 0)
		i++;
	sign = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		val = val * 10 + (str[i++] - '0');
	return (sign * val);
}

char	*ft_strcpy(char *dest, char const *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memset(void *s, int k, size_t n)
{
	size_t			i;
	unsigned char	*c;

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

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size == 0)
		return (NULL);
	if (!(mem = (void*)malloc(size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}

char	*ft_strnew(size_t size)
{
	char	*new;

	new = ft_memalloc(size + 1);
	return (new);
}

size_t	ft_intlen(int nb)
{
	int		len;

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

char	*ft_itoa(int nb)
{
	int		i;
	char	*s;

	i = ft_intlen(nb);
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	if (nb == 0)
	{
		s[0] = 48;
		return (s);
	}
	if (nb == -2147483647 -1)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		i;
	size_t		k;
	size_t		l;
	size_t		len;

	len = strlen(s1);
	l = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	i = strlen(s1) + strlen(s2);
	if (!(new = (char*)malloc(sizeof(char) * (i) + 1)))
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

char	*ft_strdup(char const *src)
{
	char	*src2;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(src2 = (char*)malloc(sizeof(char) * (i + 1))))
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

void	ft_strclr(char *s)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s == NULL)
		return ;
	j = strlen(s);
	while (i < j)
	{
		s[i] = '\0';
		i++;
	}
}