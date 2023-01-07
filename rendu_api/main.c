#include "headers/api_sae.h"
#include "headers/lecture.h"
#include "headers/tools.h"

int main(void)
{
    int menu = 0;
    printf("Bienvenue dans le gestionnaire d'annuaire\n");
    printf("[1] - Pour faire les tests en boite noire\n");
    printf("[2] - Pour afficher le menu\n");
    printf("Que voulez vous faire -> ");
    scanf("%d", &menu);
    fflush( stdout );
    if (menu == 1)
    {
        afficher_annuaire_client("../annuaire.csv");
        ajouter_client("../annuaire.csv","toto","titi","44444","lyon","000000000000","caca@gmail.com","con");
        supprimer_client("../annuaire.csv", "william.blanchard-foucher@server.fr");
        modifier_mel_client("../annuaire.csv", "william.blanchard-foucher@server.fr", "prout@gmail.com");
        modifier_autres_que_mel_client("../annuaire.csv", "william.blanchard-foucher@server.fr", "prénom", "prout");
//      ajouter_client("../annuaire.csv", "nom", "prénom", "code_postal", "ville", "telephone", "mel", "profession");
//      field_filter("../annuaire.csv", "prénom", "cher");
    }
    else if (menu == 2)
    {
        printf("Menu");
    }
    else
    {
        printf("Commande inconnue");
    }
    return 0;
}