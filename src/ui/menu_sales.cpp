//
//  menu_sales.cpp
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "ui/menu_sales.h"
#include "ui/menu_pizza.h"
#include "models/pizza.h"
#include <iostream>
#include <string>
#include "services/manage.h"
#include "services/sales.h"
#include "models/order.h"
#include "models/side_order.h"
#include "ui/menu_shorthand.h"
#include <limits>
#include "models/user.h"
#include "models/pizza_place.h"
#include "models/pizza_special.h"
#include "repositories/special_data.h"

using namespace std;

menu_sales::menu_sales() {

}

void menu_sales::start_menu(user current_user) {
    manage* u = new manage();
    sales* s = new sales();
    pizza_place place;
    if(current_user.get_username() != "") {
        place = current_user.get_place();
    }
    char action_s;
    //beðið notanda um að velja eitt af valmöguleikunum, loopar þangað til h er valið
    do {
        bool accepted = true;
        do {
            accepted = true;
            try {
                cout << "Skra pontun(p), Skra pontun flytileid(f), Sja heildarverd(v), Skra pontun senta/sotta(s), Merkja pontun greidda(g), Merkja afhendingarstad(a), Skra athugasemd(t), Sja allar pantanir(n), Eyda pontun(e) eda haetta(h): ";
                cin >> action_s;
                if(!cin) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accepted = false;
                    throw sales_exception();
                }
            } catch(sales_exception) {
                cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
            }
        } while(!accepted);
        switch(action_s) {
            case 'f': {
                //callar á menu_shorthand ui klasan,
                //notar hann til að skrá inn pizzu með syntax
                //síðan er notandi beðinn um að staðfesta að hann vilji að pizzan sé skráð
                //hent í exception ef inntakið er ekki bókstafur
                //líka meðhöndlað exception villur úr menu_shorthand
                try {
                    order* o;
                    menu_shorthand* shorthand = new menu_shorthand();
                    o = shorthand->get_shorthand();
                    if(place.get_address() != "") {
                        o->set_place(place);
                    }
                    char stadfest;
                    try {
                        do{
                            cout << "Stadfesta pontun(j/n): ";
                            cin >> stadfest;
                            if(!isalpha(stadfest)) {
                                throw sales_exception();
                            }
                            if(stadfest == 'j') {
                                s->new_order(o);
                            }
                        }while(stadfest != 'j' && stadfest != 'n');
                    } catch(sales_exception) {
                        cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                    }
                } catch(short_exception) {
                    cout << "Villa i inslaetti." << endl;
                } catch(phone_exception) {
                    cout << "Simanumer ma ekki innihalda bokstafi." << endl;
                } catch(price_exception) {
                    cout << "Verd verdur ad vera tala sem er staerri en 0." << endl;
                } catch(size_exception) {
                    cout << "Staerd verdur ad vera tala sem er staerri en 0." << endl;
                }
                break;
            }
            //pöntun skráð
            case 'p': {
                char action_s_p;
                cin.ignore();
                do {
                    try {
                        bool accepted = true;
                        order* o = new order();
                        string phone = "";
                        string address = "";
                        do {
                            //beðið um símanúmer og heimilisfang viðskiptavinar
                            //bæði skráð í tilvik af order, o
                            accepted = true;
                            cout << "Simanumer: ";
                            getline(cin, phone);
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw phone_exception();
                            }
                            if(accepted && phone != "") {
                                cout << "Heimilisfang: ";
                                getline(cin, address);
                                if(!cin) {
                                    cin.clear();
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    accepted = false;
                                    throw address_exception();
                                }
                            }
                        } while(!accepted || phone == "" || address == "");
                        o->set_phone(phone);
                        o->set_address(address);
                        int p_count = 0;
                        char action_s_p_p;
                        do {
                            cout << "Pitsa af matsedli(m) eda servalin(s):  ";
                            bool accepted = true;
                            do {
                                accepted = true;
                                try {
                                    cin >> action_s_p_p;
                                    if(!cin || !isalpha(action_s_p_p)) {
                                        cin.clear();
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        accepted = false;
                                        throw pizza_exception();
                                    }
                                } catch(pizza_exception) {
                                    cout << "Pitsa vitlaust innslegin." << endl;
                                }
                            } while(!accepted);
                            string pizza_name = "";
                            string bottom = "";
                            int size = -1;
                            pizza p;
                            //ef notandi valdi m þá er hann beðinn um að slá inn pizzu af matseðli
                            if(action_s_p_p == 'm') {
                                string pizza_name = "";
                                cin.ignore();
                                while(pizza_name == "") {
                                    cout << "Heiti pitsu af matsedli: ";
                                    getline(cin, pizza_name);
                                    p = u->find_menu_item(pizza_name);
                                    if(p.get_name() == "" || pizza_name == "") {
                                        cout << "Pitsa ekki til stadar." << endl;
                                    } else {
                                        cout << "Pitsa '" << p.get_name() << "' valin." << endl;
                                        o->add_pizza(p);
                                    }
                                    pizza_name = p.get_name();
                                }
                            } else {
                                //ef hann valdi servalda þá er búið til alveg ný pizza
                                menu_pizza* mp = new menu_pizza();
                                p = (*mp->get_pizza());
                            }
                            p_count++;
                            p.calculate_price();
                            cout << "Verd pitsu: " << p.get_price() << endl;
                            accepted = true;
                            do {
                                accepted = true;
                                try {
                                    cout << "Nyja pitsu(n) eda haetta(h):  ";
                                    cin >> action_s_p_p;
                                    if(!cin || !isalpha(action_s_p_p)) {
                                        cin.clear();
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        accepted = false;
                                        throw sales_exception();
                                    }
                                    else if(action_s_p_p != 'n' && action_s_p_p != 'h')
                                    {
                                        accepted = false;
                                    }
                                } catch(sales_exception) {
                                    cout << "Valmynds innslattur tharf ad vera bokstafur." << endl;
                                }
                            } while(!accepted);
                        } while(action_s_p_p != 'h' && p_count < 10); //þangað til notandi vill hætta að slá inn pizzur eða þegar
                        //10 pizzur eru komnar
                        int side_count = 0;
                        char action_s_p_s;
                        do {
                            side_order s;
                            string side;
                            string side_name = "";
                            cout << "Medlaeti: ";
                            cin.ignore();
                            getline(cin, side);
                            s = u->find_side(side);
                            side_name = s.get_name();
                            if(side_name == "" || side == "") {
                                cout << "Medlaeti ekki til stadar." << endl;
                            } else {
                                cout << "Medlaeti '" << side_name << "' valid." << endl;
                                o->add_side(s);
                            }
                            side_count++;
                            bool accepted = true;
                            do {
                                accepted = true;
                                try {
                                    cout << "Nytt medlaeti(n) eda haetta(h):  ";
                                    cin >> action_s_p_s;
                                    if(!cin || !isalpha(action_s_p_s)) {
                                        cin.clear();
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        accepted = false;
                                        throw sales_exception();
                                    }
                                    else if(action_s_p_s != 'n' && action_s_p_s != 'h'){
                                        accepted = false;
                                    }
                                } catch(sales_exception) {
                                    cout << "Valmynds innslattur tharf ad vera bokstafur." << endl;
                                }
                            } while(!accepted);
                        } while(action_s_p_s != 'h' && side_count < 10);//þangað til notandi hættir eða 10 meðlæti eru komin

                        int id = 0;
                        if(!s->orders_empty()) {
                            order* orders = s->get_orders();
                            id = s->get_orders_length();
                        }
                        if(place.get_address() != "") {
                            o->set_place(place);
                        }
                        o->set_id(id);
                        s->new_order(o);
                        cout << "Pontunarnumer: " << id << endl;
                        do {
                            accepted = true;
                            try {
                                cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                                cin >> action_s_p;
                                if(!cin || !isalpha(action_s_p)) {
                                    cin.clear();
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    accepted = false;
                                    throw sales_exception();
                                }
                                else if(action_s_p != 'n' && action_s_p != 'h'){
                                    accepted = false;
                                }
                            } catch(sales_exception) {
                                cout << "Valmynds innslattur tharf ad vera bokstafur." << endl;
                            }
                        } while(!accepted);
                        delete o;
                    } catch(sales_exception) {
                        cout << "Villa i inslaetti." << endl;
                    } catch(phone_exception) {
                        cout << "Simanumer tharf ad vera tala." << endl;
                    } catch(address_exception) {
                        cout << "Heimilisfang rangt." << endl;
                    } catch(price_exception) {
                        cout << "Verd verdur ad vera tala sem er staerri en 0." << endl;
                    }
                } while(action_s_p != 'h');
                break;
            }
            //notandi slær inn pöntunarnr. og fær upp heildarverð
            //exception ef pöntunarnúmer er ekki tala. skilaboð ef pöntunarnr. finnst ekki.
            case 'v': {
                char action_s_v;
                do {
                    bool accepted = true;
                    int order_number = -1;
                    do {
                        accepted = true;
                        try {
                            cout << "Pontunarnumer: ";
                            cin >> order_number;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                        } catch(sales_exception) {
                            cout << "Pontunarnumer tharf ad vera tala.";
                        }
                    } while(!accepted || order_number == -1);
                    order o = s->find_order(order_number);
                    if(o.get_id() != -1) {
                        cout << "Heildarverd: " << o.get_price() << endl; //o->price();
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    accepted = true;
                    do {
                        accepted = true;
                        try {
                            cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                            cin >> action_s_v;
                            if(!cin || !isalpha(action_s_v)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                            else if(action_s_v != 'h' && action_s_v != 'n'){
                                accepted = false;
                            }
                        } catch(sales_exception) {
                            cout << "Valdmynds innslattur tharf ad vera bokstafur." << endl;//exception ef input er ekki bókstafur eða
                            //það er invalid
                        }
                    } while(!accepted);
                } while(action_s_v != 'h');
                break;
            }
            //skráir pöntun sem sótta eða senta.
            //gerir check á að insláttur sé valid og check á að pöntunarnr sé til.
            case 's': {
                char action_s_s;
                do {
                    bool accepted = true;
                    int order_number = -1;
                    do {
                        accepted = true;
                        try {
                            cout << "Pontunarnumer: ";
                            cin >> order_number;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                        } catch(sales_exception) {
                            cout << "Pontunarnumer tharf ad vera tala." << endl;
                        }
                    } while(!accepted || order_number == -1);
                    order o = s->find_order(order_number);
                    if(o.get_id() != -1) {
                        bool accepted = true;
                        char del;
                        do {
                            accepted = true;
                            try {
                                cout << "Skra senta(e) eda sotta(o): ";
                                cin >> del;
                                if(!cin || !isalpha(del)) {
                                    cin.clear();
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    accepted = false;
                                }
                                else if(del != 'e' && del != 'o'){
                                    accepted = false;
                                }
                            } catch(sales_exception) {
                                cout << "Valdmynds innslattur tharf ad vera bokstafur." << endl;
                            }
                        } while(!accepted);
                        if(del == 'e') {
                            o.del();
                        } else if(del == 'o') {
                            o.pickup();
                        }
                        s->save_order(o);
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    accepted = true;
                    do {
                        accepted = true;
                        try {
                            cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                            cin >> action_s_s;
                            if(!cin || !isalpha(action_s_s)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                            else if(action_s_s != 'n' && action_s_s != 'h'){
                                accepted = false;
                            }
                        } catch(sales_exception) {
                            cout << "Valdmynds innslattur tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_s_s != 'h');
                break;
            }
            //merkir pöntun greidda, með check til að skoða að input sé rétt
            case 'g': {
                char action_s_g;
                do {
                    bool accepted = true;
                    int order_number = -1;
                    do {
                        accepted = true;
                        try {
                            cout << "Pontunarnumer: ";
                            cin >> order_number;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                        } catch(sales_exception) {
                            cout << "Pontunarnumer tharf ad vera tala." << endl;
                        }
                    } while(!accepted || order_number == -1);
                    order o = s->find_order(order_number);
                    if(o.get_id() != -1) {
                        o.is_paid();
                        s->save_order(o);
                        cout << "Pontun hefur verid merkt greidd. " << endl;
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    do {
                        accepted = true;
                        try {
                            cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                            cin >> action_s_g;
                            if(!cin || !isalpha(action_s_g)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                            }
                            else if(action_s_g != 'h' && action_s_g != 'n'){
                                accepted = false;
                            }
                        } catch(sales_exception) {
                            cout << "Valdmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_s_g != 'h');
                break;
            }
            //merkir afhendingarstað, með input checks
            case 'a': {
                char action_s_a;
                do {
                    bool accepted = true;
                    int order_number = -1;
                    string place = "";
                    do {
                        accepted = true;
                        try {
                            cout << "Pontunarnumer: ";
                            cin >> order_number;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                        } catch(sales_exception) {
                            cout << "Pontunarnumer tharf ad vera tala." << endl;
                        }
                    } while(!accepted || order_number == -1);
                    string place_value = "";
                    pizza_place p;
                    cin.ignore();
                    while(place_value == "") {
                        cout << "Afhendingarstardur: ";
                        getline(cin, place);
                        p = u->find_place(place);
                        place_value = p.get_name();
                        if(place_value == "") {
                            cout << "Stadur finnst ekki." << endl;
                        } else {
                            cout << "Stadur '" << place_value << "' valinn." << endl;
                        }
                    }
                    order o = s->find_order(order_number);
                    if(o.get_id() != -1) {
                        o.set_place(p);
                        s->save_order(o);
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    do {
                        accepted = true;
                        try {
                            cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                            cin >> action_s_a;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                            else if(action_s_a != 'n' && action_s_a != 'h'){
                                accepted = false;
                            }
                        } catch(sales_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_s_a != 'h');
                break;
            }
            case 't': {
                //skráir athugasemd við pöntun
                //með checks til að athuga að input sé rétt
                char action_s_t;
                do {
                    int order_number = -1;
                    string comment = "";
                    do {
                        accepted = true;
                        try {
                            cout << "Pontunarnumer: ";
                            cin >> order_number;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                            if(accepted && order_number != -1) {
                                cout << "Athugasemd: ";
                                cin.ignore();
                                getline(cin, comment);
                                if(!cin) {
                                    cin.clear();
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    accepted = false;
                                }
                            }
                        } catch(sales_exception) {
                            cout << "Pontunarnumer tharf ad vera tala." << endl;
                        }
                    } while(!accepted || order_number == -1 || comment == "");
                    order o = s->find_order(order_number);
                    if(o.get_id() != -1) {
                        o.set_comment(comment);
                        s->save_order(o);
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    bool accepted = true;
                    do {
                        accepted = true;
                        try {
                            cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                            cin >> action_s_t;
                            if(!cin || !isalpha(action_s_t)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                            else if(action_s_t != 'n' && action_s_t != 'h'){
                                accepted = false;
                            }
                        } catch(sales_exception) {
                            cout << "Valdmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_s_t != 'h');
                break;
            }
            //nær í allar virkar pantanir og prentar þær út með for loopu.
            case 'n': {
                order* orders = s->get_orders();
                for(int i = 0; i < s->get_orders_length(); i++) {
                    cout << orders[i];
                }
                break;
            }
            //tekur inn færslunúmer ef það er til þá er því eytt
            //með check til að athuga að input sé valid
            case 'e': {
                char action_s_t;
                do {
                    int order_number = -1;
                    do {
                        accepted = true;
                        try {
                            cout << "Pontunarnumer: ";
                            cin >> order_number;
                            if(!cin) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw sales_exception();
                            }
                        } catch(sales_exception) {
                            cout << "Pontunarnumer tharf ad vera tala." << endl;
                        }
                    } while(!accepted || order_number == -1);
                    order o = s->find_order(order_number);
                    if(o.get_id() != -1) {
                        s->delete_order(o);
                        cout << "Faersla '" << order_number << "' eydd." << endl;
                    } else {
                        cout << "Faersla fannst ekki. " << endl;
                    }
                    bool accepted = true;
                    do {
                        accepted = true;
                        try {
                            cout << "Veldu Nyja pontun(n) eda haetta(h): ";
                            cin >> action_s_t;
                            if(!cin || !isalpha(action_s_t)) {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                accepted = false;
                                throw new sales_exception();
                            }
                            else if(action_s_t != 'n' && action_s_t != 'h'){
                                accepted = false;
                            }
                        } catch(sales_exception) {
                            cout << "Valmynds inntak tharf ad vera bokstafur." << endl;
                        }
                    } while(!accepted);
                } while(action_s_t != 'h');
                break;
            }
        }
    } while(action_s != 'h');
    delete u;
    delete s;
}
