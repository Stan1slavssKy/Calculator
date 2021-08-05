#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include "../libs/include.h"
#include "../libs/Onegin.h"

//=============================================================================================

double calculator (text* calc_info, FILE* formula, char* file_name);
double create_nmb ();
double create_exp ();
inline void skip_spaces ();
double create_t ();
double create_p ();
double create_w ();

enum sign
{
    POS =  1,
    NEG = -1
};

const int MAX_DEGREE = 255;

//=============================================================================================

#endif