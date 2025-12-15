#include "Currency.h"

Currency::Currency(int amt) : amount(new int(amt)) {}

Currency::Currency(const Currency& other) : amount(new int(*(other.amount))) {}

Currency::~Currency() {
    delete amount;
}

Currency& Currency::operator=(const Currency& other) {
    if (this != &other) {
        *amount = *other.amount;
    }
    return *this;
}

int Currency::getAmount() const {
    return *amount;
}

void Currency::setAmount(int amt) {
    *amount = amt;
}

double Currency::getDecimalAmount() const {
    return static_cast<double>(*amount) / getSmallestUnit();
}

void Currency::input(std::istream& is) {
    double decimalAmount;
    is >> decimalAmount;
    *amount = static_cast<int>(decimalAmount * getSmallestUnit());
}

void Currency::output(std::ostream& os) const {
    os << getDecimalAmount();
}