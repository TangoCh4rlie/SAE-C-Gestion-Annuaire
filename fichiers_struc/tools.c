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
	printf("------------------------------------------------------------------------------------\n");
	printf("| MENU                                                                             |\n");
	printf("|                                                                                  |\n");
	printf("| 1 : Afficher un utilisateur                                                      |\n");
	printf("| 2 : Supprimer un utilisateur                                                     |\n");
	printf("| 3 : Compter le nombre d'utilisateur dans le fichier                              |\n");
	printf("| 4 : Verifier qu'il n'y ait pas des utilisateurs avec les mêmes adresses mail     |\n");
    printf("| 5 : Trier les clients par nom                                                    |\n");
    printf("| 6 : Affiche tous les mails des utilisateurs présent dans la base de donnée       |\n");
	printf("| 7 : Changer l'email d'un utilisateur                                             |\n");
	printf("| 8 : Changer le champ quelconque                                                  |\n");
	printf("| 9 : Debug 3 first line                                                           |\n");
	printf("| 10 : Filtre                                                                      |\n");
	printf("| 11 : new line                                                                    |\n");
	printf("| 99 : Ecrire le nouvel annuaire dans un fichier (après modifications)             |\n");
	printf("| 12 : Quitter le programme                                                        |\n");
	printf("------------------------------------------------------------------------------------\n");
}

void print_user_line (entry **tab, int length_tab)
{
	int user_line = 0;
	int user_not_find = 0;

	do{
		if (user_not_find == 1)
		{
			printf("L'utilisateur n'a pas été trouvé");
			printf("\n");
		}

		printf("Quel utilisateur voulez vous afficher -> ");
		fflush( stdout );
		scanf("%d", &user_line);
		user_not_find = 1;

	} while (user_line < 1 || user_line > length_tab);

	printf("\n");
	print_entry_all(tab, user_line - 1);
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

void Color12(int clrtxt,int clrfond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,clrfond*16+clrtxt);
}

//TODO La fonction ne permet pas de check si il n'y a pas de points après le @ A REVOIR
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
