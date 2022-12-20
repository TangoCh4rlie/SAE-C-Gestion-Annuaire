#include "SAE_anuaire.h"

entry **del_line_tab(entry **tab, char* user_email)
{
	int i;
	int length;
	int index_to_del;

	index_to_del = select_line_with_email(tab,user_email);
	length = tab_length(tab);

	if (index_to_del == -1)
	{
		printf("L'utilisateur n'a pas été trouvé");
		return tab;
	}

	if(index_to_del < length)
	{
		free(tab[index_to_del]);
		for(i = index_to_del; i < length - 1; i++)
		{
			tab[i] = tab[i + 1];
		}
		tab = realloc(tab, sizeof(entry *) * (length - 1));
	}
	printf("\n");
	printf("Ligne supprimé avec succès!");

	return tab;
}

//TODO VOIR POUR LES CONST
entry **modify_client_mail(entry **tab, const char *old_email, char *new_email)
{
	int old_email_exist;
	int valid = check_email_validity(new_email);

	old_email_exist = select_line_with_email(tab,old_email);

	if (old_email_exist == -1)
	{
		printf("L'adresse mail sélectionné n'a pas pu être trouvé, veuillez recommencer");
		return tab;
	}
	if (select_line_with_email(tab,new_email) != -1)
	{
		printf("L'adresse mail rentré existe déjà, veuillez recommencer");
		return tab;
	}
	//TODO Faire une alocation dynamique pour la nouvelle adresse mail sinon segfault si > 100
	if (strlen(new_email) > 100)
	{
		printf("L'adresse mail rentré est trop longue, veuillez recommencer");
		return tab;
	}
	if (valid == 0)
	{
		printf("L'adresse mail rentré n'est pas valide, veuillez recommencer");
		return tab;
	}
	else
	{
		int line_to_del;
		line_to_del = select_line_with_email(tab, old_email);
		tab[line_to_del]->mail = new_email;
		printf("L'email a bien été changé !\n");
	}

	return tab;
}

entry **modify_client_field(entry **tab, const char *old_email, const char *new_email)
{

}