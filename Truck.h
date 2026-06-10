#pragma once
#include "Vehicle.h"

class Truck : Vehicle
{
public:
    Truck()
    {
        int e = SetBrand("Volvo");
        e = SetSpeed(120);
        e = SetFuelType("дизель");
        e = CreateVehicle();
        e = Say();
    }

    int Say()
    {
        std::cout << "Я — вантажівка. Перевожу важкі вантажі!\n";
        return 1;
    }
};
