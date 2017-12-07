#include "special_data.h"
#include "pizza_special.h"
#include <iostream>
#include <fstream>

using namespace std;

special_data::special_data() {

}

void special_data::save_special(pizza_special* p) {
    ofstream fout;
    if(!this->is_empty()) {
        pizza_special* p_z = this->get_specials();
        pizza_special p_specials[this->number_of_specials+1];
        for(int i = 0; i < this->number_of_specials; i++) {
            p_specials[i] = p_z[i];
        }
        p_specials[this->number_of_specials-1] = (*p);
        fout.open("specials.dat", ios::out|ios::binary);
        fout.write((char*)(&p_specials), sizeof(pizza_special)*(this->number_of_specials));
        fout.close();
    } else {
        pizza_special x[1];
        x[0].set_special(p->get_price(), p->get_name());
        fout.open("specials.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(pizza_special));
        fout.close();
    }
}

bool special_data::is_empty() {
    ifstream fin;
    fin.open("specials.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

pizza_special* special_data::get_specials() {
    ifstream fin;
    fin.open("specials.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(pizza_special));
    fin.seekg(0, fin.beg);
    this->number_of_specials = records+1;
    pizza_special p_specials[records+1];
    fin.read((char*)(&p_specials), sizeof(pizza_special)*(records));
    this->p_z = new pizza_special[records+1];
    for(int i = 0; i < records; i++) {
        this->p_z[i] = p_specials[i];
    }
    fin.close();
    return p_z;
}

int special_data::get_specials_length() {
    return this->number_of_specials-1;
}

