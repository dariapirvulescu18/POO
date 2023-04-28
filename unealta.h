//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_UNEALTA_H
#define OOP_UNEALTA_H

#include "player.h"

class unealta {
    std::string denumire;
    player &anonimus;
    int numar, object_price;
    bool want;
    int new_money{};
    bool bought;
public:
    void buy();

    friend std::ostream &operator<<(std::ostream &os, const unealta &une);

    unealta(std::string denumire_, player &anonimus_, int numar_, int object_price_, bool want_);

    explicit unealta(const std::string &denumire);

    unealta();

    explicit unealta(player &anonimus);

    [[nodiscard]] bool getBought() const;

};


#endif //OOP_UNEALTA_H
