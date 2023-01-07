#include "../headers/api_sae.h"
#include "../headers/lecture.h"
#include "../headers/tools.h"

void test_afficher_annuaire_client()
{
    //check if the last line was corectly written
    ajouter_client("../annuaire.csv","toto","titi","44444","lyon","000000000000","caca@gmail.com","con");
    entry **tab = parse_tab("../annuaire.csv");
    int length_tab = tab_length(tab);
}
//afficher_annuaire_client("../annuaire.csv");
//ajouter_client("../annuaire.csv","toto","titi","44444","lyon","000000000000","caca@gmail.com","con");
//supprimer_client("../annuaire.csv", "william.blanchard-foucher@server.fr");
//modifier_mel_client("../annuaire.csv", "william.blanchard-foucher@server.fr", "prout@gmail.com");
//modifier_autres_que_mel_client("../annuaire.csv", "william.blanchard-foucher@server.fr", "prénom", "prout");