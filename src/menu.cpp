//
//  menu.cpp
//  pizza
//
//  Created by Sigurður Jökull on 27/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu.h"


menu::menu() {

}

void menu::start_menu() {
    char action;
    do {
        cout << "Veldu Umsjon(u), Sala(s), Bakstur(b), Afhending(a) eda haetta(h): ";
        cin >> action;
        switch(action) {
            case 'u': {
                char action_u;
                umsjon* u = new umsjon();
                do {
                    cout << "Veldu Skra staerd(s), Skra botn(b), Skra alegg(a), Skra matsedil(m), Skra medlaeti(e), Skra stadi(t) eda haetta(h): ";
                    cin >> action_u;
                    switch(action_u) {
                        case 's':
                            char action_u_s;
                            do {
                                int size;
                                int price;
                                cout << "Ny staerd:  ";
                                cin >> size;
                                cout << "Verd:  ";
                                cin >> price;
                                u->new_size(size, price);
                                cout << "Veldu Nyja staerd(n) eda haetta(h): ";
                                cin >> action_u_s;
                            } while(action_u_s != 'h');
                            break;
                        case 'b':
                            char action_u_b;
                            do {
                                string bottom;
                                int price;
                                cout << "Nyr botn:  ";
                                cin.ignore();
                                getline(cin, bottom);
                                cout << "Verd:  ";
                                cin >> price;
                                //u->new_bottom(bottom, price);
                                cout << "Veldu Nyjan botn(n) eda haetta(h): ";
                                cin >> action_u_b;
                            } while(action_u_b != 'h');
                            break;
                        case 'a':
                            char action_u_a;
                            do {
                                string topping;
                                int price;
                                cout << "Nytt alegg:  ";
                                cin.ignore();
                                getline(cin, topping);
                                cout << "Verd:  ";
                                cin >> price;
                                //u->new_topping(topping, price);
                                cout << "Veldu Nytt alegg(n) eda haetta(h): ";
                                cin >> action_u_a;
                            } while(action_u_a != 'h');
                            break;
                        case 'm':
                            char action_u_m;
                            do {
                                string name;
                                int price;
                                cout << "Ny pitsa a matsedli:  ";
                                cin.ignore();
                                getline(cin, name);
                                cout << "Verd:  ";
                                cin >> price;
                                string toppings[10];
                                string topping;
                                char action_u_m_t;
                                int top_count = 0;
                                do {
                                    cout << "Alegg: ";
                                    cin.ignore();
                                    getline(cin, topping);
                                    toppings[top_count] = topping;
                                    top_count++;
                                    cout << "Nytt alegg(n) eda haetta(h): ";
                                    cin >> action_u_m_t;
                                } while(action_u_m_t != 'h' && top_count < 10);
                                //u->new_menu_item(name, price, toppings);
                                cout << "Veldu Nyja pitsu(n) eda haetta(h): ";
                                cin >> action_u_m;
                            } while(action_u_m != 'h');
                            break;
                        case 'e':
                            char action_u_e;
                            do {
                                string side;
                                int price;
                                cout << "Nytt medlaeti:  ";
                                cin.ignore();
                                getline(cin, side);
                                cout << "Verd:  ";
                                cin >> price;
                                //u->new_side(side, price);
                                cout << "Veldu Nytt medlaeti(n) eda haetta(h): ";
                                cin >> action_u_e;
                            } while(action_u_e != 'h');
                            break;
                        case 't':
                            char action_u_t;
                            do {
                                string place;
                                cout << "Nyr afhendingarstadur:  ";
                                cin.ignore();
                                getline(cin, place);
                                //u->new_place(place);
                                cout << "Veldu Nyjan afhendingarstad(n) eda haetta(h): ";
                                cin >> action_u_t;
                            } while(action_u_t != 'h');
                            break;
                    }
                } while(action_u != 'h');
                break;
            }
            case 's': {
                char action_s;
                do {
                    cout << "Skra pontun(p), Sja heildarverd(v), Skra pontun senta/sotta(s), Merkja pontun greidda(g), Merkja afhendingarstad(a), Skra athugasemd(t), Sja allar pantanir(n) eda haetta(h): ";
                    cin >> action_s;
                    switch(action_s) {
                        case 'p': {
                            //orders* orders = new orders();
                            char action_s_p;
                            do {
                                string phone;
                                cout << "Simanumer:  ";
                                cin.ignore();
                                getline(cin, phone);
                                //pizza pizzas[10];
                                //side sides[10];
                                int p_count = 0;
                                char action_s_p_p;
                                do {
                                    cout << "Pitsa af matsedli(m) eda servalin(s):  ";
                                    cin >> action_s_p_p;
                                    string pizza_name;
                                    string bottom;
                                    int size;
                                    if(action_s_p_p == 'm') {
                                        cout << "Heiti pitsu af matsedli: ";
                                        cin.ignore();
                                        getline(cin, pizza_name);
                                        //pizza* p = new pizza(heiti_pitsu);
                                        //pizzas[p_count] = p;
                                    } else {
                                        cout << "Tegund botns: ";
                                        cin.ignore();
                                        getline(cin, bottom);
                                        cout << "Staerd: ";
                                        cin >> size;
                                        string toppings[10];
                                        string topping;
                                        char action_s_p_p_t;
                                        int top_count = 0;
                                        do {
                                            cout << "Alegg: ";
                                            cin.ignore();
                                            getline(cin, topping);
                                            toppings[top_count] = topping;
                                            top_count++;
                                            cout << "Nytt alegg(n) eda haetta(h): ";
                                            cin >> action_s_p_p_t;
                                        } while(action_s_p_p_t != 'h' && top_count < 10);
                                        //pizza* p = new pizza(bottom, size, toppings);
                                        //pizzas[p_count] = p;
                                    }
                                    p_count++;
                                    cout << "Verd pitsu: " << endl; // pizzas[p_count-1]->get_price();
                                    cout << "Nyja pitsu(n) eda haetta(h):  ";
                                    cin >> action_s_p_p;
                                } while(action_s_p_p != 'h' && p_count < 10);
                                int side_count = 0;
                                char action_s_p_s;
                                do {
                                    string side;
                                    cout << "Medlaeti: ";
                                    cin.ignore();
                                    getline(cin, side);
                                    //sides[side_count] = new side(side);
                                    side_count++;
                                    cout << "Nytt medlaeti(n) eda haetta(h):  ";
                                    cin >> action_s_p_s;
                                } while(action_s_p_s != 'h' && side_count < 10);
                                //int order_num = orders->new_order(phone, pizzas, side);
                                cout << "Pontunarnumer: " << endl; //order_num;
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
                                //order* o = new order(order_number);
                                cout << "Heildarverd: " << endl; //o->price();
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
                                //order* o = new order(order_number);
                                cout << "Skra senta(e) eda sotta(o): ";
                                char del;
                                cin >> del;
                                if(del == 'e') {
                                    //o->del();
                                } else if(del == 'o') {
                                    //o->pickup();
                                }
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
                                //order* o = new order(order_number);
                                //o->paid();
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
                            //orders* o = new orders();
                            //o->print_orders();
                            break;
                    }
                } while(action_s != 'h');
                break;
            }
            case 'b': {
                //locations* l = new locations();
                //l->print_locations();
                string location;
                cout << "Veldu stad: ";
                cin.ignore();
                getline(cin, location);
                char action_b;
                do {
                    cout << "Lista pitsur(l), Syna pitsu(s), Merkja i vinnslu(v), Merkja tilbuna(t) eda haetta(h): ";
                    cin >> action_b;
                    //orders* o = new orders(location);
                    switch(action_b) {
                        case 'l': {
                            //o->print_pizzas();
                            break;
                        }
                        case 's': {
                            int pizza_id;
                            cout << "Pitsunumer: ";
                            cin >> pizza_id;
                            //o->show_pizza(pizza_id);
                            break;
                        }
                        case 'v': {
                            int pizza_id;
                            cout << "Pitsunumer: ";
                            cin >> pizza_id;
                            //o->get_pizza(pizza_id)->in_progress();
                            break;
                        }
                        case 't': {
                            int pizza_id;
                            cout << "Pitsunumer: ";
                            cin >> pizza_id;
                            //o->get_pizza(pizza_id)->ready();
                            break;
                        }
                    }
                } while(action_b != 'h');
                break;
            }
            case 'a': {
                //locations* l = new locations();
                //l->print_locations();
                string location;
                cout << "Veldu stad: ";
                cin.ignore();
                getline(cin, location);
                char action_a;
                do {
                    cout << "Lista af pontunum(l), Lista af tilbunum pontunum(t), Skoda pontun(s), Merkja pontun greidda(g), Merkja pontun afhenta(a) eda haetta(h): ";
                    cin >> action_a;
                    //orders* o = new orders(location);
                    switch(action_a) {
                        case 'l': {
                            //o->print_orders();
                            break;
                        }
                        case 't': {
                            //o->print_ready_orders();
                            break;
                        }
                        case 's': {
                            int order_id;
                            cout << "Pontunarnumer: ";
                            cin >> order_id;
                            //o->print_order(order_id);
                            break;
                        }
                        case 'g': {
                            int order_id;
                            cout << "Pontunarnumer: ";
                            cin >> order_id;
                            //o->mark_paid(order_id);
                            break;
                        }
                        case 'a': {
                            int order_id;
                            cout << "Pontunarnumer: ";
                            cin >> order_id;
                            //o->mark_delivered(order_id);
                            break;
                        }
                    }
                } while(action_a != 'h');
                break;
            }
        }
    } while(action != 'h');
}


