//
//  pizza_place.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "pizza_place.h"

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

ostream& operator << (ostream& out, const pizza_place& p_place) {
    out << "Pizzastadur: " << p_place.name << endl;
    out << "Heimilisfang: " << p_place.address << endl;
    return out;
}

istream& operator >> (istream& in, pizza_place& p_place) {
    string name, address;
    cout << "Heiti pizzastads: ";
    in >> name;
    cout << "Heimilisfang: ";
    in >> address;
    p_place.set_name(name);
    p_place.set_address(address);
    return in;
}
