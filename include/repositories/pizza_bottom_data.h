//
//  pizza_bottom_data.h
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef pizza_bottom_data_h
#define pizza_bottom_data_h

#include <stdio.h>
#include "pizza_bottom.h"

class pizza_bottom_data {
private:
    int number_of_bottoms;
    pizza_bottom* bottoms;
    string pizza_bottom_file;
public:
    pizza_bottom_data();
    void save_bottom(pizza_bottom* bottom);
    pizza_bottom* get_bottoms();
    int get_bottoms_length();
    bool is_empty();
};

#endif /* pizza_bottom_data_h */
