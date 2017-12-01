//
//  delivery.h
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef delivery_h
#define delivery_h

#include <stdio.h>
#include "order.h"
#include "pizza_place.h"

class delivery {
private:
    order* orders;
    int orders_length;
    int orders_ready_length;
public:
    delivery();
    order* get_orders(pizza_place place);
    int get_orders_length();
    order* get_orders_ready(pizza_place place);
    int get_orders_ready_length();
};

#endif /* delivery_h */
