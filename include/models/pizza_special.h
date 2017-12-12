#ifndef PIZZA_SPECIAL_H
#define PIZZA_SPECIAL_H
#include <string>
#include <iostream>

using namespace std;


class pizza_special
{
    public:
        pizza_special();
        pizza_special(int price, string name);
        //setur heiti á tilboði
        void set_name(string name);
        //setur verð á tilboði
        void set_price(int price);
        //nær í heiti á tilboði
        string get_name() const;
        //nær í verð á tilboði
        int get_price() const;
        //setur verð og heiti
        void set_special(int price, string name);
        //yfirskrifar ostream virkjann
        friend ostream& operator << (ostream& out, const pizza_special& p_special);
        //yfirskrifar istream virkjann
        friend istream& operator >> (istream& in, pizza_special& p_special);

    protected:

    private:
        char name[20];
        int price;
};

#endif // PIZZA_SPECIAL_H
