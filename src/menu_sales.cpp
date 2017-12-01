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
#include <limits>

using namespace std;

menu_sales::menu_sales() {

}

void menu_sales::start_menu() {
    manage* u = new manage();
    sales* s = new sales();
    char action_s;
    do {
        bool accepted = true;
        do {
            cout << "Skra pontun(p), Skra pontun flytileid(f), Sja heildarverd(v), Skra pontun senta/sotta(s), Merkja pontun greidda(g), Merkja afhendingarstad(a), Skra athugasemd(t), Sja allar pantanir(n) eda haetta(h): ";
            cin >> action_s;
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted);
        switch(action_s) {
            case 'f': {
                order* o;
                menu_shorthand* shorthand = new menu_shorthand();
                o = shorthand->get_shorthand();
                break;
            }
            case 'p': {
                char action_s_p;
                do {
                    cin.ignore();
                    bool accepted = true;
                    order* o = new order();
                    string phone = "";
                    string address = "";
                    do {
                        cout << "Simanumer: ";
                        getline(cin, phone);
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                        if(accepted && phone != "") {
                            cout << "Heimilisfang: ";
                            getline(cin, address);
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        }
                    } while(!accepted || phone == "" || address == "");
                    o->set_phone(phone);
                    o->set_address(address);
                    int p_count = 0;
                    char action_s_p_p;
                    do {
                        cout << "Pitsa af matsedli(m) eda servalin(s):  ";
                        bool accepted = true;
                        do {
                            cin >> action_s_p_p;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        } while(!accepted);
                        string pizza_name = "";
                        string bottom = "";
                        int size = -1;
                        pizza p;
                        if(action_s_p_p == 'm') {
                            string pizza_name = "";
                            cin.ignore();
                            while(pizza_name == "") {
                                cout << "Heiti pitsu af matsedli: ";
                                getline(cin, pizza_name);
                                p = u->find_menu_item(pizza_name);
                                if(p.get_name() == "" || pizza_name == "") {
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
                        accepted = true;
                        do {
                            cout << "Nyja pitsu(n) eda haetta(h):  ";
                            cin >> action_s_p_p;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        } while(!accepted);
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
                        if(side_name == "" || side == "") {
                            cout << "Medlaeti ekki til stadar." << endl;
                        } else {
                            cout << "Medlaeti '" << side_name << "' valid." << endl;
                            o->add_side(s);
                        }
                        side_count++;
                        bool accepted = true;
                        do {
                            cout << "Nytt medlaeti(n) eda haetta(h):  ";
                            cin >> action_s_p_s;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        } while(!accepted);
                    } while(action_s_p_s != 'h' && side_count < 10);
                    
                    int id = 0;
                    if(!s->orders_empty()) {
                        order* orders = s->get_orders();
                        id = s->get_orders_length();
                    }
                    o->set_id(id);
                    s->new_order(o);
                    cout << "Pontunarnumer: " << id << endl;
                    accepted = true;
                    do {
                        cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                        cin >> action_s_p;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_s_p != 'h');
                break;
            }
            case 'v': {
                char action_s_v;
                do {
                    bool accepted = true;
                    int order_number = -1;
                    do {
                        cout << "Pontunarnumer: ";
                        cin >> order_number;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted || order_number == -1);
                    order* o = new order[1];
                    o[0] = s->find_order(order_number);
                    if(o[0].get_id() != -1) {
                        cout << "Heildarverd: " << o[0].get_price() << endl; //o->price();
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    accepted = true;
                    do {
                        cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                        cin >> action_s_v;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_s_v != 'h');
                break;
            }
            case 's': {
                char action_s_s;
                do {
                    bool accepted = true;
                    int order_number = -1;
                    do {
                        cout << "Pontunarnumer: ";
                        cin >> order_number;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted || order_number == -1);
                    order* o = new order[1];
                    o[0] = s->find_order(order_number);
                    if(o[0].get_id() != -1) {
                        bool accepted = true;
                        char del;
                        do {
                            cout << "Skra senta(e) eda sotta(o): ";
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        } while(!accepted);
                        cin >> del;
                        if(del == 'e') {
                            o[0].del();
                        } else if(del == 'o') {
                            o[0].pickup();
                        }
                        s->save_order(o[0]);
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    accepted = true;
                    do {
                        cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                        cin >> action_s_s;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_s_s != 'h');
                break;
            }
            case 'g': {
                char action_s_g;
                do {
                    bool accepted = true;
                    int order_number = -1;
                    do {
                        cout << "Pontunarnumer: ";
                        cin >> order_number;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted || order_number == -1);
                    order* o = new order[1];
                    o[0] = s->find_order(order_number);
                    if(o[0].get_id() != -1) {
                        o[0].is_paid();
                        s->save_order(o[0]);
                        cout << "Pontun hefur verid merkt greidd. " << endl;
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    accepted = true;
                    do {
                        cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                        cin >> action_s_g;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_s_g != 'h');
                break;
            }
            case 'a': {
                char action_s_a;
                do {
                    bool accepted = true;
                    int order_number = -1;
                    string place = "";
                    do {
                        cout << "Pontunarnumer: ";
                        cin >> order_number;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted || order_number == -1);
                    string place_value = "";
                    pizza_place p;
                    cin.ignore();
                    while(place_value == "") {
                        cout << "Afhendingarstardur: ";
                        getline(cin, place);
                        p = u->find_place(place);
                        place_value = p.get_name();
                        if(place_value == "") {
                            cout << "Stadur finnst ekki." << endl;
                        } else {
                            cout << "Stadur '" << place_value << "' valinn." << endl;
                        }
                    }
                    order o = s->find_order(order_number);
                    if(o.get_id() != -1) {
                        o.set_place(p);
                        s->save_order(o);
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    accepted = true;
                    do {
                        cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                        cin >> action_s_a;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_s_a != 'h');
                break;
            }
            case 't': {
                char action_s_t;
                do {
                    int order_number = -1;
                    string comment = "";
                    do {
                        cout << "Pontunarnumer: ";
                        cin >> order_number;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                        if(accepted && order_number != -1) {
                            cout << "Athugasemd: ";
                            cin.ignore();
                            getline(cin, comment);
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        }
                    } while(!accepted || order_number == -1 || comment == "");
                    order o = s->find_order(order_number);
                    if(o.get_id() != -1) {
                        o.set_comment(comment);
                        s->save_order(o);
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    bool accepted = true;
                    do {
                        cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                        cin >> action_s_t;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
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
