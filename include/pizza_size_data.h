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
#include "pizza_size.h"

class pizza_size_data {
private:
    int number_of_sizes;
    pizza_size* p_z;
public:
    pizza_size_data();
    void save_size(pizza_size* p);
    pizza_size* get_sizes();
    int get_sizes_length();
    bool is_empty();
};


#endif /* pizza_data_h */
