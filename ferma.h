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
    player jucator;
public:
    void build();

    ferma(std::string nume_, player &jucator_, std::vector<unealta> &crafty_, std::vector<std::shared_ptr<animal>> &ani,
          bool ok_);

    ferma(const ferma &other);

    ferma &operator=(ferma other);

    friend void swap(ferma &f1, ferma &f2);

    friend std::ostream &operator<<(std::ostream &os, const ferma &z);

    [[maybe_unused]] [[nodiscard]] std::string getnume() const;
//    void test_dynamic_cast();

    void defend();

    virtual ~ferma();

    void move_all_animals();

};


#endif //OOP_FERMA_H
