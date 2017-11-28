
#include "umsjon.hpp"
#include "pizza_size.h"
#include "pizza_data.h"

umsjon::umsjon() {

}

void umsjon::new_size(int size, int price) {
    pizza_size* s = new pizza_size(size, price);
    //data* d = new data(s, "sizes.txt");
}

pizza_size* umsjon::get_sizes() {
    pizza_data* p = new pizza_data();
    this->sizes = p->get_sizes();
    return this->sizes;
}
