#include "SAE_anuaire.h"

int main(int argc, char **argv)
{
	int length_tab;
	int menu_entry;
	int line_to_delete;
	int end_program = 1;
	entry **result_tab;

    if (argc == 1)
    {
        printf("Aucun fichier n'a été renseigné\n");
        return 1;
    }
    else if(access(argv[1], F_OK) == 1)
    {
        printf("Le fichier spécifié n'a pas pu être trouvé\n");
        return 1;
    }

	result_tab = parse_tab(argv[1]);
	length_tab = tab_length(result_tab);

	while(end_program)
	{
		printf("\n");
		printf("----------------------------------------------------------\n");
		printf("MENU\n");
		printf("1 : Afficher un utilisateur\n");
		printf("2 : Supprimer un utilisateur\n");
		printf("3 : Compter le nombre d'utilisateur dans le fichier\n");
		printf("4 : Verifier qu'il n'y ait pas des utilisateurs avec les mêmes adresses mail\n");
		printf("5 : Affiche tous les noms triés dans l'ordre alphabétique\n");
		printf("12 : Quitter le programme\n");
		printf("----------------------------------------------------------");
		printf("\n");
		printf("Que souhaitez vous faire : ");
		fflush( stdout );
		scanf("%d", &menu_entry);

		switch(menu_entry)
		{
			case 1:
				print_user_line(result_tab);
				break;

			case 2:
				printf("Quel utilisateur voulez vous supprimer : ");
				fflush( stdout );
				scanf("%d", &line_to_delete);
				del_line_tab(result_tab,line_to_delete);
				break;

			case 3:
				printf("\n");
				printf("Il y a %d utilisateurs dans la base de donnée\n", length_tab);
				break;

			case 4:
				printf("\n");
				check_email_not_same(result_tab);
				break;
			
			case 5:
				printf("\n");
				trier_clients_par_nom(result_tab);
				break;

			case 12:
				printf("\n");
				printf("Fin du programme...");
				end_program = 0;
				break;

			default:
				printf("\n");
				printf("Veuillez selectionner numéro correct\n");
		}
	}

    return 0;
}