#include "repositories/special_data.h"
#include "models/pizza_special.h"
#include <iostream>
#include <fstream>

using namespace std;

special_data::special_data() {

}

//Ef það er eitthvað fyrir í skránni þá er fyrst náð í pizza_special úr skránni með get_specials
//svo er þessu pizza_special bætt við og því er öllu síðan bombað í skránna.
//ef það er ekkert í skránni þá er p skrifað beint í skránna án þess að sækja eitthvað sem var fyrir
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

//skoðar hvort specials.dat sé tóm. Skilar true ef hún er tóm.
bool special_data::is_empty() {
    ifstream fin;
    fin.open("specials.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

//nær í öll pizza_special í specials.dat
pizza_special* special_data::get_specials() {
    ifstream fin;
    fin.open("specials.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(pizza_special));//nýtir fin.end til að sjá fjölda tilvika af pizza_special í specials.dat
    fin.seekg(0, fin.beg);
    this->number_of_specials = records+1;
    pizza_special p_specials[records+1];
    fin.read((char*)(&p_specials), sizeof(pizza_special)*(records));//les allar pizza_special úr specials.dat í p_specials
    this->p_z = new pizza_special[records+1];
    for(int i = 0; i < records; i++) {
        this->p_z[i] = p_specials[i];
    }
    fin.close();
    return this->p_z; //skilar öllum pizza_special tilvikunum sem voru í skránni
}

int special_data::get_specials_length() {
    return this->number_of_specials-1;
}

