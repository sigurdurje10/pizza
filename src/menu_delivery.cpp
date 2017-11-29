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

using namespace std;

menu_delivery::menu_delivery() {
    
}

void menu_delivery::start_menu() {
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
}
