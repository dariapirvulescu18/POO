//
// Created by Lenovo on 4/28/2023.
//

#ifndef OOP_VACA_H
#define OOP_VACA_H

#include "animal.h"
#include "leguma.h"
#include "indicators.h"

class vaca : public animal {
    std::vector<leguma> leg;
    bool fed;

    void afisare(std::ostream &os) const override {
        if (fed)
            os << " vaca este hranita" << "\n";
        else
            os << "vaca nu este hranita " << "\n";
        os << "Vaca poate manca " << leg.size() << " legume" << "\n";

    }

public:
    explicit vaca(const std::string &rasa = "cow", int nte = 3, const std::vector<leguma> &l = std::vector<leguma>());


    [[nodiscard]] std::shared_ptr<animal> clone() const override { return std::make_shared<vaca>(*this); }

    ~vaca() override;

    void feed() override;

    void move() const override;


};


#endif //OOP_VACA_H
