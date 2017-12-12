//
//  side_order_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "repositories/side_order_data.h"
#include "models/side_order.h"
#include <iostream>
#include <fstream>

side_order_data::side_order_data() {
}

//Ef það er eitthvað fyrir í skránni þá er fyrst náð í side_order úr skránni með get_sides
//svo er þessu side_order bætt við og því er öllu síðan bombað í skránna.
//ef það er ekkert í skránni þá er s skrifað beint í skránna án þess að sækja eitthvað sem var fyrir
void side_order_data::save_side(side_order* s) {
    ofstream fout;
    if(!this->is_empty()) {
        side_order* s_o = this->get_sides();
        side_order s_orders[this->number_of_sides+1];
        for(int i = 0; i < this->number_of_sides; i++) {
            s_orders[i] = s_o[i];
        }
        s_orders[this->number_of_sides-1] = (*s);
        fout.open("side_orders.dat", ios::out|ios::binary);
        fout.write((char*)(&s_orders), sizeof(side_order)*(this->number_of_sides));
        fout.close();
    } else {
        side_order x[1];
        x[0].set_side_order(s->get_price(), s->get_name());
        fout.open("side_orders.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(side_order));
        fout.close();
    }
}

//skoðar hvort side_orders.dat sé tóm. Skilar true ef hún er tóm.
bool side_order_data::is_empty() {
    ifstream fin;
    fin.open("side_orders.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

//nær í öll side_order í side_orders.dat
side_order* side_order_data::get_sides() {
    ifstream fin;
    fin.open("side_orders.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(side_order));//nýtir fin.end til að sjá fjölda tilvika af side_order í side_orders.dat
    fin.seekg(0, fin.beg);
    this->number_of_sides = records+1;
    side_order s_orders[records+1];
    fin.read((char*)(&s_orders), sizeof(side_order)*(records));//les öll side_order úr side_orders.dat í s_orders
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
