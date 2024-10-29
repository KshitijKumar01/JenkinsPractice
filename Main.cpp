#include <iostream>
#include "Operations.h"

int main()
{

    std::shared_ptr<Operations> ptr = Operations::createInstance();
    ptr->CreateEngineObjects();

    std::future<std::string> t1 = std::async(&Operations::EngineNumberOfMaxHorsePower, ptr);
    std::future<std::optional<std::vector<float>>> t2 = std::async(&Operations::TwoFloatValues, ptr);
    std::future<float> t3 = std::async(&Operations::AverageEngineTorque, ptr);
    std::future<void> t4 = std::async(&Operations::TakeInput, ptr);
    std::future<std::vector<EngineType>> t5 = std::async(&Operations::EngineTypeNInstance, ptr);
    std::optional<std::vector<float>> TwoFloatValues;
    std::string EngineNumber;
    float AverageTorque;
    std::vector<EngineType> EngineTypes;

    try
    {
        EngineNumber = t1.get();
        TwoFloatValues = t2.get();
        AverageTorque = t3.get();
        t4.wait();
        EngineTypes = t5.get();

        std::cout << "Engine number for maximum horse power is : " << EngineNumber << std::endl;
        std::cout << "Average Torque of all engine is : " << AverageTorque << std::endl;
    }
    catch (std::future_error &fe)
    {
        if (fe.code() == std::future_errc::no_state)
        {
            std::cout << fe.what() << std::endl;
        }
    }

    if (TwoFloatValues.has_value())
    {
        std::cout << "First and Last Float values are: ";
        for (float f : TwoFloatValues.value())
        {
            std::cout << f << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Null Signal Found" << std::endl;
    }

    return 0;
}