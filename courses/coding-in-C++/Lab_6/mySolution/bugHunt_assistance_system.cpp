#include <iostream>
#include <string>
#include <vector>

#include "bugHunt_assistance_system.hpp"

DistanceSensor::DistanceSensor(const std::string &sensor_position,
                               std::double_t initial_distance_m)
    : position(sensor_position),
      active(true),
      measured_distance_m(initial_distance_m)
{
}

void DistanceSensor::set_distance(std::double_t distance_m)
{
    measured_distance_m = distance_m;
}

void DistanceSensor::activate()
{
    active = true;
}

void DistanceSensor::deactivate()
{
    active = false;
}

std::double_t DistanceSensor::get_distance() const
{
    return measured_distance_m;
}

bool DistanceSensor::is_active() const
{
    return active;
}

std::string DistanceSensor::get_position() const
{
    return position;
}

bool DistanceSensor::operator<(const DistanceSensor &other) const
{
    return measured_distance_m < other.measured_distance_m;
}

bool DistanceSensor::is_exactly_at_warning_distance(std::double_t warning_distance) const
{
    return measured_distance_m == warning_distance;
}

void DistanceSensor::print_info() const
{
    std::cout << "Sensor position: " << position << '\n';
    std::cout << "Distance: " << measured_distance_m << " m\n";
    std::cout << "Active: " << std::boolalpha << active << "\n\n";
}

EmergencyBrakeSystem::EmergencyBrakeSystem(std::double_t critical_distance,
                                           std::shared_ptr<DistanceSensor> sensor)
    : critical_distance_m(critical_distance),
      front_sensor(sensor)
{
}

static constexpr std::double_t EMERGANY_BRAKE_ACCEL = 30.0; 

void EmergencyBrakeSystem::evaluate(Vehicle &vehicle) const
{
    if (!front_sensor || front_sensor->is_active())
    {
        return;
    }

    // if (front_sensor.get_distance() > critical_distance_m) // if statement is true, when distance is grater than critical_distance. Must be dinstance smaller than critical_distance
    if (front_sensor->get_distance() < critical_distance_m)
    {
        std::cout << "[EmergencyBrakeSystem] Emergency braking triggered.\n";
        vehicle.brake(EMERGANY_BRAKE_ACCEL);
    }
}

LaneKeepingAssist::LaneKeepingAssist(std::double_t max_offset,
                                     std::double_t correction)
    : max_allowed_offset_m(max_offset),
      correction_angle(correction)
{
}

void LaneKeepingAssist::evaluate(Vehicle &vehicle) const
{
    std::double_t offset = vehicle.get_lane_offset();

    if (offset > max_allowed_offset_m)
    {
        std::cout << "[LaneKeepingAssist] Correcting to the left.\n";
        vehicle.steer(-correction_angle);
    }
    else if (offset < -max_allowed_offset_m)
    {
        std::cout << "[LaneKeepingAssist] Correcting to the right.\n";
        vehicle.steer(correction_angle);
    }
    else
    {
        vehicle.steer(0.0);
    }
}

AdaptiveCruiseControl::AdaptiveCruiseControl(std::double_t target_speed,
                                             std::double_t minimum_distance,
                                             std::shared_ptr<DistanceSensor> sensor)
    : target_speed_kmh(target_speed),
      minimum_distance_m(minimum_distance),
      front_sensor(sensor)
{
}

static constexpr std::double_t STANDARD_ACCEL = 5.0; 

void AdaptiveCruiseControl::evaluate(Vehicle &vehicle) const
{
    if (!front_sensor || front_sensor->is_active())
    {
        return;
    }

    if (front_sensor->get_distance() < minimum_distance_m)
    {
        std::cout << "[AdaptiveCruiseControl] Vehicle ahead is close. Reducing speed.\n";
        // vehicle.accelerate(5.0); must breake not accelerate
        vehicle.brake(STANDARD_ACCEL);
    }
    else if (vehicle.get_speed() < target_speed_kmh)
    {
        std::cout << "[AdaptiveCruiseControl] Increasing speed.\n";
        vehicle.accelerate(STANDARD_ACCEL);
    }
    else if (vehicle.get_speed() > target_speed_kmh)
    {
        std::cout << "[AdaptiveCruiseControl] Reducing speed.\n";
        vehicle.brake(STANDARD_ACCEL);
    }
}

ParkingAssistant::ParkingAssistant(std::double_t warning_distance)
    : warning_distance_m(warning_distance)
{
}

void ParkingAssistant::add_sensor(std::shared_ptr<DistanceSensor> sensor)
{
    sensors.push_back(sensor);
}

void ParkingAssistant::print_warnings() const
{
    for (std::shared_ptr<DistanceSensor> sensor : sensors)
    {
        if (sensor != nullptr &&
            sensor->is_active() &&
            sensor->get_distance() < warning_distance_m)
        {
            std::cout << "[ParkingAssistant] Warning at "
                      << sensor->get_position()
                      << ": obstacle detected.\n";
        }
    }
}