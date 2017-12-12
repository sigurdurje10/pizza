//
//  topping.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef topping_h
#define topping_h

#include <stdio.h>

#include <string.h>
#include <iostream>

using namespace std;

class topping {
public:
    topping();
    topping(int price, string name);
    virtual ~topping();
    //setur nafnið
    void set_name(string name);
    //setur verðið
    void set_price(int price);
    //nær í nafnið
    string get_name() const;
    //nær í verðið
    int get_price() const;
    //setur verð og nafn
    void set_topping(int price, string name);
    //yfirskrifar ostream
    friend ostream& operator << (ostream& out, const topping& p_topping);
    //yfirskrifar istream
    friend istream& operator >> (istream& in, topping& p_topping);
protected:

private:
    char name[20];
    int price;
};

#endif /* topping_h */
