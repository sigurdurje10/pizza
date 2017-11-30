//
//  order_data.cpp
//  order
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "order_data.h"
#include <iostream>
#include <fstream>

order_data::order_data() {
    this->order_file = "orders.dat";
}

void order_data::save_order(order p, order* list) {
    ofstream fout;
    order orders[this->number_of_orders];
    for(int i = 0; i < this->number_of_orders; i++) {
        orders[i] = list[i];
    }
    fout.open(this->order_file, ios::out|ios::binary);
    fout.write((char*)(&orders), sizeof(order)*(this->number_of_orders));
    fout.close();
}

void order_data::save_order(order* p) {
    ofstream fout;
    if(!this->is_empty()) {
        order* p_m = this->get_orders();
        order orders[this->number_of_orders+1];
        for(int i = 0; i < this->number_of_orders; i++) {
            orders[i] = p_m[i];
        }
        orders[this->number_of_orders-1] = (*p);
        fout.open(this->order_file, ios::out|ios::binary);
        fout.write((char*)(&orders), sizeof(order)*(this->number_of_orders));
        fout.close();
    } else {
        order x[1];
        x[0] = p[0];
        fout.open(this->order_file, ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(order));
        fout.close();
    }
}

bool order_data::is_empty() {
    ifstream fin;
    fin.open(this->order_file, ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

order* order_data::get_orders() {
    ifstream fin;
    fin.open(this->order_file, ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(order));
    fin.seekg(0, fin.beg);
    this->number_of_orders = records+1;
    order p_m[records+1];
    fin.read((char*)(&p_m), sizeof(order)*(records));
    this->orders = new order[records+1];
    for(int i = 0; i < records; i++) {
        this->orders[i] = p_m[i];
    }
    fin.close();
    return this->orders;
}

int order_data::get_orders_length() {
    return this->number_of_orders-1;
}


