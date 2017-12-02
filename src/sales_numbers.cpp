//
//  sales_numbers.cpp
//  pizza
//
//  Created by Sigurður Jökull on 01/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "sales_numbers.h"
#include "sales.h"

sales_numbers::sales_numbers(int day, int month, int year, int date_switch) {
    this->s = new sales();
    this->active_orders = this->s->get_orders();
    this->active_length = this->s->get_orders_length();
    this->old_orders = this->s->get_old_orders();
    this->old_length = this->s->get_orders_length();
    if(day == 0 && month == 0 && year == 0) {
    } else if(date_switch == 1) {
        order* active_orders_date = new order[this->active_length];
        int orders_date_count = 0;
        for(int i=0; i<this->active_length; i++) {
            order o = this->active_orders[i];
            if(o.get_year() > year) {
                active_orders_date[orders_date_count] = o;
                orders_date_count++;
            } else if(o.get_year() == year) {
                if(o.get_month() > month) {
                    active_orders_date[orders_date_count] = o;
                    orders_date_count++;
                } else if(o.get_month() == month) {
                    if(o.get_day() > day || o.get_day() == day) {
                        active_orders_date[orders_date_count] = o;
                        orders_date_count++;
                    }
                }
            }
        }
        this->active_orders = active_orders_date;
        this->active_length = orders_date_count;
        order* old_orders_date = new order[this->old_length];
        int old_date_count = 0;
        for(int i=0; i<this->old_length; i++) {
            order o = this->old_orders[i];
            if(o.get_year() > year) {
                old_orders_date[orders_date_count] = o;
                old_date_count++;
            } else if(o.get_year() == year) {
                if(o.get_month() > month) {
                    old_orders_date[orders_date_count] = o;
                    old_date_count++;
                } else if(o.get_month() == month) {
                    if(o.get_day() > day || o.get_day() == day) {
                        old_orders_date[orders_date_count] = o;
                        old_date_count++;
                    }
                }
            }
        }
        this->old_orders = old_orders_date;
        this->old_length = old_date_count;
    } else if(date_switch == 2) {
        order* active_orders_date = new order[this->active_length];
        int orders_date_count = 0;
        for(int i=0; i<this->active_length; i++) {
            order o = this->active_orders[i];
            if(o.get_year() == year) {
                if(o.get_month() == month) {
                    if(o.get_day() == day) {
                        active_orders_date[orders_date_count] = o;
                        orders_date_count++;
                    }
                }
            }
        }
        this->active_orders = active_orders_date;
        this->active_length = orders_date_count;
        order* old_orders_date = new order[this->old_length];
        int old_date_count = 0;
        for(int i=0; i<this->old_length; i++) {
            order o = this->old_orders[i];
            if(o.get_year() == year) {
                if(o.get_month() == month) {
                    if(o.get_day() == day) {
                        old_orders_date[orders_date_count] = o;
                        old_date_count++;
                    }
                }
            }
        }
        this->old_orders = old_orders_date;
        this->old_length = old_date_count;
    }
}

int sales_numbers::order_numbers() {
    int sum = this->active_length;
    sum += this->old_length;
    return sum;
}

int sales_numbers::pizza_numbers() {
    int sum = 0;
    for(int i=0; i<this->active_length; i++) {
        sum += this->active_orders[i].get_pizzas_count();
    }
    for(int i=0; i<this->old_length; i++) {
        sum += this->old_orders[i].get_pizzas_count();
    }
    return sum;
}

int sales_numbers::total_sales() {
    int sum = 0;
    for(int i=0; i<this->active_length; i++) {
        sum += this->active_orders[i].get_price();
    }
    for(int i=0; i<this->old_length; i++) {
        sum += this->old_orders[i].get_price();
    }
    return sum;
}
