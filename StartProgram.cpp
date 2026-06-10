#include "StartProgram.h"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "SportsCar.h"
#include "ElectricCar.h"

void StartProgram()
{
    std::cout << "=== Легковий автомобіль ===\n";
    Car myCar;

    std::cout << "\n=== Вантажівка ===\n";
    Truck myTruck;

    std::cout << "\n=== Спортивний автомобіль ===\n";
    SportsCar mySportsCar("Twin-Turbo V8");

    std::cout << "\n=== Електромобіль ===\n";
    ElectricCar myElectric("Електромотор", 100, 600);
}
