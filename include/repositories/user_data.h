//
//  user_data.h
//  user
//
//  Created by Sigurður Jökull on 02/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef user_data_h
#define user_data_h

#include <stdio.h>
#include "models/user.h"

class user_data {
private:
    int number_of_users;
    user* users;
public:
    user_data();
    //vistar marga user í skrá
    void save_users(user* list);
    //vistar einn user í skrá, bætir við þá sem voru í skránni
    void save_user(user* p);
    //nær í alla notendur
    user* get_users();
    //nær í number_of_users - 1
    int get_users_length();
    //skilar true ef skráin er true
    bool is_empty();
};

#endif /* user_data_h */
