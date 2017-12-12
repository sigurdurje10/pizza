#ifndef SPECIAL_DATA_H
#define SPECIAL_DATA_H
#include "models/pizza_special.h"


class special_data
{
private:
    int number_of_specials;
    pizza_special* p_z;
public:
    special_data();
    //vistar tilbo� � skr�, b�tir vi� �au sem voru
    void save_special(pizza_special* p);
    //n�r � �ll tilbo�in
    pizza_special* get_specials();
    //n�r � number_of_specials - 1
    int get_specials_length();
    //er skr�in t�m? skilar true ef svo er
    bool is_empty();
};


#endif // SPECIAL_DATA_H
