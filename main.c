#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "libft/libft.h"

int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strndup(char const *src, size_t n);

int	main(int argc, char** argv) {
	char	*input;

	while (1) {
		// readlineを利用して入力を取得
		input = readline("minishell> ");
		// Ctrl-Dまたは"exit"で終了する
		if (input == NULL || strcmp(input, "exit") == 0)
		{
			printf("exit\n");
			break ;
		}
		// 空行の場合は履歴に加えない
		if (ft_strcmp(input, "") != 0)
			add_history(input);
		free(input);
	}
	free(input);
	return (0);
}
