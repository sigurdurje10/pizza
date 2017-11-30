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
    void set_name(string name);
    void set_price(int price);
    string get_name() const;
    int get_price() const;
    void set_topping(int price, string name);
    friend ostream& operator << (ostream& out, const topping& p_topping);
    friend istream& operator >> (istream& in, topping& p_topping);
protected:
    
private:
    char name[20];
    int price;
};

#endif /* topping_h */
