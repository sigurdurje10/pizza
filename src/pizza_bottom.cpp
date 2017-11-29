#include "pizza_bottom.h"

pizza_bottom::pizza_bottom(){
    name[0] = '/0';
    prize = 0;
}

pizza_bottom::pizza_bottom(int prize, string name){
    strcpy(this->name, name.c_str());
    this->prize = prize;
}

pizza_bottom::~pizza_bottom(){
    //dtor
}
