#include "topping.h"

topping::topping(){
    name[0] = '/0';
    price = 0;
}

topping::topping(int price, string name){
    strcpy(this->name, name.c_str());
    this->price = price;
}

topping::~topping(){
    //dtor
}
