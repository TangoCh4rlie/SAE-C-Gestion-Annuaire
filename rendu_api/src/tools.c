#include "../headers/api_sae.h"

int tab_length(entry **tab)
{
	int i = 0;

	while (tab != NULL && tab[i] != 0)
		i++;

	return i;
}

entry **add_tab(entry **tab, entry *to_tab)
{
	int length = tab_length(tab);

	if (tab == NULL)
		tab = malloc(1);

	tab = realloc(tab, sizeof(entry*) * (length + 2)); //pour les deux \0
	tab[length++] = to_tab;
	tab[length] = NULL;

	return tab;

}

int select_line_with_email(entry **tab, const char* email)
{
	int i = 0;
	int n = tab_length(tab);
	int cmp;
	int index_tab = -1;

	while (i < n)
	{
		cmp = strcmp(tab[i]->mail, email);
		if (cmp == 0)
			index_tab = i;
		i++;
	}
	return index_tab;
}

int check_email_validity(char *email)
{
	int i = 0;
	int at = 0;
	int dot = 0;
	int dot_pos = 0;
	unsigned int len = strlen(email);

	if (email[0] == '@' || email[0] == '.')
		return 0;

	while (i < len)
	{
		if (email[i] == '@')
		{
			at++;
		}
		if (email[i] == '.')
		{
			dot++;
			dot_pos = i;
		}
		i++;
	}

	if (at != 1)
		return 0;

	if (dot_pos == len - 1)
		return 0;

	return 1;
}
