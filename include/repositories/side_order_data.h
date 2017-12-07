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
#include "side_order.h"

class side_order_data {
private:
    int number_of_sides;
    side_order* sides;
    string side_order_file;
public:
    side_order_data();
    void save_side(side_order* side);
    side_order* get_sides();
    int get_sides_length();
    bool is_empty();
};

#endif /* side_order_data_h */
