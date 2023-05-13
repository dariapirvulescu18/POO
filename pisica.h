//
// Created by Lenovo on 5/5/2023.
//

#ifndef OOP_PISICA_H
#define OOP_PISICA_H

#include "animal.h"
#include "indicators.h"

class pisica : public animal {
    bool sleepy;

    void afisare(std::ostream &os) const override {
        if (sleepy)
            os << " pisica este somnoroasa" << "\n";
        else
            os << "pisica nu este somnoroasa " << "\n";
    }

public:
    pisica(const std::string &rasa, int nte, bool sleepy);

    void move() const override;

    [[nodiscard]] std::shared_ptr<animal> clone() const override { return std::make_shared<pisica>(*this); }

};


#endif //OOP_PISICA_H
