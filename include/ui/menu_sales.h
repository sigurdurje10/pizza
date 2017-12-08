//
//  menu_sales.h
//  pizza
//
//  Created by Sigurður Jökull on 29/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#ifndef menu_sales_h
#define menu_sales_h

#include <stdio.h>
#include "models/user.h"
#include "exception/exception.h"

class menu_sales {
private:

public:
    menu_sales();
    void start_menu(user current_user);

};


#endif /* menu_sales_h */
