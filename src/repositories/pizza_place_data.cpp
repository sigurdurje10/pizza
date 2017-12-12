//
//  pizza_place_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 30/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "repositories/pizza_place_data.h"

pizza_place_data::pizza_place_data()
{
    //ctor
}

pizza_place_data::~pizza_place_data()
{
    //dtor
}
//Ef það er eitthvað fyrir í skránni þá er fyrst náð í pizza_place úr skránni með get_places
//svo er þessu tilviki af pizza_places bætt við og því er öllu síðan bombað í skránna.
//ef það er ekkert í skránni þá er p skrifað beint í skránna án þess að sækja eitthvað sem var fyrir
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

//skoðar hvort places.dat sé tóm. Skilar true ef hún er tóm.
bool pizza_place_data::is_empty() {
    ifstream fin;
    fin.open("places.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

//nær í alla pizza_place úr places.dat
pizza_place* pizza_place_data::get_places() {
    ifstream fin;
    fin.open("places.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(pizza_place));//nýtir fin.end til að sjá fjölda tilvika af pizza_place í places.dat
    fin.seekg(0, fin.beg);
    this->number_of_places = records+1;
    pizza_place p_places[records+1];
    fin.read((char*)(&p_places), sizeof(pizza_place)*(records));//les alla pizza_place úr places.dat í p_places
    this->p_p = new pizza_place[records+1];
    for(int i = 0; i < records; i++) {
        this->p_p[i] = p_places[i];
    }
    fin.close();
    return p_p;//skilar öllum pizza_place tilvikunum sem voru í skránni
}

int pizza_place_data::get_places_length() {
    return this->number_of_places-1;
}
