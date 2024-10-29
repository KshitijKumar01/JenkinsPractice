#include "Engine.h"

Engine::Engine(EngineType type, float hp, std::string number, CylinderType ctype, float torque)
:_engine_type{type},_engine_horse_power{hp},_engine_number{number},_engine_cylinder{ctype},_engine_torque{torque}
{
}
std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    std::string val1="";
    std::string val2="";

    if(rhs.engineType()==EngineType::REGULAR){
        val1="Regular Engine";
    }
    else{
        val1="Turbocharged Engine";
    }

    if(rhs.engineCylinder()==CylinderType::FOURCYLINDER){
        val2="Four Cylinder";
    }
    else{
        val2="Six Cylinder";
    }
    os << "_engine_type: " << val1
       << " _engine_horse_power: " << rhs._engine_horse_power
       << " _engine_number: " << rhs._engine_number
       << " _engine_cylinder: " << val2
       << " _engine_torque: " << rhs._engine_torque;
    return os;
}
