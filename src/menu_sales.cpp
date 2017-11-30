//
//  menu_sales.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_sales.h"
#include "menu_pizza.h"
#include "pizza.h"
#include <iostream>
#include <string>
#include "manage.h"
#include "sales.h"
#include "order.h"
#include "side_order.h"

using namespace std;

menu_sales::menu_sales() {
    
}

void menu_sales::start_menu() {
    manage* u = new manage();
    sales* s = new sales();
    char action_s;
    do {
        cout << "Skra pontun(p), Sja heildarverd(v), Skra pontun senta/sotta(s), Merkja pontun greidda(g), Merkja afhendingarstad(a), Skra athugasemd(t), Sja allar pantanir(n) eda haetta(h): ";
        cin >> action_s;
        switch(action_s) {
            case 'p': {
                char action_s_p;
                do {
                    order* o = new order();
                    string phone;
                    cout << "Simanumer: ";
                    cin.ignore();
                    getline(cin, phone);
                    o->set_phone(phone);
                    string address;
                    cout << "Heimilisfang: ";
                    getline(cin, address);
                    o->set_address(address);
                    int p_count = 0;
                    char action_s_p_p;
                    do {
                        cout << "Pitsa af matsedli(m) eda servalin(s):  ";
                        cin >> action_s_p_p;
                        string pizza_name;
                        string bottom;
                        int size;
                        pizza p;
                        if(action_s_p_p == 'm') {
                            string pizza_name = "";
                            while(pizza_name == "") {
                                cout << "Heiti pitsu af matsedli: ";
                                cin.ignore();
                                getline(cin, pizza_name);
                                p = u->find_menu_item(pizza_name);
                                if(p.get_name() == "") {
                                    cout << "Pitsa ekki til stadar." << endl;
                                } else {
                                    cout << "Pitsa '" << p.get_name() << "' valin." << endl;
                                    o->add_pizza(p);
                                }
                                pizza_name = p.get_name();
                            }
                        } else {
                            menu_pizza* mp = new menu_pizza();
                            p = (*mp->get_pizza());
                        }
                        p_count++;
                        p.calculate_price();
                        cout << "Verd pitsu: " << p.get_price() << endl;
                        cout << "Nyja pitsu(n) eda haetta(h):  ";
                        cin >> action_s_p_p;
                    } while(action_s_p_p != 'h' && p_count < 10);
                    int side_count = 0;
                    char action_s_p_s;
                    do {
                        side_order s;
                        string side;
                        string side_name = "";
                        cout << "Medlaeti: ";
                        cin.ignore();
                        getline(cin, side);
                        s = u->find_side(side);
                        side_name = s.get_name();
                        if(side_name == "") {
                            cout << "Medlaeti ekki til stadar." << endl;
                        } else {
                            cout << "Medlaeti '" << side_name << "' valid." << endl;
                        }
                        side_count++;
                        cout << "Nytt medlaeti(n) eda haetta(h):  ";
                        cin >> action_s_p_s;
                    } while(action_s_p_s != 'h' && side_count < 10);
                    int id = 0;
                    if(!s->orders_empty()) {
                        order* orders = s->get_orders();
                        id = s->get_orders_length();
                    }
                    o->set_id(id);
                    s->new_order(o);
                    cout << "Pontunarnumer: " << id << endl;
                    cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                    cin >> action_s_p;
                } while(action_s_p != 'h');
                break;
            }
            case 'v': {
                char action_s_v;
                do {
                    int order_number;
                    cout << "Pontunarnumer: ";
                    cin >> order_number;
                    order* o = new order[1];
                    o[0] = s->find_order(order_number);
                    if(o->get_id() != -1) {
                        cout << "Heildarverd: " << o[0].get_price() << endl; //o->price();
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                    cin >> action_s_v;
                } while(action_s_v != 'h');
                break;
            }
            case 's': {
                char action_s_s;
                do {
                    int order_number;
                    cout << "Pontunarnumer: ";
                    cin >> order_number;
                    order* o = new order[1];
                    o[0] = s->find_order(order_number);
                    cout << "Skra senta(e) eda sotta(o): ";
                    char del;
                    cin >> del;
                    if(del == 'e') {
                        //o->del();
                        o[0].del();
                    } else if(del == 'o') {
                        //o->pickup();
                        o[0].pickup();
                    }
                    s->save_order(o[0]);
                    cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                    cin >> action_s_s;
                } while(action_s_s != 'h');
                break;
            }
            case 'g': {
                char action_s_g;
                do {
                    int order_number;
                    cout << "Pontunarnumer: ";
                    cin >> order_number;
                    order* o = new order[1];
                    o[0] = s->find_order(order_number);
                    o->is_paid();
                    //s->save_order(o);
                    cout << "Pontun hefur verid merkt greidd. " << endl;
                    cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                    cin >> action_s_g;
                } while(action_s_g != 'h');
                break;
            }
            case 'a': {
                char action_s_a;
                do {
                    int order_number;
                    string place;
                    cout << "Pontunarnumer: ";
                    cin >> order_number;
                    cout << "Afhendingarstardur: ";
                    cin.ignore();
                    getline(cin, place);
                    //order* o = new order(order_number);
                    //o->set_place(place);
                    cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                    cin >> action_s_a;
                } while(action_s_a != 'h');
                break;
            }
            case 't': {
                char action_s_t;
                do {
                    int order_number;
                    string comment;
                    cout << "Pontunarnumer: ";
                    cin >> order_number;
                    cout << "Athugasemd: ";
                    cin.ignore();
                    getline(cin, comment);
                    //order* o = new order(order_number);
                    //o->set_comment(comment);
                    cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                    cin >> action_s_t;
                } while(action_s_t != 'h');
                break;
            }
            case 'n':
                order* orders = s->get_orders();
                for(int i = 0; i < s->get_orders_length(); i++) {
                    cout << orders[i];
                }
                break;
        }
    } while(action_s != 'h');
}
