//
//  user_data.cpp
//  user
//
//  Created by Sigurður Jökull on 02/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "user_data.h"
#include "user.h"
#include <iostream>
#include <fstream>

using namespace std;

user_data::user_data() {
    this->user_file = "users.dat";
}

void user_data::save_users(user* list) {
    ofstream fout;
    user users[this->get_users_length()];
    for(int i = 0; i < this->get_users_length(); i++) {
        users[i] = list[i];
    }
    fout.open("orders.dat", ios::out|ios::binary);
    fout.write((char*)(&users), sizeof(user)*(this->get_users_length()));
    fout.close();
}

void user_data::save_user(user* p) {
    ofstream fout;
    if(!this->is_empty()) {
        user* p_m = this->get_users();
        user users[this->number_of_users+1];
        for(int i = 0; i < this->number_of_users; i++) {
            users[i] = p_m[i];
        }
        users[this->number_of_users-1] = (*p);
        fout.open("users.dat", ios::out|ios::binary);
        fout.write((char*)(&users), sizeof(user)*(this->number_of_users));
        fout.close();
    } else {
        user x[1];
        x[0] = p[0];
        fout.open("users.dat", ios::out|ios::binary);
        fout.write((char*)(&x), sizeof(user));
        fout.close();
    }
}

bool user_data::is_empty() {
    ifstream fin;
    fin.open("users.dat", ios::binary);
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == -1 || fin.tellg() == 0) {
        return true;
    }
    return false;
}

user* user_data::get_users() {
    ifstream fin;
    fin.open("users.dat", ios::binary);
    fin.seekg(0, fin.end);
    int records = (fin.tellg() / sizeof(user));
    fin.seekg(0, fin.beg);
    this->number_of_users = records+1;
    user p_m[records+1];
    fin.read((char*)(&p_m), sizeof(user)*(records));
    this->users = new user[records+1];
    for(int i = 0; i < records; i++) {
        this->users[i] = p_m[i];
    }
    fin.close();
    return this->users;
}

int user_data::get_users_length() {
    return this->number_of_users-1;
}
