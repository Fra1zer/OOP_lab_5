#ifndef DOLLAR_H
#define DOLLAR_H

#include "Currency.h"

class Dollar : public Currency {
private:
    static const double EXCHANGE_RATE;
    static const int SMALLEST_UNIT = 100;
    
public:
    Dollar(int amt = 0);
    Dollar(double decimalAmount);
    Dollar(const Dollar& other);
    virtual ~Dollar();
    
    Dollar& operator=(const Dollar& other);
    
    double toRubles() const;
    void display(std::ostream& os) const;
    
    void input(std::istream& is);
    void output(std::ostream& os) const;
    
    std::string getCurrencyName() const;
    double getExchangeRate() const;
    int getSmallestUnit() const;
    
    double getDecimalAmount() const;
    
    static double getDollarRate();
    static int dollarsToCents(double dollars);
    static double centsToDollars(int cents);
};

#endif