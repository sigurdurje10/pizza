//
//  menu_baking.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_baking.h"
#include <iostream>
#include <string>

using namespace std;

menu_baking::menu_baking() {
    
}

void menu_baking::start_menu() {
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
}
