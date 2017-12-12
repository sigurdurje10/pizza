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
#include "pizza_place.h"

class order {
public:
    order();
    virtual ~order();
    //setur heimilisfang og símanúmer viðskiptavinar
    order(string address, string phone);
    //bætir við tilviki af pizzu við pöntun
    void add_pizza(pizza p);
    //setur pizza p í stað pizzu sem var númer #pizza_count
    void set_pizza(pizza p, int pizza_count);
    //bæri við meðlæti
    void add_side(side_order s);
    //setur heimilisfang
    void set_address(string address);
    //setur símanúmer
    void set_phone(string phone);
    //nær í allar pizzur í pöntuninni, skilar pizza pointer
    pizza* get_pizzas() const;
    //nær í öll meðlæti í pöntuninni, skila side_order pointer
    side_order* get_side() const;
    //nær í heimilisfang
    string get_address();
    //nær í símanúmer
    string get_phone();
    //setur order id
    void set_id(int id);
    //nær í order id
    int get_id();
    //nær í order verð
    int get_price();
    //setur að það eigi að senda pizzu
    void del();
    //setur að það eigi að sækja pizzu
    void pickup();
    //setur að það sé búið að borga
    void is_paid();
    //nær í upl. hvort það sé búið að borga.
    bool get_paid();
    //setur hvaða pizzastaður sér um pöntunina
    void set_place(pizza_place place);
    //nær í hvaða pizzastaður sér um pöntunina
    pizza_place get_place();
    //setur inn athugasemd, max 128 stafir
    void set_comment(string s);
    //nær í athugasemd
    string get_comment();
    //nær í fjölda pizza í pöntun
    int get_pizzas_count();
    //nær í fjölda meðlætis
    int get_sides_count();
    //skilar bool gildi hvort það sé búið að afhenda
    bool get_delivered();
    //setur hvort það sé búið að afhenda
    void set_delivered(bool d);
    //setur tíma pöntunar
    void set_time();
    //nær í tíma pöntunar
    int get_time();
    //er pöntun sein? ónýt? Skilar hvort hún er sein. Stillir private breytuna damaged ef hún er ónýt.
    bool get_late();
    //nær í hvort það eigi að sækja
    int get_deliver();
    //setur hvort það eigi að sækja
    void set_deliver(int del);
    //nær í daginn sem pöntunin var gerð
    int get_day();
    //nær í mánuð sem pöntunin var gerð
    int get_month();
    //nær í ár sem pöntunin var gerð
    int get_year();
    //yfirskrifar ostream
    friend ostream& operator << (ostream& out, const order& order);
    //yfirskrifar istream
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
    bool delivered;
    int time_o;
    bool late;
    bool damaged;
    int day;
    int month;
    int year;
};

#endif /* order_h */
