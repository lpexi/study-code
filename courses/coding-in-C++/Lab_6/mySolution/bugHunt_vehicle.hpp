#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

class Vehicle
{
private:
    std::string model;
    std::double_t speed_kmh;
    std::double_t steering_angle;
    std::double_t lane_offset_m;
    bool brake_light_on;

public:
    Vehicle(const std::string &vehicle_model);

    void accelerate(std::double_t amount_kmh);
    void brake(std::double_t amount_kmh);
    void steer(std::double_t angle);
    void update_lane_offset(std::double_t offset);

    std::double_t get_speed() const;
    std::double_t get_steering_angle() const;
    std::double_t get_lane_offset() const;

    std::string &get_model();

    bool is_brake_light_on() const;

    void print_status() const;
};

#endif