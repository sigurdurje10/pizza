//
//  pizza_data.cpp
//  pizza
//
//  Created by Sigurður Jökull on 28/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "repositories/pizza_size_data.h"
#include "models/pizza_size.h"
#include <iostream>
#include <fstream>

using namespace std;

pizza_size_data::pizza_size_data() {

}
//Ef það er eitthvað fyrir í skránni þá er fyrst náð í pizza_size úr skránni með get_sizes
//svo er þessu pizza_size bætt við og því er öllu síðan bombað í skránna.
//ef það er ekkert í skránni þá er p skrifað beint í skránna án þess að sækja eitthvað sem var fyrir
void pizza_size_data::save_size(pizza_size* p) {
    ofstream fout;
    if(!this->is_empty()) {
        pizza_size* p_z = this->get_sizes();
        pizza_size p_sizes[this->number_of_sizes+1];
        for(int i = 0; i < this->number_of_sizes; i++) {
            p_sizes[i] = p_z[i];
        }
        p_sizes[this->number_of_sizes-1] = (*p);
        fout.open("sizes.dat", ios::out|ios::binary);
        fout.write((char*)(&p_sizes), sizeof(pizza_size)*(this->number_of_sizes));
        fout.close();
    } else {
        pizza_size x[1];
        x[0].set_pizza(p->get_size(), p->get_price());
        fout.open("sizes.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(pizza_size));
        fout.close();
    }
}

//skoðar hvort sized.dat sé tóm. Skilar true ef hún er tóm.
bool pizza_size_data::is_empty() {
    ifstream fin;
    fin.open("sizes.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

//nær í öll pizza_sizes úr sizes.dat
pizza_size* pizza_size_data::get_sizes() {
    ifstream fin;
    fin.open("sizes.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(pizza_size));//nýtir fin.end til að sjá fjölda tilvika af pizza_size í sizes.dat
    fin.seekg(0, fin.beg);
    this->number_of_sizes = records+1;
    pizza_size p_sizes[records+1];
    fin.read((char*)(&p_sizes), sizeof(pizza_size)*(records));//les öll pizza_size úr sizes.dat í p_sizes
    this->p_z = new pizza_size[records+1];
    for(int i = 0; i < records; i++) {
        this->p_z[i] = p_sizes[i];
    }
    fin.close();
    return p_z;//skilar öllum pizza_size tilvikunum sem voru í skránni
}

int pizza_size_data::get_sizes_length() {
    return this->number_of_sizes-1;
}

