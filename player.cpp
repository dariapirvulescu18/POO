//
// Created by Lenovo on 4/23/2023.
//

#include "player.h"


player::player(const std::vector<leguma> &leg_, const std::vector<std::shared_ptr<animal>> &anim_) : leg{leg_},
                                                                                                     anim{anim_} {
    money_ = 0;
    points = 0;

}

void player::gain_money() {
    for (auto &l: leg) {
        money_ += 10 * l.getquantity();
        points += l.getquantity();
        if (!l.getready()) {
            money_ -= 10;
            points -= 1;
        }
    }
    for (auto &a: anim) {
        money_ += 100 * a->getproducts();
        points += 10 * a->getproducts();
        if (!a->getdead()) {
            money_ -= 100;
            points -= 100;
        }
        if (a->gethungry()) {
            money_ -= 10 * a->getdays();
            points -= a->getdays();
        }
    }
    std::cout << "You have gained " << money_ << " money and " << points << " points" << "\n";

}

int player::updateMoney(int amount) {
    money_ = amount;
    return money_;
}

std::ostream &operator<<(std::ostream &os, const player &p) {
    for (const auto &l: p.leg)
        os << l << " ";
    os << "\n";
    for (const auto &f: p.anim)
        os << f << " ";
    os << "\n";
    return os;
}


[[nodiscard]] int player::getmoney() const {
    return money_;
}

