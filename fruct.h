//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_FRUCT_H
#define OOP_FRUCT_H

#include <string>
#include <iostream>

class fruct {
    std::string tip;
    std::string culoare;
    std::string gust;
    int kg, pret;

    friend class fruct_builder;

public:
    friend std::ostream &operator<<(std::ostream &os, const fruct &fr);

    fruct() = default;

};


#endif //OOP_FRUCT_H
