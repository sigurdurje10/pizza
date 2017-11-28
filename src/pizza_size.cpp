#include "pizza_size.h"

pizza_size::pizza_size(int size, int price) {
    this->size = size;
    this->price = price;
}

int pizza_size::get_size() {
    return this->size;
}

int pizza_size::get_price() {
    return this->price;
}
