//
//  pizza_place.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "pizza_place.h"
#include <iostream>
#include <string>
#include <string.h>
#include <limits>

using namespace std;

pizza_place::pizza_place(){
    name[0] = '\0';
    address[0] = '\0';
}

pizza_place::pizza_place(string name, string addr){
    strcpy(this->name, name.c_str());
    strcpy(this->address, addr.c_str());
}

pizza_place::~pizza_place(){
    //dtor
}

string pizza_place::get_name() const {
    string str(name);
    return str;
}
string pizza_place::get_address() const {
    string str(address);
    return str;
}

ostream& operator << (ostream& out, const pizza_place& p_place) {
    out << "Pizzastadur: " << p_place.name << endl;
    out << "Heimilisfang: " << p_place.address << endl;
    return out;
}

istream& operator >> (istream& in, pizza_place& p_place) {
    bool accepted = true;
    string name = "";
    string address = "";
    in.ignore();
    do {
        cout << "Heiti pizzastads: ";
        getline(in, name);
        if(!in) {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            accepted = false;
        }
        if(accepted && name != "") {
            cout << "Heimilisfang: ";
            getline(in, address);
            if(!in) {
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        }
    } while(!accepted || name == "" || address == "");
    p_place.set_name(name);
    p_place.set_address(address);
    return in;
}
