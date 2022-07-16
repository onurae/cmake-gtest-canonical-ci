#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

class Calculator
{
public:
    Calculator() = default;
    virtual ~Calculator() = default;
    int Square(int i) const;
};

#endif // !CALCULATOR_HPP