//
//  topping.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "topping.h"
#include <string>
#include <limits>

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
    bool accepted = true;
    string topping = "";
    int price = -1;
    in.ignore();
    do {
        accepted = true;
        cout << "Alegg: ";
        getline(in, topping);
        if(!in) {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            accepted = false;
        }
        if(accepted) {
            cout << "Verd: ";
            in >> price;
            if(!in) {
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        }
    } while(!accepted || topping == "" || price == -1);
    p_topping.set_name(topping);
    p_topping.set_price(price);
    return in;
}
