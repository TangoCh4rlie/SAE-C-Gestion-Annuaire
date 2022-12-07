#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

char *get_string(FILE * file);

entry *get_line(FILE * file);

void print_entry(entry **to_print, int line);

int tab_length(entry **tab);

entry **add_tab(entry **tab, entry *to_tab);

entry **parse_tab(char *filename);

char **get_all_mail(entry **tab);

entry **del_line_tab(entry **tab, int to_del);

int **check_email_not_same(entry **tab);

void print_user_line (entry **tab);

void **trier_clients_par_nom(entry **tab);

void display_menu();

char **get_all_mail_UwU(entry **tab);