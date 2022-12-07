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
//int print_user_line_asked()
//{
//	int good_var = 0;
//	int select = 0;
//	int length_tab;
//
//	length_tab = tab_length(result_tab);
//
//	while(!good_var)
//	{
//		printf("\n");
//		printf("Rentrer l'id de l'utilisateur: ");
//		fflush( stdout );
//		scanf("%d", &select);
//		if(select >= length_tab || select < 0)
//		{
//			printf("\n");
//			printf("---Utilisateur introuvable---");
//			printf("\n");
//		}
//		else
//		{
//			printf("\n");
//			printf("--------------------------------------------\n");
//			print_entry(result_tab[select-1]);
//			printf("--------------------------------------------\n");
//			good_var = 1;
//		}
//
//	}
//	return 0;
//}