//
//  sales.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "sales.h"
#include "order.h"
#include "order_data.h"

sales::sales() {
    
}

int sales::new_order(order* o) {
    order_data* d = new order_data();
    d->save_order(o);
    //delete o;
    delete d;
    return o->get_id();
}

void sales::save_order(order o) {
    order_data* d = new order_data();
    order* orders = d->get_orders();
    if(!o.get_delivered()) {
        for(int i = 0; i<d->get_orders_length(); i++) {
            if(orders[i].get_id() == o.get_id()) {
                orders[i] = o;
            }
        }
        d->save_orders(orders);
    } else {
        d->save_old_order(&o);
        order* orders_n = new order[d->get_orders_length()-1];
        int order_count = 0;
        for(int i = 0; i<d->get_orders_length(); i++) {
            if(orders[i].get_id() == o.get_id()) {
            } else {
                orders_n[order_count] = orders[i];
                order_count++;
            }
        }
        d->save_orders(orders_n);
    }
    delete d;
}

void sales::delete_order(order o) {
    order_data* d = new order_data();
    order* orders = d->get_orders();
    order* orders_n = new order[d->get_orders_length()-1];
    int order_count = 0;
    for(int i = 0; i<d->get_orders_length(); i++) {
        if(orders[i].get_id() == o.get_id()) {
        } else {
            orders_n[order_count] = orders[i];
            order_count++;
        }
    }
    d->save_orders(orders_n);
}

order* sales::get_orders() {
    order_data* d = new order_data();
    this->orders = d->get_orders();
    this->orders_length = d->get_orders_length();
    for(int i=0; i<this->get_orders_length(); i++) {
        this->orders[i].get_late();
    }
    delete d;
    return this->orders;
}

order* sales::get_old_orders() {
    order_data* d = new order_data();
    this->orders = d->get_old_orders();
    this->orders_length = d->get_orders_length();
    delete d;
    return this->orders;
}

order sales::find_order(int order_value) {
    order* ord = this->get_orders();
    for(int i=0; i<this->get_orders_length(); i++) {
        if(order_value == ord[i].get_id()) {
            return ord[i];
        }
    }
    return (*new order());
}

int sales::get_orders_length() {
    return this->orders_length;
}

bool sales::orders_empty() {
    order_data* d = new order_data();
    return d->is_empty();
}
