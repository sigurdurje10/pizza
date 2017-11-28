#ifndef UMSJON_H
#define UMSJON_H
#include <stdio.h>
#include "pizza_size.h"

class umsjon {
private:
    pizza_size* sizes;
    int sizes_length;
    //pizza_data* p;
public:
    umsjon();
    void new_size(int size, int price);
    pizza_size* get_sizes();
    int get_sizes_length();
};

#endif // UMSJON_H
