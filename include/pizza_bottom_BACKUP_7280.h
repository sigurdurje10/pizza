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
        name[19] = '/0';
    }
    int get_price(){
        return price;
    }
    string get_name(){
        return name;
    }
<<<<<<< HEAD
    friend ostream& operator << (ostream& out, const pizza_bottom& p_bottom);
    friend istream& operator >> (istream& in, pizza_bottom& p_bottom);

=======
    void set_pizza_bottom(string name, int price);
    
    friend ostream& operator << (ostream& out, const pizza_bottom& p_bottom);
    friend istream& operator >> (istream& in, pizza_bottom& p_bottom);
    
>>>>>>> 49c8086319f189b2ed69401af867aec4ab6599b5
protected:
    
private:
    int price;
    char name[20];
};

#endif /* pizza_bottom_h */
