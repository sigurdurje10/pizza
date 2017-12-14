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

manage::manage() {

}

/*
*Skráir nýja stærð.
*/
void manage::new_size(pizza_size* s) {
    pizza_size_data* d = new pizza_size_data();
    d->save_size(s);
    delete s;
    delete d;
}

/*
*Sækir allar stærðir.
*/
pizza_size* manage::get_sizes() {
    pizza_size_data* p = new pizza_size_data();
    this->sizes = p->get_sizes();
    this->sizes_length = p->get_sizes_length();
    delete p;
    return this->sizes;
}

/*
*Finna stærð.
*/
pizza_size manage::find_size(int size) {
    pizza_size* sz = this->get_sizes();
    for(int i=0; i<this->get_sizes_length(); i++) {
        if(size == sz[i].get_size()) {
            return sz[i];
        }
    }
    return (*new pizza_size());
}

/*
*Sækir fjölda stærða.
*/
int manage::get_sizes_length() {
    return this->sizes_length;
}

/*
*Nýtt álegg.
*/
void manage::new_topping(topping* t) {
    topping_data* d = new topping_data();
    d->save_topping(t);
    delete t;
    delete d;
}

/*
*Sækir öll álegg.
*/
topping* manage::get_toppings() {
    topping_data* d = new topping_data();
    this->toppings = d->get_toppings();
    this->toppings_length = d->get_toppings_length();
    delete d;
    return this->toppings;
}

/*
*Finnur álegg.
*/
topping manage::find_topping(string topping_value) {
    topping* top = this->get_toppings();
    for(int i=0; i<this->get_toppings_length(); i++) {
        if(topping_value == top[i].get_name()) {
            return top[i];
        }
    }
    return (*new topping());
}

/*
*Sækir fjölda álegga.
*/
int manage::get_toppings_length() {
    return this->toppings_length;
}


/*
*Skráir nýjan botn.
*/
void manage::new_bottom(pizza_bottom* b) {
    pizza_bottom_data* d = new pizza_bottom_data();
    d->save_bottom(b);
    delete b;
    delete d;
}

/*
*Sækir allar botna.
*/
pizza_bottom* manage::get_bottoms() {
    pizza_bottom_data* d = new pizza_bottom_data();
    this->bottoms = d->get_bottoms();
    this->bottoms_length = d->get_bottoms_length();
    delete d;
    return this->bottoms;
}

/*
*Finnur botn.
*/
pizza_bottom manage::find_bottom(string bottom) {
    pizza_bottom* bottoms = this->get_bottoms();
    for(int i = 0; i < this->get_bottoms_length(); i++) {
        if(bottom == bottoms[i].get_name()) {
            return bottoms[i];
        }
    }
    return (*new pizza_bottom());
}

/*
*Sækir fjölda botna.
*/
int manage::get_bottoms_length() {
    return this->bottoms_length;
}

/*
*Skráir nýjan stað.
*/
void manage::new_place(pizza_place* p) {
    pizza_place_data* d = new pizza_place_data();
    d->save_place(p);
    delete p;
    delete d;
}

/*
*Sækir allar staði.
*/
pizza_place* manage::get_places() {
    pizza_place_data* d = new pizza_place_data();
    this->places = d->get_places();
    this->places_length = d->get_places_length();
    delete d;
    return this->places;
}

/*
*Sækir fjölda staða.
*/
int manage::get_places_length() {
    return this->places_length;
}

/*
*Finnur stað.
*/
pizza_place manage::find_place(string place_value) {
    pizza_place* places = this->get_places();
    for(int i=0; i<this->get_places_length(); i++) {
        if(place_value == places[i].get_name()) {
            return places[i];
        }
    }
    return (*new pizza_place());
}

/*
*Skrá nýja stærð.
*/
void manage::new_side(side_order* s) {
    side_order_data* d = new side_order_data();
    d->save_side(s);
    delete s;
    delete d;
}

/*
*Sækir öll meðlæti.
*/
side_order* manage::get_sides() {
    side_order_data* d = new side_order_data();
    this->sides = d->get_sides();
    this->sides_length = d->get_sides_length();
    delete d;
    return this->sides;
}

/*
*Finnur meðlæti.
*/
side_order manage::find_side(string side_value) {
    side_order* sides = this->get_sides();
    for(int i=0; i<this->get_sides_length(); i++) {
        if(side_value == sides[i].get_name()) {
            return sides[i];
        }
    }
    return (*new side_order());
}

/*
*Sækir fjölda meðlæta.
*/
int manage::get_sides_length() {
    return this->sides_length;
}

/*
*Ny pitsa a matsedli..
*/
void manage::new_menu_item(pizza* p) {
    p_data* d = new p_data();
    d->save_pizza(p);
    delete p;
    delete d;
}

/*
*Sækir allar pitsur af matsedli.
*/
pizza* manage::get_menu() {
    p_data* p = new p_data();
    this->pizzas = p->get_pizzas();
    this->pizzas_length = p->get_pizzas_length();
    delete p;
    return this->pizzas;
}

/*
*Finna pitsu af matsedli.
*/
pizza manage::find_menu_item(string pizza_name) {
    pizza* pizzas = this->get_menu();
    for(int i=0; i<this->get_menu_length(); i++) {
        if(pizza_name == pizzas[i].get_name()) {
            return pizzas[i];
        }
    }
    return (*new pizza());
}

/*
*Sækir fjolda pitsna a matsedli.
*/
int manage::get_menu_length() {
    return this->pizzas_length;
}

/*
*Skráir nýjan notanda.
*/
void manage::new_user(user* p) {
    user_data* d = new user_data();
    d->save_user(p);
    delete p;
    delete d;
}

/*
*Sækir alla notanda.
*/
user* manage::get_users() {
    ;user_data*p =new user_data();
    this->users = p->get_users();
    this->users_length = p->get_users_length();
    delete p;
    return this->users;
}

/*
*Finnur notanda.
*/
user manage::find_user(string username, string password) {
    user* users = this->get_users();
    for(int i=0; i<this->get_users_length(); i++) {
        if(username == users[i].get_username() && password == users[i].get_password()) {
            return users[i];
        }
    }
    return (*new user());
}

/*
*Sækir fjölda notanda.
*/
int manage::get_users_length() {
    return this->users_length;
}

/*
*Stilla notanda.
*/
void manage::set_user(user u) {
    this->current_user = u;
}

/*
*Sækja notanda.
*/
user manage::get_user() {
    return this->current_user;
}


//Skráir nýtt tilboð.
/*
void manage::new_special(pizza_special* p) {
    special_data* d = new special_data();
    d->save_special(p);
    delete p;
    delete d;
}


//Sækir öll tilboð.

pizza_special* manage::get_specials() {
    special_data* p = new special_data();
    this->specials = p->get_specials();
    this->specials_length = p->get_specials_length();
    delete p;
    return this->specials;
}

int manage::get_specials_length(){
    return this->special_length;
}*/
/*
Finna tilboð.

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
