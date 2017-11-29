#ifndef PIZZA_H
#define PIZZA_H
#include "pizza_bottom.h"
#include "pizza_size.h"
#include "topping.h"

class pizza
{
    public:
        pizza();
        virtual ~pizza();
        void set_pizza_size(pizza_size size_of_pizza);
        void set_pizza_bottom(pizza_bottom bottom_of_pizza);
        void add_topping(topping topping);
        pizza_size get_pizza_size();
        void set_price();


    protected:

    private:
        pizza_size size_of_pizza;
        pizza_bottom bottom_of_pizza;
        topping toppings_of_pizza[10];
        int prize;
        int curr_toppings;

};

#endif // PIZZA_H
