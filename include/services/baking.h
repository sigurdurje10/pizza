//
//  baking.h
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef baking_h
#define baking_h

#include <stdio.h>
#include "models/pizza.h"
#include "models/pizza_place.h"
#include "services/manage.h"
#include "models/order.h"

class baking {
private:
    pizza* pizzas;
    int pizzas_length;
    order* orders;
    int order_length;
    order current_order;
public:
    baking();
    pizza* get_pizzas(pizza_place place);
    pizza get_pizza(int id, pizza_place place);
    int get_pizzas_length();
    order get_current_order();
};

#endif /* baking_h */
