#ifndef ORDER_H
#define ORDER_H


class order
{
    public:
        order();
        virtual ~order();
        //get set foll

    protected:

    private:
        pizza pizza_list[5];
        side_order side_list[5];
        char address[20];
        char phone_number[8];
};

#endif // ORDER_H
