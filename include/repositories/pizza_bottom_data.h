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
#include "models/pizza_bottom.h"

class pizza_bottom_data {
private:
    int number_of_bottoms;
    pizza_bottom* bottoms;
public:
    pizza_bottom_data();
    //vistar eitt tilvik af bottom í skrá, bætir við þær sem voru
    void save_bottom(pizza_bottom* bottom);
    //nær í öll tilvik af pizza_bottom úr skrá
    pizza_bottom* get_bottoms();
    //skilar number_of_bottoms - 1
    int get_bottoms_length();
    bool is_empty();
};

#endif /* pizza_bottom_data_h */
