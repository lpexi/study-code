#include <math

class shape
{
private:

public:
    virtual double ComputeArea() const
    {
        return 0.0;
    }
    virtual ~shape();
};

class circle : public shape
{
    protected:
        double radius;
    public:
        circle(double radius) : radius(radius){}
        double ComputeArea() const override
        {
            3.141 * radius * radius;
            return;
        }
};

class rectangle : public shape
{
    protected:
        double x;
        double y;
    public:
        double ComputeArea() const override
        {
            x * y;
            return;
        }
};