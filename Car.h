#pragma once
#include "Vehicle.h"

class Car : Vehicle
{
public:
    Car()
    {
        int e = SetBrand("Toyota");
        e = SetSpeed(180);
        e = SetFuelType("бензин");
        e = CreateVehicle();
        e = Say();
    }

    int Say()
    {
        std::cout << "Я — легковий автомобіль. Їду по місту!\n";
        return 1;
    }
};
