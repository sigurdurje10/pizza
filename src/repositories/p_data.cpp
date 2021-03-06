//
//  p_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "repositories/p_data.h"
#include <iostream>
#include <fstream>

p_data::p_data() {
}

void p_data::save_pizzas(pizza* list) {
    ofstream fout;
    pizza* p_m = this->get_pizzas();
    pizza pizzas[this->get_pizzas_length()];
    for(int i = 0; i < this->get_pizzas_length(); i++) {
        pizzas[i] = list[i];
    }
    fout.open("orders.dat", ios::out|ios::binary);
    fout.write((char*)(&pizzas), sizeof(pizza)*(this->get_pizzas_length()));//skrifar allar pizzunar sem voru í list áður
    //í orders.dat. skrifar stærð pizza * fjöldi pizza út
    fout.close();
}

//Ef það er eitthvað fyrir í skránni þá er fyrst náð í pizza úr skránni með get_pizzas
//svo er þessu pizza bætt við og því er öllu síðan bombað í skránna.
//ef það er ekkert í skránni þá er p skrifað beint í skránna án þess að sækja eitthvað sem var fyrir
void p_data::save_pizza(pizza* p) {
    ofstream fout;
    if(!this->is_empty()) {
        pizza* p_m = this->get_pizzas();
        pizza pizzas[this->number_of_pizzas+1];
        for(int i = 0; i < this->number_of_pizzas; i++) {
            pizzas[i] = p_m[i];
        }
        pizzas[this->number_of_pizzas-1] = (*p);
        fout.open("pizzas.dat", ios::out|ios::binary);
        fout.write((char*)(&pizzas), sizeof(pizza)*(this->number_of_pizzas));
        fout.close();
    } else {
        pizza x[1];
        x[0] = p[0];
        fout.open("pizzas.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(pizza));
        fout.close();
    }
}

//skoðar hvort pizza.dat sé tóm. Skilar true ef hún er tóm.
bool p_data::is_empty() {
    ifstream fin;
    fin.open("pizzas.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

//nær í allar pizzur í pizzas.dat
pizza* p_data::get_pizzas() {
    ifstream fin;
    fin.open("pizzas.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(pizza)); //nýtir fin.end til að sjá fjölda tilvika af pizza í pizzas.dat
    fin.seekg(0, fin.beg);
    this->number_of_pizzas = records+1;
    pizza p_m[records+1];
    fin.read((char*)(&p_m), sizeof(pizza)*(records));//les allar pizzur úr pizzas.dat í p_m
    this->pizzas = new pizza[records+1];
    for(int i = 0; i < records; i++) {
        this->pizzas[i] = p_m[i];
    }
    fin.close();
    return this->pizzas;//skilar öllum pizza tilvikunum sem voru í skránni
}

int p_data::get_pizzas_length() {
    return this->number_of_pizzas-1;
}
