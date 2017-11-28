#ifndef PIZZA_DATA_H
#define PIZZA_DATA_H


#include <stdio.h>
#include "pizza_size.h"


class pizza_data {
private:
    int number_of_sizes;
    pizza_size pizza_sizes[];
public:
    pizza_data();
    void save_size(pizza_size* p);
    pizza_size* get_sizes();
    int get_sizes_length();
    bool is_empty();
};



#endif // PIZZA_DATA_H
