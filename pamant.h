//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_PAMANT_H
#define OOP_PAMANT_H

#include "leguma.h"
#include <vector>
#include "player.h"


class pamant {
    std::vector<leguma> leg;
    player &farmer;
    bool ok;
    int new_money{};

public:
    void growfaster();

    friend std::ostream &operator<<(std::ostream &os, const pamant &p);

    explicit pamant(std::vector<leguma> &leg_, player &farmer_, bool ok_);

};


#endif //OOP_PAMANT_H
