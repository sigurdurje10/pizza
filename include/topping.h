#ifndef TOPPING_H
#define TOPPING_H
#include <string.h>
#include <iostream>

using namespace std;

class topping
{
    public:
        topping();
        topping(int price, string name);
        virtual ~topping();
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

#endif // TOPPING_H
