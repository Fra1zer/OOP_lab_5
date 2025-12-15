#include "Euro.h"

const double Euro::EXCHANGE_RATE = 85.3;

Euro::Euro(int amt) : Currency(amt) {}

Euro::Euro(double decimalAmount) : Currency(eurosToCents(decimalAmount)) {}

Euro::Euro(const Euro& other) : Currency(other) {}

Euro::~Euro() {}

Euro& Euro::operator=(const Euro& other) {
    if (this != &other) {
        Currency::operator=(other);
    }
    return *this;
}   

double Euro::toRubles() const {
    return centsToEuros(getAmount()) * EXCHANGE_RATE;
}

void Euro::display(std::ostream& os) const {
    os << getDecimalAmount() << " EUR = " << toRubles() << " RUB";
}

void Euro::input(std::istream& is) {
    double euros;
    is >> euros;
    setAmount(eurosToCents(euros));
}

void Euro::output(std::ostream& os) const {
    os << getDecimalAmount();
}

std::string Euro::getCurrencyName() const {
    return "Евро (EUR)";
}

double Euro::getExchangeRate() const {
    return EXCHANGE_RATE;
}

int Euro::getSmallestUnit() const {
    return SMALLEST_UNIT;
}

double Euro::getDecimalAmount() const {
    return centsToEuros(getAmount());
}

double Euro::getEuroRate() {
    return EXCHANGE_RATE;
}

int Euro::eurosToCents(double euros) {
    return static_cast<int>(euros * SMALLEST_UNIT + 0.5);
}

double Euro::centsToEuros(int cents) {
    return static_cast<double>(cents) / SMALLEST_UNIT;
}