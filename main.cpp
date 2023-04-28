#include <string>
#include <iostream>
#include <vector>
//#include <utility>
#include <memory>
#include "leguma.h"
#include "animal.h"
#include "player.h"
#include "unealta.h"
#include "ferma.h"
#include "pamant.h"
#include "ext/indicators.h"


class vaca : public animal {
    std::vector<leguma> leg;
    bool fed;
public:
    explicit vaca(const std::string &rasa = "cow", int nte = 3, const std::vector<leguma> &l = std::vector<leguma>())
            : animal(rasa, nte), leg(l) {
        fed = false;
    }

    [[nodiscard]] std::shared_ptr<animal> clone() const override { return std::make_shared<vaca>(*this); }

    ~vaca() override {
        std::cout << "destructor vaca" << "\n";
    }

    void feed() override {
        if (leg.size() == 3) {
            fed = true;
            std::cout << "The cow has been fed!" << "\n";
        }

    }

    void move() const override {
        if (fed) {
            indicators::IndeterminateProgressBar bar{
                    indicators::option::BarWidth{40},
                    indicators::option::Start{"👩‍🌾"},
                    indicators::option::Fill{"·"},
                    indicators::option::Lead{"🐮"},
                    indicators::option::End{"👨‍🌾"},
                    indicators::option::PostfixText{"happy cow"},
                    indicators::option::ForegroundColor{indicators::Color::yellow},
                    indicators::option::FontStyles{
                            std::vector<indicators::FontStyle>{indicators::FontStyle::bold}}
            };

            indicators::show_console_cursor(false);

            auto job = [&bar]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                bar.mark_as_completed();
                std::cout << termcolor::bold << termcolor::green
                          << "THE COW IS DONE WALKING\n" << termcolor::reset;
            };
            std::thread job_completion_thread(job);

            // Update bar state
            while (!bar.is_completed()) {
                bar.tick();
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }

            job_completion_thread.join();

            indicators::show_console_cursor(true);
        }
    }

};

class caine : public animal {
    int days_to_defend;
    bool happy;

public:
    explicit caine(const std::string &rasa = "dog", int nte = 4, int days_to_defend = 0) : animal(rasa, nte),
                                                                                           days_to_defend(
                                                                                                   days_to_defend) {
        happy = false;
    }


    [[nodiscard]] std::shared_ptr<animal> clone() const override { return std::make_shared<caine>(*this); }

    ~caine() override {
        std::cout << "destructor caine" << "\n";
    }

    int gain() override {
        if (days_to_defend <= 4) {
            happy = true;
            std::cout << "The farm is protected" << "\n";
            return 0;
        }
        return 1;
    }

    void move() const override {
        if (happy) {
            indicators::IndeterminateProgressBar bar{
                    indicators::option::BarWidth{40},
                    indicators::option::Start{"🌳"},
                    indicators::option::Fill{"."},
                    indicators::option::Lead{"🐶"},
                    indicators::option::End{"🌳"},
                    indicators::option::PostfixText{"happy dog"},
                    indicators::option::ForegroundColor{indicators::Color::blue},
                    indicators::option::FontStyles{
                            std::vector<indicators::FontStyle>{indicators::FontStyle::bold}}
            };

            indicators::show_console_cursor(false);

            auto job = [&bar]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                bar.mark_as_completed();
                std::cout << termcolor::bold << termcolor::magenta
                          << "THE DOG IS DONE PROTECTING THE FARM\n" << termcolor::reset;
            };
            std::thread job_completion_thread(job);

            // Update bar state
            while (!bar.is_completed()) {
                bar.tick();
                std::this_thread::sleep_for(std::chrono::milliseconds(80));
            }

            job_completion_thread.join();

            indicators::show_console_cursor(true);

        }

    }
};


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
    ferma LOLA(crafts, farmanimal, true);
    LOLA.build();
    pamant fertil(vegetable, Alex, true);
    fertil.growfaster();
    MILKA->move();
    PUFI->move();
    return 0;

}