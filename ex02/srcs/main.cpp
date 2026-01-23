#include "../includes/Identihy.hpp"

int main() {
    std::cout << "===== Let's start our tests =====" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "\n===== Test #" << i + 1 << " =====" << std::endl;

        Base* base = generate();

        if (!base) {
            std::cerr << "Generation failed" << std::endl;
            continue;
        }

        std::cout << "\n===== Pointer identification ====" << std::endl;
        identify(base);
        std::cout << "\n===== Reference identification =====" << std::endl;
        identify(*base);

        delete base;
        std::cout << std::endl;
    }
    return 0;
}