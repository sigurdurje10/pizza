#include "pizza_size.h"

pizza_size::pizza_size() {

}

pizza_size::pizza_size(int size, int price) {
    this->size = size;
    this->price = price;
}

void pizza_size::set_pizza(int size, int price) {
    this->size = size;
    this->price = price;
}

int pizza_size::get_size() {
    return this->size;
}

int pizza_size::get_price() {
    return this->price;
}

void pizza_size::set_size(int size) {
    this->size = size;
}

void pizza_size::set_price(int price) {
    this->price = price;
}
