#ifndef PIZZA_PLACE_H
#define PIZZA_PLACE_H

#include <string.h>
#include <iostream>

using namespace std;

class pizza_place
{
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
        char* get_name(){
            return name;
        }
        char* get_address(){
            return address;
        }

    protected:

    private:
        char name[20];
        char address[30];
};

#endif // PIZZA_PLACE_H
