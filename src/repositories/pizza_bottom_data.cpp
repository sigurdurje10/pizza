//
//  pizza_bottom_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "repositories/pizza_bottom_data.h"
#include "models/pizza_bottom.h"
#include <iostream>
#include <fstream>

pizza_bottom_data::pizza_bottom_data() {
    this->pizza_bottom_file = "pizza_bottoms.dat";
}

void pizza_bottom_data::save_bottom(pizza_bottom* s) {
    ofstream fout;
    if(!this->is_empty()) {
        pizza_bottom* s_o = this->get_bottoms();
        pizza_bottom s_orders[this->number_of_bottoms+1];
        for(int i = 0; i < this->number_of_bottoms; i++) {
            s_orders[i] = s_o[i];
        }
        s_orders[this->number_of_bottoms-1] = (*s);
        fout.open("pizza_bottoms.dat", ios::out|ios::binary);
        fout.write((char*)(&s_orders), sizeof(pizza_bottom)*(this->number_of_bottoms));
        fout.close();
    } else {
        pizza_bottom x[1];
        x[0].set_pizza_bottom(s->get_name(), s->get_price());
        fout.open("pizza_bottoms.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(pizza_bottom));
        fout.close();
    }
}

bool pizza_bottom_data::is_empty() {
    ifstream fin;
    fin.open("pizza_bottoms.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

pizza_bottom* pizza_bottom_data::get_bottoms() {
    ifstream fin;
    fin.open("pizza_bottoms.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(pizza_bottom));
    fin.seekg(0, fin.beg);
    this->number_of_bottoms = records+1;
    pizza_bottom s_orders[records+1];
    fin.read((char*)(&s_orders), sizeof(pizza_bottom)*(records));
    this->bottoms = new pizza_bottom[records+1];
    for(int i = 0; i < records; i++) {
        this->bottoms[i] = s_orders[i];
    }
    fin.close();
    return this->bottoms;
}

int pizza_bottom_data::get_bottoms_length() {
    return this->number_of_bottoms-1;
}
