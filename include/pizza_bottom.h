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
#include <string>

using namespace std;

class pizza_bottom {
public:
    pizza_bottom();
    pizza_bottom(int prize, string name);
    virtual ~pizza_bottom();
    void set_prize(int prize){
        this->price = prize;
    }
    void set_name(string name){
        strcpy(this->name, name.c_str());
    }
    int get_prize(){
        return price;
    }
    string get_name(){
        string str(name);
        return str;
    }
    
protected:
    
private:
    int price;
    char name[20];
};

#endif /* pizza_bottom_h */
