//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_FERMA_H
#define OOP_FERMA_H

#include <vector>
#include "unealta.h"
#include "animal.h"

class ferma {
    std::vector<unealta> crafty;
    std::vector<std::shared_ptr<animal>> farm_animal;
    bool ok;
    std::string nume;
public:
    void build();

    ferma(std::vector<unealta> &crafty_, std::vector<std::shared_ptr<animal>> &ani, bool ok_);

    friend std::ostream &operator<<(std::ostream &os, const ferma &z);


};


#endif //OOP_FERMA_H
