//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_UNEALTA_H
#define OOP_UNEALTA_H

#include "player.h"

class unealta {
    std::string denumire, viteza;

    int numar, object_price;
    bool want;
    int new_money{};
    bool bought;
public:
    void buy(player &anonimus);

    friend std::ostream &operator<<(std::ostream &os, const unealta &une);

    unealta(std::string denumire_, std::string viteza, int numar_, int object_price_, bool want_);

//    explicit unealta(const std::string &denumire, player &anonimus);
//
//    unealta();
//
//    explicit unealta(player &anonimus);

    [[nodiscard]] bool getBought() const;

};


#endif //OOP_UNEALTA_H
