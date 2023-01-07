#include "../headers/lecture.h"
#include "../headers/tools.h"

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

entry **parse_tab(const char *filename)
{
	FILE* file_in;

	entry *tmp;
	entry **result_tab = NULL;

	file_in = fopen(filename, "r");
	if(!file_in) {
		perror("File opening failed");
		exit(EXIT_FAILURE);
	}

	do
	{
		tmp = get_line(file_in);
		result_tab = add_tab(result_tab, tmp);
	}
	while(!feof(file_in));

	fclose(file_in);

	return result_tab;
}

//TODO Warnings lignes 94 pas compris

int check_email_not_same(entry **tab)
{
	int i;
	int j;
	int length_tab;
    int annuaire_valid = 0;

	length_tab = tab_length(tab);

	i = 0;
	while(i < length_tab)
	{
		j = 0;
		while(j < length_tab)
		{
			if(strcmp(tab[i]->mail, tab[j]->mail) == 0 && i != j && i < j)
			{
				printf("L'email %s est le meme ligne %d et ligne %d\n", tab[i]->mail, i, j);
                annuaire_valid = 1;
			}
			j++;
		}
		i++;
	}
    if (annuaire_valid == 0)
        printf("L'annuaire est valide\n");

    if (annuaire_valid == 1)
    {
        printf("L'annuaire n'est pas valide\n");
        exit(EXIT_FAILURE);
    }
	return 0;
}

//the email can't be empty and can't be the same
void verifier_validite_annuraire_clients(const char * nom_annuaire)

{
    int i;
    int length_tab;
    int error;
    entry **tab;

    tab = parse_tab(nom_annuaire);
    length_tab = tab_length(tab);

    i = 0;
    while(i < length_tab)
    {
        if(strcmp(tab[i]->mail, " ") == 0 || strcmp(tab[i]->mail, "") == 0)
        {
            printf("L'email de la ligne %d est vide\n", i);
            error = 1;
        }
        i++;
    }
    if(error == 1)
    {
        printf("Le fichier n'est pas conforme\n");
        exit(EXIT_FAILURE);
    }
    check_email_not_same(tab);
}