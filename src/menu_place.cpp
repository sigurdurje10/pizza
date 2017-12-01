//
//  menu_place.cpp
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_place.h"
#include "pizza_place.h"
#include <string.h>
#include "manage.h"

menu_place::menu_place() {
    
}

pizza_place menu_place::get_place() {
    manage* u = new manage();
    pizza_place* places = u->get_places();
    for(int i = 0; i<u->get_places_length(); i++) {
        cout << places[i];
    }
    string location_value = "";
    pizza_place place;
    cin.ignore();
    while(location_value == "") {
        bool accepted = true;
        string location = "";
        do {
            cout << "Veldu stad: ";
            getline(cin, location);
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted || location == "");
        place = u->find_place(location);
        location_value = place.get_name();
        if(location_value == "") {
            cout << "Stadur finnst ekki." << endl;
        } else {
            cout << "Stadur '" << location_value << "' valinn." << endl;
        }
    }
    return place;
}
