//
//  topping.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "topping.h"
#include <string>

topping::topping(){
    name[0] = '\0';
    price = 0;
}

topping::topping(int price, string name){
    strcpy(this->name, name.c_str());
    this->price = price;
}

void topping::set_topping(int price, string name) {
    strcpy(this->name, name.c_str());
    this->price = price;
}

topping::~topping(){
    //dtor
}

void topping::set_name(string name){
    strcpy(this->name, name.c_str());
}
void topping::set_price(int price){
    this->price = price;
}
string topping::get_name() const {
    string str(name);
    return str;
}
int topping::get_price() const {
    return price;
}

ostream& operator << (ostream& out, const topping& p_topping) {
    out << "Alegg: " << p_topping.get_name() << endl;
    out << "Verd: " << p_topping.get_price() << endl;
    return out;
}

istream& operator >> (istream& in, topping& p_topping) {
    string topping;
    int price;
    cout << "Alegg: ";
    in.ignore();
    getline(in, topping);
    cout << "Verd: ";
    in >> price;
    p_topping.set_name(topping);
    p_topping.set_price(price);
    return in;
}
