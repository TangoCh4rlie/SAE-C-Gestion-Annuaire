#include "../headers/api_sae.h"

void write_content_new_file(entry **result_tab)
{
	FILE* fp_out;

	fp_out = fopen("Sortie_test.txt", "w");

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