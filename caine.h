//
// Created by Lenovo on 4/28/2023.
//

#ifndef OOP_CAINE_H
#define OOP_CAINE_H

#include "animal.h"
#include "indicators.h"

class caine : public animal {
    int days_to_defend;
    bool happy;

public:
    explicit caine(const std::string &rasa = "dog", int nte = 4, int days_to_defend = 0);


    [[nodiscard]] std::shared_ptr<animal> clone() const override { return std::make_shared<caine>(*this); }

    ~caine() override;

    int gain() override;

    void move() const override;

};


#endif //OOP_CAINE_H
