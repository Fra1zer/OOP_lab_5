#ifndef EURO_H
#define EURO_H

#include "Currency.h"

class Euro : public Currency {
private:
    static const double EXCHANGE_RATE;
    static const int SMALLEST_UNIT = 100;
    
public:
    Euro(int amt = 0);
    Euro(double decimalAmount);
    Euro(const Euro& other);
    virtual ~Euro();
    
    Euro& operator=(const Euro& other);
    
    double toRubles() const;
    void display(std::ostream& os) const;
    
    void input(std::istream& is);
    void output(std::ostream& os) const;
    
    std::string getCurrencyName() const;
    double getExchangeRate() const;
    int getSmallestUnit() const;
    
    double getDecimalAmount() const;
    
    static double getEuroRate();
    static int eurosToCents(double euros);
    static double centsToEuros(int cents);
};

#endif