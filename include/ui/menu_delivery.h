//
//  menu_delivery.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef menu_delivery_h
#define menu_delivery_h

#include <stdio.h>
#include "models/user.h"
#include "exception/exception.h"

class menu_delivery {
private:

public:
    menu_delivery();
    void start_menu(user current_user);

};

#endif /* menu_delivery_h */
