//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_ANIMAL_H
#define OOP_ANIMAL_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "exceptii.h"
class animal {
    std::string rasa;
    int products, dayswithoutfood, needtoeat;
    bool hungry, energy, fed;
    virtual void afisare(std::ostream &os) const;
public:
    virtual void feed();

    virtual void move() const = 0;

    [[nodiscard]] virtual std::shared_ptr<animal> clone() const = 0;

    void become_hungry();

    virtual int gain();

    friend std::ostream &operator<<(std::ostream &os, const animal &anim);

    animal(std::string rasa_, int nte);

    const std::string &getName();

    virtual ~animal();

    [[nodiscard]] int getproducts() const;

    [[nodiscard]] bool getdead() const;

    [[nodiscard]] bool gethungry() const;

    [[nodiscard]] int getdays() const;

};

#endif //OOP_ANIMAL_H
