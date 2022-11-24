#include "SAE_anuaire.h"

int main(int argc, char **argv)
{
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
    parse_tab(argv[1]);						//appelle la fonction stocktabkleau
                                           //check le nombre d'arg stocké dans le argc puis fonction check si le fichier de argv[1] existe

    return 0;
}