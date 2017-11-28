#ifndef PIZZA_SIZE_H
#define PIZZA_SIZE_H

#include <stdio.h>


class pizza_size {
private:
    int size;
    int price;
public:
    pizza_size(int size, int price);
    int get_size();
    int get_price();
};

#endif // PIZZA_SIZE_H
