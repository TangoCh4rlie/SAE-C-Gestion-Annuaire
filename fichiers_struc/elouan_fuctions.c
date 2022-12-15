#include "SAE_anuaire.h"

int select_line_with_email(entry **tab, char* email)
{
	int i = 0;
	int n = tab_length(tab);
	int cmp = -1;
	int index_tab = 0;

	while (i < n)
	{
		cmp = strcmp(tab[i]->mail, email);
		if (cmp == 0)
			index_tab = i + 1;
		i++;
	}
	return index_tab;
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