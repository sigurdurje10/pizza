//
//  user.h
//  pizza
//
//  Created by Sigurður Jökull on 02/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef user_h
#define user_h

#include <stdio.h>
#include <string>
#include "pizza_place.h"

using namespace std;

class user {
private:
    char username[32];
    char password[32];
    pizza_place place;
public:
    user();
    user(string username, string password, pizza_place place);
    string get_username();
    string get_password();
    pizza_place get_place();
};

#endif /* user_h */
