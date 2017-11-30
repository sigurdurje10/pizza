//
//  pizza_size.cpp
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "pizza_size.h"

using namespace std;

pizza_size::pizza_size() {
    
}

pizza_size::pizza_size(int size, int price) {
    this->size = size;
    this->price = price;
}

void pizza_size::set_pizza(int size, int price) {
    this->size = size;
    this->price = price;
}

int pizza_size::get_size() {
    return this->size;
}

int pizza_size::get_price() {
    return this->price;
}

void pizza_size::set_size(int size) {
    this->size = size;
}

void pizza_size::set_price(int price) {
    this->price = price;
}

ostream& operator << (ostream& out, const pizza_size& p_size) {
    out << "Staerd: " << p_size.size << endl;
    out << "Verd: " << p_size.price << endl;
    return out;
}

istream& operator >> (istream& in, pizza_size& p_size) {
    int size, price;
    cout << "Staerd: ";
    in >> size;
    cout << "Verd: ";
    in >> price;
    p_size.set_size(size);
    p_size.set_price(price);
    return in;
}

