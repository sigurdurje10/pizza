#include "side_order.h"

side_order::side_order(){
    prize = 0;
    name[0] = '/0';
}

side_order::~side_order(){
    //dtor
}

side_order::side_order(int prize, string name){
    this->prize = prize;
    strcpy(this->name, name.c_str());
}
