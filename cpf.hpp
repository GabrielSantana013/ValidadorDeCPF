#pragma once // Evita que o cabeçalho seja incluído mais de uma vez

#include <iostream>
#include <memory>
#include <ctime>
#include <algorithm>

class Cpf{

    public:
        Cpf();
        std::string m_numbs;
        void generateFirstDigit();
        void generateSecondDigit();
        void formatCpf();
        bool checkCpf(std::string *);
};