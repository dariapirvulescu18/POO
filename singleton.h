//
// Created by Lenovo on 6/16/2023.
//

#ifndef OOP_SINGLETON_H
#define OOP_SINGLETON_H

#include <iostream>
#include <utility>

template<class T>
class singleton {
protected:
    singleton() = default;

public:
    singleton(singleton const &) = delete;

    singleton &operator=(singleton const &) = delete;

    template<class... Args>
    static T &get_instance(Args &&... args) {
        static T instance(std::forward<Args>(args)...);
        return instance;
    }
};


#endif //OOP_SINGLETON_H
