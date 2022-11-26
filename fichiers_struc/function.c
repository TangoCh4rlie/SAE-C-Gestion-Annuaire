#include "SAE_anuaire.h"

extern entry **result_tab;

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

														//fonction ouverture de fichier
void print_entry(entry *to_print)
{
    printf("Nom: %s\n", to_print->lastname);
    printf("Prenom: %s\n", to_print->firstname);
    printf("Code postal: %s\n", to_print->zipcode);
    printf("Ville: %s\n", to_print->city);
    printf("Téléphone: %s\n", to_print->phone);
    printf("Mail: %s\n", to_print->mail);
    printf("Profession: %s\n", to_print->job);
}

int parse_tab(char *filename)
{

    FILE* file;


    entry *tmp;
    int select = 0;
    int length_tab;
    int good_var = 0;

    file = fopen(filename, "r");
                                                    //boucle
    do
    {
        tmp = get_line(file);
        result_tab = add_tab(result_tab, tmp);
    }
    while(!feof(file));

    length_tab = tab_length(result_tab);

    printf("Il y a %d utilisateurs dans la base de donnée\n", length_tab);

	print_user_line_asked();


    fclose(file);
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
