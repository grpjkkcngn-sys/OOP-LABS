#pragma once
#include "Car.h"

class SportsCar : Car
{
protected:
    std::string turbo;

public:
    int SetTurbo(std::string turbo_type)
    {
        turbo = turbo_type;
        return 1;
    }

    SportsCar(std::string turbo_type)
    {
        int e = SetTurbo(turbo_type);
        std::cout << "Тип турбіни: " << turbo << "\n";
    }

    SportsCar() {}
};
