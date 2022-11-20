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
    entry *result;
    result = malloc(sizeof(entry));
    result->lastname = get_string(file);
    result->firstname = get_string(file);
    result->zipcode = get_string(file);
    result->city = get_string(file);
    result->phone = get_string(file);
    result->mail = get_string(file);
    result->job = get_string(file); 
                                                        //si mail est NULL alors free et + NULL plus message d'erreur 
    return result;                                      //créer fonction () qui check             
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

int parse_tab(char *namefile)
{

    FILE* file;

    entry **result = NULL;
    entry *tmp;
    int select = 0;

    file = fopen(namefile, "r");
                                                    //boucle
    tmp = get_line(file);
    result = add_tab(result, tmp);
    printf("Rentrer l'id de l'utilisateur: ");
    fflush( stdout );
    scanf("%d", &select);
    if(select >= tab_length(result))
    {
        printf("Utilisateur introuvable\n");
        return 1;
    }
    print_entry(result[select]);			

    fclose(file);
}