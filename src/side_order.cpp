//
//  side_order.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "side_order.h"
#include <iostream>
#include <string>
#include <string.h>

side_order::side_order(){
    price = 0;
    name[0] = '\0';
}

side_order::~side_order(){
    //dtor
}

side_order::side_order(int price, string name){
    this->price = price;
    strcpy(this->name, name.c_str());
}

void side_order::set_side_order(int price, string name) {
    this->price = price;
    strcpy(this->name, name.c_str());
}

void side_order::set_price(int price){
    this->price = price;
}

void side_order::set_name(string name){
    strcpy(this->name, name.c_str());
}

int side_order::get_price() const {
    return price;
}

string side_order::get_name() const {
    string str(name);
    return str;
}

ostream& operator << (ostream& out, const side_order& s_order) {
    out << "Heiti: " << s_order.get_name() << endl;
    out << "Verd: " << s_order.get_price() << endl;
    return out;
}

istream& operator >> (istream& in, side_order& s_order) {
    string name;
    int price;
    cout << "Heiti: ";
    in.ignore();
    getline(in, name);
    cout << "Verd: ";
    in >> price;
    s_order.set_name(name);
    s_order.set_price(price);
    return in;
}
