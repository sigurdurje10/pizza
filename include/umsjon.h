#ifndef UMSJON_H
#define UMSJON_H
#include <stdio.h>
#include "pizza_size.h"

class umsjon {
private:
    pizza_size* sizes;
public:
    umsjon();
    void new_size(int size, int price);
    pizza_size* get_sizes();
};
#endif // UMSJON_H
