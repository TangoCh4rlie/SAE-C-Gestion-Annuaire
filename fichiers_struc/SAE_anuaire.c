#include "SAE_anuaire.h"

int main(int argc, char **argv)
{
	int length_tab;
	entry **result_tab;

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

	result_tab = parse_tab(argv[1]);

	length_tab = tab_length(result_tab);

	printf("Il y a %d utilisateurs dans la base de donnée\n", length_tab);

	check_email_not_same(result_tab);
    return 0;
}