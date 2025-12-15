#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <iostream>

class Currency {
protected:
    int* amount;

public:
    Currency(int amt = 0);
    Currency(const Currency& other);
    virtual ~Currency();
    
    Currency& operator=(const Currency& other);
    
    virtual double toRubles() const = 0;
    virtual void display(std::ostream& os) const = 0;
    
    virtual void input(std::istream& is);
    virtual void output(std::ostream& os) const;
    
    int getAmount() const;
    void setAmount(int amt);
    double getDecimalAmount() const;
    
    virtual std::string getCurrencyName() const = 0;
    virtual double getExchangeRate() const = 0;
    virtual int getSmallestUnit() const = 0;
};

#endif