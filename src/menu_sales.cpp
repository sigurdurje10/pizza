//
//  menu_sales.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_sales.h"
#include <iostream>
#include <string>

using namespace std;

menu_sales::menu_sales() {
    
}

void menu_sales::start_menu() {
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
}
