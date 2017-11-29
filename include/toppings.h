#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <string.h>
#include <iostream>

using namespace std;

class toppings
{
    public:
        toppings();
        toppings(int price, string name);
        virtual ~toppings();
        void set_name(string name){
            strcpy(this->name, name.c_str());
        }
        void set_price(int price){
            this->price = price;
        }
        char* get_name(){
            return name;
        }
        int get_price(){
            return price;
        }
    protected:

    private:
        char name[20];
        int price;
};

#endif // TOPPINGS_H
