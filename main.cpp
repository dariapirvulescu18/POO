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
#include "fruct_builder.h"
#include "unealta_factory.h"

int main() {
    auto &f = fruct_builder::get_instance();

    fruct zmeura = f.tip_fruct("fructe de padure").culoare_fruct("rosie").gust_fruct("dulce").kg_fruct(13).pret_fruct(
            5).build();
    fruct piersica = f.culoare_fruct("galbena").gust_fruct("dulce").kg_fruct(6).pret_fruct(3).build();
    fruct mar = f.tip_fruct("creste in copac").culoare_fruct("rosie").kg_fruct(8).pret_fruct(4).build();

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
//        auto &u_f=unealta_factory::get_instance();
        unealta ciocan = unealta_factory::ciocan();
        unealta lopata = unealta_factory::lopata();
        unealta cuie = unealta_factory::cuie();
        lopata.buy(Alex);
        ciocan.buy(Alex);
        cuie.buy(Alex);

        std::vector<unealta> crafts;
        crafts.push_back(lopata);
        crafts.push_back(ciocan);
        crafts.push_back(cuie);

        auto &HAYDAY = ferma::get_instance("HAYDAY", Alex, crafts, farmanimal, true);


        HAYDAY.build();
        HAYDAY.defend();
        HAYDAY.move_all_animals();

        pamant fertil(vegetable, Alex, true);
        fertil.growfaster();
        pamant infertil(fructe, Alex, true);
        pamant::plant_fruit();
        std::cout << Luna;
        std::cout << PUFI;
        std::cout << MILKA;
        vaca eroare("", -3, vegetable);


    }
    catch (eroare_joc &exc) {
        std::cout << exc.what();
    }


    return 0;

}