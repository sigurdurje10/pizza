//
//  menu.cpp
//  pizza
//
//  Created by Sigurður Jökull on 27/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu.h"
#include <iostream>
#include <string>
#include "manage.h"
#include "menu_manage.h"
#include "pizza_size.h"
#include "menu_baking.h"
#include "menu_delivery.h"
#include "menu_sales.h"


using namespace std;

menu::menu() {

}

void menu::start_menu() {
    char action;
    do {
        cout << "Veldu Umsjon(u), Sala(s), Bakstur(b), Afhending(a) eda haetta(h): ";
        cin >> action;
        switch(action) {
            case 'u': {
                menu_manage* manage = new menu_manage();
                manage->start_menu();
                break;
            }
            case 's': {
                menu_sales* sales = new menu_sales();
                sales->start_menu();
                break;
            }
            case 'b': {
                menu_baking* baking = new menu_baking();
                baking->start_menu();
                break;
            }
            case 'a': {
                menu_delivery* delivery = new menu_delivery();
                delivery->start_menu();
                break;
            }
        }
    } while(action != 'h');
}

