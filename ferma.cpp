//
// Created by Lenovo on 4/23/2023.
//

#include "ferma.h"

#include <utility>

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

ferma::ferma(std::string nume_, player &jucator_, std::vector<unealta> &crafty_,
             std::vector<std::shared_ptr<animal>> &ani, bool ok_)
        : crafty(crafty_), farm_animal(ani), ok(ok_), nume(std::move(nume_)),
          jucator(jucator_) {}

ferma::ferma(const ferma &other) : ok(other.ok), nume(other.nume), jucator(other.jucator) {
    for (const auto &a: other.farm_animal)
        farm_animal.emplace_back(a->clone());
    for (const auto &c: other.crafty)
        crafty.emplace_back(c);
}

void swap(ferma &f1, ferma &f2) {
    std::swap(f1.ok, f2.ok);
    std::swap(f1.nume, f2.nume);
    std::swap(f1.farm_animal, f2.farm_animal);
    std::swap(f1.crafty, f2.crafty);
    swap(f1.jucator, f2.jucator);
}

ferma &ferma::operator=(ferma other) {
    swap(*this, other);
    return *this;
}


std::ostream &operator<<(std::ostream &os, const ferma &z) {
    for (const auto &c: z.crafty)
        os << c << " ";
    os << "\n";
    for (const auto &g: z.farm_animal)
        os << g << " ";
    os << "\n";
    return os;
}

[[maybe_unused]] std::string ferma::getnume() const {
    return nume;
}

//void ferma::test_dynamic_cast() {
//    for (auto &animal: farm_animal) {
//        if (auto v = std::dynamic_pointer_cast<vaca>(animal)) {
//            v->move();
//        }
//    }
//}

void ferma::defend() {
    for (auto &animal: farm_animal) {
        if (auto c = std::dynamic_pointer_cast<caine>(animal)) {
            std::cout << "Pay the dog to defend the farm!\n";
            if (jucator.getmoney() > 1000) {
                std::cout << "You are able to defend the farm\n";
                c->move();
            }
        }
    }
}

ferma::~ferma() = default;

void ferma::move_all_animals() {
    for (const auto &ani: farm_animal)
        ani->move();

}

