//
//  menu_numbers.cpp
//  pizza
//
//  Created by Sigurður Jökull on 01/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_numbers.h"
#include "sales_numbers.h"
#include "exception.h"

menu_numbers::menu_numbers() {
    
}

void menu_numbers::start_menu() {
    sales_numbers* s = new sales_numbers(0,0,0,0);
    char action;
    do {
        bool accepted = true;
        do {
            cout << "Veldu Fjolda pantana(p), Fjolda pitsna(i), Heildarvelta(v), Fjoldi vidskiptavina(s), Skoda fra dagsetningu(d), Skoda a dagsetningu(a) eda haetta(h): ";
            cin >> action;
            if(!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
        } while(!accepted);
        switch(action) {
            case 'd': {
                try {
                    int month = 0;
                    int day = 0;
                    int year = 0;
                    cout << "Ar: ";
                    cin >> year;
                    if(year < 1900 || year > 2017) {
                        throw date_exception();
                    }
                    cout << "Manudur: ";
                    cin >> month;
                    if(month < 1 || month > 12) {
                        throw date_exception();
                    }
                    cout << "Dagur: ";
                    cin >> day;
                    if(day < 1 || day > 31) {
                        throw date_exception();
                    }
                    s = new sales_numbers(day, month, year, 1);
                } catch(date_exception) {
                    cout << "Villa in dagsetningu." << endl;
                }
                break;
            }
            case 'a': {
                int month = 0;
                int day = 0;
                int year = 0;
                try {
                    cout << "Ar: ";
                    cin >> year;
                    if(year < 1900 || year > 2017) {
                        throw date_exception();
                    }
                    cout << "Manudur: ";
                    cin >> month;
                    if(month < 1 || month > 12) {
                        throw date_exception();
                    }
                    cout << "Dagur: ";
                    cin >> day;
                    if(day < 1 || day > 31) {
                        throw date_exception();
                    }
                    s = new sales_numbers(day, month, year, 2);
                } catch(date_exception) {
                    cout << "Villa in dagsetningu." << endl;
                }
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
            case 's': {
                int people_numbers = s->people_numbers();
                cout << "Fjoldi vidskiptavina: " << people_numbers << endl;
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
