//
//  order_data.h
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef order_data_h
#define order_data_h

#include <stdio.h>
#include "order.h"

class order_data {
private:
    int number_of_orders;
    order* orders;
    string order_file;
public:
    order_data();
    void save_order(order p, order* list);
    void save_order(order* p);
    order* get_orders();
    int get_orders_length();
    bool is_empty();
};

#endif /* order_data_h */
