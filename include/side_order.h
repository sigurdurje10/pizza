#ifndef SIDE_ORDER_H
#define SIDE_ORDER_H

#include <string.h>
#include <iostream>

using namespace std;

class side_order
{
    public:
        side_order();
        virtual ~side_order();
        side_order(int prize, string name);
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

#endif // SIDE_ORDER_H
