#include "../includes/Identihy.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate() {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    int r = std::rand() % 3;
    if (r == 0) {
        std::cout << "Generated A\n";
        return new A;
    }
    else if (r == 1) {
        std::cout << "Generated B\n";
        return new B;
    }
    else if (r == 2) {
        std::cout << "Generates C\n";
        return new C;
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "identify(Base*): A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "identify(Base*): B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "identify(Base*): C\n";
    else
        std::cout << "identify(Base*): Unknown\n";
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "identify(Base&): A\n";
        return;
    } catch (...) {}
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "identify(Base&): B\n";
        return;
    } catch (...) {}
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "identify(Base&): C\n";
        return;
    } catch (...) {}
    std::cout << "identify(Base&): Unknown";
}