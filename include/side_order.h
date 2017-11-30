//
//  side_order.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef side_order_h
#define side_order_h

#include <stdio.h>
#include <string>

using namespace std;

class side_order {
public:
    side_order();
    virtual ~side_order();
    side_order(int price, string name);
    void set_side_order(int price, string name);
    void set_price(int prize);
    void set_name(string name);
    int get_price() const;
    string get_name() const;
    friend ostream& operator << (ostream& out, const side_order& s_order);
    friend istream& operator >> (istream& in, side_order& s_order);
protected:
    
private:
    int price;
    char name[20];
};


#endif /* side_order_h */
