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
	t_simple_cmd ** cmds;
	char	*str;
	printf("%s\n", getenv("PATH"));
	// while (1)
	// {printf("%lu\n", strlen(readline("minishell> ")));}
	while (1)
	{
	str = readline("minishell> ");
	test = tokenizer(str);
	if (!test)
	{
		printf("error\n");
		return (0);
	}
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
	// printf("%d\n", ft_lasttnode(test)->token);
	cmds = parser(test);
	ft_deltall(test);
	}
}