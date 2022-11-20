#include "SAE_anuaire.h"

int tab_length(entry **tab)
{
    int i = 0;

    while (tab != NULL && tab[i] != 0)                          //différent de false null ou 0
        i++;

    return i;
}

entry **add_tab(entry **tab, entry *to_tab)
{
    int length = tab_length(tab);

    if (tab == NULL)
        tab = malloc(1);

    tab = realloc(tab, sizeof(entry*) * (length + 2)); //pour les deux \0
    tab[length++] = to_tab;
    tab[length] = NULL;

    return tab;

}