//
// Created by Marco Silva on 17/02/2023
//

class Math
{
    public:
    template<typename T> static T Clamp(T A, T min, T max)
    {
        if (A < min) return min;
        if (A > max) return max;
        return A;
    }

};