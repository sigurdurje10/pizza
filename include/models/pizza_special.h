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
        //setur heiti � tilbo�i
        void set_name(string name);
        //setur ver� � tilbo�i
        void set_price(int price);
        //setur l�singu
        void set_description(string desc);
        //setur me�l�ti
        void set_side_order(side_order o);
        //setur fj�lda pizza
        void set_quantity(int quant);
        //setur pizza st�r�
        void set_pizza_size(pizza_size s);
        //n�r � heiti � tilbo�i
        string get_name() const;
        //n�r � ver� � tilbo�i
        int get_price() const;
        //n�r � fj�lda tilbo�a
        int get_quantity() const;
        //n�r � l�singu � tilbo�i
        string get_description() const;
        //n�r � me�l�ti�
        side_order get_side_order() const;
        //n�r � pizzast�r�ina
        pizza_size get_pizza_size() const;
        //setur ver� og heiti
        void set_special(int price, string name);
        //yfirskrifar ostream virkjann
        friend ostream& operator << (ostream& out, const pizza_special& p_special);
        //yfirskrifar istream virkjann
        friend istream& operator >> (istream& in, pizza_special& p_special);



};

#endif // PIZZA_SPECIAL_H
