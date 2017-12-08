//
//  menu_pizza.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "ui/menu_pizza.h"
#include "models/pizza.h"
#include "services/manage.h"
#include <limits>
#include "exception/exception.h"

menu_pizza::menu_pizza() {

}

pizza* menu_pizza::get_pizza() {
    pizza* p = new pizza();
    manage* u = new manage();
    string bottom_found = "";
    cin.ignore();
    while(bottom_found == "") {
        bool accepted = true;
        string bottom = "";
        do {
            cout << "Botn: ";
            getline(cin, bottom);
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted || bottom == "");
        pizza_bottom bottom_obj = u->find_bottom(bottom);
        bottom_found = bottom_obj.get_name();
        p->set_pizza_bottom(bottom_obj);
        if(bottom_found == "") {
            cout << "Botn ekki fundinn." << endl;
        } else {
            cout << "Botn '" << bottom_found << "' valinn." << endl;
        }
    }
    int size_found = 0;
    while(size_found == 0) {
        bool accepted = true;
        int size = -1;
        do {
            cout << "Staerd: ";
            cin >> size;
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted || size == -1);
        pizza_size size_obj = u->find_size(size);
        size_found = size_obj.get_size();
        p->set_pizza_size(size_obj);
        if(size_found == 0) {
            cout << "Staerd ekki fundinn." << endl;
        } else {
            cout << "Staerd " << size_found << "\" valinn." << endl;
        }
    }
    char action_u_m_t;
    int top_count = 0;
    do {
        string topping_value = "";
        bool accepted = true;
        cin.ignore();
        do {
            cout << "Alegg: ";
            getline(cin, topping_value);
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted || topping_value == "");
        topping top_obj = u->find_topping(topping_value);
        if(top_obj.get_name() != "") {
            p->add_topping(top_obj);
            cout << "Alegg '" << top_obj.get_name() << "' baett vid." << endl;
        } else {
            cout << "Alegg ekki fundid." << endl;
        }
        accepted = true;
        do {
            try {
                cout << "Nytt alegg(n) eda haetta(h): ";
                cin >> action_u_m_t;
                if(!cin || !isalpha(action_u_m_t)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accepted = false;
                    throw topping_exception();
                }
            } catch(topping_exception) {
                cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
            }
        } while(!accepted);
    } while(action_u_m_t != 'h' && top_count < 10);
    return p;
}
