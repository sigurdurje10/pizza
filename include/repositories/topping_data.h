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
#include "models/topping.h"
#include <string>

using namespace std;

class topping_data {
private:
    int number_of_toppings;
    topping* toppings;
    string topping_file;
public:
    topping_data();
    //vistar eitt álegg í skrá, bætir við þær sem fyrir voru
    void save_topping(topping* topping);
    //nær í öll álegg
    topping* get_toppings();
    //nær í number_of_toppings - 1
    int get_toppings_length();
    //skilar true ef skrá er tóm
    bool is_empty();
};


#endif /* topping_data_h */
