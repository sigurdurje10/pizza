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
    //vistar tilboð í skrá, bætir við þau sem voru
    void save_special(pizza_special* p);
    //nær í öll tilboðin
    pizza_special* get_specials();
    //nær í number_of_specials - 1
    int get_specials_length();
    //er skráin tóm? skilar true ef svo er
    bool is_empty();
};


#endif // SPECIAL_DATA_H
