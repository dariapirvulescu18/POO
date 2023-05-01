#include <string>
#include <iostream>
#include <vector>
//#include <stdexcept>
#include <memory>
#include "leguma.h"
#include "animal.h"
#include "player.h"
#include "unealta.h"
#include "ferma.h"
#include "pamant.h"
#include "vaca.h"
#include "caine.h"

//class eroare_stringuri :public std::runtime_error
//{
//    using std::runtime_error::runtime_error;
//};
//class eroare_numere: public std::logic_error{
//    using std::logic_error::logic_error;
//};

int main() {
    leguma cartof("potato", 3);
    leguma rosie("tomato", 5);
    leguma castravete("cucumber", 7);

    leguma l1("l1", 5), l2(l1), l3("l3", 6);
    l3 = l2;
    l2.grow();
    std::cout << l1 << " " << l2 << " " << l3 << "\n";

    std::cout << "You have planted " << cartof.getName() << " and " << rosie.getName() << "." << "\n";
    for (int i = 0; i < 3; i++) {
        cartof.grow();
        rosie.grow();
    }

    cartof.harvested();
    rosie.harvested();

    std::vector<leguma> vegetable;
    vegetable.push_back(cartof);
    vegetable.push_back(rosie);
    vegetable.push_back(castravete);

    std::shared_ptr<vaca> MILKA = std::make_shared<vaca>("Milka", 3, vegetable);
    MILKA->feed();
    MILKA->gain();
    MILKA->become_hungry();

    std::shared_ptr<vaca> LILY = std::make_shared<vaca>("Lily", 3, vegetable);

    std::shared_ptr<caine> PUFI = std::make_shared<caine>("pufi", 4, 3);
    PUFI->gain();


    for (int i = 0; i < 8; i++) {
        PUFI->become_hungry();
    }
    PUFI->feed();
    std::cout << PUFI->getName() << "\n";
    std::vector<std::shared_ptr<animal>> farmanimal;

    farmanimal.push_back(PUFI);

    farmanimal.push_back(MILKA);
    farmanimal.push_back(LILY);


    player Alex{vegetable, {
            vaca("MILKA", 3, vegetable).clone(),
            vaca("LILY", 3, vegetable).clone(),
            caine("PUFI", 4, 3).clone()
    }
    };
    Alex.gain_money();
    unealta lopata("shovels", Alex, 5, 145, true);
    unealta ciocan("hammers", Alex, 4, 100, true);
    unealta cuie("nails", Alex, 10, 50, true);
    lopata.buy();
    ciocan.buy();
    cuie.buy();
    std::vector<unealta> crafts;
    crafts.push_back(lopata);
    crafts.push_back(ciocan);
    crafts.push_back(cuie);
    ferma LOLA("LOLA", crafts, farmanimal, true);
    LOLA.build();
    pamant fertil(vegetable, Alex, true);
    fertil.growfaster();


    MILKA->move();
    PUFI->move();
    LOLA.test_dynamic_cast();
//    player HAYDAY("HAYDAY",crafts,farmanimal,true),f1(HAYDAY);
//    HAYDAY=LOLA;
//    std::cout<<HAYDAY.getnume()<<f1.getnume()<<"\n";

    return 0;

}