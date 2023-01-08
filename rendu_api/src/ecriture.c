#include "../headers/api_sae.h"
#include "../headers/tools.h"

void ecriture_annuaire_clients(entry **result_tab, char * filename)
{
	FILE* fp_out;

	fp_out = fopen(filename, "w");

	int i = 0;
	int len = tab_length(result_tab);

	do
	{
		fprintf(fp_out,"%s,", result_tab[i]->lastname);
		fprintf(fp_out,"%s,", result_tab[i]->firstname);
		fprintf(fp_out,"%s,", result_tab[i]->zipcode);
		fprintf(fp_out,"%s,", result_tab[i]->city);
		fprintf(fp_out,"%s,", result_tab[i]->phone);
		fprintf(fp_out,"%s,", result_tab[i]->mail);
		fprintf(fp_out,"%s\n", result_tab[i]->job);

		i++;
	}
	while(i < len);

	fclose(fp_out);
}