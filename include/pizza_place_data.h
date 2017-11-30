#ifndef PIZZA_PLACE_DATA_H
#define PIZZA_PLACE_DATA_H
#include "pizza_place.h"
#include <iostream>
#include <fstream>
using namespace std;

class pizza_place_data
{
    public:
        pizza_place_data();
        virtual ~pizza_place_data();
        void save_place(pizza_place* p);
        pizza_place* get_places();
        int get_places_length();
        bool is_empty();

    protected:

    private:
        int number_of_places;
        pizza_place* p_p;

};

#endif // PIZZA_PLACE_DATA_H
