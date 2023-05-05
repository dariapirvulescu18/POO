//
// Created by Lenovo on 5/1/2023.
//

#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <stdexcept>

class eroare_joc : public std::runtime_error {
    using std::runtime_error::runtime_error;
public:
    ~eroare_joc() override;
};

class eroare_animal : public eroare_joc {
    using eroare_joc::eroare_joc;
};

class eroare_pamant : public eroare_joc {
    using eroare_joc::eroare_joc;
};


#endif //OOP_EXCEPTII_H
