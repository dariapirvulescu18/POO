//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_LEGUMA_H
#define OOP_LEGUMA_H

#include <iostream>
#include <string>

class leguma {
private:
    std::string nume;
    int cantitate, daysToHarvest, dayspassed;
    bool isReadyToHarvest;

public:
    void grow();

    int harvested();


    leguma &operator=(const leguma &other);

    friend std::ostream &operator<<(std::ostream &os, const leguma &le);

    leguma(std::string nume_, int daysto_);

    leguma(const leguma &other);

    ~leguma();

    const std::string &getName();

    [[nodiscard]] int getquantity() const;

    [[nodiscard]] bool getready() const;

    [[nodiscard]] int getdays1() const;

    [[nodiscard]] int getdays2() const;
};

#endif //OOP_LEGUMA_H
