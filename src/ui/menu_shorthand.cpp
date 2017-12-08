//
//  menu_shorthand.cpp
//  pizza
//
//  Created by Sigurður Jökull on 01/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "ui/menu_shorthand.h"
#include "models/order.h"
#include <string.h>
#include "models/pizza.h"
#include "services/manage.h"
#include "services/sales.h"

using namespace std;

menu_shorthand::menu_shorthand() {

}

order* menu_shorthand::get_shorthand() {
    manage* u = new manage();
    sales* sales_class = new sales();
    order* o = new order();
    cout << "Skráðu simanumer og heimilisfang" << endl;
    cout << "Fyrir pitsu af matsedli: s:(simanumer); h:(heimilisfang); m:(heiti pitsu); m:(onnur pitsa); e:(medlaeti);" << endl;
    cout << "Fyrir servalda pitsu: s:(simanumer); h:(heimilisfang); p:b:(botn); s:(staerd); a:(alegg);; e:(medlaeti);" << endl;

    string command = "";
    cin.ignore();
    getline(cin, command);

    string delimiter = ";";
    int position_s = command.find("s:");
    int position_semi = command.find(";");
    if(position_s == -1 || position_semi == -1) {
        throw short_exception();
    }
    string phone = command.substr(position_s+2, position_semi-2);
    command = command.substr(position_semi+1, command.length());
    int position_h = command.find("h:");
    position_semi = command.find(";");
    if(position_h == -1 || position_semi == -1) {
        throw short_exception();
    }
    string address = command.substr(position_h+2, position_semi-3);
    command = command.substr(position_semi+1, command.length());
    o->set_phone(phone);
    o->set_address(address);

    int position_m = command.find("m:");
    pizza m;
    while(position_m != -1) {
        position_semi = command.find(";");
        if(position_m == -1 || position_semi == -1) {
            throw short_exception();
        }
        string pizza_name = command.substr(position_m+2, position_semi-3);
        command = command.substr(position_semi+1, command.length());
        m = u->find_menu_item(pizza_name);
        o->add_pizza(m);
        position_m = command.find("m:");
    }

    int position_p = command.find("p:");
    pizza p;
    while(position_p != -1) {
        int position_b = command.find("b:");
        position_semi = command.find(";");
        if(position_p == -1 || position_b == -1 || position_semi == -1) {
            throw short_exception();
        }
        string bottom = command.substr(position_b+2, position_semi-5);
        command = command.substr(position_semi+1, command.length());
        pizza_bottom bottom_obj = u->find_bottom(bottom);
        p.set_pizza_bottom(bottom_obj);

        int position_size = command.find("s:");
        position_semi = command.find(";");
        if(position_size == -1 || position_semi == -1) {
            throw short_exception();
        }
        string size = command.substr(position_size+2, position_semi-3);
        int size_int = stoi(size);
        command = command.substr(position_semi+1, command.length());
        pizza_size size_obj = u->find_size(size_int);
        p.set_pizza_size(size_obj);

        int position_a = command.find("a:");
        topping t;
        while(position_a != -1) {
            position_semi = command.find(";");
            if(position_a == -1 || position_semi == -1) {
                throw short_exception();
            }
            string top = command.substr(position_a+2, position_semi-3);
            command = command.substr(position_semi+1, command.length());
            topping top_obj = u->find_topping(top);
            p.add_topping(top_obj);
            position_a = command.find("a:");
        }

        position_semi = command.find(";");
        command = command.substr(position_semi+1, command.length());
        if(position_semi == -1) {
            throw short_exception();
        }
        o->add_pizza(p);
        position_p = command.find("p:");
        if(position_p == -1) {
            throw short_exception();
        }
    }

    int position_e = command.find("e:");
    side_order s;
    while(position_e != -1) {
        position_semi = command.find(";");
        if(position_e == -1 || position_semi == -1) {
            throw short_exception();
        }
        string side = command.substr(position_e+2, position_semi-3);
        command = command.substr(position_semi+1, command.length());
        s = u->find_side(side);
        o->add_side(s);
        position_e = command.find("e:");
    }
    int id = 0;
    if(!sales_class->orders_empty()) {
        order* orders = sales_class->get_orders();
        id = sales_class->get_orders_length();
    }
    o->set_id(id);
    cout << (*o);
    return o;
}
