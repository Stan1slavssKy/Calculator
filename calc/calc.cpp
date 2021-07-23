#include "calc.h"

char* counter = nullptr;

//=============================================================================================

double calculator (text* calc_info, FILE* formula, char* file_name)
{
    assert (calc_info);
    assert (formula);
    assert (file_name);

    input_inform (file_name, calc_info); 
    assert (calc_info -> file_buffer);

    counter = calc_info -> file_buffer;
    
    return create_n ();
}

//=============================================================================================

double create_n ()
{   
    while (*counter == ' ')
        counter++;

    double out_nmb = atof (counter);

    while (*counter != ' ')
        counter++;

    return out_nmb;
}

//=============================================================================================