//
// Created by Lenovo on 6/16/2023.
//

#ifndef OOP_UNEALTA_FACTORY_H
#define OOP_UNEALTA_FACTORY_H

#include "unealta.h"
#include "singleton.h"

class unealta_factory : public singleton<unealta_factory> {
public:
    static unealta ciocan() { return {"hammers", "lent", 4, 100, true}; }

//    static unealta surubelnita(){ return  {"screwdriver","fast",  4, 100, true};}
    static unealta lopata() { return {"shovel", "medium", 4, 100, true}; }

    static unealta cuie() { return {"nails", "fast", 4, 100, true}; }
//    static unealta suruburi() { return  {"screws","fast",  4, 100, true};}
//    static unealta surubelnita_stelata() { return  {"star screwdriver","fast",  4, 100, true};}
};


#endif //OOP_UNEALTA_FACTORY_H
