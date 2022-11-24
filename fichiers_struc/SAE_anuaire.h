#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct entry_
{
    //tous les critères
    char * lastname;
    char * firstname;
    char * zipcode;
    char * city;
    char * phone;
    char * mail;
    char * job;
} entry;

char *get_string(FILE * file);

entry *get_line(FILE * file);

void print_entry(entry *to_print);

int tab_length(entry **tab);

entry **add_tab(entry **tab, entry *to_tab);

int parse_tab(char *namefile);