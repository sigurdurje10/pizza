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
    manage* u = new manage();
    pizza_place* places = u->get_places();
    for(int i = 0; i<u->get_places_length(); i++) {
        cout << places[i];
    }
    baking* b = new baking();
    string location_value = "";
    pizza_place place;
    while(location_value == "") {
        string location;
        cout << "Veldu stad: ";
        cin.ignore();
        getline(cin, location);
        place = u->find_place(location);
        location_value = place.get_name();
        if(location_value == "") {
            cout << "Stadur finnst ekki." << endl;
        } else {
            cout << "Stadur '" << location_value << "' valinn." << endl;
        }
    }
    
    char action_b;
    do {
        cout << "Lista pitsur(l), Syna pitsu(s), Merkja i vinnslu(v), Merkja tilbuna(t) eda haetta(h): ";
        cin >> action_b;
        switch(action_b) {
            case 'l': {
                b->get_pizzas(place);
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