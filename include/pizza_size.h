#ifndef PIZZA_SIZE_H
#define PIZZA_SIZE_H

#include <stdio.h>
#include <iostream>
using namespace std;

class pizza_size {
private:
    int size;
    int price;
public:
    pizza_size();
    pizza_size(int size, int price);
    int get_size();
    int get_price();
    void set_size(int size);
    void set_price(int price);
    void set_pizza(int size, int price);
    friend ostream& operator << (ostream& out, const pizza_size& p_size);
    friend istream& operator >> (istream& in, pizza_size& p_size);
};

#endif // PIZZA_SIZE_H
