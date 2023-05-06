#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "fruct.h"
#include "leguma.h"
#include "animal.h"
#include "player.h"
#include "unealta.h"
#include "ferma.h"
#include "pamant.h"
#include "vaca.h"
#include "caine.h"
#include "pisica.h"
#include "exceptii.h"


int main() {
    fruct zmeura("fructe de padure", 13);
    fruct piersica("creste in copac", 6);
    fruct mar("creste in copac", 8);
    std::vector<fruct> fructe;

    fructe.push_back(zmeura);
    fructe.push_back(piersica);
    fructe.push_back(mar);

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


    try {
        pisica Luna("pisica", 5, false);
        vaca MILKA("Milka", 3, vegetable);
        MILKA.feed();
        MILKA.gain();
        MILKA.become_hungry();

        vaca LILY("Lily", 3, vegetable);
        caine PUFI("Pufi", 4, 3);
        PUFI.gain();
        for (int i = 0; i < 8; i++) {
            PUFI.become_hungry();
        }
        PUFI.feed();
        std::cout << PUFI.getName() << "\n";

        std::vector<std::shared_ptr<animal>> farmanimal;

        farmanimal.push_back(PUFI.clone());
        farmanimal.push_back(MILKA.clone());
        farmanimal.push_back(Luna.clone());
        farmanimal.push_back(LILY.clone());

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

        ferma LOLA("LOLA", Alex, crafts, farmanimal, true);
        LOLA.build();
        LOLA.defend();
        LOLA.move_all_animals();


//        ferma HAYDAY("HAYDAY",Alex,crafts, farmanimal, true), f1(HAYDAY);
//        HAYDAY = LOLA;
//        std::cout << HAYDAY.getnume() << f1.getnume() << "\n";

        pamant fertil(vegetable, Alex, true);
        fertil.growfaster();
        pamant infertil(fructe, Alex, true);
        pamant::plant_fructs();
        vaca eroare("", -3, vegetable);
    }
    catch (eroare_joc &exc) {
        std::cout << exc.what();
    }


    return 0;

}