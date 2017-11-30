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

ostream& operator << (ostream& out, const pizza& pizza) {
    out << "Heiti: " << pizza.get_name() << endl;
    out << "Verd: " << pizza.get_price() << endl;
    //out << "Botn: " << pizza.get_pizza_bottom().get_name();
    out << "Staerd: " << pizza.get_pizza_size().get_size() << endl;
    topping* toppings = pizza.get_pizza_toppings();
    for(int i = 0; i < pizza.curr_toppings; i++) {
        out << "Alegg: " << toppings[i].get_name() << endl;
    }
    return out;
}

istream& operator >> (istream& in, pizza& pizza) {
    
    return in;
}
