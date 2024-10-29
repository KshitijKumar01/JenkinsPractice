#include "Operations.h"
#include "EmptyContainerFutureException.h"
#include "NumberFutureException.h"
std::shared_ptr<Operations> Operations::_object{nullptr};
std::shared_ptr<Operations> Operations::createInstance()
{
    if (_object)
    {
        return _object;
    }
    else
    {
        _object.reset(new Operations());
        return _object;
    }
}

void Operations::CreateEngineObjects()
{
    _data_container.push_back(std::make_shared<Engine>(EngineType::REGULAR, 10005.0f, "E-1045", CylinderType::FOURCYLINDER, 15400.6f));
    _data_container.push_back(std::make_shared<Engine>(EngineType::TURBOCHARGED, 5677.0f, "E-4567", CylinderType::FOURCYLINDER, 8876.6f));
    _data_container.push_back(std::make_shared<Engine>(EngineType::REGULAR, 785500.0f, "E-2345", CylinderType::FOURCYLINDER, 4563.6f));
    _data_container.push_back(std::make_shared<Engine>(EngineType::TURBOCHARGED, 34859.0f, "E-8990", CylinderType::FOURCYLINDER, 98756.6f));
}

std::string Operations::EngineNumberOfMaxHorsePower()
{
    if (_data_container.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty !");
    }
    int maxHp = _data_container[0]->engineHorsePower();
    std::string EngineNumber = _data_container[0]->engineNumber();
    for (std::shared_ptr<Engine> e : _data_container)
    {
        if (maxHp < e->engineHorsePower())
        {
            maxHp = e->engineHorsePower();
            EngineNumber = e->engineNumber();
        }
    }

    return EngineNumber;
}

std::optional<std::vector<float>> Operations::TwoFloatValues()
{
    if (_data_container.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty !");
    }
    if (_data_container.size() < 2)
    {
        throw NumberFutureException(std::future_errc::no_state, "Container has less than two values!");
    }
    std::vector<float> result;
    result.push_back(_data_container[0]->engineTorque());
    result.push_back(_data_container[_data_container.size() - 1]->engineTorque());

    if (result.size() < 2)
    {
        return std::nullopt;
    }
    return result;
}

float Operations::AverageEngineTorque()
{
    if (_data_container.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty !");
    }

    float totalTorque{0.0f};
    for (std::shared_ptr<Engine> e : _data_container)
    {
        totalTorque += e->engineTorque();
    }

    return totalTorque / _data_container.size();
}

void Operations::TakeInput()
{
    if (_data_container.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty !");
    }
    std::lock_guard<std::mutex> lg(mt);
    std::cout << "Enter Value for N : ";
    std::cin >> _N;
    flag = true;
}

std::vector<EngineType> Operations::EngineTypeNInstance()
{
    if (_data_container.empty())
    {
        throw EmptyContainerFutureException(std::future_errc::no_state, "Container is Empty !");
    }
    std::vector<EngineType> result;
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]()
            { return flag; });

    if (_N < 0 || _N >= _data_container.size())
    {
        throw NumberFutureException(std::future_errc::no_state, "_N's Value is not valid");
    }

    for (int i = 0; i < _N; i++)
    {
        result.push_back(_data_container[i]->engineType());
    }

    return result;
}
