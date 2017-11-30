#include "pizza_place_data.h"

pizza_place_data::pizza_place_data()
{
    //ctor
}

pizza_place_data::~pizza_place_data()
{
    //dtor
}

void pizza_place_data::save_place(pizza_place* p) {
    ofstream fout;
    if(!this->is_empty()) {
        pizza_place* p_p = this->get_places();
        pizza_place p_places[this->number_of_places+1];
        for(int i = 0; i < this->number_of_places; i++) {
            p_places[i] = p_p[i];
        }
        p_places[this->number_of_places-1] = (*p);
        fout.open("places.dat", ios::out|ios::binary);
        fout.write((char*)(&p_places), sizeof(pizza_place)*(this->number_of_places));
        fout.close();
    } else {
        pizza_place x[1];
        x[0].set_name(p->get_name());
        x[0].set_address(p->get_address());
        fout.open("places.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(pizza_place));
        fout.close();
    }
}

bool pizza_place_data::is_empty() {
    ifstream fin;
    fin.open("places.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

pizza_place* pizza_place_data::get_places() {
    ifstream fin;
    fin.open("places.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(pizza_place));
    fin.seekg(0, fin.beg);
    this->number_of_places = records+1;
    pizza_place p_places[records+1];
    fin.read((char*)(&p_places), sizeof(pizza_place)*(records));
    this->p_p = new pizza_place[records+1];
    for(int i = 0; i < records; i++) {
        this->p_p[i] = p_places[i];
    }
    fin.close();
    return p_p;
}

int pizza_place_data::get_places_length() {
    return this->number_of_places-1;
}




