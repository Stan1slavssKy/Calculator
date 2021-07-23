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
    
    return create_exp ();
}

//=============================================================================================

double create_nmb ()
{   
    while (*counter == ' ')
        counter++;

    double out_nmb = atof (counter);

    while (isdigit (*counter) || *counter == '.')
        counter++;

    return out_nmb;
}

//=============================================================================================

double create_exp ()
{
    double res_nmb = 0; 

    while (*counter != '\0')
    {
        while (*counter == ' ')
            counter++;   

        if (isdigit (*counter))
        {
            res_nmb = create_nmb ();
            printf ("\t\tIS [%c]\n", *counter);
        } 
        else if (*counter == '+')
        {
            counter++;
            res_nmb += create_nmb ();    
        }
        else if (*counter == '-')
        {
            counter++; 
            res_nmb -= create_nmb ();    
        } 
    }

    return res_nmb;
}

//=============================================================================================
