//
//  baking.cpp
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "baking.h"
#include "sales.h"

baking::baking() {
    
}

pizza* baking::get_pizzas(pizza_place place) {
    sales* s = new sales();
    order* orders = s->get_orders();
    order* place_orders = new order[s->get_orders_length()];
    int ord_count = 0;
    for(int i = 0; i<s->get_orders_length(); i++) {
        if(orders[i].get_place().get_name() == place.get_name()) {
            place_orders[ord_count] = orders[i];
            ord_count++;
        }
    }
    int pizza_count = 0;
    for(int i = 0; i<ord_count; i++) {
        pizza_count += place_orders[i].get_pizzas_count();
    }
    pizza* pizzas = new pizza[pizza_count];
    for(int i = 0; i<ord_count; i++) {
        place_orders[i].get_pizzas();
    }
    return this->pizzas;
}
