
#include "umsjon.hpp"
#include "pizza_size.h"
#include "pizza_data.h"

umsjon::umsjon() {

}

void umsjon::new_size(int size, int price) {
    pizza_size* s = new pizza_size(size, price);
    pizza_data* d = new pizza_data();
    d->save_size(s);
    delete s;
    delete d;
}

pizza_size* umsjon::get_sizes() {
    pizza_data* p = new pizza_data();
    this->sizes = p->get_sizes();
    this->sizes_length = p->get_sizes_length();
    delete p;
    return this->sizes;
}

int umsjon::get_sizes_length() {
    return this->sizes_length;
}
