//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_FRUCT_H
#define OOP_FRUCT_H

#include <string>
#include <iostream>

class fruct {
    std::string tip;
    int kg;
public:
    friend std::ostream &operator<<(std::ostream &os, const fruct &fr);

    fruct(std::string tip_, int kg_);

};


#endif //OOP_FRUCT_H
