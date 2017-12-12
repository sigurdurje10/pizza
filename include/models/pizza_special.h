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
        //setur heiti � tilbo�i
        void set_name(string name);
        //setur ver� � tilbo�i
        void set_price(int price);
        //n�r � heiti � tilbo�i
        string get_name() const;
        //n�r � ver� � tilbo�i
        int get_price() const;
        //setur ver� og heiti
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
