//
//  menu.cpp
//  pizza
//
//  Created by Sigurður Jökull on 27/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "ui/menu.h"
#include <iostream>
#include <string>
#include "services/manage.h"
#include "models/pizza_size.h"
#include "ui/menu_manage.h"
#include "ui/menu_sales.h"
#include "ui/menu_baking.h"
#include "ui/menu_delivery.h"
#include "ui/menu_numbers.h"
#include "ui/menu_login.h"
#include <limits>


using namespace std;

menu::menu() {

}

void menu::start_menu() {
    menu_login* login = new menu_login();
    user current_user;
    char action;
    do {
        bool accepted = true;
        //loopar í gegnum á meðan cin er ekki valid. Fer í switch case ef input er valid.
        do {
            accepted = true;
            cout << "Veldu Umsjon(u), Sala(s), Bakstur(b), Afhending(a), Solutolur(o), Innskraning(i), Nyskraning(n) eda haetta(h): ";
            cin >> action;
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted);
        //kallar á menu eftir hvert inputið er. Loopar ef case sem er til er ekki valið.
        //h hættir keyrslu forritsins
        switch(action) {
            case 'u': {
                menu_manage* manage = new menu_manage();
                manage->start_menu();
                break;
            }
            case 's': {
                menu_sales* sales = new menu_sales();
                sales->start_menu(current_user);
                break;
            }
            case 'b': {
                menu_baking* baking = new menu_baking();
                baking->start_menu(current_user);
                break;
            }
            case 'a': {
                menu_delivery* delivery = new menu_delivery();
                delivery->start_menu(current_user);
                break;
            }
            case 'o': {
                menu_numbers* numbers = new menu_numbers();
                numbers->start_menu();
                break;
            }
            case 'i': {
                login->start_menu();
                current_user = login->m->get_user();
                break;
            }
            case 'n': {
                login->reg_menu();
                break;
            }
        }
    } while(action != 'h');
    delete login;
}


