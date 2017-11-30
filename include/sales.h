//
//  sales.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef sales_h
#define sales_h

#include <stdio.h>
#include "order.h"

class sales {
private:
    order* orders;
    int orders_length;
public:
    sales();
    void new_order(order* o);
    void save_order(order o);
    order* get_orders();
    order find_order(int id);
    int get_orders_length();
    bool orders_empty();
    
};

#endif /* sales_h */
