#include <stdio.h>
#include <stdlib.h>

														//decalaration de la structure des données

struct annuaire
{
    //tous les critères 
    char * nom;
    char * prenom;
    char * cp;
    char * ville;
    char * numero_tel;
    char * mail;
    char * profession;
};
typedef struct annuaire anu;

														//fonction permetant de récuperer un element (séparé par uen virgule)
														//ex elouan,reymond,villeurbanne
														//lorsqu'on appelle la fonction celle ci return (un char) elouan si on 
														//la rappelle reymond et ainsi de suite

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

														//fonction ouverture de fichier

int stocktableau(char *namefile){

    FILE* file;											//demander aussi pas tout compris

    int verif;
    char val;

    file = fopen(namefile, "r");						//ouvre le fichier
    char *tmp;											//création de tmp par ce que si on appelle la fonction get_sting
    tmp = get_string(file);								//dans le printf ca fait de la merde je sais pas pourquoi
    printf("%s\n", tmp);

    exit(1);											//kill le programme

    fclose(file);
}

int main(){

    stocktableau("database.csv");						//appelle la fonction stocktabkleau

    return 0;
}
