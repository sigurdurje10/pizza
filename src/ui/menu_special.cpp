#include "ui/menu_special.h"
#include <limits>
#include <string.h>
#include <iostream>
#include "services/manage.h"
#include "models/pizza_special.h"

using namespace std;

menu_special::menu_special(){

}

//nýtir yfirskrifaðan >> operator hjá pizza_special til þess að láta notanda skrifa inn upl. í tilboð.
/*void menu_special::start_menu(){

    manage* m =new manage();
    pizza_special* p_special = new pizza_special();
    cin >> *p_special;
    m->new_special(p_special);
    delete m;
}

pizza_special* menu_special::get_special(){
    pizza_special* p_special = new pizza_special();
    manage* u = new manage();
    bool accepted = true;
    string special = "";
    string description = "";
    int p_count = -1;
    int price = -1;
    side_order s;
    pizza_size p;
     do {
        accepted = true;
        cout << "Nafn tilbods: ";
        cin.ignore();
        getline(cin, special);
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
            }
            if(accepted){
                cout << "Lysing: ";
                cin.ignore();
                getline(cin, description);
                if(!cin){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accepted= false;
                }
                if(accepted){
                    cout << "Fjoldi pizza: ";
                    cin >> p_count;
                    if(!cin){
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        accepted= false;
                    }
                    if(accepted){
                        string side;
                        string side_name = "";
                        do{
                            cout << "Medlaeti: ";
                            cin.ignore();
                            getline(cin, side);
                            s = u->find_side(side);
                            side_name = s.get_name();
                            if(side_name == "" || side == "") {
                                cout << "Medlaeti ekki til stadar." << endl;
                                accepted = false;
                            } else {
                                cout << "Medlaeti '" << side_name << "' valid." << endl;
                                accepted = true;
                                //special->add_side(s);
                            }
                        }while(accepted == false);
                        if(accepted){
                            int size_found = 0;
                            while(size_found == 0) {
                                bool accepted = true;
                                int size = -1;
                                do {
                                    accepted = true;
                                    cout << "Staerd: ";
                                    cin >> size;
                                    if(!cin) {
                                        cin.clear();
                                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                        accepted = false;
                                    }
                                } while(!accepted || size == -1);
                                pizza_size size_obj = u->find_size(size);
                                size_found = size_obj.get_size();
                                p_special->set_pizza_size(size_obj);
                                if(size_found == 0) {
                                    cout << "Staerd ekki fundinn." << endl;
                                } else {
                                    cout << "Staerd " << size_found << "\" valinn." << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    } while(!accepted || special == "" || price == -1);
    p_special->set_name(special);
    p_special->set_price(price);
    p_special->set_description(description);
    p_special->set_side_order(s);
    p_special->set_quantity(p_count);
    return p_special;
}*/
