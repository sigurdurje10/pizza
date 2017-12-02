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
#include "pizza_place.h"
#include "baking.h"
#include "menu_place.h"
#include "sales.h"
#include "user.h"

using namespace std;

menu_baking::menu_baking() {
    
}

void menu_baking::start_menu(user current_user) {
    manage* u = new manage();
    baking* b = new baking();
    sales* s = new sales();
    menu_place* mp = new menu_place();
    string username = current_user.get_username();
    pizza_place place;
    if(username == "") {
        cin.ignore();
        place = mp->get_place();
    } else {
        place = current_user.get_place();
    }
    
    char action_b;
    do {
        bool accepted = true;
        do {
            cout << "Lista pitsur(l), Syna pitsu(s), Merkja i vinnslu(v), Merkja tilbuna(t) eda haetta(h): ";
            cin >> action_b;
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted);
        switch(action_b) {
            case 'l': {
                pizza* pizzas = b->get_pizzas(place);
                for(int i = 0; i<b->get_pizzas_length(); i++) {
                    cout << pizzas[i];
                }
                break;
            }
            case 's': {
                bool accepted = true;
                int pizza_id = -1;
                do {
                    cout << "Pitsunumer: ";
                    cin >> pizza_id;
                    if(!cin) {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        accepted = false;
                    }
                } while(!accepted);
                pizza p = b->get_pizza(pizza_id, place);
                if(p.get_id() == -1) {
                    cout << "Pitsa fannst ekki." << endl;
                } else {
                    cout << p;
                }
                break;
            }
            case 'v': {
                bool accepted = true;
                int pizza_id = -1;
                do {
                    cout << "Pitsunumer: ";
                    cin >> pizza_id;
                    if(!cin) {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        accepted = false;
                    }
                } while(!accepted);
                pizza p = b->get_pizza(pizza_id, place);
                if(p.get_id() == -1) {
                    cout << "Pitsa fannst ekki." << endl;
                } else {
                    p.set_progress(true);
                    order o = b->get_current_order();
                    o.set_pizza(p, p.get_p_count());
                    s->save_order(o);
                    cout << "Pitsa merkt i vinnslu." << endl;
                }
                break;
            }
            case 't': {
                bool accepted = true;
                int pizza_id;
                do {
                    cout << "Pitsunumer: ";
                    cin >> pizza_id;
                    if(!cin) {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        accepted = false;
                    }
                } while(!accepted);
                pizza p = b->get_pizza(pizza_id, place);
                if(p.get_id() == -1) {
                    cout << "Pitsa fannst ekki." << endl;
                } else {
                    p.set_ready(true);
                    order o = b->get_current_order();
                    o.set_pizza(p, p.get_p_count());
                    s->save_order(o);
                    cout << "Pitsa merkt tilbuin" << endl;
                }
                break;
            }
        }
    } while(action_b != 'h');
}
