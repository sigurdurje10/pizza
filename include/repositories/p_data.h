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
#include "models/pizza.h"

class p_data {
private:
    int number_of_pizzas;
    pizza* pizzas;
public:
    p_data();
    //vistar margar pizzur í skrá
    void save_pizzas(pizza* list);
    //vistar eina pizzu í skrá, bætir við þær sem voru
    void save_pizza(pizza* p);
    //nær í pizzur
    pizza* get_pizzas();
    //skilar number_of_pizzas - 1
    int get_pizzas_length();
	//skilar true ef skráin er tóm
    bool is_empty();
};

#endif /* p_data_h */
