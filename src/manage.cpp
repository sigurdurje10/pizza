//
//  umsjon.cpp
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "manage.h"
#include "pizza_size.h"
#include "pizza_data.h"
#include <iostream>

using namespace std;

manage::manage() {
    
}

void manage::new_size(pizza_size* s) {
    pizza_data* d = new pizza_data();
    d->save_size(s);
    delete s;
    delete d;
}

pizza_size* manage::get_sizes() {
    pizza_data* p = new pizza_data();
    this->sizes = p->get_sizes();
    this->sizes_length = p->get_sizes_length();
    delete p;
    return this->sizes;
}

int manage::get_sizes_length() {
    return this->sizes_length;
}
