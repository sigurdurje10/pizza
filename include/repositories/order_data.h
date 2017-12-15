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
#include "models/order.h"

class order_data {
private:
    int number_of_orders;
    order* orders;
    string order_file;
public:
    order_data();
    //vistar lista af pöntunum sem virkar pantanir
    void save_orders(order* list);
    void save_orders(order* list, int count);
    //vistar eina pöntun sem virka pöntun
    void save_order(order* p);
    //vistar pöntun sem óvirka pöntun
    void save_old_order(order* p);
    //nær í virkar pantanir
    order* get_orders();
    //nær í virkar pantanir
    order* get_old_orders();
    //nær í fjölda af pöntunum
    int get_orders_length();
    //eru engin skráð virk pöntun? Skilar bool gildi ef tómt
    bool is_empty();
    //er engin skrá óvirk pöntun? Skilar bool gildi ef tómt.
    bool is_old_empty();
};

#endif /* order_data_h */
