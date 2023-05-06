//
// Created by Lenovo on 4/28/2023.
//

#include "caine.h"

caine::caine(const std::string &rasa, int nte, int days_to_defend) : animal(rasa, nte), days_to_defend(days_to_defend) {
    happy = false;
}


caine::~caine() {
    std::cout << "destructor caine" << "\n";
}

int caine::gain() {
    if (days_to_defend <= 4) {
        happy = true;
        std::cout << "The farm is protected" << "\n";

    }
    return 0;
}

void caine::move() const {
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


