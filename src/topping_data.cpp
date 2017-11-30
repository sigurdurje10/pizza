//
//  topping_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "topping_data.h"
#include "topping.h"
#include <iostream>
#include <fstream>

topping_data::topping_data() {
    this->topping_file = "toppings.dat";
}

void topping_data::save_topping(topping* t) {
    ofstream fout;
    if(!this->is_empty()) {
        topping* p_t = this->get_toppings();
        topping p_toppings[this->number_of_toppings+1];
        for(int i = 0; i < this->number_of_toppings; i++) {
            p_toppings[i] = p_t[i];
        }
        p_toppings[this->number_of_toppings-1] = (*t);
        fout.open(this->topping_file, ios::out|ios::binary);
        fout.write((char*)(&p_toppings), sizeof(topping)*(this->number_of_toppings));
        fout.close();
    } else {
        topping x[1];
        x[0].set_topping(t->get_price(), t->get_name());
        fout.open(this->topping_file, ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(topping));
        fout.close();
    }
}

bool topping_data::is_empty() {
    ifstream fin;
    fin.open(this->topping_file, ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

topping* topping_data::get_toppings() {
    ifstream fin;
    fin.open(this->topping_file, ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(topping));
    fin.seekg(0, fin.beg);
    this->number_of_toppings = records+1;
    topping p_toppings[records+1];
    fin.read((char*)(&p_toppings), sizeof(topping)*(records));
    this->toppings = new topping[records+1];
    for(int i = 0; i < records; i++) {
        this->toppings[i] = p_toppings[i];
    }
    fin.close();
    return this->toppings;
}

int topping_data::get_toppings_length() {
    return this->number_of_toppings-1;
}
