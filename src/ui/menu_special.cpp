#include "ui/menu_special.h"
#include <limits>
#include <string.h>
#include <iostream>
#include "models/pizza_special.h"
#include "services/manage.h"

using namespace std;

menu_special::menu_special(){

}

void menu_special::start_menu(){

    manage* m =new manage();
    pizza_special* p_special = new pizza_special();
    cin >> *p_special;
    m->new_special(p_special);

}
