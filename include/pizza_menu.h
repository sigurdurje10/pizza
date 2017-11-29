#ifndef PIZZA_MENU_H
#define PIZZA_MENU_H


class pizza_menu
{
    public:
        pizza_menu();
        virtual ~pizza_menu();
        void add_pizza(pizza the_pizza);

    protected:

    private:
        pizza menu_pizzas[10];
};

#endif // PIZZA_MENU_H
