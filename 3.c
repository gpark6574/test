#include <unistd.h>

int board[11];
const int MAX = 11;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_put_nbr(int i)
{
	if (i < 10)
		write(1, &"0123456789"[i], 1);
	else if (i == 10)
		write(1, "10", 2);
}

int fu_abs(int a, int b)
{
	if (a < b)
		return b - a;
	else
		return a - b;
}

int promising(int level)
{
	int i;

	i = 1;
	while (i < level)
	{
		if (board[i] == board[level])
			return 0;
		else if (fu_abs(level, i) == fu_abs(board[level], board[i]))
			return 0;
		i++;
	}
	return 1;
}

int queens(int level)
{
	int i;

	if (!(promising(level)))
		return 0;
	else if (level == MAX - 1)
	{
		i = 1;
		while (i < MAX)
		{
			ft_put_nbr(board[i]);
			ft_putchar(32);
			i++;
		}
		ft_putchar('\n');
	}
	i = 1;
	while (i < MAX)
	{
		board[level + 1] = i;
		if (queens(level + 1))
			return 1;
		i++;
	}
	return 0;
}

int main() {
	queens(0);
	return 0;
}
