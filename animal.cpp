//
// Created by Lenovo on 4/23/2023.
//

#include "animal.h"

void animal::move() const {}


void animal::become_hungry() {
    dayswithoutfood++;
    products -= 10;
    if (dayswithoutfood == needtoeat)
        hungry = true, products -= 100;
    if (hungry && dayswithoutfood >= needtoeat * 2)
        energy = false;

}

void animal::feed() {
    if (hungry) {
        fed = true;
        std::cout << "The animal is fed!" << "\n";
    }
}

int animal::gain() {
    if (!energy) {
        std::cout << "The animal is dead!" << "\n";
        return 0;
    }

    if (products > 0) {
        std::cout << "The " << rasa << " gave you " << products << "!" << "\n";
        return products;
    }
    return 0;
}


std::ostream &operator<<(std::ostream &os, const animal &anim) {
    os << anim.rasa << " " << anim.products << anim.dayswithoutfood << anim.needtoeat << anim.hungry << anim.energy
       << "\n";
    return os;
}

animal::animal(std::string rasa_, int nte) : rasa{std::move(rasa_)}, needtoeat{nte} {
    products = 100 * needtoeat;
    dayswithoutfood = 0;
    hungry = false;
    energy = true;
    fed = false;
    if (rasa.empty())
        throw eroare_animal("The animal must have a name!\n");
    if (nte <= 0)
        throw eroare_animal("The animal must have a positive number fot its days to eat!\n");
}

animal::~animal() = default;

const std::string &animal::getName() {
    return rasa;
}

[[nodiscard]] int animal::getproducts() const {
    return products;
}

[[nodiscard]] bool animal::getdead() const {
    return energy;
}

[[nodiscard]] bool animal::gethungry() const {
    return hungry;
}

[[nodiscard]] int animal::getdays() const {
    return dayswithoutfood;
}
