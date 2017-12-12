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
    //setur stærðina.
    void set_pizza_size(pizza_size size_of_pizza);
    //setur botninn
    void set_pizza_bottom(pizza_bottom bottom_of_pizza);
    //bætir við áleggi max. 10 álegg, ef álegg eru fl. en 10 þá gerist ekkert þegar það er kallað í þetta fall.
    void add_topping(topping topping);
    //nær í stærð pizzu(heiti og verð), skilar pizza_size object
    pizza_size get_pizza_size() const;
    //nær í stærð botns og verð botns, skilar pizza_bottom object
    pizza_bottom get_pizza_bottom() const;
    //skilar pointer á öll áleggin.
    topping* get_pizza_toppings() const;
    //setur heiti á pizzunni
    void set_name(string name);
    //setur verð á pizzunni
    void set_price(int price);
    //reiknar út verðið
    void calculate_price();
    //nær í heitið
    string get_name() const;
    //nær í verðið
    int get_price() const;
    //setur id á pizzunni, notað í bakstri
    void set_id(int id);
    //nær í id á pizzunni
    int get_id();
    //staða pizzu
    bool get_progress();
    //setur stöðu pizzu
    void set_progress(bool progress);
    //skilar hvort pizza er tilbúinn.
    bool get_ready();
    //setur hvort pizza sé tilbúinn
    void set_ready(bool ready);
    //nær í númer pizzu í order
    int get_p_count();
    //setur númer pizzu í order
    void set_p_count(int p);
    //yfirskrifar ostream
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
