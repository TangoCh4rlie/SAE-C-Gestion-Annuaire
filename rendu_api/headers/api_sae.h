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



//Fonction erwan

char **get_all_mail(entry **tab);

void **trier_clients_par_nom(entry **tab);

void display_tab(entry **tab);

//Fonction elouan

void supprimer_client(const char * nom_annuaire, const char* mel_p);

void modifier_mel_client(const char * nom_annuaire, const char * mel_p, const char * nv_mel_p);

void modifier_autres_que_mel_client(const char * nom_annuaire, const char * mel_p, const char * nom_champ, const char * nv_valeur);

void field_filter(const char * nom_annuaire, const char *nom_champ, const char *val_chaine);