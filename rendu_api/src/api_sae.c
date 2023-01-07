#include "../headers/api_sae.h"
#include "../headers/tools.h"
#include "../headers/lecture.h"
#include "../headers/ecriture.h"


//Fonction Elouan

void supprimer_client(const char * nom_annuaire, const char* mel_p)
{
	int i;
	int length;
	int index_to_del;

    verifier_validite_annuraire_clients(nom_annuaire);

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

    ecriture_annuaire_clients(result_tab, "resultat_supprimer.txt");

    free(result_tab);
}

void modifier_mel_client(const char * nom_annuaire, const char * mel_p, const char * nv_mel_p)
{
	int old_email_exist;
	int valid = check_email_validity(nv_mel_p);

    verifier_validite_annuraire_clients(nom_annuaire);

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

    ecriture_annuaire_clients(result_tab, "resultat_modifier_mel.txt");

    free(result_tab);
}

void modifier_autres_que_mel_client(const char * nom_annuaire, const char * mel_p, const char * nom_champ, const char * nv_valeur)
{
    verifier_validite_annuraire_clients(nom_annuaire);
    entry ** result_tab = parse_tab(nom_annuaire);
	int line = select_line_with_email(result_tab, mel_p);
	if (line == -1)
		printf("L'adresse mail %s n'a pas été trouvé dans l'annuaire", mel_p);
	else if(strcmp(nom_champ, "prénom") == 0)
	{
		result_tab[line]->firstname = (char*) nv_valeur;
		printf("Le prénom à bien été changé par %s", nv_valeur);
	}
	else if(strcmp(nom_champ, "nom") == 0)
	{
		result_tab[line]->lastname = (char*) nv_valeur;
		printf("Le nom à bien été changé par %s", nv_valeur);
	}
	else if(strcmp(nom_champ, "code-postal") == 0)
	{
		result_tab[line]->zipcode = (char*) nv_valeur;
		printf("Le code postal à bien été changé par %s", nv_valeur);
	}
	else if(strcmp(nom_champ, "ville") == 0)
	{
		result_tab[line]->city = (char*) nv_valeur;
		printf("La ville à bien été changé par %s", nv_valeur);
	}
	else if(strcmp(nom_champ, "téléphone") == 0)
	{
		result_tab[line]->phone = (char*) nv_valeur;
		printf("Le numéro de téléphone à bien été changé par %s", nv_valeur);
	}
	else if(strcmp(nom_champ, "email") == 0)
	{
		result_tab[line]->mail =(char*)  (char*) nv_valeur;
		printf("Le mail à bien été changé par %s", nv_valeur);
	}
	else if(strcmp(nom_champ, "profession") == 0)
	{
		result_tab[line]->job = (char*) nv_valeur;
		printf("La profession à bien été changé par %s", nv_valeur);
	}
	else
		printf("Le nom du champ renseigné n'est pas correct\n");

    ecriture_annuaire_clients(result_tab, "resultat_modifier_autres_que_mel.txt");
    fflush(stdout);

    free(result_tab);
}

//TODO Faire la fonction filtre from scratch
//TODO verifier que le fichier est conforme pas double email et email not empty

//void field_filter(const char * nom_annuaire, const char *nom_champ, const char *val_chaine)
//{
//    entry ** result_tab = parse_tab(nom_annuaire);
//	if(strcmp(nom_champ, "prénom") == 0)
//	{
//
//	}
//	else if(stricmp(field_name, "nom") == 0)
//	{
//		result_tab[line]->lastname = new_var;
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

void ajouter_client(const char *nom_annuaire, const char *nom_p, const char *prenom_p, const char *code_postal_p, const char *ville_p, const char *telephone_p, const char *mel_p, const char *profession_p)
{
    FILE * file_out;
    entry **tab=parse_tab(nom_annuaire);
    file_out = fopen("resultat_ajouter.txt","a");
    fprintf(file_out,"%s,",nom_p);
    fprintf(file_out,"%s,",prenom_p);
    fprintf(file_out,"%s,",code_postal_p);
    fprintf(file_out,"%s,",ville_p);
    fprintf(file_out,"%s,",telephone_p);
    fprintf(file_out,"%s,",mel_p);
    fprintf(file_out,"%s,",profession_p);
    ecriture_annuaire_clients(tab,"resultat_ajouter.txt");
    if(check_email_validity(mel_p)==0)
    {
        printf("Il n'y a pas d'adresse mail, merci d'en rajouter une");
    }
    fclose(file_out);
    printf("La ligne a été ajoutée avec succès !\n");

    free(tab);
}