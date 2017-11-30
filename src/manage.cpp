//
//  umsjon.cpp
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "manage.h"
#include "pizza_size.h"
#include "pizza_size_data.h"
#include <iostream>
#include "topping.h"
#include "topping_data.h"
#include "side_order.h"
#include "side_order_data.h"
#include "p_data.h"
#include "pizza_place.h"
#include "pizza_place_data.h"


manage::manage() {

}

void manage::new_size(pizza_size* s) {
    pizza_size_data* d = new pizza_size_data();
    d->save_size(s);
    delete s;
    delete d;
}

pizza_size* manage::get_sizes() {
    pizza_size_data* p = new pizza_size_data();
    this->sizes = p->get_sizes();
    this->sizes_length = p->get_sizes_length();
    delete p;
    return this->sizes;
}

pizza_size manage::find_size(int size) {
    pizza_size* sz = this->get_sizes();
    for(int i=0; i<this->get_sizes_length(); i++) {
        if(size == sz[i].get_size()) {
            return sz[i];
        }
    }
    return (*new pizza_size());
}

int manage::get_sizes_length() {
    return this->sizes_length;
}

void manage::new_topping(topping* t) {
    topping_data* d = new topping_data();
    d->save_topping(t);
    delete t;
    delete d;
}

topping* manage::get_toppings() {
    topping_data* d = new topping_data();
    this->toppings = d->get_toppings();
    this->toppings_length = d->get_toppings_length();
    delete d;
    return this->toppings;
}

topping manage::find_topping(string topping_value) {
    topping* top = this->get_toppings();
    for(int i=0; i<this->get_toppings_length(); i++) {
        if(topping_value == top[i].get_name()) {
            return top[i];
        }
    }
    return (*new topping());
}

int manage::get_toppings_length() {
    return this->toppings_length;
}


/*void manage::new_bottom(pizza_bottom* b) {
    pizza_bottom_data* d = new pizza_bottom_data();
    d->save_bottom(b);
    delete b;
    delete d;
}

pizza_bottom* manage::get_bottoms() {
    pizza_bottom_data* d = new pizza_bottom_data();
    this->bottoms = d->get_bottoms();
    this->bottoms_length = d->get_bottoms_length();
    delete d;
    return this->bottoms;
}

pizza_bottom manage::find_bottom(string bottom) {
    pizza_bottom* bottoms = this->get_bottoms();
    for(int i = 0; i < this->get_bottoms_length(); i++) {
        if(bottom == bottoms[i].get_name()) {
            return bottoms[i];
        }
    }
    return (*new bottom());
}

int manage::get_bottoms_length() {
    return this->bottoms_length;
}
*/
void manage::new_place(pizza_place* p) {
    pizza_place_data* d = new pizza_place_data();
    d->save_place(p);
    delete p;
    delete d;
}

pizza_place* manage::get_places() {
    pizza_place_data* d = new pizza_place_data();
    this->places = d->get_places();
    this->places_length = d->get_places_length();
    delete d;
    return this->places;
}

int manage::get_places_length() {
    return this->places_length;
}

void manage::new_side(side_order* s) {
    side_order_data* d = new side_order_data();
    d->save_side(s);
    delete s;
    delete d;
}

side_order* manage::get_sides() {
    side_order_data* d = new side_order_data();
    this->sides = d->get_sides();
    this->sides_length = d->get_sides_length();
    delete d;
    return this->sides;
}

side_order manage::find_side(string side_value) {
    side_order* sides = this->get_sides();
    for(int i=0; i<this->get_sides_length(); i++) {
        if(side_value == sides[i].get_name()) {
            return sides[i];
        }
    }
    return (*new side_order());
}

int manage::get_sides_length() {
    return this->sides_length;
}

void manage::new_menu_item(pizza* p) {
    p_data* d = new p_data();
    d->save_pizza(p);
    delete p;
    delete d;
}

pizza* manage::get_menu() {
    p_data* p = new p_data();
    this->pizzas = p->get_pizzas();
    this->pizzas_length = p->get_pizzas_length();
    delete p;
    return this->pizzas;
}

pizza manage::find_menu_item(string pizza_name) {
    pizza* pizzas = this->get_menu();
    for(int i=0; i<this->get_menu_length(); i++) {
        if(pizza_name == pizzas[i].get_name()) {
            return pizzas[i];
        }
    }
    return (*new pizza());
}

int manage::get_menu_length() {
    return this->pizzas_length;
}
