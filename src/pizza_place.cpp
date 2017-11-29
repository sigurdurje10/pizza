#include "pizza_place.h"

pizza_place::pizza_place(){
    name[0] = '/0';
    address[0] = '/0';
}

pizza_place::pizza_place(string name, string addr){
    strcpy(this->name, name.c_str());
    strcpy(this->address, addr.c_str());
}

pizza_place::~pizza_place(){
    //dtor
}
