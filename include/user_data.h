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
#include "user.h"

class user_data {
private:
    int number_of_users;
    user* users;
    string user_file;
public:
    user_data();
    void save_users(user* list);
    void save_user(user* p);
    user* get_users();
    int get_users_length();
    bool is_empty();
};

#endif /* user_data_h */
