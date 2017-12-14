#include "models/pizza_special.h"
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

void pizza_special::set_description(string desc){
    strcpy(this->description, desc.c_str());
}

void pizza_special::set_side_order(side_order o){
    this->side_o = o;
}

void pizza_special::set_pizza_size(pizza_size s){
    this->pizza_s = s;
}

void pizza_special::set_quantity(int quant){
    this->quantity = quant;
}

int pizza_special::get_quantity() const{
    return this->quantity;
}
string pizza_special::get_description() const{
    string str(this->description);
    return str;
}
side_order pizza_special::get_side_order() const{
    return this->side_o;
}
pizza_size pizza_special::get_pizza_size() const{
    return this->pizza_s;
}


//Yfirskrifar ostream virkjann. Skrifar út nafn og verð tilboðs.
ostream& operator << (ostream& out, const pizza_special& p_special) {
    out << "Nafn tilbodar: " << p_special.get_name() << endl;
    out << "Verd: " << p_special.get_price() << endl;
    out << "Lysing: " << p_special.get_description() << endl;
    out << "Fjoldi pizza: " << p_special.get_quantity() << endl;
    out << "Staerd: " << p_special.get_pizza_size().get_size() << endl;
    out << "Medlaeti: " << p_special.get_side_order().get_name() << endl;
    return out;
}

//Yfirskrifar istream virkjann. Loopar ef eitthvað af inputunum er invalid.
istream& operator >> (istream& in, pizza_special& p_special){

    return in;
}
