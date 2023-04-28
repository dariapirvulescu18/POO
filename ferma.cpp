//
// Created by Lenovo on 4/23/2023.
//

#include "ferma.h"

void ferma::build() {
    for (auto &a: farm_animal) {
        ok = true;
        for (auto &u: crafty)
            if (!u.getBought())
                ok = false;
        if (ok) {
            std::cout << "The animal " << a->getName() << " now has a home!" << "\n";
        } else
            std::cout << "You don't have enough crafts to build this animal a home:((" << "\n";

    }

}

ferma::ferma(std::vector<unealta> &crafty_, std::vector<std::shared_ptr<animal>> &ani, bool ok_) : crafty(
        std::move(crafty_)),
                                                                                                   farm_animal(
                                                                                                           std::move(
                                                                                                                   ani)),
                                                                                                   ok(ok_) {

}

ferma::ferma(const ferma &other) : ok(other.ok) {
    for (const auto &a: other.farm_animal)
        farm_animal.emplace_back(a->clone());
    for (const auto &c: other.crafty)
        crafty.emplace_back(c);
}
//    ferma &ferma::operator=(ferma other){
//            swap(*this,other);
//    return *this;
//}

// void ferma::swap(ferma &f1,ferma &f2){
//    std::swap(f1.ok,f2.ok);
//    std::swap(f1.farm_animal,f2.farm_animal);
//    std::swap(f1.crafty,f2.crafty);
//}

std::ostream &operator<<(std::ostream &os, const ferma &z) {
    for (const auto &c: z.crafty)
        os << c << " ";
    os << "\n";
    for (const auto &g: z.farm_animal)
        os << g << " ";
    os << "\n";
    return os;
}

void ferma::vaca_sound() {
    for (auto &animal: farm_animal) {
        if (auto cur = std::dynamic_pointer_cast<vaca>(animal)) {
            std::cout << "moo" << "\n";
        }
    }
}


