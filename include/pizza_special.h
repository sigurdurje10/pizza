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
        void set_name(string name);
        void set_price(int price);
        string get_name() const;
        int get_price() const;
        void set_special(int price, string name);
        friend ostream& operator << (ostream& out, const pizza_special& p_special);
        friend istream& operator >> (istream& in, pizza_special& p_special);

    protected:

    private:
        char name[20];
        int price;
};

#endif // PIZZA_SPECIAL_H
