

#include "leguma.h"

void leguma::grow() {
    dayspassed++;
    cantitate += dayspassed * daysToHarvest;
    if (daysToHarvest == dayspassed)
        isReadyToHarvest = true;

}

int leguma::harvested() {
    if (isReadyToHarvest) {
        std::cout << "You have harvested " << cantitate << " kg of " << nume << "!" << "\n";
        return cantitate;
    } else {
        std::cout << "This crop is not ready to harvest yet." << "\n";
        cantitate = 0;
        return 0;
    }
}


leguma &leguma::operator=(const leguma &other) {
    nume = other.nume;
    cantitate = other.cantitate;
    daysToHarvest = other.daysToHarvest;
    dayspassed = other.dayspassed;
    isReadyToHarvest = other.isReadyToHarvest;


    return *this;
}

std::ostream &operator<<(std::ostream &os, const leguma &le) {
    os << le.nume << " " << le.cantitate << " " << le.dayspassed << " " << le.isReadyToHarvest << " "
       << le.daysToHarvest << "\n";
    return os;
}

leguma::leguma(std::string nume_, int daysto_) : nume{std::move(nume_)}, daysToHarvest{daysto_} {
    cantitate = 0;
    dayspassed = 0;
    isReadyToHarvest = false;
}

leguma::leguma(const leguma &other) : nume{other.nume}, cantitate{other.cantitate},
                                      daysToHarvest{other.daysToHarvest}, dayspassed{other.dayspassed},
                                      isReadyToHarvest{other.isReadyToHarvest} {}

leguma::~leguma() {
    std::cout << "am distrus" << "\n";
}

const std::string &leguma::getName() {
    return nume;
}

[[nodiscard]] int leguma::getquantity() const {
    return cantitate;
}

[[nodiscard]] bool leguma::getready() const {
    return isReadyToHarvest;
}

[[nodiscard]] int leguma::getdays1() const {
    return daysToHarvest;
}

[[nodiscard]] int leguma::getdays2() const {
    return dayspassed;
}

