//
//  get_random_int.cpp
//  NCursesDemo
//
//  Created by Russell Schoen on 3/8/20.
//  Copyright © 2020 Russell Schoen. All rights reserved.
//

#include "get_random_int.hpp"
#include <stdlib.h>
#include <ctime>

int get_random_int(int max) {
    return rand()%max;
}
