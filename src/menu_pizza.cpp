//
//  menu_pizza.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_pizza.h"
#include "pizza.h"
#include "manage.h"

menu_pizza::menu_pizza() {
    
}

pizza* menu_pizza::get_pizza() {
    pizza* p = new pizza();
    manage* u = new manage();
    /*string bottom_found = "";
     while(bottom_found == "") {
     string bottom;
     cout << "Botn: ";
     cin.ignore();
     getline(cin, bottom);
     pizza_bottom bottom_obj = u->find_bottom(bottom);
     bottom_found = bottom_obj.get_name();
     p->set_pizza_bottom(bottom_obj);
     if(bottom_found == "") {
     cout << "Botn ekki fundinn." << endl;
     } else {
     cout << "Botn '" << bottom_found << "' valinn." << endl;
     }
     }*/
    int size_found = 0;
    while(size_found == 0) {
        int size;
        cout << "Staerd: ";
        cin >> size;
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
    string topping_value;
    do {
        cout << "Alegg: ";
        cin.ignore();
        getline(cin, topping_value);
        topping top_obj = u->find_topping(topping_value);
        if(top_obj.get_name() != "") {
            p->add_topping(top_obj);
            cout << "Alegg '" << top_obj.get_name() << "' baett vid." << endl;
        } else {
            cout << "Alegg ekki fundid." << endl;
        }
        //delete top_obj;
        cout << "Nytt alegg(n) eda haetta(h): ";
        cin >> action_u_m_t;
    } while(action_u_m_t != 'h' && top_count < 10);
    return p;
}
