#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "libft/libft.h"

int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strndup(char const *src, size_t n);
void	put_newline();
void	set_signal_handler(int signo, void *func);

int	shell_init()
{
	// SIGINTとSIGQUITを手当てする
	set_signal_handler(SIGINT, put_newline);
	set_signal_handler(SIGQUIT, SIG_IGN);
	// environから環境変数を取得する
	// ※OLDDIRは引き継がない
	// カレントディレクトリを取得しPWDに格納する
}

int	main(int argc, char** argv) {
	char	*input;

	shell_init();
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
