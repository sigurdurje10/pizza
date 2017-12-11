//
//  baking.cpp
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "services/baking.h"
#include "services/sales.h"

baking::baking() {

}
/*
*Sækir allar pitsur.
*/
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
    this->pizzas_length = pizza_count;
    this->pizzas = new pizza[pizza_count];
    this->orders = new order[pizza_count];
    int counter = 0;
    for(int i = 0; i<ord_count; i++) {
        pizza* p = place_orders[i].get_pizzas();
        for(int j=0; j<place_orders[i].get_pizzas_count(); j++) {
            this->pizzas[counter] = p[j];
            this->pizzas[counter].set_id(counter);
            this->pizzas[counter].set_p_count(j);
            this->orders[counter] = place_orders[i];
            counter++;
        }
    }
    return this->pizzas;
}

/*
*Sækir eima pitsu.
*/
pizza baking::get_pizza(int id, pizza_place place) {
    pizza* pizzas = this->get_pizzas(place);
    for(int i = 0; i<this->pizzas_length; i++) {
        if(i == id) {
            pizzas[i].set_id(i);
            this->current_order = this->orders[i];
            return pizzas[i];
        }
    }
    return (*new pizza());
}

/*
*Sækir fjoldi pitsna.
*/
int baking::get_pizzas_length() {
    return this->pizzas_length;
}

/*
*Sækir núverandi pöntun.
*/
order baking::get_current_order() {
    return this->current_order;
}
