//
//  topping_data.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef topping_data_h
#define topping_data_h

#include <stdio.h>
#include "topping.h"
#include <string>

using namespace std;

class topping_data {
private:
    int number_of_toppings;
    topping* toppings;
    string topping_file;
public:
    topping_data();
    void save_topping(topping* topping);
    topping* get_toppings();
    int get_toppings_length();
    bool is_empty();
};


#endif /* topping_data_h */
