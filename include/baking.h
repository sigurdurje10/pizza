//
//  baking.hpp
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef baking_h
#define baking_h

#include <stdio.h>
#include "pizza.h"
#include "pizza_place.h"
#include "manage.h"

class baking {
private:
    pizza* pizzas;
    int pizzas_length;
public:
    baking();
    pizza* get_pizzas(pizza_place place);
    
};

#endif /* baking_hpp */
