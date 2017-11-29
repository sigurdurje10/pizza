#ifndef PIZZA_BOTTOM_H
#define PIZZA_BOTTOM_H
#include <string.h>
#include <iostream>

using namespace std;

class pizza_bottom
{
    public:
        pizza_bottom();
        pizza_bottom(int prize, string name);
        virtual ~pizza_bottom();
        void set_prize(int prize){
            this->prize = prize;
        }
        void set_name(string name){
            strcpy(this->name, name.c_str());
        }
        int get_prize(){
            return prize;
        }
        char* get_name(){
            return name;
        }

    protected:

    private:
        int prize;
        char name[20];
};

#endif // PIZZA_BOTTOM_H
