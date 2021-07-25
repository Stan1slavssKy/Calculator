#include "calc.h"

//=============================================================================================

int main (int argc, char** argv)
{
    text calc_info = {};

    char* file_name = console_input (argc, argv);
    assert (file_name);

    FILE* formula = fopen ("test", "rb");
    assert (formula);

    printf ("%lg\n", calculator (&calc_info, formula, file_name));

    fclose (formula);
    free_memory (&calc_info);

    return 0;
}

//=============================================================================================