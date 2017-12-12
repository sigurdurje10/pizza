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
    //engin set föll því constructorinn er notaður í það
    user(string username, string password, pizza_place place);
    //nær í notendanafn
    string get_username();
    //nær í passwordið
    string get_password();
    //nær í pizzastaðinn sem notandinn vinnur hjá
    pizza_place get_place();
};

#endif /* user_h */
