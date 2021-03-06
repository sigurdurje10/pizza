//
//  delivery.cpp
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "services/delivery.h"
#include "models/order.h"
#include "services/manage.h"
#include "services/sales.h"

delivery::delivery() {

}

/*
*Sækir allar óafhentar pantanir.
*/
order* delivery::get_orders(pizza_place place) {
    sales* s = new sales();
    order* orders = s->get_orders();
    order* orders_place = new order[s->get_orders_length()];
    int order_count = 0;
    for(int i=0; i<s->get_orders_length(); i++) {
        if(orders[i].get_place().get_name() == place.get_name()) {
            orders_place[order_count] = orders[i];
            order_count++;
        }
    }
    this->orders_length = order_count;
    return orders_place;
}

/*
*Sækir allar afhentar pitsur.
*/
order* delivery::get_old_orders(pizza_place place) {
    sales* s = new sales();
    order* orders = s->get_old_orders();
    order* orders_place = new order[s->get_orders_length()];
    int order_count = 0;
    for(int i=0; i<s->get_orders_length(); i++) {
        if(orders[i].get_place().get_name() == place.get_name()) {
            orders_place[order_count] = orders[i];
            order_count++;
        }
    }
    this->orders_length = order_count;
    return orders_place;
}

/*
*Sækir fjölda pantana.
*/
int delivery::get_orders_length() {
    return this->orders_length;
}

/*
*Sækir allar tilbúnar pantanir.
*/
order* delivery::get_orders_ready(pizza_place place) {
    order* orders = this->get_orders(place);
    order* finished_orders = new order[this->get_orders_length()];
    int order_count = 0;
    for(int i=0; i<this->get_orders_length(); i++) {
        pizza* pizzas = orders[i].get_pizzas();
        bool ready = true;
        for(int j=0; j<orders[i].get_pizzas_count(); j++) {
            if(!pizzas[j].get_ready()) {
                ready = false;
            }
        }
        if(ready) {
            finished_orders[order_count] = orders[i];
            order_count++;
        }
    }
    this->orders_ready_length = order_count;
    return finished_orders;
}

/*
*Sækir fjolda tilbúna pantana.
*/
int delivery::get_orders_ready_length() {
    return this->orders_ready_length;
}
