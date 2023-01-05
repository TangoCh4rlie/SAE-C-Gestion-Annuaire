#include "api_sae.h"

//Fonction du tool.c

int tab_length(entry **tab);

entry **add_tab(entry **tab, entry *to_tab);

int select_line_with_email(entry **tab, const char* email);

int check_email_validity(const char *email);

void print_user_line (entry **tab, int length_tab);

void print_entry_all(entry **to_print, int line);