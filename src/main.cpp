//
//  main.cpp
//  pizza
//
//  Created by Sigurður Jökull on 27/11/2017.
//  Copyright © 2017 Sigurður Jökull. All rights reserved.
//

#include <iostream>
#include "menu.h"
#include <iostream>
#include <fstream>
#include "pizza_size.h"

using namespace std;

int main(int argc, const char * argv[]) {
    menu* m = new menu();
    m->start_menu();
    delete m;
    return 0;
}