#include "api_sae.h"

//Fonction du tool.c

int tab_length(entry **tab);

entry **add_tab(entry **tab, entry *to_tab);

int select_line_with_email(entry **tab, const char* email);

int check_email_validity(char *email);