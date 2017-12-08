//
//  sales_numbers.h
//  pizza
//
//  Created by Sigurður Jökull on 01/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef sales_numbers_h
#define sales_numbers_h

#include <stdio.h>
#include "models/order.h"
#include "services/sales.h"

class sales_numbers {
private:
    order* active_orders;
    int active_length;
    order* old_orders;
    int old_length;
    sales* s;
    struct people;
public:
    sales_numbers(int day, int month, int year, int date_switch);
    int order_numbers();
    int pizza_numbers();
    int customer_numbers();
    int total_sales();
    int people_numbers();
};

#endif /* sales_numbers_h */
