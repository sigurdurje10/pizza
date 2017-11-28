#ifndef PIZZA_DATA_H
#define PIZZA_DATA_H


#include <stdio.h>
#include "pizza_size.h"

class pizza_data {
private:

public:
    pizza_data();
    void save_size(pizza_size* p);
    pizza_size* get_sizes();
};


#endif // PIZZA_DATA_H
