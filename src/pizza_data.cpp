//
//  pizza_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "pizza_data.h"
#include "pizza_size.h"
#include <iostream>
#include <fstream>

using namespace std;

pizza_data::pizza_data() {

}

void pizza_data::save_size(pizza_size* p) {
    ofstream fout;
    if(!this->is_empty()) {
        this->get_sizes();
        this->pizza_sizes[this->number_of_sizes-1].set_pizza(p->get_size(), p->get_price());
        cout << "number of sizes:" << this->number_of_sizes << endl;
        fout.open("sizes.dat", ios::out|ios::binary);
        fout.write((char*)(&this->pizza_sizes), sizeof(pizza_size)*(this->number_of_sizes));
        fout.close();
    } else {
        pizza_size x[1];
        x[0].set_pizza(p->get_size(), p->get_price());
        fout.open("sizes.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(pizza_size));
        fout.close();
    }
}

bool pizza_data::is_empty() {
    ifstream fin;
    fin.open("sizes.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

pizza_size* pizza_data::get_sizes() {
    ifstream fin;
    fin.open("sizes.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(pizza_size));
    fin.seekg(0, fin.beg);
    this->number_of_sizes = records+1;
    this->pizza_sizes[records+1];
    fin.read((char*)(&pizza_sizes), sizeof(pizza_size)*(records));
    fin.close();
    return pizza_sizes;
}

int pizza_data::get_sizes_length() {
    return this->number_of_sizes-1;
}
