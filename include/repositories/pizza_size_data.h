//
//  pizza_data.h
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef pizza_data_h
#define pizza_data_h

#include <stdio.h>
#include "models/pizza_size.h"

class pizza_size_data {
private:
    int number_of_sizes;
    pizza_size* p_z;
public:
    pizza_size_data();
    //vistar tilvik af pizza_size í skrá
    void save_size(pizza_size* p);
    //nær í allar stærðir úr skránni og skilar pointer á fyrsta tilvikið
    pizza_size* get_sizes();
    //skilar number_of_sizes - 1
    int get_sizes_length();
    //skilar hvort skráin sé tóm
    bool is_empty();
};


#endif /* pizza_data_h */
