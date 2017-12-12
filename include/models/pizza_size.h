//
//  pizza_size.h
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef pizza_size_h
#define pizza_size_h

#include <stdio.h>
#include <iostream>
using namespace std;

class pizza_size {
private:
    int size;
    int price;
public:
    pizza_size();
    //constructor sem setur stærð og verð
    pizza_size(int size, int price);
    //nær í stærð
    int get_size();
    //nær í verð
    int get_price();
    //setur stærð
    void set_size(int size);
    //setur verð
    void set_price(int price);
    //setur stærð og verð
    void set_pizza(int size, int price);
    //yfirskrifar ostream
    friend ostream& operator << (ostream& out, const pizza_size& p_size);
    //yfirskrifar istream
    friend istream& operator >> (istream& in, pizza_size& p_size);
};

#endif /* pizza_size_h */
