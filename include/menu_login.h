//
//  menu_login.h
//  pizza
//
//  Created by Sigurður Jökull on 01/12/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef menu_login_h
#define menu_login_h

#include <stdio.h>
#include "manage.h"

class menu_login {
private:
public:
    menu_login();
    void start_menu();
    void reg_menu();
    manage* m;
};


#endif /* menu_login_h */
