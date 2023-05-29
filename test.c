#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/envir.h"
#include "include/minishell.h"
void leaks(){system("leaks a.out");}

t_global	g_var;
int	main(int ac, char **av, char **env)
{
	t_lexer **test;
	t_lexer *tmp;
	t_env **envar;
	t_simple_cmd **cmds;
	t_simple_cmd *ctmp;
	t_lexer	*rtmp;
	char	*str;
	(void)ac;
	(void)av;
	// printf("%s\n", getenv("PATH"));
	// while (1)
	// {printf("%lu\n", strlen(readline("minishell> ")));}
	while (1)
	{
	str = readline("minishell> ");
	add_history(str);
	// str = "<< ''";
	envar = get_envar(env);
	test = tokenizer(str);
	if (test && test != (t_lexer **)(1))
	{
	tmp = *test;
	while (tmp)
	{
		if (tmp->token == word)
			printf("%d\t%s\tWORD\n", tmp->index, tmp->str);
		if (tmp->token == dbq_word)
			printf("%d\t%s\tDBQ_WORD\n", tmp->index, tmp->str);
		if (tmp->token == sq_word)
			printf("%d\t%s\tSQ_WORD\n", tmp->index, tmp->str);
		if (tmp->token == w_space)
			printf("%d\t%s\tW_SPACE\n", tmp->index, tmp->str);
		if (tmp->token == is_pipe)
			printf("%d\t%s\tPIPE\n", tmp->index, tmp->str);
		if (tmp->token == rd_input)
			printf("%d\t%s\tRD_INPUT\n", tmp->index, tmp->str);
		if (tmp->token == rd_output)
			printf("%d\t%s\tRD_OUTPUT\n", tmp->index, tmp->str);
		if (tmp->token == here_doc)
			printf("%d\t%s\tHERE_DOC\n", tmp->index, tmp->str);
		if (tmp->token == rd_output_apnd)
			printf("%d\t%s\tRD_OUTPUT_APND\n", tmp->index, tmp->str);
		tmp = tmp->next;
	}
	}
	cmds = parser(test, envar, &g_var);
	concatenate(test, cmds);
	get_heredocs(cmds, envar);
	if (cmds)
	{
		ctmp = *cmds;
		while (ctmp)
		{
			printf("Command number : %d\n", ctmp->index);
			rtmp = *(ctmp->redirections);
			while (rtmp)
			{
				printf("rd type : %d\t %s\n", rtmp->token, rtmp->str);
				rtmp = rtmp->next;
			}
			int i = 0;
			if (!ctmp->cmd)
			{
				ctmp = ctmp->next;
				continue ;
			}
			while(ctmp->cmd[i])
			{
				printf("command : %s\n", ctmp->cmd[i]);
				i++;
			}
			ctmp = ctmp->next;
		}
	}
	// tmp = *test;
	// while (tmp)
	// {
	// 	if (tmp->token == word)
	// 		printf("%d\t%s\tWORD\n", tmp->index, tmp->str);
	// 	if (tmp->token == dbq_word)
	// 		printf("%d\t%s\tDBQ_WORD\n", tmp->index, tmp->str);
	// 	if (tmp->token == sq_word)
	// 		printf("%d\t%s\tSQ_WORD\n", tmp->index, tmp->str);
	// 	if (tmp->token == w_space)
	// 		printf("%d\t%s\tW_SPACE\n", tmp->index, tmp->str);
	// 	if (tmp->token == is_pipe)
	// 		printf("%d\t%s\tPIPE\n", tmp->index, tmp->str);
	// 	if (tmp->token == rd_input)
	// 		printf("%d\t%s\tRD_INPUT\n", tmp->index, tmp->str);
	// 	if (tmp->token == rd_output)
	// 		printf("%d\t%s\tRD_OUTPUT\n", tmp->index, tmp->str);
	// 	if (tmp->token == here_doc)
	// 		printf("%d\t%s\tHERE_DOC\n", tmp->index, tmp->str);
	// 	if (tmp->token == rd_output_apnd)
	// 		printf("%d\t%s\tRD_OUTPUT_APND\n", tmp->index, tmp->str);
	// 	tmp = tmp->next;
	// }
	unlink_hd(cmds);
	if (cmds)
		ft_delpall(cmds);
	if (test && test != (t_lexer **)(1))
		ft_deltall(test);
	free(str);
	ft_delvall(envar);
	// leaks();
	}
}