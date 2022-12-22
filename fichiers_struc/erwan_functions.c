#include "SAE_anuaire.h"

char **get_all_mail(entry **tab)
{
	int i;
	int length_tab;
	char **result_tab;

	length_tab = tab_length(tab);
	result_tab = malloc(sizeof(char *) * length_tab);
	i = 0;
	while(i < length_tab)
	{
		result_tab[i] = tab[i]->mail;
		printf("%s\n", result_tab[i]);
		i++;
	}
	return result_tab;
}

void **trier_clients_par_nom(entry **tab)
{
	int i;
	int j;
	entry *tmp;
	int length_tab;

	length_tab = tab_length(tab);

	i = 0;
	while(i < length_tab)
	{
		j = 0;
		while(j < length_tab)
		{
			if(stricmp(tab[i]->lastname, tab[j]->lastname) >= 1 && i != j && i < j)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	Color12(6,0);
	printf("Les ");
	Color12(4,0);
	printf("clients ");
	Color12(6,0);
	printf("ont bien été triés par ");
	Color12(5,0);
	printf("nom");
	Color12(15,0);
	return 0;
}

void display_tab(entry **tab)
{
	int i;
	int length_tab;
	char **result_tab;

	length_tab = tab_length(tab);
	result_tab = malloc(sizeof(char *) * length_tab);
	i = 0;
	while(i < length_tab)
	{
		result_tab[i] = tab[i]->lastname;
		printf("%s\n", result_tab[i]);
		i++;
	}
}

/* SI strcmp=0 alors = si strcmp=1 alors > (b>a) si strcmp=-1 alors < (a<b) */

/*
TODO même mail qui n'est pas le même mail
 TODO email pas vide
- les users qui ont un attribut en moins sont décalés
*/