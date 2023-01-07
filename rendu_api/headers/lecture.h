#include "api_sae.h"

char *get_string(FILE * file);

entry *get_line(FILE * file);

int check_email_not_same(entry **tab);

//C'est la fonction chargement_annuaire_client nous ne l'avons pas renommé car elle est utilisée partout dans le code
/// \brief Charge un annuaire de clients depuis un fichier
/// \postcondition L'annuaire est chargé dans un tableau de structure
/// \param nom_annuaire Le nom du fichier contenant l'annuaire
entry **parse_tab(const char *filename);

/// \brief Permet de vérifier la validité de l'annuaire (pas de doublons d'emails et tous les champs email sont remplis)
/// \param nom_annuaire Le nom du fichier contenant l'annuaire
void verifier_validite_annuraire_clients(const char * nom_annuaire);