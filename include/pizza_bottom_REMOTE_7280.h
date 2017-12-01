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

using namespace std;

class pizza_bottom {
public:
    pizza_bottom();
    pizza_bottom(int price, string name);
    virtual ~pizza_bottom();
    void set_price(int price){
        this->price = price;
    }
    void set_name(string name){
        strcpy(this->name, name.c_str());
    }
    int get_price(){
        return price;
    }
    string get_name(){
        string str(name);
        return str;
    }
    void set_pizza_bottom(string name, int price);
    
    friend ostream& operator << (ostream& out, const pizza_bottom& p_bottom);
    friend istream& operator >> (istream& in, pizza_bottom& p_bottom);
    
protected:
    
private:
    int price;
    char name[20];
};

#endif /* pizza_bottom_h */
