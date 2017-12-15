//
//  order_data.cpp
//  order
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "repositories/order_data.h"
#include <iostream>
#include <fstream>

order_data::order_data() {
    this->order_file = "orders.dat";
}

//savear lista, býr til order af fjölda get_orders_length(), objectið heitir orders.
//copyar úr list í orders með for loop.
//skrifar síðan úr orders í orders.dat
void order_data::save_orders(order* list) {
    ofstream fout;
    order* p_m = this->get_orders();
    order orders[this->get_orders_length()];
    for(int i = 0; i < this->get_orders_length(); i++) {
        orders[i] = list[i];
    }
    fout.open("orders.dat", ios::out|ios::binary);
    fout.write((char*)(&orders), sizeof(order)*(this->get_orders_length())); //char pointer(pointer á byte) á fyrsta order
    // síðan stærð á order klasa margafaldað með fjölda af pöntunum. Sem sagt allt orders skrifar í orders.dat

    fout.close();
}

void order_data::save_orders(order* list, int count) {
    ofstream fout;
    order orders[count];
    for(int i = 0; i < count; i++) {
        orders[i] = list[i];
    }
    fout.open("orders.dat", ios::out|ios::binary);
    fout.write((char*)(&orders), sizeof(order)*(count));
    fout.close();
}

//sama gert og save_orders. Ef það er eitthvað fyrir í skránni þá er fyrst náð í orders úr skránni með get_orders
//svo er þessu order bætt við og því er öllu síðan bombað í skránna.
//ef það er ekkert í skránni þá er p skrifað beint í skránna án þess að sækja eitthvað sem var fyrir
void order_data::save_order(order* p) {
    ofstream fout;
    if(!this->is_empty()) {
        order* p_m = this->get_orders();
        order orders[this->number_of_orders+1];
        for(int i = 0; i < this->number_of_orders; i++) {
            orders[i] = p_m[i];
        }
        orders[this->number_of_orders-1] = (*p);
        fout.open("orders.dat", ios::out|ios::binary);
        fout.write((char*)(&orders), sizeof(order)*(this->number_of_orders));
        fout.close();
    } else {
        order x[1];
        x[0] = p[0];
        fout.open("orders.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(order));
        fout.close();
    }
}

//sama og í save_order nema hér er sett í order_old.dat.
void order_data::save_old_order(order* p) {
    ofstream fout;
    if(!this->is_old_empty()) {
        order* p_m = this->get_old_orders();
        order orders[this->number_of_orders+1];
        for(int i = 0; i < this->number_of_orders; i++) {
            orders[i] = p_m[i];
        }
        orders[this->number_of_orders-1] = (*p);
        fout.open("orders_old.dat", ios::out|ios::binary);
        fout.write((char*)(&orders), sizeof(order)*(this->number_of_orders));
        fout.close();
    } else {
        order x[1];
        x[0] = p[0];
        fout.open("orders_old.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(order));
        fout.close();
    }
}

//skoðað hvort skráin sé tóm með því að skoða hvort að endinn á file skili 0 eða 1
bool order_data::is_empty() {
    ifstream fin;
    fin.open("orders.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

//sama og is_empty nema fyrir orders_old.dat
bool order_data::is_old_empty() {
    ifstream fin;
    fin.open("orders_old.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

//skilar öllum orders úr orders.dat
order* order_data::get_orders() {
    ifstream fin;
    fin.open("orders.dat", ios::binary);
    fin.seekg(0, fin.end); //fer í enda skrár
    int records = (fin.tellg() / sizeof(order)); //records er = fjöldi orders í orders.dat - 1
    fin.seekg(0, fin.beg);//setur næsta char sem á að taka úr input stream í byrjun files
    this->number_of_orders = records+1;
    order p_m[records+1];
    fin.read((char*)(&p_m), sizeof(order)*(records));//setur inní p_m það sem er í orders.dat
    this->orders = new order[records+1];
    for(int i = 0; i < records; i++) {
        this->orders[i] = p_m[i];
    }
    fin.close();
    return this->orders;//skilar því sem var í orders.dat
}

//sama og get_orders
order* order_data::get_old_orders() {
    this->number_of_orders = 1;
    if(!this->is_old_empty()) {
        ifstream fin;
        fin.open("orders_old.dat", ios::binary);
        fin.seekg(0, fin.end);
        int records = (fin.tellg() / sizeof(order));
        fin.seekg(0, fin.beg);
        this->number_of_orders = records+1;
        order p_m[records+1];
        fin.read((char*)(&p_m), sizeof(order)*(records));
        this->orders = new order[records+1];
        for(int i = 0; i < records; i++) {
            this->orders[i] = p_m[i];
        }
        fin.close();
    }
    return this->orders;
}

int order_data::get_orders_length() {
    return this->number_of_orders-1;
}


