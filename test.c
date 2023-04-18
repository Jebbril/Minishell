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
	// while (1)
	// {printf("%lu\n", strlen(readline("minishell> ")));}
	test = tokenizer("s | < ><<>>ss    'ss'  ss ss  s");
	if (!test)
	{
		printf("error\n");
		return (0);
	}
	tmp = *test;
	while (tmp)
	{
		printf("%d\t%s\t%d\n", tmp->index, tmp->str, tmp->token);
		tmp = tmp->next;
	}
	ft_deltall(test);
}