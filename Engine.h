#ifndef ENGINE_H
#define ENGINE_H
#include "EngineType.h"
#include "CylinderType.h"
#include <iostream>
class Engine
{
private:
    /* data */
    EngineType _engine_type;
    float _engine_horse_power;
    std::string _engine_number;
    CylinderType _engine_cylinder;
    float _engine_torque;

public:
    Engine() = default;
    Engine(const Engine &) = delete;
    Engine(Engine &&) = delete;
    Engine &operator=(const Engine &) = delete;
    Engine &operator=(Engine &&) = delete;
    ~Engine() = default;

    Engine(EngineType type, float hp, std::string number, CylinderType ctype, float torque);

    EngineType engineType() const { return _engine_type; }
    void setEngineType(const EngineType &engine_type) { _engine_type = engine_type; }

    float engineHorsePower() const { return _engine_horse_power; }
    void setEngineHorsePower(float engine_horse_power) { _engine_horse_power = engine_horse_power; }

    std::string engineNumber() const { return _engine_number; }

    CylinderType engineCylinder() const { return _engine_cylinder; }
    void setEngineCylinder(const CylinderType &engine_cylinder) { _engine_cylinder = engine_cylinder; }

    float engineTorque() const { return _engine_torque; }
    void setEngineTorque(float engine_torque) { _engine_torque = engine_torque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};


#endif // ENGINE_H
