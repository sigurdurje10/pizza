//
//  pizza_place_data.h
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef pizza_place_data_h
#define pizza_place_data_h

#include "pizza_place.h"
#include <iostream>
#include <fstream>
using namespace std;

class pizza_place_data
{
public:
    pizza_place_data();
    virtual ~pizza_place_data();
    void save_place(pizza_place* p);
    pizza_place* get_places();
    int get_places_length();
    bool is_empty();
    
protected:
    
private:
    int number_of_places;
    pizza_place* p_p;
    
};

#endif /* pizza_place_data_h */
