#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	while (1)
	{printf("%lu\n", strlen(readline("minishell> ")));}
}