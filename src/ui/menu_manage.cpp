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
    //fyrsta loopan sem loopar í gegnum menueið. Hún hættir þegar notandi slær inn 'h' sem action_u inntakið.
    do {
        bool accepted = true;
        //loopar á meðan inntakið er ekki valid
        do {
            accepted = true;
            try {
                cout << "Veldu Skra staerd(s), Skra botn(b), Skra alegg(a), Skra matsedil(m), Skra medlaeti(e), Skra stadi(t), Skra tilbod(i), syna lista af...(l), eda haetta(h): ";
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
            //
            case 's':
                char action_u_s;
                //biður notanda um að slá inn verð og stærð.
                //hendir í exception ef annað hvort er ekki rétt
                //spyr síðan notanda ef hann vill gera nýja stærð
                do {
                    try {
                        pizza_size* p_size = new pizza_size();
                        cin >> p_size[0];
                        u->new_size(p_size);
                        //delete p_size;
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
                        accepted = true;
                        try {
                            cout << "Veldu Nyja staerd(n) eda haetta(h): ";
                            cin >> action_u_s;
                            if(!cin || !isalpha(action_u_s)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw menu_exception();
                            }
                            else if(action_u_s != 'h' && action_u_s != 'n'){
                                accepted = false;
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                    //delete[] p;
                } while(action_u_s != 'h');
                break;
            case 'b':
                //biður um heiti á botn og verð
                //hendir í exception ef verð er ekki tala stærri en 0
                char action_u_b;
                do {
                    try {
                        pizza_bottom* b = new pizza_bottom();
                        cin >> b[0];
                        u->new_bottom(b);
                        //delete b;
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
                        accepted = true;
                        try {
                            //biður um að velja nýjan botn eða að hætta
                            //hendir í exception ef það er ekki sett inn staf
                            //loopar aftur ef hvort n né h er valið
                            cout << "Veldu Nyjan botn(n) eda haetta(h): ";
                            cin >> action_u_b;
                            if(!cin || !isalpha(action_u_b)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw menu_exception();
                            }
                            else if(action_u_b != 'n' && action_u_b != 'h'){
                                accepted = false;
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                    //delete[] bottoms;
                } while(action_u_b != 'h');
                break;
            case 'a':
                //biður um heiti á áleggi og verð
                //notandi beðinn um að gera nýtt álegg eða að hætta, hendir í exception ef inputið er ekki valid, loopar ef
                //input er annar stafur en h eða n
                char action_u_a;
                do {
                    try {
                        try {
                            topping* t = new topping();
                            cin >> t[0];
                            u->new_topping(t);
                            //delete t;
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
                            accepted = true;
                            try {
                                cout << "Veldu Nytt alegg(n) eda haetta(h): ";
                                cin >> action_u_a;
                                if(!cin || !isalpha(action_u_a)) {
                                    cin.clear();
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    accepted = false;
                                    throw menu_exception();
                                }
                                else if(action_u_a != 'h' && action_u_a != 'n'){
                                    accepted = false;
                                }
                            } catch(menu_exception) {
                                cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                            }
                        } while(!accepted);
                        //delete[] top;
                    } catch(price_exception) {
                        cout << "Verd verdur ad vera tala sem er staerri en 0." << endl;
                    }
                } while(action_u_a != 'h');
                break;
            case 'm':
                //biður notanda um verð og heiti á masteðilspizzu og nýtir sér síðan menu_pizza ui klasan til þess að skrá inn restina af pizzunni
                //hendir í price exception ef skráð er verð sem er lægri en 0
                //spurt er notanda hvort hann vilji búa til nýja pizzu eða hætta
                char action_u_m;
                do {
                    try {
                        bool accepted = true;
                        string name = "";
                        int price = -1;
                        menu_pizza* mp;
                        cin.ignore();
                        do {
                            accepted = true;
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
                        //delete mp;
                        pizza* men = u->get_menu();
                        int arr_len = u->get_menu_length();
                        cout << "Allar pitsur:" << endl;
                        for(int i = 0; i < arr_len; i++) {
                            cout << men[i];
                        }
                    } catch(price_exception) {
                        cout << "Verd tharf ad vera tala og staerri en 0." << endl;
                    }
                    accepted = true;
                    do {
                        accepted = true;
                        try {
                            cout << "Veldu Nyja pitsu(n) eda haetta(h): ";
                            cin >> action_u_m;
                            if(!cin || !isalpha(action_u_m)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw menu_exception();
                            }
                            else if(action_u_m != 'h' && action_u_m != 'n'){
                                accepted = false;
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_u_m != 'h');
                break;
            case 'e':
                //sama og hin casein, biður um heiti og verð
                //hendir í exception ef verð er ekki tala sem er 0 eða stærri
                //hendir í exception action_u_e er ekki bókstafur, loopar ef þetta er annar bókstafur en n eða h
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
                        accepted = true;
                        try {
                            cout << "Veldu Nytt medlaeti(n) eda haetta(h): ";
                            cin >> action_u_e;
                            if(!cin || !isalpha(action_u_e)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                            else if(action_u_e != 'h' && action_u_e != 'n'){
                                accepted = false;
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_u_e != 'h');
                break;
            case 't':
                //svipað og hin nema biður um heiti á stað og heimilisfang
                //
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
                        accepted = true;
                        try {
                            cout << "Veldu Nyjan afhendingarstad(n) eda haetta(h): ";
                            cin >> action_u_t;
                            if(!cin || !isalpha(action_u_t)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                            else if(action_u_t != 'n' && action_u_t != 'h'){
                                accepted = false;
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_u_t != 'h');
                break;
            case 'i':
                //býr til nýtt tilboð. Byrjar menu_special og gerir flest í gegnum það.
                //spyr notandann ef hann vill búa til nýtt special eða hætta.
                char action_u_i;
                do {
                    menu_special * m_special =new menu_special();
                    m_special->start_menu();
                    bool accepted = true;
                    do {
                        accepted = true;
                        cout << "Gerdu nytt tilbod(n) eda haetta(h): ";
                        cin >> action_u_i;
                        if(!cin) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            accepted = false;
                        }
                        else if(action_u_i != 'h' && action_u_i != 'n'){
                            accepted = false;
                        }
                    } while(!accepted);
                }while(action_u_i != 'h');
                break;
            case 'l':
                char action_l;
                do{
                    do {
                        accepted = true;
                        try {
                            cout << "Veldu Syna staerdir(s), Syna botn(b), Syna alegg(a), Syna matsedilspizzur(m), Syna oll medlaeti(e), Syna stadi(t), Syna oll tilbod(i), eda haetta(h): ";
                            cin >> action_l;
                            if(!cin || !isalpha(action_l)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw menu_exception();
                            }
                        } catch(menu_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                    int counter = 0;
                    switch(action_l) {
                        case 's':{
                            pizza_size* ps = u->get_sizes();
                            int arr_lent = u->get_sizes_length();
                            cout << "Staerdir: " << endl;
                            for(int i = 0; i < arr_lent; i++) {
                                cout << ps[i];
                            }
                            //delete[] ps;
                            break;
                        }
                        case 'b':{
                            pizza_bottom* bottoms = u->get_bottoms();
                            int arr_len = u->get_bottoms_length();
                            cout << "Botnar: " << endl;
                            for(int i = 0; i < arr_len; i++) {
                                cout << bottoms[i];
                            }
                            //delete[] bottoms;
                            break;
                        }
                        case 'a':{
                            topping* top = u->get_toppings();
                            int arr_len = u->get_toppings_length();
                            cout << "Alegg: " << endl;
                            for(int i = 0; i < arr_len; i++) {
                                cout << top[i];
                            }
                            //delete[] top;
                            break;
                        }
                        case 'm':{
                            pizza* men = u->get_menu();
                            int arr_len = u->get_menu_length();
                            cout << "Allar pitsur:" << endl;
                            for(int i = 0; i < arr_len; i++) {
                                cout << men[i];
                            }
                            //delete[] men;
                            break;
                        }

                        case 'e':{
                            side_order* sides = u->get_sides();
                            int arr_len = u->get_sides_length();
                            cout << "Medlaeti: " << endl;
                            for(int i = 0; i < arr_len; i++) {
                                cout << sides[i];
                            }
                            //delete[] sides;
                            break;
                        }
                        case 't':{
                            pizza_place* places = u->get_places();
                            int arr_len = u->get_places_length();
                            cout << "Afhendingarstadir: " << endl;
                            for(int i = 0; i < arr_len; i++) {
                                cout << places[i];
                            }
                            //delete[] places;
                        }
                            break;
                       /* case 'i':{

                            break;
                        }*/

                    }
                }while(action_l != 'h');
                break;
            }
    } while(action_u != 'h');
    delete u;
}
