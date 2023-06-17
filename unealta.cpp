//
// Created by Lenovo on 4/23/2023.
//

#include "unealta.h"

#include <utility>


void unealta::buy(player &anonimus) {
    new_money = anonimus.getmoney();
    if (want and anonimus.getmoney() > object_price * numar) {
        new_money -= object_price * numar;
        std::cout << "You have purchased " << numar << " " << denumire << " and now have " << new_money << " money !"
                  << "\n";
        bought = true;
        anonimus.updateMoney(new_money);
    } else {
        while (object_price * numar > anonimus.getmoney())
            numar--;
        if (numar != 0 and want) {
            new_money -= object_price * numar;
            std::cout << "You have purchased " << numar << " " << denumire << " and lost " << new_money << " money !"
                      << "\n";
            bought = true;
            anonimus.updateMoney(new_money);
        } else
            std::cout << "You can't buy this item!" << "\n";
    }

}

std::ostream &operator<<(std::ostream &os, const unealta &une) {
    os << une.denumire << " " << une.numar << "\n";
    return os;
}

unealta::unealta(std::string denumire_, std::string viteza, int numar_, int object_price_, bool want_) :
        denumire{std::move(denumire_)}, viteza{std::move(viteza)}, numar{numar_}, object_price{object_price_},
        want{want_} {

    bought = false;
}

[[nodiscard]] bool unealta::getBought() const {
    return bought;
}

