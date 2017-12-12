//
//  side_order_data.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef side_order_data_h
#define side_order_data_h

#include <stdio.h>
#include "models/side_order.h"

class side_order_data {
private:
    int number_of_sides;
    side_order* sides;
public:
    side_order_data();
    //vistar eitt meðlæti í skrá, bætir við þau sem voru
    void save_side(side_order* side);
    //nær í öll meðlæti
    side_order* get_sides();
    //nær í number_of_sides - 1
    int get_sides_length();
    bool is_empty();
};

#endif /* side_order_data_h */
