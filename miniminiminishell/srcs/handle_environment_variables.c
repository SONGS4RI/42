#include "../includes/miniminiminishell.h"

char    *get_env(char *name)
{
    char    *env_variable;

    env_variable = getenv(name);
    free(name);
    return (env_variable);
}
