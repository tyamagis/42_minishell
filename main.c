#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "libft/libft.h"
#include "alist.h"

int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strndup(char const *src, size_t n);
void	put_newline(void);
void	set_signal_handler(int signo, void *func);

typedef struct s_info {
	int		last_result;
	t_alist	*env_list;
}	t_info;

t_info	g_info = {0};

void	exec_builtin_env(t_alist *env_list)
{
	while (env_list)
	{
		printf("%s=%s\n", env_list->key, env_list->value);
		env_list = env_list->next;
	}
}

t_alist	*init_env_values(char **env)
{
	t_alist	*head;
	char	*key;
	char	*eq_pos;

	head = NULL;
	while (*env)
	{
		eq_pos = ft_strchr(*env, '=');
		key = ft_strndup(*env, eq_pos - *env);
		if (key == NULL)
			exit(1);
		if (ft_strcmp(key, "OLDPWD") != 0)
			head = add_new_alist(head, key, eq_pos + 1);
		free(key);
		env++;
	}
	return (head);
}

int	shell_init(void)
{
	extern char	**environ;

	// SIGINTとSIGQUITを手当てする
	set_signal_handler(SIGINT, put_newline);
	set_signal_handler(SIGQUIT, SIG_IGN);
	// environから環境変数を取得する
	g_info.env_list = init_env_values(environ);
	// ※OLDDIRは引き継がない
	// カレントディレクトリを取得しPWDに格納する
}

int	main(int argc, char **argv)
{
	char	*input;

	shell_init();
	while (1)
	{
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
		// envコマンド簡易実装
		if (ft_strcmp(input, "env") == 0)
			exec_builtin_env(g_info.env_list);
		free(input);
	}
	free(input);
	free_alist(g_info.env_list);
	return (0);
}
