//
//  menu_manage.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "ui/menu_manage.h"
#include <iostream>
#include <string>
#include "models/pizza_size.h"
#include "services/manage.h"
#include "models/topping.h"
#include "models/side_order.h"
#include "models/pizza.h"
#include "ui/menu_pizza.h"
#include <limits>
#include "exception/exception.h"
#include "ui/menu_special.h"
using namespace std;

menu_manage::menu_manage() {

}

void menu_manage::start_menu() {
    char action_u;
    manage* u = new manage();
    do {
        bool accepted = true;
        do {
            try {
                cout << "Veldu Skra staerd(s), Skra botn(b), Skra alegg(a), Skra matsedil(m), Skra medlaeti(e), Skra stadi(t), Skra tilbod(i) eda haetta(h): ";
                cin >> action_u;
                if(!cin || !isalpha(action_u)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accepted = false;
                    throw menu_exception();
                }
            } catch(menu_exception) {
                cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
            }
        } while(!accepted);
        switch(action_u) {
            case 's':
                char action_u_s;
                do {
                    try {
                        pizza_size* p_size = new pizza_size();
                        cin >> p_size[0];
                        u->new_size(p_size);
                    } catch(price_exception){
                        cout << "Verd verdur ad vera tala sem er staerri en 0." << endl;
                    } catch(size_exception) {
                        cout << "Staerd verdur ad vera tala sem er staerri en 0." << endl;
                    }
                    pizza_size* p = u->get_sizes();
                    int arr_len = u->get_sizes_length();
                    cout << "Staerdir: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << p[i];
                    }
                    bool accepted = true;
                    do {
                        try {
                            cout << "Veldu Nyja staerd(n) eda haetta(h): ";
                            cin >> action_u_s;
                            if(!cin || !isalpha(action_u_s)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw menu_exception();
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_u_s != 'h');
                break;
            case 'b':
                char action_u_b;
                do {
                    try {
                        pizza_bottom* b = new pizza_bottom();
                        cin >> b[0];
                        u->new_bottom(b);
                    }catch(price_exception) {
                        cout << "Verd verdur ad vera tala sem er staerri en 0." << endl;
                    }
                    pizza_bottom* bottoms = u->get_bottoms();
                    int arr_len = u->get_bottoms_length();
                    cout << "Botnar: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << bottoms[i];
                    }
                    bool accepted = true;
                    do {
                        try {
                            cout << "Veldu Nyjan botn(n) eda haetta(h): ";
                            cin >> action_u_b;
                            if(!cin || !isalpha(action_u_b)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw menu_exception();
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        } catch(price_exception) {
                            cout << "Verd verdur ad vera staerra en 0." << endl;
                        }
                    } while(!accepted);
                } while(action_u_b != 'h');
                break;
            case 'a':
                char action_u_a;
                do {
                    try {
                        try {
                            topping* t = new topping();
                            cin >> t[0];
                            u->new_topping(t);
                        } catch(price_exception) {
                            cout << "Verd verdur ad vera tala sem er staerri en 0." << endl;
                        }
                        topping* top = u->get_toppings();
                        int arr_len = u->get_toppings_length();
                        cout << "Alegg: " << endl;
                        for(int i = 0; i < arr_len; i++) {
                            cout << top[i];
                        }
                        bool accepted = true;
                        do {
                            try {
                                cout << "Veldu Nytt alegg(n) eda haetta(h): ";
                                cin >> action_u_a;
                                if(!cin || !isalpha(action_u_a)) {
                                    cin.clear();
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    accepted = false;
                                    throw menu_exception();
                                }
                            } catch(menu_exception) {
                                cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                            }
                        } while(!accepted);
                    } catch(price_exception) {
                        cout << "Verd verdur ad vera tala sem er staerri en 0." << endl;
                    }
                } while(action_u_a != 'h');
                break;
            case 'm':
                char action_u_m;
                do {
                    try {
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
                                    throw price_exception();
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
                            try {
                                cout << "Veldu Nyja pitsu(n) eda haetta(h): ";
                                cin >> action_u_m;
                                if(!cin || !isalpha(action_u_m)) {
                                    cin.clear();
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    accepted = false;
                                    throw menu_exception();
                                }
                            } catch(menu_exception) {
                                cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                            }
                        } while(!accepted);
                    } catch(price_exception) {
                        cout << "Verd tharf ad vera tala og staerri en 0." << endl;
                    }
                } while(action_u_m != 'h');
                break;
            case 'e':
                char action_u_e;
                do {
                    try {
                        side_order* s = new side_order();
                        cin >> s[0];
                        u->new_side(s);
                    } catch(price_exception) {
                        cout << "Verd verdur ad vera tala staerri en 0." << endl;
                    }
                    side_order* sides = u->get_sides();
                    int arr_len = u->get_sides_length();
                    cout << "Medlaeti: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << sides[i];
                    }
                    bool accepted = true;
                    do {
                        try {
                            cout << "Veldu Nytt medlaeti(n) eda haetta(h): ";
                            cin >> action_u_e;
                            if(!cin || !isalpha(action_u_e)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
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
                        try {
                            cout << "Veldu Nyjan afhendingarstad(n) eda haetta(h): ";
                            cin >> action_u_t;
                            if(!cin || !isalpha(action_u_t)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_u_t != 'h');
                break;
            case 'i':
                char action_u_i;
                do {
                    menu_special * m_special =new menu_special();
                    m_special->start_menu();
                    bool accepted =true;
                    do {
                        cout << "Gerdu nytt tilbod(n) eda haetta(h): ";
                        cin >> action_u_i;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                    } while(!accepted);

                }while(action_u_i != 'h');
                break;
        }
    } while(action_u != 'h');
}
