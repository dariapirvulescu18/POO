//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <vector>

#include "animal.h"
#include "leguma.h"

class player {
    std::vector<leguma> leg;
    std::vector<std::shared_ptr<animal>> anim;
    int money_{}, points{};

public:


    void gain_money();

    int updateMoney(int amount);

    friend std::ostream &operator<<(std::ostream &os, const player &p);

    explicit player(const std::vector<leguma> &leg_, std::vector<std::shared_ptr<animal>> anim_);

    [[nodiscard]] int getmoney() const;


};

#endif //OOP_PLAYER_H
