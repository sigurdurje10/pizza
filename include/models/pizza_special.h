#ifndef PIZZA_SPECIAL_H
#define PIZZA_SPECIAL_H
#include <string>
#include <iostream>
#include "models/side_order.h"
#include "models/pizza_size.h"

using namespace std;


class pizza_special
{

    private:
        char name[20];
        char description[80];
        int quantity;
        int price;
        side_order side_o;
        pizza_size pizza_s;

    public:
        pizza_special();
        pizza_special(int price, string name);
        //setur heiti á tilboði
        void set_name(string name);
        //setur verð á tilboði
        void set_price(int price);
        //setur lýsingu
        void set_description(string desc);
        //setur meðlæti
        void set_side_order(side_order o);
        //setur fjölda pizza
        void set_quantity(int quant);
        //setur pizza stærð
        void set_pizza_size(pizza_size s);
        //nær í heiti á tilboði
        string get_name() const;
        //nær í verð á tilboði
        int get_price() const;
        //nær í fjölda tilboða
        int get_quantity() const;
        //nær í lýsingu á tilboði
        string get_description() const;
        //nær í meðlætið
        side_order get_side_order() const;
        //nær í pizzastærðina
        pizza_size get_pizza_size() const;
        //setur verð og heiti
        void set_special(int price, string name);
        //yfirskrifar ostream virkjann
        friend ostream& operator << (ostream& out, const pizza_special& p_special);
        //yfirskrifar istream virkjann
        friend istream& operator >> (istream& in, pizza_special& p_special);



};

#endif // PIZZA_SPECIAL_H
