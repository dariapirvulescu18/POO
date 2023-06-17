//
// Created by Lenovo on 4/23/2023.
//

#include "fruct.h"

std::ostream &operator<<(std::ostream &os, const fruct &fr) {
    os << fr.tip << " " << fr.kg << "\n";
    return os;
}



