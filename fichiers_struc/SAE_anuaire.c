#include "SAE_anuaire.h"

int main(int argc, char **argv)
{
	int length_tab;
	int menu_entry;
	char user_email[100];
	int index_tab;
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
		display_menu();
		printf("Que souhaitez vous faire -> ");
		fflush( stdout );
		scanf(" %d", &menu_entry);

		switch(menu_entry)
		{
			case 1:
				print_user_line(result_tab, length_tab);
				break;

			case 2:
				printf("Quel utilisateur voulez vous supprimer (renter son adresse E-mail) -> ");
				fflush( stdout );
				scanf("%s", user_email);
				index_tab = select_line_with_email(result_tab,user_email);
				printf("\n%d", index_tab);
				del_line_tab(result_tab, index_tab);
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

			case 6:
				printf("\n");
				get_all_mail(result_tab);
				break;

			case 7:
				printf("\n");
				modify_client_mail(result_tab, "roland.lambert@server.fr", "cacaboudin");
				break;

			case 12:
				printf("\n");
				printf("Fin du programme...");
				end_program = 0;
				break;

			default:
				printf("\n");
				printf("Veuillez sélectionner numéro correct\n");
		}
	}

    return 0;
}