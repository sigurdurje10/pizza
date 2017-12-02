//
//  menu_numbers.cpp
//  pizza
//
//  Created by Sigurður Jökull on 01/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_numbers.h"
#include "sales_numbers.h"

menu_numbers::menu_numbers() {
    
}

void menu_numbers::start_menu() {
    sales_numbers* s = new sales_numbers(0,0,0,0);
    char action;
    do {
        bool accepted = true;
        do {
            cout << "Veldu Fjolda pantana(p), Fjolda pitsna(i), Heildarvelta(v), Skoda fra dagsetningu(d), Skoda a dagsetningu(a) eda haetta(h): ";
            cin >> action;
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted);
        switch(action) {
            case 'd': {
                int month = 0;
                int day = 0;
                int year = 0;
                cout << "Ar: ";
                cin >> year;
                cout << "Manudur: ";
                cin >> month;
                cout << "Dagur: ";
                cin >> day;
                s = new sales_numbers(day, month, year, 1);
                break;
            }
            case 'a': {
                int month = 0;
                int day = 0;
                int year = 0;
                cout << "Ar: ";
                cin >> year;
                cout << "Manudur: ";
                cin >> month;
                cout << "Dagur: ";
                cin >> day;
                s = new sales_numbers(day, month, year, 2);
                break;
            }
            case 'p': {
                int order_numbers = s->order_numbers();
                cout << "Fjoldi pantana: " << order_numbers << endl;
                break;
            }
            case 'i': {
                int pizza_numbers = s->pizza_numbers();
                cout << "Fjoldi pitsna: " << pizza_numbers << endl;
                break;
            }
            case 'v': {
                int total_sales = s->total_sales();
                cout << "Heildarvelta: " << total_sales << endl;
                break;
            }
        }
    } while(action != 'h');
}
