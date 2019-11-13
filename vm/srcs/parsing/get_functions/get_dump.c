#include "corewar.h"

void		get_dump(t_parser *parser, char **av)
{
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		parser->env.cycles_to_dump = ft_atol(*av);
		if (parser->env.cycles_to_dump >= 0
				&& parser->env.cycles_to_dump <= INT_MAX)
			parser->state = S_OPTION;
	}
	else
		parser->state = S_ERR;
}
