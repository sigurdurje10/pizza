//
//  pizza.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef pizza_h
#define pizza_h

#include <stdio.h>
#include "pizza_size.h"
#include "pizza_bottom.h"
#include "topping.h"
#include <string>

class pizza {
public:
    pizza();
    virtual ~pizza();
    void set_pizza_size(pizza_size size_of_pizza);
    void set_pizza_bottom(pizza_bottom bottom_of_pizza);
    void add_topping(topping topping);
    pizza_size get_pizza_size() const;
    pizza_bottom get_pizza_bottom() const;
    topping* get_pizza_toppings() const;
    void set_name(string name);
    void set_price(int price);
    void calculate_price();
    string get_name() const;
    int get_price() const;
    void set_id(int id);
    int get_id();
    bool get_progress();
    void set_progress(bool progress);
    bool get_ready();
    void set_ready(bool ready);
    int get_p_count();
    void set_p_count(int p);
    friend ostream& operator << (ostream& out, const pizza& pizza);
    friend istream& operator >> (istream& in, pizza& pizza);
    
protected:
    
private:
    pizza_size size_of_pizza;
    pizza_bottom bottom_of_pizza;
    topping toppings_of_pizza[10];
    int price;
    int curr_toppings;
    char name[64];
    int id;
    bool in_progress;
    bool ready;
    int p_count;
};

#endif /* pizza_h */
