//
//  menu_login.cpp
//  pizza
//
//  Created by Sigurður Jökull on 01/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_login.h"
#include <string.h>
#include <iostream>
#include "manage.h"
#include "menu_place.h"

using namespace std;

menu_login::menu_login() {
    
}

void menu_login::start_menu() {
    this->m = new manage();
    string username_value = "";
    user u;
    cin.ignore();
    while(username_value == "") {
        bool accepted = true;
        string username = "";
        string password = "";
        do {
            cout << "Notandanafn: ";
            getline(cin, username);
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
            if(accepted) {
                cout << "Password: ";
                getline(cin, password);
                if(!cin) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accepted = false;
                }
            }
        } while(!accepted || username == "" || password == "");
        u = m->find_user(username, password);
        username_value = u.get_username();
        if(username_value == "") {
            cout << "Notandi finnst ekki." << endl;
        } else {
            cout << "Skradur inn sem '" << username_value << "'." << endl;
            m->set_user(u);
        }
    }
}

void menu_login::reg_menu() {
    manage* m = new manage();
    menu_place* m_place = new menu_place();
    string username_value = "";
    user u;
    cin.ignore();
    while(username_value == "") {
        bool accepted = true;
        string username = "";
        string password = "";
        pizza_place place;
        user* u;
        do {
            cout << "Notandanafn: ";
            getline(cin, username);
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
            if(accepted) {
                cout << "Password: ";
                getline(cin, password);
                if(!cin) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accepted = false;
                }
                if(accepted) {
                    place = m_place->get_place();
                }
            }
        } while(!accepted || username == "" || password == "" || place.get_name() == "");
        u = new user(username, password, place);
        username_value = username;
        m->new_user(u);
        cout << "Notandi nyskradur." << endl;
    }
}
