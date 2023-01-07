#include "api_sae.h"

//Fonction du tool.c

int tab_length(entry **tab);

entry **add_tab(entry **tab, entry *to_tab);

int select_line_with_email(entry **tab, const char* email);

int check_email_validity(const char *email);

void print_user_line (entry **tab, int length_tab);

/// \brief Fonction permettant d'afficher un utilisateur
/// \param to_print Tableau d'entrée avec les informations des l'utilisateurs
/// \param line Ligne de l'utilisateur à afficher
void afficher_utilisateur(entry **to_print, int line);

/// \brief Fonction permettant d'afficher l'entièreté de l'annuaire
/// \precondition L'annuraire doit être valide
/// \param nom_fichier Nom du fichier contenant l'annuaire
void afficher_annuaire_client(const char * nom_fichier);