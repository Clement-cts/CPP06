#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

static void printData(const std::string& label, Data* data) {
    std::cout << label << std::endl;
    std::cout << " address : " << data << std::endl;
    std::cout << " number : " << data->number << std::endl;
    std::cout << " text : " << data->text << std::endl;
    std::cout << std::endl;
}

int main () {
    Data data1;
    data1.number = 42;
    data1.text = "hello world";

    Data data2;
    data2.number = -128;
    data2.text = "hello other world";

    std::cout << "===== Before serialization =====" << std::endl;
    printData("Data1", &data1);
    printData("Data2", &data2);

    uintptr_t raw1 = Serializer::serialize(&data1);
    uintptr_t raw2 = Serializer::serialize(&data2);

    Data* ptr1 = Serializer::deserialize(raw1);
    Data* ptr2 = Serializer::deserialize(raw2);

    std::cout << "\n===== After deserialization =====" << std::endl;
    printData("Data1", ptr1);
    printData("Data2", ptr2);

    std::cout << "\n===== Address checking =====" << std::endl;
    std::cout << "data1 == ptr1 ? " << (&data1 == ptr1 ? "YES" : "NO") << std::endl;
    std::cout << "data2 == ptr2 ? " << (&data2 == ptr2 ? "YES" : "NO") << std::endl;

    return 0;
}