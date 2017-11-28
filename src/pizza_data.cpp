#include "pizza_data.h"
#include "pizza_size.h"
#include <iostream>
#include <fstream>

using namespace std;

pizza_data::pizza_data() {

}

void pizza_data::save_size(pizza_size* p) {
    ofstream fout;

    fout.open("sizes.dat", ios::out|ios::binary); //fstream::trunc
    fout.write((char*)(&p), sizeof(p));
    fout.close();

}

pizza_size* pizza_data::get_sizes() {
    pizza_size* pizza_sizes;
    ifstream fin;
    fin.open("sizes.dat", ios::binary);
    fin.read((char*)(&pizza_sizes), sizeof(pizza_sizes));
    fin.close();
    return pizza_sizes;
}
