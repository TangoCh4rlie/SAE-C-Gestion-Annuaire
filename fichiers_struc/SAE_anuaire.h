#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

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

//Fonction du tool.c

int tab_length(entry **tab);

entry **add_tab(entry **tab, entry *to_tab);

void display_menu();

void print_user_line (entry **tab, int length_tab);

int select_line_with_email(entry **tab, const char* email);

void Color12(int clrtxt,int clrfond);

int check_email_validity(char *email);

//Fonction erwan

char **get_all_mail(entry **tab);

void **trier_clients_par_nom(entry **tab);

void display_tab(entry **tab);

//Fonction elouan

entry **del_line_tab(entry **tab, char* user_email);

entry **modify_client_mail(entry **tab, const char *old_email, char *new_email);

//Fonction du function.c

char *get_string(FILE * file);

entry *get_line(FILE * file);

void print_entry_all(entry **to_print, int line);

entry **parse_tab(char *filename);

int **check_email_not_same(entry **tab);

void write_content_new_file(FILE * fp_out, int length_tab, entry **result_tab);

