//
//  pizza_place.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef pizza_place_h
#define pizza_place_h

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

class pizza_place {
public:
    pizza_place();
    pizza_place(string name, string addr);
    virtual ~pizza_place();
    void set_name(string name){
        strcpy(this->name, name.c_str());
    }
    void set_address(string addr){
        strcpy(this->address, addr.c_str());
    }
    string get_name() const;
    string get_address() const;
    
    friend ostream& operator << (ostream& out, const pizza_place& p_place);
    friend istream& operator >> (istream& in, pizza_place& p_place);
    
protected:
    
private:
    char name[20];
    char address[30];
};

#endif /* pizza_place_h */
