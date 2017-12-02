//
//  user.cpp
//  pizza
//
//  Created by Sigurður Jökull on 02/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include "user.h"

user::user() {
    
}

user::user(string username, string password, pizza_place place) {
    strcpy(this->username, username.c_str());
    strcpy(this->password, password.c_str());
    this->place = place;
}

string user::get_username() {
    string str(this->username);
    return str;
}

string user::get_password() {
    string str(this->password);
    return str;
}

pizza_place user::get_place() {
    return this->place;
}
