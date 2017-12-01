//
//  pizza.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "pizza.h"

pizza::pizza() {
    this->price = 0;
    this->ready = false;
    this->in_progress = false;
    this->id = -1;
    this->curr_toppings = 0;
}

pizza::~pizza() {
    //dtor
}

void pizza::set_pizza_size(pizza_size size_of_pizza) {
    this->size_of_pizza = size_of_pizza;
}

void pizza::set_pizza_bottom(pizza_bottom bottom_of_pizza) {
    this->bottom_of_pizza = bottom_of_pizza;
}

void pizza::add_topping(topping topping) {
    if(this->curr_toppings < 10) {
        this->toppings_of_pizza[this->curr_toppings] = topping;//.set_topping(topping->get_price(), topping->get_name());
        this->curr_toppings++;
    }
}

pizza_size pizza::get_pizza_size() const {
    return this->size_of_pizza;
}

pizza_bottom pizza::get_pizza_bottom() const {
    return this->bottom_of_pizza;
}

topping* pizza::get_pizza_toppings() const {
    topping* toppings = new topping[this->curr_toppings];
    for(int i = 0; i<this->curr_toppings; i++) {
        toppings[i] = this->toppings_of_pizza[i];
    }
    return toppings;
}

void pizza::set_price(int price) {
    this->price = price;
}

void pizza::set_name(string name) {
    strcpy(this->name, name.c_str());
}

void pizza::calculate_price() {
    if(this->price == 0) {
        //this->price += this->get_pizza_bottom().get_price();
        this->price += get_pizza_size().get_price();
        topping* top = this->get_pizza_toppings();
        for(int i = 0; i<this->curr_toppings; i++) {
            this->price += top[i].get_price();
        }
    }
}

int pizza::get_price() const {
    return this->price;
}

string pizza::get_name() const {
    string str(this->name);
    return str;
}

int pizza::get_id() {
    return this->id;
}

void pizza::set_id(int id) {
    this->id = id;
}

void pizza::set_progress(bool progress) {
    this->in_progress = progress;
}

bool pizza::get_progress() {
    return this->in_progress;
}

void pizza::set_ready(bool ready) {
    this->ready = ready;
}

bool pizza::get_ready() {
    return this->ready;
}

int pizza::get_p_count() {
    return this->p_count;
}

void pizza::set_p_count(int p) {
    this->p_count = p;
}

ostream& operator << (ostream& out, const pizza& pizza) {
    if(pizza.id != -1) {
        out << "Pitsa numer: " << pizza.id << endl;
    }
    out << "Heiti: " << pizza.get_name() << endl;
    out << "Verd: " << pizza.get_price() << endl;
    out << "Botn: " << pizza.get_pizza_bottom().get_name() << endl;
    out << "Staerd: " << pizza.get_pizza_size().get_size() << endl;
    topping* toppings = pizza.get_pizza_toppings();
    for(int i = 0; i < pizza.curr_toppings; i++) {
        out << "Alegg: " << toppings[i].get_name() << endl;
    }
    if(pizza.ready) {
        out << "Tilbuin." << endl;
    } else if(pizza.in_progress) {
        out << "I vinnslu." << endl;
    }
    return out;
}

istream& operator >> (istream& in, pizza& pizza) {
    
    return in;
}
