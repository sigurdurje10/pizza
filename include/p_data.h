//
//  p_data.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef p_data_h
#define p_data_h

#include <stdio.h>
#include <string>
#include "pizza.h"

class p_data {
private:
    int number_of_pizzas;
    pizza* pizzas;
    string pizza_file;
public:
    p_data();
    void save_pizzas(pizza* list);
    void save_pizza(pizza* p);
    pizza* get_pizzas();
    int get_pizzas_length();
    bool is_empty();
};

#endif /* p_data_h */
