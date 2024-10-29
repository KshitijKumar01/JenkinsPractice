#ifndef OPERATIONS_H
#define OPERATIONS_H

#include<iostream>
#include<vector>
#include<memory>
#include<mutex>
#include "Engine.h"
#include<future>
#include<condition_variable>
#include<optional>

using VType=std::vector<std::shared_ptr<Engine>>;
class Operations
{
private:
    /* data */
    int _N{0};
    std::mutex mt;
    std::condition_variable cv;
    bool flag=false;
    VType _data_container{};
    Operations(std::vector<int> data);
    static std::shared_ptr<Operations> _object;
    Operations(){}

public:
    Operations(const Operations &)=delete;
    Operations(Operations && )=delete;
    Operations & operator=(const Operations & )=delete;
    Operations &operator=(Operations &&)=delete;
    ~Operations()=default;

    static std::shared_ptr<Operations> createInstance();

    void CreateEngineObjects();
    std::string EngineNumberOfMaxHorsePower();
    std::optional<std::vector<float>> TwoFloatValues();
    float AverageEngineTorque();
    void TakeInput();
    std::vector<EngineType> EngineTypeNInstance();
};

#endif // OPERATIONS_H
