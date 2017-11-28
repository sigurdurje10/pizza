#ifndef PIZZA_SIZE_H
#define PIZZA_SIZE_H

#include <stdio.h>


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
};

#endif // PIZZA_SIZE_H
