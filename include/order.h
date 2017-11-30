//
//  order.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef order_h
#define order_h

#include <stdio.h>
#include "pizza.h"
#include "side_order.h"

class order {
public:
    order();
    virtual ~order();
    order(string address, string phone);
    void add_pizza(pizza p);
    void add_side(side_order s);
    void set_address(string address);
    void set_phone(string phone);
    pizza* get_pizzas() const;
    side_order* get_side() const;
    string get_address();
    string get_phone();
    void set_id(int id);
    int get_id();
    int get_price();
    void del();
    void pickup();
    void is_paid();
    void set_place(pizza_place place);
    pizza_place get_place();
    void set_comment(string s);
    string get_comment();
    int get_pizzas_count();
    friend ostream& operator << (ostream& out, const order& order);
    friend istream& operator >> (istream& in, order& order);
protected:
    
private:
    pizza pizza_list[5];
    int pizza_count;
    side_order side_list[5];
    int side_count;
    char address[20];
    char phone_number[8];
    int id;
    int deliver;
    bool paid;
    pizza_place place;
    char comment[128];
};

#endif /* order_h */
