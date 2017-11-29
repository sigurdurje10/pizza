//
//  menu_manage.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "menu_manage.h"
#include <iostream>
#include <string>
#include "pizza_size.h"
#include "manage.h"

using namespace std;

menu_manage::menu_manage() {
    
}

void menu_manage::start_menu() {
    char action_u;
    manage* u = new manage();
    do {
        cout << "Veldu Skra staerd(s), Skra botn(b), Skra alegg(a), Skra matsedil(m), Skra medlaeti(e), Skra stadi(t) eda haetta(h): ";
        cin >> action_u;
        switch(action_u) {
            case 's':
                char action_u_s;
                do {
                    pizza_size* p_size = new pizza_size();
                    cin >> p_size[0];
                    u->new_size(p_size);
                    pizza_size* p = u->get_sizes();
                    int arr_len = u->get_sizes_length();
                    cout << "Staerdir: " << endl;
                    for(int i = 0; i < arr_len; i++) {
                        cout << p[i];
                    }
                    cout << "Veldu Nyja staerd(n) eda haetta(h): ";
                    cin >> action_u_s;
                } while(action_u_s != 'h');
                break;
            case 'b':
                char action_u_b;
                do {
                    string bottom;
                    int price;
                    cout << "Nyr botn:  ";
                    cin.ignore();
                    getline(cin, bottom);
                    cout << "Verd:  ";
                    cin >> price;
                    //u->new_bottom(bottom, price);
                    cout << "Veldu Nyjan botn(n) eda haetta(h): ";
                    cin >> action_u_b;
                } while(action_u_b != 'h');
                break;
            case 'a':
                char action_u_a;
                do {
                    string topping;
                    int price;
                    cout << "Nytt alegg:  ";
                    cin.ignore();
                    getline(cin, topping);
                    cout << "Verd:  ";
                    cin >> price;
                    //u->new_topping(topping, price);
                    cout << "Veldu Nytt alegg(n) eda haetta(h): ";
                    cin >> action_u_a;
                } while(action_u_a != 'h');
                break;
            case 'm':
                char action_u_m;
                do {
                    string name;
                    int price;
                    cout << "Ny pitsa a matsedli:  ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Verd:  ";
                    cin >> price;
                    string toppings[10];
                    string topping;
                    char action_u_m_t;
                    int top_count = 0;
                    do {
                        cout << "Alegg: ";
                        cin.ignore();
                        getline(cin, topping);
                        toppings[top_count] = topping;
                        top_count++;
                        cout << "Nytt alegg(n) eda haetta(h): ";
                        cin >> action_u_m_t;
                    } while(action_u_m_t != 'h' && top_count < 10);
                    //u->new_menu_item(name, price, toppings);
                    cout << "Veldu Nyja pitsu(n) eda haetta(h): ";
                    cin >> action_u_m;
                } while(action_u_m != 'h');
                break;
            case 'e':
                char action_u_e;
                do {
                    string side;
                    int price;
                    cout << "Nytt medlaeti:  ";
                    cin.ignore();
                    getline(cin, side);
                    cout << "Verd:  ";
                    cin >> price;
                    //u->new_side(side, price);
                    cout << "Veldu Nytt medlaeti(n) eda haetta(h): ";
                    cin >> action_u_e;
                } while(action_u_e != 'h');
                break;
            case 't':
                char action_u_t;
                do {
                    string place;
                    cout << "Nyr afhendingarstadur:  ";
                    cin.ignore();
                    getline(cin, place);
                    //u->new_place(place);
                    cout << "Veldu Nyjan afhendingarstad(n) eda haetta(h): ";
                    cin >> action_u_t;
                } while(action_u_t != 'h');
                break;
        }
    } while(action_u != 'h');
}
