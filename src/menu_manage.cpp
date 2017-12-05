//
//  menu_manage.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_manage.h"
#include <iostream>
#include <string>
#include "pizza_size.h"
#include "manage.h"
#include "topping.h"
#include "side_order.h"
#include "pizza.h"
#include "menu_pizza.h"
#include <limits>
using namespace std;

menu_manage::menu_manage() {

}

void menu_manage::start_menu() {
    char action_u;
    manage* u = new manage();
    do {
        bool accepted = true;
        do {
            cout << "Veldu Skra staerd(s), Skra botn(b), Skra alegg(a), Skra matsedil(m), Skra medlaeti(e), Skra stadi(t) eda haetta(h): ";
            cin >> action_u;
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted);
        switch(action_u) {
            case 's':
                char action_u_s;
                do {
                    pizza_size* p_size = new pizza_size();
                    cin >> p_size[0];
                    u->new_size(p_size);
                    pizza_size* p = u->get_sizes();
                    int arr_len = u->get_sizes_length();
                    cout << "Staerdir: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << p[i];
                    }
                    bool accepted = true;
                    do {
                        cout << "Veldu Nyja staerd(n) eda haetta(h): ";
                        cin >> action_u_s;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_u_s != 'h');
                break;
            case 'b':
                char action_u_b;
                do {
                    pizza_bottom* b = new pizza_bottom();
                    cin >> b[0];
                    u->new_bottom(b);
                    pizza_bottom* bottoms = u->get_bottoms();
                    int arr_len = u->get_bottoms_length();
                    cout << "Botnar: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << bottoms[i];
                    }
                    bool accepted = true;
                    do {
                        cout << "Veldu Nyjan botn(n) eda haetta(h): ";
                        cin >> action_u_b;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_u_b != 'h');
                break;
            case 'a':
                char action_u_a;
                do {
                    topping* t = new topping();
                    cin >> t[0];
                    u->new_topping(t);
                    topping* top = u->get_toppings();
                    int arr_len = u->get_toppings_length();
                    cout << "Alegg: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << top[i];
                    }
                    bool accepted = true;
                    do {
                        cout << "Veldu Nytt alegg(n) eda haetta(h): ";
                        cin >> action_u_a;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_u_a != 'h');
                break;
            case 'm':
                char action_u_m;
                do {
                    bool accepted = true;
                    string name = "";
                    int price = -1;
                    menu_pizza* mp;
                    cin.ignore();
                    do {
                        cout << "Ny pitsa a matsedli: ";
                        getline(cin, name);
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                        if(accepted) {
                            cout << "Verd: ";
                            cin >> price;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                            if(accepted) {
                                mp = new menu_pizza();
                            }
                        }
                    } while(!accepted || name == "" || price == -1);
                    pizza* p = mp->get_pizza();
                    p->set_name(name);
                    p->set_price(price);
                    u->new_menu_item(p);
                    pizza* men = u->get_menu();
                    int arr_len = u->get_menu_length();
                    cout << "Allar pitsur:" << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << men[i];
                    }
                    accepted = true;
                    do {
                        cout << "Veldu Nyja pitsu(n) eda haetta(h): ";
                        cin >> action_u_m;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_u_m != 'h');
                break;
            case 'e':
                char action_u_e;
                do {
                    side_order* s = new side_order();
                    cin >> s[0];
                    u->new_side(s);
                    side_order* sides = u->get_sides();
                    int arr_len = u->get_sides_length();
                    cout << "Medlaeti: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << sides[i];
                    }
                    bool accepted = true;
                    do {
                        cout << "Veldu Nytt medlaeti(n) eda haetta(h): ";
                        cin >> action_u_e;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_u_e != 'h');
                break;
            case 't':
                char action_u_t;
                do {
                    pizza_place* p = new pizza_place();
                    cin >> p[0];
                    u->new_place(p);
                    pizza_place* places = u->get_places();
                    int arr_len = u->get_places_length();
                    cout << "Afhendingarstadir: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << places[i];
                    }
                    bool accepted = true;
                    do {
                        cout << "Veldu Nyjan afhendingarstad(n) eda haetta(h): ";
                        cin >> action_u_t;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);
                } while(action_u_t != 'h');
                break;
        }
    } while(action_u != 'h');
}
