//
//  pizza_menu.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef pizza_menu_h
#define pizza_menu_h

#include <stdio.h>
#include "pizza.h"

class pizza_menu {
public:
    pizza_menu();
    virtual ~pizza_menu();
    void add_pizza(pizza* the_pizza);
    
protected:
    
private:
    pizza menu_pizzas[10];
};

#endif /* pizza_menu_h */
