//
// Created by Lenovo on 6/16/2023.
//

#ifndef OOP_FRUCT_BUILDER_H
#define OOP_FRUCT_BUILDER_H

#include <utility>

#include "fruct.h"
#include "singleton.h"

class fruct_builder : public singleton<fruct_builder> {
    fruct f;
public:
    fruct_builder() = default;

    fruct_builder &tip_fruct(std::string string) {
        f.tip = std::move(string);
        return *this;
    }

    fruct_builder &culoare_fruct(std::string string) {
        f.culoare = std::move(string);
        return *this;
    }

    fruct_builder &gust_fruct(std::string string) {
        f.gust = std::move(string);
        return *this;
    }

    fruct_builder &kg_fruct(int kg) {
        f.kg = kg;
        return *this;
    }

    fruct_builder &pret_fruct(int pret) {
        f.pret = pret;
        return *this;
    }

    fruct build() {
        return f;
    }
};


#endif //OOP_FRUCT_BUILDER_H
