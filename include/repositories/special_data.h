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
    void save_special(pizza_special* p);
    pizza_special* get_specials();
    int get_specials_length();
    bool is_empty();
};


#endif // SPECIAL_DATA_H
