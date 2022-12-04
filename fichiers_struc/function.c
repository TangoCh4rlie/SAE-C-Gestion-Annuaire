#include "SAE_anuaire.h"

char *get_string(FILE * file)
{

    int verif; 
    char *res;         									//création d'un pointeur pour la valeur de retour
    char buf;
    int string_done;    								//varible pour check si il y a un \n une ,
    int i;
    i = 0;
    string_done = 0;
    res = malloc(1);									//cree physiquement res dans la memoire
    while (!feof(file) && !string_done)
    {
        verif = fscanf(file, "%c", &buf);				//fait la verif si c'est bien une lettre
        if (verif == 1 && buf != ',' && buf != '\n')
        {
            res = realloc(res, sizeof(char) * (i + 1)); //le tableau étant dynamique malloc agrandi celui-ci de la taille d'un charactère
            res[i++] = buf;								//ajout la lettre récupéré a la suite du tableau (i++ pour eco une ligne)
        }
        else
            string_done = 1;							//permet de sortir de la boucle si \n ou ,
    }
    res = realloc(res, sizeof(char) * (i + 1));
    res[i] = 0;											//demander a thomas (surement pour pas avoir d'erreur de ortie de tableau)

    return res;
}

entry *get_line(FILE * file)
{
    entry *result_tab;
    result_tab = malloc(sizeof(entry));
    result_tab->lastname = get_string(file);
    result_tab->firstname = get_string(file);
    result_tab->zipcode = get_string(file);
    result_tab->city = get_string(file);
    result_tab->phone = get_string(file);
    result_tab->mail = get_string(file);
    result_tab->job = get_string(file);
                                                        //si mail est NULL alors free et + NULL plus message d'erreur 
    return result_tab;                                      //créer fonction () qui check
}

void print_entry(entry **to_print, int line)
{
    printf("Nom: %s\n", to_print[line]->lastname);
    printf("Prenom: %s\n", to_print[line]->firstname);
    printf("Code postal: %s\n", to_print[line]->zipcode);
    printf("Ville: %s\n", to_print[line]->city);
    printf("Téléphone: %s\n", to_print[line]->phone);
    printf("Mail: %s\n", to_print[line]->mail);
    printf("Profession: %s\n", to_print[line]->job);
}

entry **parse_tab(char *filename)
{
    FILE* file;

    entry *tmp;
	entry **result_tab = NULL;

    file = fopen(filename, "r");

    do
    {
        tmp = get_line(file);
        result_tab = add_tab(result_tab, tmp);
    }
    while(!feof(file));

    fclose(file);

	return result_tab;
}

entry **del_line_tab(entry **tab, int to_del)
{
	int i;
	int length;

	length = tab_length(tab);

	if(to_del < length)
	{
		free(tab[to_del]);
		for(i = to_del; i < length - 1; i++)
		{
			tab[i] = tab[i + 1];
		}
		tab = realloc(tab, sizeof(entry *) * (length - 1));
	}
	printf("\n");
	printf("Ligne supprimé avec succès!");

	return tab;
}

char **get_all_mail(entry **tab)
{
	int i;
	int length_tab;
	char **result_tab;

	length_tab = tab_length(tab);
	result_tab = malloc(sizeof(char *) * length_tab);
	i = 0;
	while(i < length_tab)
	{
		result_tab[i] = tab[i]->mail;
		printf("%s\n", result_tab[i]);
		i++;
	}
	return result_tab;
}

int **check_email_not_same(entry **tab)
{
	int i;
	int j;
	int nb_of_mail = 0;
	int length_tab;

	length_tab = tab_length(tab);

	i = 0;
	while(i < length_tab)
	{
		j = 0;
		while(j < length_tab)
		{
			if(strcmp(tab[i]->mail, tab[j]->mail) == 0 && i != j && i < j && tab[i]->mail != " " && tab[j]->mail != " ")
			{
				printf("L'email %s est le meme ligne %d et ligne %d\n", tab[i]->mail, i, j);
				nb_of_mail++;
			}
			j++;
		}
		i++;
	}
	return 0;
}

void print_user_line (entry **tab)
{
	int user_line = 0;

	printf("Quel utilisateur voulez vous afficher -> ");
	fflush( stdout );
	scanf("%d", &user_line);
	printf("\n");
	print_entry(tab, user_line);
}

void affiche_tab(entry **tab)
{
	int i;
	int length_tab;
	char **result_tab;

	length_tab = tab_length(tab);
	result_tab = malloc(sizeof(char *) * length_tab);
	i = 0;
	while(i < length_tab)
	{
		result_tab[i] = tab[i]->lastname;
		printf("%s\n", result_tab[i]);
		i++;
	}
}

char **get_all_name(entry **tab)
{
	int i;
	int length_tab;
	char **result_tab;

	length_tab = tab_length(tab);
	result_tab = malloc(sizeof(char *) * length_tab);
	i = 0;
	while(i < length_tab)
	{
		result_tab[i] = tab[i]->lastname;
		printf("%s\n", result_tab[i]);
		i++;
	}
	return result_tab;
}

void **trier_clients_par_nom(entry **tab)
{
	int i;
	int j;
	char **tmp;
	int length_tab;

	length_tab = tab_length(tab);

	i = 0;
	while(i < length_tab)
	{
		j = 0;
		while(j < length_tab)
		{
			if(strcmp(tab[i]->lastname, tab[j]->lastname) >= 1 && i != j && i < j)
			{
					tmp=tab[i];
					tab[i]=tab[j];
					tab[j]=tmp;
			}
			j++;
		}
		i++;
	}
	affiche_tab(tab);
	return 0;
}

/* SI strcmp=0 alors = si strcmp=1 alors > (b>a) si strcmp=-1 alors < (a<b) */

/*
- même mail qui n'est pas le même mail
- user_line qui affiche avec 1 de décalage
- les users qui ont un attribut en moins sont décalés
*/

char **get_all_mail_UwU(entry **tab)
{
	int i;
	int length_tab;
	char **result_tab;

	length_tab = tab_length(tab);
	result_tab = malloc(sizeof(char *) * length_tab);
	i = 0;
	while(i < length_tab)
	{
		result_tab[i] = tab[i]->mail;
		printf("%s\n", result_tab[i]);
		i++;
	}
	return result_tab;
}

void modify_client_name(entry **tab,char ancient_mail,char new_mail){
	if 
}