#include "api_sae.h"

char *get_string(FILE * file);

entry *get_line(FILE * file);

entry **parse_tab(char *filename);

int **check_email_not_same(entry **tab);