//
//  pizza_bottom.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "pizza_bottom.h"
#include <limits>

pizza_bottom::pizza_bottom(){
    name[0] = '\0';
    price = 0;
}

pizza_bottom::pizza_bottom(int price, string name){
    strcpy(this->name, name.c_str());
    this->price = price;
}

pizza_bottom::~pizza_bottom(){
    //dtor
}

void pizza_bottom::set_pizza_bottom(string name, int price) {
    strcpy(this->name, name.c_str());
    this->price = price;
}

ostream& operator << (ostream& out, const pizza_bottom& p_bottom) {
    out << "Botn: " << p_bottom.name << endl;
    out << "Verd: " << p_bottom.price << endl;
    return out;
}

istream& operator >> (istream& in, pizza_bottom& p_bottom) {
    bool accepted = true;
    string name = "";
    int price = -1;
    in.ignore();
    do {
        accepted = true;
        cout << "Tegund botns: ";
        getline(in, name);
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
    } while(!accepted || name == "" || price == -1);
    p_bottom.set_name(name);
    p_bottom.set_price(price);
    return in;
}
