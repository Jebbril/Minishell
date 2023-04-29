#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "include/lexer.h"
#include "include/parser.h"
void leaks(){system("leaks a.out");}
int	main(void)
{
	t_lexer **test;
	t_lexer *tmp;
	t_simple_cmd **cmds;
	t_simple_cmd *ctmp;
	char	*str;
	// printf("%s\n", getenv("PATH"));
	// while (1)
	// {printf("%lu\n", strlen(readline("minishell> ")));}
	while (1)
	{
	str = readline("minishell> ");
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
		if (tmp->token == pipe)
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
	cmds = parser(test);
	if (cmds)
	{
		ctmp = *cmds;
		while (ctmp)
		{
			printf("Command number : %d\n", ctmp->index);
			ctmp = ctmp->next;
		}
	}
	if (cmds)
		ft_delpall(cmds);
	if (test && test != (t_lexer **)(1))
		ft_deltall(test);
	free(str);
	// leaks();
	}
}