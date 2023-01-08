#include "headers/api_sae.h"
#include "headers/lecture.h"
#include "headers/tools.h"
#include "headers/menu.h"

void test_boite_noire();

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
        test_boite_noire();
    }
    else if (menu == 2)
    {
        char nom_annuraire[100];
        printf("Sur quel annuaire souhaitez-vous travailler ->");
        fflush(stdout);
        scanf("%s", nom_annuraire);
        menu_presentation(nom_annuraire);
    }
    else
    {
        printf("Commande inconnue");
    }
    return 0;
}

void test_boite_noire() {
    //Toous les champs sont remplis et corrects
    assert(ajouter_client("../annuaire.csv","toto","titi","44444","lyon","000000000000","test@gmail.com","boulager") == 0);
    //Le champ mal_p est vide
    assert(ajouter_client("../annuaire.csv","toto","titi","44444","lyon","000000000000","","boulager") == 1);
    //tous les champs sont vides mais le mail est repli
    assert(ajouter_client("../annuaire.csv","","","","","","test@gmail.com","") == 0);

    assert(trier_clients_par_nom("../annuaire.csv") == 0);
    //Les mail n'est pas valide
    assert(supprimer_client("../annuaire.csv","existe.pas@gmail.com") == 1);
    //Le mail est valide
    assert(supprimer_client("../annuaire.csv","william.blanchard-foucher@server.fr") == 0);
    //Le mail n'est pas valide car  il n'existe pas
    assert(modifier_mel_client("../annuaire.csv","exist.pas@gmail.com","nouveau@gmail.com") == 1);
    //L'email existe déja
    assert(modifier_mel_client("../annuaire.csv","william.blanchard-foucher@server.fr","william.blanchard-foucher@server.fr") == 1);
    //L'email est trop long
    assert(modifier_mel_client("../annuaire.csv","william.blanchard-foucher@server.fr","plusde100charactereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee@gmail.com") == 1);
    //L'email n'est pas valide
    assert(modifier_mel_client("../annuaire.csv","william.blanchard-foucher@server.fr","pasvlide@email") == 1);
    //L'email est valide
    assert(modifier_mel_client("../annuaire.csv","william.blanchard-foucher@server.fr","valid@gmail.com") == 0);
    //L'email n'est pas dans l'annuaire
    assert(modifier_autres_que_mel_client("../annuaire.csv","pas_dans_l_annuaire@gmail.com","nom","toto") == 1);
    //L'email est dans l'annuaire
    assert(modifier_autres_que_mel_client("../annuaire.csv","william.blanchard-foucher@server.fr","nom","toto") == 0);
}
