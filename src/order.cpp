//
//  order.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "order.h"

order::order() {
    this->pizza_count = 0;
    this->side_count = 0;
    this->deliver = 0;
    this->id = -1;
    this->comment[0] = '\0';
    this->address[0] = '\0';
    this->phone_number[0] = '\0';
    this->delivered = false;
}

order::~order() {
    //dtor
}

order::order(string address, string phone) {
    this->pizza_count = 0;
    this->side_count = 0;
    this->deliver = 0;
    this->id = -1;
    this->comment[0] = '\0';
    this->delivered = false;
    strcpy(this->address, address.c_str());
    strcpy(this->phone_number, phone.c_str());

}

void order::add_pizza(pizza p) {
    p.calculate_price();
    if(pizza_count < 5) {
        this->pizza_list[pizza_count] = p;
        pizza_count++;
    }
}

void order::set_pizza(pizza p, int pizza_count) {
    this->pizza_list[pizza_count] = p;
}

void order::add_side(side_order s) {
    if(side_count < 5){
        this->side_list[side_count] = s;
    }
}

void order::del() {
    this->deliver = 1;
}

void order::pickup() {
    this->deliver = 2;
}

void order::is_paid() {
    this->paid = true;
}

void order::set_address(string address) {
    strcpy(this->address, address.c_str());
}

void order::set_phone(string phone) {
    strcpy(this->phone_number, phone.c_str());
}

void order::set_id(int id) {
    this->id = id;
}

int order::get_id() {
    return this->id;
}

int order::get_price() {
    int sum = 0;
    pizza* p = this->get_pizzas();
    for(int i = 0; i < this->pizza_count; i++) {
        p[i].calculate_price();
        sum += p[i].get_price();
    }
    side_order* s = this->get_side();
    for(int i = 0; i < this->pizza_count; i++) {
        sum += s[i].get_price();
    }
    return sum;
}

void order::set_place(pizza_place p) {
    this->place = p;
}

pizza_place order::get_place() {
    return this->place;
}

void order::set_comment(string s) {
    strcpy(this->comment, s.c_str());
}

string order::get_comment() {
    string str(this->comment);
    return str;
}

pizza* order::get_pizzas() const {
    pizza* pizzas = new pizza[this->pizza_count];
    for(int i = 0; i < this->pizza_count; i++) {
        pizzas[i] = this->pizza_list[i];
    }
    return pizzas;
}

int order::get_pizzas_count() {
    return this->pizza_count;
}

side_order* order::get_side() const {
    side_order* sides = new side_order[this->side_count];
    for(int i = 0; i < this->side_count; i++) {
        sides[i] = this->side_list[i];
    }
    return sides;
}

string order::get_address() {
    string str(this->address);
    return str;
}

string order::get_phone() {
    string str(this->phone_number);
    return str;
}

bool order::get_delivered() {
    return this->delivered;
}

void order::set_delivered(bool d) {
    this->delivered = d;
}

ostream& operator << (ostream& out, const order& order) {
    out << "Id: " << order.id << endl;
    out << "Simanumer: " << order.phone_number << endl;
    out << "Heimilisfang: " << order.address << endl;
    if(order.deliver == 1) {
        out << "Sent" << endl;
    } else if(order.deliver == 2) {
        out << "Sott" << endl;
    }
    if(order.paid) {
        out << "Buid ad greida." << endl;
    }
    out << "Athugasemd: " << order.comment << endl;
    if(order.place.get_name() != "") {
        out << "Afhendingarstadur: " << order.place.get_name() << endl;
    }
    pizza* pizzas = order.get_pizzas();
    for(int i = 0; i < order.pizza_count; i++) {
        out << pizzas[i];
    }
    side_order* sides = order.get_side();
    for(int i = 0; i < order.side_count; i++) {
        out << sides[i];
    }
    return out;
}

istream& operator >> (istream& in, order& order) {

    return in;
}
