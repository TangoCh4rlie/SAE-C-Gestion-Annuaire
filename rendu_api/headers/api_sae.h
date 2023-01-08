#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

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

/// \brief Permet de trier les clients à partir de leur nom
/// \precondition Le nom de l'annuaire doit être valide
/// \postcondition Le fichier de sortie est composé du fichier d'entrée mais avec les lignes composant les clients triées en fonction de leur nom
/// \param nom_annuaire Le nom de l'annuaire
int trier_clients_par_nom(char * nom_annuaire);

/// \brief Permet d'ajouter un client dans l'annuaire
/// \precondition Le nom de l'annuaire doit être valide et mel_p ne peut pas être une chaîne vide
/// \postcondition Le fichier de sortie est composé du fichier d'entrée + les données d'un nouveau clientssi l'adresse mail n'est pas déjà utilisé
/// \param nom_annuaire Le nom de l'annuaire
/// \param nom_p Le nom du nouveau client
/// \param prenom_p Le prénom du nouveau client
/// \param code_postal_p Le code postal du nouveau client
/// \param ville_p La ville du nouveau client
/// \param telephone_p Le numéro de téléphone du nouveau client
/// \param mel_p Le mail du nouveau client
/// \param profession_p La profession du nouveau client
int ajouter_client(const char *nom_annuaire, const char *nom_p, const char *prenom_p, const char *code_postal_p, const char *ville_p, const char *telephone_p, const char *mel_p, const char *profession_p);

//Fonction elouan

/// \brief Permet de supprimer un client de l'annuaire
/// \precondition Le nom de l'annuaire doit être valide
/// \precondition L'adresse mail du client à supprimer doit être présente dans l'annuaire et ne doit pas être vide
/// \postcondition Le fichier de sortie est composé de toutes les lignes du fichier d'entrée sauf celle du client à supprimer
/// \param nom_annuaire Le nom de l'annuaire
/// \param mel_p L'adresse mail du client à supprimer
int supprimer_client(const char * nom_annuaire, const char* mel_p);

/// \brief Permet de modifier l'adresse mail d'un client
/// \precondition Le nom de l'annuaire doit être valide
/// \precondition L'adresse mail du client à modifier doit être présente dans l'annuaire et ne doit pas être vide
/// \precondition La nouvelle adresse mail du client ne doit pas de trouver déjà dans l'annuaire et ne doit pas être vide
/// \postcondition Le fichier de sortie est composé de toutes les lignes du fichier d'entrée avec l'email de l'utilisateur modifié
/// \param nom_annuaire Le nom de l'annuaire
/// \param mel_p L'adresse mail du client à modifier
/// \param nv_mel_p La nouvelle adresse mail du client
int modifier_mel_client(const char * nom_annuaire, const char * mel_p, const char * nv_mel_p);

/// \brief Permet de modifier d'autres champ que le mail d'un client
/// \precondition Le nom de l'annuaire doit être valide
/// \precondition L'adresse mail du client à modifier doit être présente dans l'annuaire et ne doit pas être vide
/// \precondition nom_champ soit être un des champs suivant : nom, prenom, code_postal, ville, telephone, profession
/// \postcondition Le fichier de sortie est composé de toutes les lignes du fichier d'entrée avec le champ de l'utilisateur modifié
/// \param nom_annuaire Le nom de l'annuaire
/// \param mel_p L'adresse mail du client à modifier
/// \param nom_champ Le nom du chazzzmp à modifier
/// \param nv_champ La nouvelle valeur du champ
int modifier_autres_que_mel_client(const char * nom_annuaire, const char * mel_p, const char * nom_champ, const char * nv_valeur);