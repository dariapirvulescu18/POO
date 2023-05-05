//
// Created by Lenovo on 5/5/2023.
//

#include "pisica.h"

pisica::pisica(const std::string &rasa, int nte, bool sleepy) : animal(rasa, nte), sleepy(sleepy) {}

void pisica::move() const {
    if (!sleepy) {
        indicators::IndeterminateProgressBar bar{
                indicators::option::BarWidth{40},
                indicators::option::Start{"🌷"},
                indicators::option::Fill{"."},
                indicators::option::Lead{"😸"},
                indicators::option::End{"🌷"},
                indicators::option::PostfixText{"happy cat"},
                indicators::option::ForegroundColor{indicators::Color::magenta},
                indicators::option::FontStyles{
                        std::vector<indicators::FontStyle>{indicators::FontStyle::bold}}
        };

        indicators::show_console_cursor(false);

        auto job = [&bar]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(6000));
            bar.mark_as_completed();
            std::cout << termcolor::bold << termcolor::blue
                      << "THE CAT IS SLEEPY NOW\n" << termcolor::reset;
        };
        std::thread job_completion_thread(job);

        // Update bar state
        while (!bar.is_completed()) {
            bar.tick();
            std::this_thread::sleep_for(std::chrono::milliseconds(90));
        }

        job_completion_thread.join();

        indicators::show_console_cursor(true);

    }

}

