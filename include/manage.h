//
//  umsjon.hpp
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef umsjon_h
#define umsjon_h

#include <stdio.h>
#include "pizza_size.h"
#include "pizza_data.h"

class manage {
private:
    pizza_size* sizes;
    int sizes_length;
    //pizza_size* s;
    //pizza_data* d;
    //pizza_data* p;
public:
    manage();
    void new_size(pizza_size* s);
    pizza_size* get_sizes();
    int get_sizes_length();
    void delete_p();
};

#endif /* umsjon_hpp */
