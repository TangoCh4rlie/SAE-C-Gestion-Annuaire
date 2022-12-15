#include "SAE_anuaire.h"

int tab_length(entry **tab)
{
    int i = 0;

    while (tab != NULL && tab[i] != 0)                          //différent de false null ou 0
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

void display_menu()
{
	printf("\n");
	printf("----------------------------------------------------------\n");
	printf("MENU\n");
	printf("1 : Afficher un utilisateur\n");
	printf("2 : Supprimer un utilisateur\n");
	printf("3 : Compter le nombre d'utilisateur dans le fichier\n");
	printf("4 : Verifier qu'il n'y ait pas des utilisateurs avec les mêmes adresses mail\n");
    printf("5 : Ratio\n");
    printf("6 : Affiche mail\n");
	printf("12 : Quitter le programme\n");
	printf("----------------------------------------------------------");
	printf("\n");
}

void print_user_line (entry **tab)
{
	int user_line = 0;

	printf("Quel utilisateur voulez vous afficher -> ");
	fflush( stdout );
	scanf("%d", &user_line);
	printf("\n");
	print_entry_all(tab, user_line);
}