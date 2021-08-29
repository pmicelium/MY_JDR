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

// GNL //

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
