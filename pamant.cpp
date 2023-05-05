

#include "pamant.h"


void pamant::growfaster() {
    new_money = farmer.getmoney();
    for (const auto &l: leg) {
        if (!l.getready() and farmer.getmoney() > 100 * l.getdays1() and ok) {
            new_money -= 100 * (l.getdays1() - l.getdays2());
            std::cout << "Now you have " << new_money << " money !" << "\n";
            farmer.updateMoney(new_money);
        } else
            std::cout << "You can't speed up the process!" << "\n";

    }

}

void pamant::plant_fructs() {
    std::cout << "You want to plant some fruct?\n";
}

std::ostream &operator<<(std::ostream &os, const pamant &p) {
    for (const auto &l: p.leg)
        os << l << " ";
    os << "\n";

    return os;
}

pamant::pamant(std::vector<leguma> &leg_, player &farmer_, bool ok_) : leg{leg_}, farmer{farmer_}, ok{ok_} {}

pamant::pamant(std::vector<fruct> &fr_, player &farmer, bool ok_) : fr(fr_), farmer(farmer), ok{ok_} {
    if (fr.size() < 3)
        throw eroare_pamant("You can't plant less than 3 fructs!\n");
}





