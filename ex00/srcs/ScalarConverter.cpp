#include "../includes/ScalarConvert.hpp"

static bool isPseudoLiteral(const std::string &s) {
    return (s == "nan" || s == "nanf"
        || s == "+inf" || s == "-inf"
        || s == "+inff" || s == "-inff");
}

static bool isCharLiteral(const std::string &s) {
    return (s.length() == 1 && !std::isdigit(s[0]));
}

//strtod: string to double, can transform a char with a textual float in data type double.
static bool isValidNumber(const std::string &s) {
    char *end;
    std::strtod(s.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0')
        return true;
    return (*end == '\0');
}

//isprint: test is a char is printable or no.
static void printChar (double d) {
    if (d < 0 || d > 127 || d!= d)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << static_cast<char>(d) << " \n";
}

static void printInt(double d) {
    if (d < INT_MIN || d > INT_MAX || d != d)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
}

static void printFloat(double d) {
    float f = static_cast<float>(d);

    if (d != d)
        std::cout << "float: nanf\n";
    else if (d == 1.0 / 0.0)
        std::cout << "float: +inff\n";
    else if (d == -1.0 / 0.0)
        std::cout << "float: -inff\n";
    else {
        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f\n";
    }
}

static void printDouble(double d) {
    if (d != d)
        std::cout << "double: nan\n";
    else if (d == 1.0 / 0.0)
        std::cout << "double: +inf\n";
    else if (d == -1.0 / 0.0)
        std::cout << "double: -inf\n";
    else {
        std::cout << "float: " << d;
        if (d == static_cast<int>(d))   
            std::cout << ".0";
        std::cout << "\n";
    }
}

void ScalarConverter::convert(const std::string &literal) {
    double value;

    if (isPseudoLiteral(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    }
    else if (isCharLiteral(literal)) {
        value = static_cast<double>(literal[0]);
    }
    else if (isValidNumber(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    }
    else {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}