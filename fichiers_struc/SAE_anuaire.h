#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct entry_
{
	//all criteria
	char * lastname;
	char * firstname;
    char * zipcode;
    char * city;
    char * phone;
    char * mail;
    char * job;
} entry;

entry **result_tab = NULL;

char *get_string(FILE * file);

entry *get_line(FILE * file);

void print_entry(entry *to_print);

int tab_length(entry **tab);

entry **add_tab(entry **tab, entry *to_tab);

int parse_tab(char *filename);

char **get_all_mail(entry **tab);

entry **del_line_tab(entry **tab, int to_del);

int print_user_line_asked();