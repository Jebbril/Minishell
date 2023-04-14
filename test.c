#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "include/lexer.h"

int	main(void)
{
	t_lexer **test;
	t_lexer *tmp;
	while (1)
	{printf("%lu\n", strlen(readline("minishell> ")));}
	test = tokenizer("      s     s");
	tmp = *test;
	while (tmp)
	{
		printf("%d\t%d\n", tmp->index, tmp->token);
		tmp = tmp->next;
	}
}