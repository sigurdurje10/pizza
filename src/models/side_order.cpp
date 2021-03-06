//
//  side_order.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "models/side_order.h"
#include <iostream>
#include <string>
#include <string.h>
#include <limits>
#include "exception/exception.h"

side_order::side_order(){
    price = 0;
    name[0] = '\0';
}

side_order::~side_order(){
    //dtor
}

side_order::side_order(int price, string name){
    //this->price = price;
    this->set_price(price);
    strcpy(this->name, name.c_str());
}

void side_order::set_side_order(int price, string name) {
    this->price = price;
    strcpy(this->name, name.c_str());
}

void side_order::set_price(int price){
    if(price < 0) {
        throw price_exception();
    }
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

//yfirskrifar ostream virkjann til þess að skrifa út innihald side_order
ostream& operator << (ostream& out, const side_order& s_order) {
    out << "Medlaeti: " << s_order.get_name() << endl;
    out << "Verd: " << s_order.get_price() << endl;
    return out;
}

//biður notandann um að skrifa inn heiti og verð á meðlæti. Er með check til að koma í veg fyrir invalid input.
//Ef input er invalid þá loopast.
istream& operator >> (istream& in, side_order& s_order) {
    bool accepted = true;
    string name = "";
    int price = -1;
    in.ignore();
    do {
        accepted = true;
        cout << "Heiti: ";
        getline(in, name);
        if(!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            accepted = false;
        }
        if(accepted) {
            cout << "Verd: ";
            in >> price;
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
                throw price_exception();
            }
        }
    } while(!accepted || name == "" || price == -1);
    s_order.set_name(name);
    s_order.set_price(price);

    return in;
}
