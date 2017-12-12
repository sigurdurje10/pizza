#include "models/pizza_special.h"
#include "models/side_order.h"
#include "services/manage.h"
#include <limits>
#include <string.h>
#include <iostream>


using namespace std;

pizza_special::pizza_special(){
    name[0] = '\0';
    price = 0;
}

pizza_special::pizza_special(int price, string name){
   strcpy(this->name, name.c_str());
    this->price = price;
}
void pizza_special::set_name(string name){
    strcpy(this->name, name.c_str());
}
void pizza_special::set_price(int price){
    this->price = price;
}
string pizza_special::get_name() const {
    string str(name);
    return str;
}
int pizza_special::get_price() const {
    return price;
}
void pizza_special::set_special(int price, string name){

    strcpy(this->name, name.c_str());
    this->price = price;
}
//Yfirskrifar ostream virkjann. Skrifar út nafn og verð tilboðs.
ostream& operator << (ostream& out, const pizza_special& p_special) {
    out << "Nafn tilbodar: " << p_special.get_name() << endl;
    out << "Verd: " << p_special.get_price() << endl;
    return out;
}

//Yfirskrifar istream virkjann. Loopar ef eitthvað af inputunum er invalid.
istream& operator >> (istream& in, pizza_special& p_special){
    manage* u = new manage();
    bool accepted = true;
    string special = "";
    string description = "";
    int p_count = -1;
    int price = -1;
     do {
        accepted = true;
        cout << "Nafn tilbods: ";
        in.ignore();
        getline(in, special);
        if(!in) {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            accepted = false;
        }
        if(accepted) {
            cout << "Verd: ";
            in >> price;
            if(!in) {
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                accepted = false;
            }
            if(accepted){
                cout << "Lysing: ";
                in.ignore();
                getline(in, description);
                if(!in){
                    in.clear();
                    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accepted= false;
                }
                if(accepted){
                    cout << "Fjoldi pizza: ";
                    cin >> p_count;
                    if(!in){
                        in.clear();
                        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        accepted= false;

                    }
                    if(accepted){
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
                            //special->add_side(s);
                        }

                    }
                }
            }
        }
    } while(!accepted || special == "" || price == -1);
    p_special.set_name(special);
    p_special.set_price(price);
    return in;
}
