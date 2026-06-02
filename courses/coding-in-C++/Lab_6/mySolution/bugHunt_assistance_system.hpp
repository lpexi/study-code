#ifndef ASSISTANCE_SYSTEM_HPP
#define ASSISTANCE_SYSTEM_HPP

#include <memory>

#include "bugHunt_vehicle.hpp"

class DistanceSensor
{
private:
    std::string position;
    bool active;
    std::double_t measured_distance_m;

public:

    DistanceSensor(const std::string &sensor_position,
                   std::double_t initial_distance_m);

    void set_distance(std::double_t distance_m);
    void activate();
    void deactivate();

    std::double_t get_distance() const;
    bool is_active() const;
    std::string get_position() const;

    bool operator<(const DistanceSensor &other) const;
    bool is_exactly_at_warning_distance(std::double_t warning_distance) const;

    void print_info() const;
};

class EmergencyBrakeSystem
{
private:
    std::double_t critical_distance_m;
    std::shared_ptr<DistanceSensor> front_sensor;


public:
    EmergencyBrakeSystem(std::double_t critical_distance, std::shared_ptr<DistanceSensor> sensor);

    void evaluate(Vehicle &vehicle) const;
};

class LaneKeepingAssist
{
private:
    std::double_t max_allowed_offset_m;
    std::double_t correction_angle;

public:
    LaneKeepingAssist(std::double_t max_offset, std::double_t correction);

    void evaluate(Vehicle &vehicle) const;
};

class AdaptiveCruiseControl
{
private:
    std::double_t target_speed_kmh;
    std::double_t minimum_distance_m;
    std::shared_ptr<DistanceSensor> front_sensor;

public:
    AdaptiveCruiseControl(std::double_t target_speed,
                          std::double_t minimum_distance,
                          std::shared_ptr<DistanceSensor> sensor);

    void evaluate(Vehicle &vehicle) const;
};

class ParkingAssistant
{
private:
    std::vector<std::shared_ptr<DistanceSensor>> sensors;
    std::double_t warning_distance_m;

public:
    ParkingAssistant(std::double_t warning_distance);

    void add_sensor(std::shared_ptr<DistanceSensor> sensor);
    void print_warnings() const;
};

#endif