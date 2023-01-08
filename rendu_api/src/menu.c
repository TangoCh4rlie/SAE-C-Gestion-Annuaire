#include "../headers/api_sae.h"
#include "../headers/ecriture.h"
#include "../headers/lecture.h"
#include "../headers/tools.h"

void affichage_menu();
void print_user_line(char * nom_annuaire);

void menu_presentation(char * nom_annuaire) {

    int exit_menu = 0;
    int menu_entry;
    char user_email[100];
    char new_user_email[100];
    char field[11];
    char new_content_field[100];

    char firstname[100];
    char lastname[100];
    char zipcode[100];
    char city[100];
    char phone[100];
    char mail[100];
    char job[100];

    while (exit_menu == 0)
    {
        affichage_menu();
        printf("Que souhaitez vous faire -> ");
        fflush( stdout );
        scanf(" %d", &menu_entry);

        switch(menu_entry)
        {
            case 0:
                verifier_validite_annuraire_clients(nom_annuaire);
                break;

            //TODO verifier cette fonction
            case 1:
                printf("\n");
                printf("Veuillez rentrer les informations de l'utilisateur à ajouter\n");
                printf("Prénom -> ");
                fflush( stdout );
                scanf("%s", firstname);
                printf("Nom -> ");
                fflush( stdout );
                scanf("%s", lastname);
                printf("Code postal -> ");
                fflush( stdout );
                scanf("%s", zipcode);
                printf("Ville -> ");
                fflush( stdout );
                scanf("%s", city);
                printf("Téléphone -> ");
                fflush( stdout );
                scanf("%s", phone);
                printf("Email -> ");
                fflush( stdout );
                scanf("%s", mail);
                printf("Profession -> ");
                fflush( stdout );
                scanf("%s", job);

                ajouter_client(nom_annuaire, firstname, lastname, zipcode, city, phone, mail, job);
                break;

            case 2:
                printf("Quel email voulez vous modifier -> ");
                fflush( stdout );
                scanf("%s", user_email);
                printf("Par quelle email voulez vous la remplacer -> ");
                fflush( stdout );
                scanf("%s", new_user_email);
                printf("\n");
                modifier_mel_client(nom_annuaire, user_email, new_user_email);
                break;

            case 3:
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
                modifier_autres_que_mel_client(nom_annuaire,user_email, field, new_content_field);
                break;

            case 4:
                printf("Quel utilisateur voulez vous supprimer (renter son adresse E-mail) -> ");
                fflush( stdout );
                scanf("%s", user_email);
                supprimer_client(nom_annuaire, user_email);
                break;

            case 5:
                printf("\n");
                trier_clients_par_nom(nom_annuaire);
                afficher_annuaire_client("resultat_trier_par_nom.txt");
                break;

            case 6:

            case 7:
                printf("\n");
                printf("Cette fonctionnalité n'est pas encore disponible\n");
                break;

            case 8:
                print_user_line(nom_annuaire);
                break;

            case 9:
                printf("\n");
                entry **tab_for_len = parse_tab(nom_annuaire);
                printf("Il y a %d utilisateurs dans la base de donnée\n", tab_length(tab_for_len));
                free(tab_for_len);
                break;

            case 10:
                printf("\n");
                afficher_annuaire_client(nom_annuaire);
                break;

            case 12:
                printf("\n");
                printf("Fin du programme...");
                exit_menu = 1;
                break;

            default:
                printf("\n");
                printf("Veuillez sélectionner numéro correct\n");
        }
    }
}

void affichage_menu()
{
    printf("\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("| MENU                                                                             |\n");
    printf("|                                                                                  |\n");
    printf("| 0 : Vérifier la validité de l'annuaire sélectionné                               |\n");
    printf("| 1 : Ajouter un client                                                            |\n");
    printf("| 2 : Modifier le mail d'un utilisateur                                            |\n");
    printf("| 3 : Modifier un autre champ de que le mail d'un utilisateur                      |\n");
    printf("| 4 : Supprimer un utilisateur                                                     |\n");
    printf("| 5 : Afficher les utilisateurs triés par prenom                                   |\n");
    printf("| 6 : Afficher les clients dont certains champs sont maquant                       |\n");
    printf("| 7 : Filtrer un champ                                                             |\n");
    printf("| 8 : Afficher un utilisateurs                                                     |\n");
    printf("| 9 : Compter le nombre d'utilisateur dans le fichier                              |\n");
    printf("| 10 : Afficher l'entièreté de l'annuaire                                          |\n");
    printf("| 12 : Quitter le programme                                                        |\n");
    printf("------------------------------------------------------------------------------------\n");
}

void print_user_line(char * nom_annuaire)
{
    int user_line = 0;
    int user_not_find = 0;

    entry ** tab = parse_tab(nom_annuaire);
    int length_tab = tab_length(tab);

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
    afficher_utilisateur(tab, user_line - 1);
    free(tab);
}