//
//  order.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "order.h"
#include <ctime>
#include <chrono>
#include "exception.h"

using namespace std;

order::order() {
    this->pizza_count = 0;
    this->side_count = 0;
    this->deliver = 0;
    this->id = -1;
    this->comment[0] = '\0';
    this->address[0] = '\0';
    this->phone_number[0] = '\0';
    this->delivered = false;
    this->late = false;
    this->set_time();
    this->damaged = false;
    this->paid = false;
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
    this->late = false;
    strcpy(this->address, address.c_str());
    //strcpy(this->phone_number, phone.c_str());
    this->set_phone(phone);
    this->set_time();
    this->damaged = false;
    this->paid = false;
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
    if(side_count < 5) {
        this->side_list[this->side_count] = s;
        this->side_count++;
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
    bool valid = true;
    for(int i=0; i<phone.length(); i++) {
        if(!isdigit(phone[i])) {
            valid = false;
        }
    }
    if(!valid) {
        throw phone_exception();
    }
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

int order::get_sides_count() {
    return this->side_count;
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

void order::set_time() {
    time_t now = time(0);
    struct tm tstruct = *localtime(&now);
    this->time_o = tstruct.tm_hour * 60 * 60 + tstruct.tm_min * 60 + tstruct.tm_sec;
    this->day = tstruct.tm_mday;
    this->month = tstruct.tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    this->year = tstruct.tm_year + 1900;
}

int order::get_day() {
    return this->day;
}

int order::get_month() {
    return this->month;
}

int order::get_year() {
    return this->year;
}

int order::get_time() {
    return this->time_o;
}

bool order::get_late() {
    time_t now = time(0);
    struct tm tstruct = *localtime(&now);
    int seconds = tstruct.tm_hour * 60 * 60 + tstruct.tm_min * 60 + tstruct.tm_sec;
    if((seconds - this->time_o) > (30*60)) {
        this->late = true;
    }
    if((seconds - this->time_o) > (60*60)) {
        this->damaged = true;
    }
    return this->late;
}

void order::set_deliver(int del) {
    this->deliver = del;
}

int order::get_deliver() {
    return this->deliver;
}

bool order::get_paid() {
    return this->paid;
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
    if(order.late) {
        out << "Sein." << endl;
    }
    if(order.damaged) {
        out << "Ónýt." << endl;
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
