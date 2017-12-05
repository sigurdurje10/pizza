//
//  menu_delivery.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_delivery.h"
#include <iostream>
#include <string>
#include "manage.h"
#include "menu_place.h"
#include "pizza_place.h"
#include "delivery.h"
#include "sales.h"
#include <limits>

using namespace std;

menu_delivery::menu_delivery() {
    
}

void menu_delivery::start_menu(user current_user) {
    
    sales* s = new sales();
    delivery* d = new delivery;
    menu_place* mp = new menu_place();
    string username = current_user.get_username();
    pizza_place place;
    if(username == "") {
        cin.ignore();
        place = mp->get_place();
    } else {
        place = current_user.get_place();
    }
    
    char action_a;
    do {
        bool accepted = true;
        do {
            try {
                cout << "Lista af pontunum(l), Lista af tilbunum pontunum(t), Skoda pontun(s), Merkja pontun greidda(g), Merkja pontun afhenta(a), Lista af afhentum pontunum(h) eda haetta(h): ";
                cin >> action_a;
                if(!cin) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accepted = false;
                    throw delivery_exception();
                }
                if(!isalpha(action_a)) {
                    throw delivery_exception();
                }
            } catch(delivery_exception) {
                cout << "Valdmynds inntak tharf ad vera bokstafur.";
            }
        } while(!accepted);
        switch(action_a) {
            case 'h': {
                order* orders = d->get_old_orders(place);
                for(int i=0; i<d->get_orders_length(); i++) {
                    cout << orders[i];
                }
                break;
            }
            case 'l': {
                order* orders = d->get_orders(place);
                for(int i=0; i<d->get_orders_length(); i++) {
                    cout << orders[i];
                }
                break;
            }
            case 't': {
                order* orders = d->get_orders_ready(place);
                for(int i=0; i<d->get_orders_ready_length(); i++) {
                    cout << orders[i];
                }
                break;
            }
            case 's': {
                bool accepted = true;
                int order_id;
                do {
                    try {
                        cout << "Pontunarnumer: ";
                        cin >> order_id;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                            throw ordernum_exception();
                        }
                    } catch(ordernum_exception) {
                        cout << "Pontunarnumer tharf ad vera tala." << endl;
                    }
                } while(!accepted);
                order order = s->find_order(order_id);
                if(order.get_id() == -1) {
                    cout << "Pontun fannst ekki." << endl;
                } else {
                    cout << order;
                }
                break;
            }
            case 'g': {
                bool accepted = true;
                int order_id;
                do {
                    try {
                        cout << "Pontunarnumer: ";
                        cin >> order_id;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                            throw ordernum_exception();
                        }
                    } catch(ordernum_exception) {
                        cout << "Pontunarnumer tharf ad vera tala." << endl;
                    }
                } while(!accepted);
                order order = s->find_order(order_id);
                if(order.get_id() == -1) {
                    cout << "Pontun fannst ekki." << endl;
                } else {
                    order.is_paid();
                    s->save_order(order);
                    cout << "Pontun merkt greidd." << endl;
                }
                break;
            }
            case 'a': {
                bool accepted = true;
                int order_id;
                do {
                    try {
                        cout << "Pontunarnumer: ";
                        cin >> order_id;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                            throw ordernum_exception();
                        }
                    } catch(ordernum_exception) {
                        cout << "Pontunarnumer tharf ad vera tala." << endl;
                    }
                } while(!accepted);
                order order = s->find_order(order_id);
                if(order.get_id() == -1) {
                    cout << "Pontun fannst ekki." << endl;
                } else {
                    order.set_delivered(true);
                    s->save_order(order);
                    cout << "Pontun merkt afhent." << endl;
                }
                break;
            }
        }
    } while(action_a != 'h');
}
