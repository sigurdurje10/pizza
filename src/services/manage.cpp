//
//  umsjon.cpp
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "services/manage.h"
#include "models/pizza_size.h"
#include "repositories/pizza_size_data.h"
#include <iostream>
#include "models/topping.h"
#include "repositories/topping_data.h"
#include "models/side_order.h"
#include "repositories/side_order_data.h"
#include "repositories/p_data.h"
#include "repositories/pizza_place_data.h"
#include "repositories/pizza_bottom_data.h"
#include "models/user.h"
#include "repositories/user_data.h"
#include "models/pizza_special.h"
#include "repositories/special_data.h"

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


void manage::new_bottom(pizza_bottom* b) {
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
    return (*new pizza_bottom());
}

int manage::get_bottoms_length() {
    return this->bottoms_length;
}

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

pizza_place manage::find_place(string place_value) {
    pizza_place* places = this->get_places();
    for(int i=0; i<this->get_places_length(); i++) {
        if(place_value == places[i].get_name()) {
            return places[i];
        }
    }
    return (*new pizza_place());
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

void manage::new_user(user* p) {
    user_data* d = new user_data();
    d->save_user(p);
    delete p;
    delete d;
}

user* manage::get_users() {
    ;user_data*p =new user_data();
    this->users = p->get_users();
    this->users_length = p->get_users_length();
    delete p;
    return this->users;
}

user manage::find_user(string username, string password) {
    user* users = this->get_users();
    for(int i=0; i<this->get_users_length(); i++) {
        if(username == users[i].get_username() && password == users[i].get_password()) {
            return users[i];
        }
    }
    return (*new user());
}

int manage::get_users_length() {
    return this->users_length;
}

void manage::set_user(user u) {
    this->current_user = u;
}

user manage::get_user() {
    return this->current_user;
}
void manage::new_special(pizza_special* p) {
    special_data* d = new special_data();
    d->save_special(p);
    delete p;
    delete d;
}/*

user* manage::get_specials() {
    ;user_data*p =new user_data();
    this->users = p->get_users();
    this->users_length = p->get_users_length();
    delete p;
    return this->users;
}

user manage::find_user(string username, string password) {
    user* users = this->get_users();
    for(int i=0; i<this->get_users_length(); i++) {
        if(username == users[i].get_username() && password == users[i].get_password()) {
            return users[i];
        }
    }
    return (*new user());
}

int manage::get_users_length() {
    return this->users_length;
}*/
