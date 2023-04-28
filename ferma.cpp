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

ferma::ferma(std::vector<unealta> &crafty_, std::vector<std::shared_ptr<animal>> &ani, bool ok_) : crafty{crafty_},
                                                                                                   farm_animal{ani},
                                                                                                   ok{ok_} {

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


