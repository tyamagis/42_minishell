#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "libft/libft.h"

void	put_newline(void)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

void	set_signal_handler(int signo, void *func)
{
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) == -1)
	{
		perror("sigemptyset");
		exit(1);
	}
	sa.sa_handler = func;
	sa.sa_flags = 0;
	if (sigaction(signo, &sa, NULL))
	{
		perror("sigaction");
		exit(1);
	}
}
