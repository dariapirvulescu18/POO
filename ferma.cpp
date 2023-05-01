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

ferma::ferma(std::string nume_, std::vector<unealta> &crafty_, std::vector<std::shared_ptr<animal>> &ani, bool ok_)
        : crafty(std::move(crafty_)), farm_animal(std::move(ani)),
          ok(ok_),
          nume(std::move(nume_)) {}

[[maybe_unused]] ferma::ferma(const ferma &other) : ok(other.ok), nume(other.nume) {
    for (const auto &a: other.farm_animal)
        farm_animal.emplace_back(a->clone());
    for (const auto &c: other.crafty)
        crafty.emplace_back(c);
}

ferma &ferma::operator=(ferma other) {
    std::swap(*this, other);
    return *this;
}

void swap(ferma &f1, ferma &f2) {
    std::swap(f1.ok, f2.ok);
    std::swap(f1.nume, f2.nume);
    std::swap(f1.farm_animal, f2.farm_animal);
    std::swap(f1.crafty, f2.crafty);
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

void ferma::test_dynamic_cast() {
    for (auto &animal: farm_animal) {
        if (auto v = std::dynamic_pointer_cast<vaca>(animal)) {
            v->move();
        }
    }
}

[[maybe_unused]] std::basic_string<char> ferma::getnume() const {
    return nume;
}


