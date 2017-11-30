//
//  side_order_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "side_order_data.h"
#include "side_order.h"
#include <iostream>
#include <fstream>

side_order_data::side_order_data() {
    this->side_order_file = "side_orders.dat";
}

void side_order_data::save_side(side_order* s) {
    ofstream fout;
    if(!this->is_empty()) {
        side_order* s_o = this->get_sides();
        side_order s_orders[this->number_of_sides+1];
        for(int i = 0; i < this->number_of_sides; i++) {
            s_orders[i] = s_o[i];
        }
        s_orders[this->number_of_sides-1] = (*s);
        fout.open(this->side_order_file, ios::out|ios::binary);
        fout.write((char*)(&s_orders), sizeof(side_order)*(this->number_of_sides));
        fout.close();
    } else {
        side_order x[1];
        x[0].set_side_order(s->get_price(), s->get_name());
        fout.open(this->side_order_file, ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(side_order));
        fout.close();
    }
}

bool side_order_data::is_empty() {
    ifstream fin;
    fin.open(this->side_order_file, ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

side_order* side_order_data::get_sides() {
    ifstream fin;
    fin.open(this->side_order_file, ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(side_order));
    fin.seekg(0, fin.beg);
    this->number_of_sides = records+1;
    side_order s_orders[records+1];
    fin.read((char*)(&s_orders), sizeof(side_order)*(records));
    this->sides = new side_order[records+1];
    for(int i = 0; i < records; i++) {
        this->sides[i] = s_orders[i];
    }
    fin.close();
    return this->sides;
}

int side_order_data::get_sides_length() {
    return this->number_of_sides-1;
}
