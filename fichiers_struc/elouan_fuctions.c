#include "SAE_anuaire.h"

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

entry **modify_client_mail(entry **tab, char *old_email, char *new_email){

	int line_to_del;
	line_to_del = select_line_with_email(tab, old_email);
	tab[line_to_del - 1]->mail = new_email;

	return tab;
}