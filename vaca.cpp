//
// Created by Lenovo on 4/28/2023.
//

#include "vaca.h"

vaca::vaca(const std::string &rasa, int nte, const std::vector<leguma> &l)
        : animal(rasa, nte), leg(l) {
    fed = false;
}


vaca::~vaca() {
    std::cout << "destructor vaca" << "\n";
}

void vaca::feed() {
    if (leg.size() == 3) {
        fed = true;
        std::cout << "The cow has been fed!" << "\n";
    }

}

void vaca::move() const {
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




