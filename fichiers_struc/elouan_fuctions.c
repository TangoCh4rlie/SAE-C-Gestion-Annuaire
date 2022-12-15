#include "SAE_anuaire.h"

int select_line_with_email(entry **tab, char email)
{
	return 0;
}

entry **del_line_tab(entry **tab, int to_del)
{
	int i;
	int length;

	length = tab_length(tab);

	if(to_del < length)
	{
		free(tab[to_del]);
		for(i = to_del; i < length - 1; i++)
		{
			tab[i] = tab[i + 1];
		}
		tab = realloc(tab, sizeof(entry *) * (length - 1));
	}
	printf("\n");
	printf("Ligne supprimé avec succès!");

	return tab;
}