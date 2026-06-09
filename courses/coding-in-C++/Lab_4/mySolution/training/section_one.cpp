#include <iostream>
#include <cmath>
#include <vector>

class vector2D
{
private:
    std::int_fast16_t XValue = 0;
    std::int_fast16_t YValue = 0;
public:
    vector2D(auto X, auto Y) : XValue(X), YValue(Y){}

    auto getXValue() const 
    {
        return XValue;
    }
    auto getYValue() const
    {
        return YValue;
    }
    
    auto vecAdd(const vector2D &vec) const;
    auto vecSub() const;
    auto vecScale() const;
    auto vecCompare() const;
};

auto vector2D::vecAdd(const vector2D &vec1, const vector2D &vec2) const
{
    auto tmpX = 0;
    auto tmpY = 0;

    tmpX = vec1.getXValue() + vec2.getXValue();
    tmpY = vec1.getYValue() + vec2.getYValue();
    
    return vector2D(tmpX, tmpY);
}


int main()
{

}

