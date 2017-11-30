//
//  pizza_bottom.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "pizza_bottom.h"

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
