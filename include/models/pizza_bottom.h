//
//  pizza_bottom.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef pizza_bottom_h
#define pizza_bottom_h

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "exception/exception.h"

using namespace std;

class pizza_bottom {
public:
    pizza_bottom();
    //constructor sem setur verð og heiti botns
    pizza_bottom(int price, string name);
    virtual ~pizza_bottom();
    //setur verð botns, setur exception ef verð er undir 0
    void set_price(int price){
        if(price < 0) {
            throw price_exception();
        }
        this->price = price;
    }
    //setur heiti
    void set_name(string name){
        strcpy(this->name, name.c_str());
    }
    //nær í verð
    int get_price(){
        return price;
    }
    //nær í heiti á botn
    string get_name(){
        string str(name);
        return str;
    }
    void set_pizza_bottom(string name, int price);

    //yfirskrifar ostream
    friend ostream& operator << (ostream& out, const pizza_bottom& p_bottom);
    //yfirskrifar istream
    friend istream& operator >> (istream& in, pizza_bottom& p_bottom);

protected:

private:
    int price;
    char name[20];
};

#endif /* pizza_bottom_h */
