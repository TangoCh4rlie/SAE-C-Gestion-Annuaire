#include "api_sae.h"

char *get_string(FILE * file);

entry *get_line(FILE * file);

void print_entry_all(entry **to_print, int line);

entry **parse_tab(char *filename);

int **check_email_not_same(entry **tab);