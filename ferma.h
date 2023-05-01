//
// Created by Lenovo on 4/23/2023.
//

#ifndef OOP_FERMA_H
#define OOP_FERMA_H

#include <vector>
#include <utility>
#include "unealta.h"
#include "animal.h"
#include "caine.h"
#include "vaca.h"

class ferma {
    std::vector<unealta> crafty;
    std::vector<std::shared_ptr<animal>> farm_animal;
    bool ok;
    std::string nume;
public:
    void build();

    ferma(std::string nume_, std::vector<unealta> &crafty_, std::vector<std::shared_ptr<animal>> &ani, bool ok_);

    [[maybe_unused]] ferma(const ferma &other);

    ferma &operator=(ferma other);

    friend void swap(ferma &f1, ferma &f2);

    friend std::ostream &operator<<(std::ostream &os, const ferma &z);

    void test_dynamic_cast();

//    [[maybe_unused]] [[nodiscard]] std::basic_string<char> getnume() const;

};


#endif //OOP_FERMA_H
