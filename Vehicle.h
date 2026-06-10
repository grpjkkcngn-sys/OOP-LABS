#pragma once
#include <iostream>
#include <string>

class Vehicle
{
private:
    std::string brand;
    int speed;          // максимальна швидкість, км/год
    std::string fuelType;

public:
    int SetBrand(std::string vehicle_brand)
    {
        brand = vehicle_brand;
        return 1;
    }

    int SetSpeed(int max_speed)
    {
        speed = max_speed;
        return 1;
    }

    int SetFuelType(std::string fuel)
    {
        fuelType = fuel;
        return 1;
    }

    int Say()
    {
        std::cout << "Я — транспортний засіб!\n";
        return 1;
    }

protected:
    int CreateVehicle()
    {
        std::cout << "Бренд: " << brand
                  << ", макс. швидкість: " << speed << " км/год"
                  << ", пальне: " << fuelType << ".\n";
        return 1;
    }
};
