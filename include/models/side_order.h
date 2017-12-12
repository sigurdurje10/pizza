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
    //constructor sem setur verð og heiti
    side_order(int price, string name);
    //fall sem setur eins og constructorinn gerir
    void set_side_order(int price, string name);
    //setur verð
    void set_price(int prize);
    //setur heiti
    void set_name(string name);
    //nær í verð
    int get_price() const;
    //nær í heiti
    string get_name() const;
    //yfirskrifar ostream
    friend ostream& operator << (ostream& out, const side_order& s_order);
    //yfirskrifar istream
    friend istream& operator >> (istream& in, side_order& s_order);
protected:

private:
    int price;
    char name[20];
};


#endif /* side_order_h */
