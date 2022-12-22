#include "SAE_anuaire.h"

//TODO Rajouter des asserts mais questionner car kill le prog

int main(int argc, char **argv)
{




	int length_tab;
	int menu_entry;
	char user_email[100];
	char new_user_email[100];
	int end_program = 1;
	entry **result_tab;
	char field[11];
	char new_content_field[100];

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
				del_line_tab(result_tab, user_email);
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
				printf("Quel email voulez vous modifier -> ");
				fflush( stdout );
				scanf("%s", user_email);
				printf("Par quelle email voulez vous la remplacer -> ");
				fflush( stdout );
				scanf("%s", new_user_email);
				printf("\n");
				modify_client_mail(result_tab, user_email, new_user_email);
				break;

			case 8:
				printf("\n");
				printf("Les champs dispnibles sont:\n");
				printf("\t[prénom]\n");
				printf("\t[nom]\n");
				printf("\t[code-postal]\n");
				printf("\t[ville]\n");
				printf("\t[téléphone]\n");
				printf("\t[email]\n");
				printf("\t[profession]\n");
				printf("Quel champ voulez-vous modifier -> ");
				fflush( stdout );
				scanf("%s", field);
				printf("De quel utilisateur voulez-vous modifier le champ %s (rentrer son adresse mail) -> ", field);
				fflush( stdout );
				scanf("%s", user_email);
				printf("Par quelle valeur voulez-vous remplacer l'ancienne -> ");
				fflush( stdout );
				scanf("%s", new_content_field);
				modify_client_field(result_tab,user_email, field, new_content_field);
				break;

			case 9:
				printf("\n");
				print_entry_all(result_tab, 0);
				printf("\n");
				print_entry_all(result_tab, 1);
				printf("\n");
				print_entry_all(result_tab, 2);
				printf("\n");
				break;

			case 99:
				write_content_new_file(result_tab);
				printf("\n");
				printf("Fin du programme...");
				end_program = 0;
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