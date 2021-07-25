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
    skip_spaces ();

    double out_nmb = atof (counter);

    while (isdigit(*counter) || *counter == '.')
        counter++;

    skip_spaces ();
            
    return out_nmb;
}

//=============================================================================================

double create_exp ()
{
    skip_spaces ();
    sign   s  = POS;
    
    if (*counter == '-')
    {
        counter++;
        s = NEG;  
    }

    double res_nmb = create_t () * s;

    while (*counter == '+' || *counter == '-')
    {
        if (*counter == '+')
        {
            counter++;
            s = POS;
        }
        else if (*counter == '-')
        {
            counter++;
            s = NEG; 
        }   

        skip_spaces ();

        res_nmb += create_t () * s;
    }

    return res_nmb;
}

//=============================================================================================

double create_t ()
{
    skip_spaces ();
    
    double res_nmb = create_p ();

    while (*counter == '*' || *counter == '/')
    {
        skip_spaces ();

        if (*counter == '*')
        {
            counter++;
            res_nmb *= create_p ();
        }
        else if (*counter == '/')
        {
            counter++;
            res_nmb /= create_p ();
        }   
    }

    skip_spaces ();

    return res_nmb;
}

//=============================================================================================

double create_p ()
{
    skip_spaces ();

    double res_nmb = 0;

    if (*counter == '(')
    {
        counter++;

        res_nmb = create_exp ();

        if (*counter == ')')
            counter++;
        else  
            fprintf (stderr, "Error, %d\n", __LINE__);
    }
    else
    {
        res_nmb = create_nmb ();
    }

    return res_nmb;
}

//=============================================================================================

inline void skip_spaces ()
{
    while (isspace (*counter))
        counter++;   
}

//=============================================================================================