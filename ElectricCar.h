#pragma once
#include "SportsCar.h"

class ElectricCar : SportsCar
{
private:
    int batteryCapacity;  // ємність батареї, кВт*год
    int range;            // запас ходу, км

public:
    int SetBatteryCapacity(int capacity)
    {
        batteryCapacity = capacity;
        return 1;
    }

    int SetRange(int car_range)
    {
        range = car_range;
        return 1;
    }

    ElectricCar(std::string turbo_type, int capacity, int car_range)
    {
        int e = SetTurbo(turbo_type);
        e = SetBatteryCapacity(capacity);
        e = SetRange(car_range);
        std::cout << "Це електромобіль. Турбіна: " << turbo
                  << ", батарея: " << batteryCapacity << " кВт*год"
                  << ", запас ходу: " << range << " км.\n";
    }
};
