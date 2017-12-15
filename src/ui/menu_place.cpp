//
//  menu_place.cpp
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "ui/menu_place.h"
#include "models/pizza_place.h"
#include <string.h>
#include "services/manage.h"
#include <limits>

menu_place::menu_place() {

}

//skrifar út lista af stöðum frá skrá, biður síðan notanda um að velja einn af þeim stöðum
//segir síðan notandanum hvort að staðurinn sem hann valdi fannst
pizza_place menu_place::get_place() {
    manage* u = new manage();
    pizza_place* places = u->get_places();
    for(int i = 0; i<u->get_places_length(); i++) {
        cout << places[i];
    }
    string location_value = "";
    pizza_place place;
    while(location_value == "") {
        bool accepted = true;
        string location = "";
        do {
            accepted = true;
            cout << "Veldu stad: ";
            getline(cin, location);
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
            cout << location << endl;
        } while(!accepted || location == "");
        place = u->find_place(location);
        location_value = place.get_name();
        if(location_value == "") {
            cout << "Stadur finnst ekki." << endl;
        } else {
            cout << "Stadur '" << location_value << "' valinn." << endl;
        }
    }
    delete u;
    delete[] places;
    return place;
}
