#include "headers/api_sae.h"

int main(void)
{
    supprimer_client("../annuaire.csv", "william.blanchard-foucher@server.fr");
    modifier_mel_client("../annuaire.csv", "william.blanchard-foucher@server.fr", "prout@gmail.com");

    return 0;
}