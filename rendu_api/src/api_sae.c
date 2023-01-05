#include "../headers/api_sae.h"
#include "../headers/tools.h"
#include "../headers/lecture.h"
#include "../headers/ecriture.h"


//Fonction Elouan

void supprimer_client(char * nom_annuaire, const char* mel_p)
{
	int i;
	int length;
	int index_to_del;

    entry ** result_tab = parse_tab(nom_annuaire);

	index_to_del = select_line_with_email(result_tab,mel_p);
	length = tab_length(result_tab);

	if (index_to_del == -1)
	{
		printf("L'utilisateur n'a pas été trouvé");
		return;
	}

	if(index_to_del < length)
	{
		free(result_tab[index_to_del]);
		for(i = index_to_del; i < length - 1; i++)
		{
			result_tab[i] = result_tab[i + 1];
		}
		result_tab = (entry**) realloc(result_tab, sizeof(entry *) * (length - 1));
        if (result_tab == NULL)
        {
            printf("Erreur d'alllocation mémoire");
            return;
        }
	}
    printf("L'utilisateur a bien été supprimé\n");

    write_content_new_file(result_tab, "resultat_supprimer.txt");

    free(result_tab);
}

void modifier_mel_client(char * nom_annuaire, const char * mel_p, const char * nv_mel_p)
{
	int old_email_exist;
	int valid = check_email_validity(nv_mel_p);
    entry ** result_tab = parse_tab(nom_annuaire);

	old_email_exist = select_line_with_email(result_tab,mel_p);

	if (old_email_exist == -1)
	{
		printf("L'adresse mail sélectionné n'a pas pu être trouvé, veuillez recommencer");
		return;
	}
	if (select_line_with_email(result_tab,nv_mel_p) != -1)
	{
		printf("L'adresse mail rentré existe déjà, veuillez recommencer");
		return;
	}
	//TODO Faire une alocation dynamique pour la nouvelle adresse mail sinon segfault si > 100
	if (strlen(mel_p) > 100)
	{
		printf("L'adresse mail rentré est trop longue, veuillez recommencer");
		return;
	}
	if (valid == 0)
	{
		printf("L'adresse mail rentré n'est pas valide, veuillez recommencer");
		return;
	}
	else
	{
		int line_to_del;
		line_to_del = select_line_with_email(result_tab, mel_p);
		result_tab[line_to_del]->mail = (char*) nv_mel_p;
		printf("L'email a bien été changé !\n");
	}

    write_content_new_file(result_tab, "resultat_modifier_mel.txt");

    free(result_tab);
}

//TODO toujours les pb avec les const
//entry **modify_client_field(entry **tab, const char *email, const char *field_name, char *new_var)
//{
//	int line = select_line_with_email(tab, email);
//	if (line == -1)
//		printf("L'adresse mail %s n'a pas été trouvé dans l'annuaire", email);
//	else if(stricmp(field_name, "prénom") == 0)
//	{
//		tab[line]->firstname = new_var;
//		printf("Le prénom à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "nom") == 0)
//	{
//		tab[line]->lastname = new_var;
//		printf("Le nom à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "code-postal") == 0)
//	{
//		tab[line]->zipcode = new_var;
//		printf("Le code postal à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "ville") == 0)
//	{
//		tab[line]->city = new_var;
//		printf("La ville à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "téléphone") == 0)
//	{
//		tab[line]->phone = new_var;
//		printf("Le numéro de téléphone à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "email") == 0)
//	{
//		tab[line]->mail = new_var;
//		printf("Le mail à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "profession") == 0)
//	{
//		tab[line]->job = new_var;
//		printf("La profession à bien été changé par %s", new_var);
//	}
//	else
//		printf("Le nom du champ renseigné n'est pas correct");
//
//	return tab;
//}
//
//int field_filter(entry **tab, const char *field_name, char *string)
//{
//	if(stricmp(field_name, "prénom") == 0)
//	{
//		//generate a function to filter the tab with the firstname
//		int i;
//		int length = tab_length(tab);
//		for (i = 0; i < length; i++)
//		{
//			if (stricmp(tab[i]->firstname, string) == 0) {
//				printf("Prénom : %s", tab[i]->firstname);
//			}
//		}
//		int len = tab_length(tab);
//		printf("%d\n", len);
//		fflush( stdout );
//
//		unsigned int string_len = strlen(string);
//		printf("%d\n", string_len);
//		fflush( stdout );
//
//		char *filtered_items[len];
//		int num_filtered_items = 0;
//
//		for (int i = 0; i < len; i++)
//		{
//			char* tmp = tab[i]->firstname;
//			unsigned int item_len = strlen(tmp);
//			printf("Test 2 _____________\n");
//			printf("%d\n", i);
//			fflush( stdout );
//
//			for (int j = 0; j < item_len - string_len + 1; j++)
//			{
//				if (strncmp(tmp, string, string_len) == 0)
//				{
//					filtered_items[num_filtered_items] = tmp;
//					num_filtered_items++;
//					break;
//				}
//			}
//		}
//		for (int i = 0; i < num_filtered_items; i++)
//			printf("%s\n", filtered_items[i]);
//	}
//	else if(stricmp(field_name, "nom") == 0)
//	{
//		tab[line]->lastname = new_var;
//		printf("Le nom à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "code-postal") == 0)
//	{
//		tab[line]->zipcode = new_var;
//		printf("Le code postal à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "ville") == 0)
//	{
//		tab[line]->city = new_var;
//		printf("La ville à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "téléphone") == 0)
//	{
//		tab[line]->phone = new_var;
//		printf("Le numéro de téléphone à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "email") == 0)
//	{
//		tab[line]->mail = new_var;
//		printf("Le mail à bien été changé par %s", new_var);
//	}
//	else if(stricmp(field_name, "profession") == 0)
//	{
//		tab[line]->job = new_var;
//		printf("La profession à bien été changé par %s", new_var);
//	}
//	else
//		printf("Le nom du champ renseigné n'est pas correct");
//
//	return 0;
//}