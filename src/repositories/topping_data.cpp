//
//  topping_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "repositories/topping_data.h"
#include "models/topping.h"
#include <iostream>
#include <fstream>

topping_data::topping_data() {
    this->topping_file = "toppings.dat";
}

//Ef það er eitthvað fyrir í skránni þá er fyrst náð í topping úr skránni með get_toppings
//svo er þessu topping bætt við og því er öllu síðan bombað í skránna.
//ef það er ekkert í skránni þá er t skrifað beint í skránna án þess að sækja eitthvað sem var fyrir
void topping_data::save_topping(topping* t) {
    ofstream fout;
    if(!this->is_empty()) {
        topping* p_t = this->get_toppings();
        topping p_toppings[this->number_of_toppings+1];
        for(int i = 0; i < this->number_of_toppings; i++) {
            p_toppings[i] = p_t[i];
        }
        p_toppings[this->number_of_toppings-1] = (*t);
        fout.open("toppings.dat", ios::out|ios::binary);
        fout.write((char*)(&p_toppings), sizeof(topping)*(this->number_of_toppings));
        fout.close();
    } else {
        topping x[1];
        x[0].set_topping(t->get_price(), t->get_name());
        fout.open("toppings.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(topping));
        fout.close();
    }
}

//skoðar hvort toppings.dat sé tóm. Skilar true ef hún er tóm.
bool topping_data::is_empty() {
    ifstream fin;
    fin.open("toppings.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

//nær í öll topping í toppings.dat
topping* topping_data::get_toppings() {
    ifstream fin;
    fin.open("toppings.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(topping));//nýtir fin.end til að sjá fjölda tilvika af topping í toppings.dat
    fin.seekg(0, fin.beg);
    this->number_of_toppings = records+1;
    topping p_toppings[records+1];
    fin.read((char*)(&p_toppings), sizeof(topping)*(records));//les öll topping úr topping.dat í p_toppings
    this->toppings = new topping[records+1];
    for(int i = 0; i < records; i++) {
        this->toppings[i] = p_toppings[i];
    }
    fin.close();
    return this->toppings;//skilar öllum topping tilvikum sem voru í skránni
}

int topping_data::get_toppings_length() {
    return this->number_of_toppings-1;
}
