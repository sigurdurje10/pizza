//
//  umsjon.h
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef manage_h
#define manage_h

#include <stdio.h>
#include "models/pizza_size.h"
#include "repositories/pizza_size_data.h"
#include "models/topping.h"
#include "models/pizza_bottom.h"
#include "models/pizza_place.h"
#include "models/side_order.h"
#include "models/pizza.h"
#include "models/user.h"
#include "models/pizza_special.h"

class manage {
private:
    pizza_size* sizes;
    int sizes_length;

    topping* toppings;
    int toppings_length;

    pizza_bottom* bottoms;
    int bottoms_length;

    pizza_place* places;
    int places_length;

    side_order* sides;
    int sides_length;

    pizza* pizzas;
    int pizzas_length;

    user* users;
    int users_length;
    user current_user;

    pizza_special* pizza_special;
    int special_length;
public:
    manage();

    void new_size(pizza_size* s);
    pizza_size* get_sizes();
    pizza_size find_size(int size);
    int get_sizes_length();

    void new_topping(topping* t);
    topping* get_toppings();
    topping find_topping(string topping);
    int get_toppings_length();

    void new_bottom(pizza_bottom* b);
    pizza_bottom* get_bottoms();
    pizza_bottom find_bottom(string bottom);
    int get_bottoms_length();

    void new_place(pizza_place* p);
    pizza_place* get_places();
    pizza_place find_place(string place_value);
    int get_places_length();

    void new_side(side_order* s);
    side_order* get_sides();
    side_order find_side(string side_value);
    int get_sides_length();

    void new_menu_item(pizza* p);
    pizza* get_menu();
    pizza find_menu_item(string pizza_name);
    int get_menu_length();

    void new_user(user* p);
    user* get_users();
    user find_user(string username, string password);
    int get_users_length();
    void set_user(user u);
    user get_user();
/*
    void new_special(pizza_special* p);
    pizza_special* get_specials();
    int get_specials_length();
*/
};

#endif /* umsjon_h */
