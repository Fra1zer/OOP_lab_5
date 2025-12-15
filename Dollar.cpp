#include "Dollar.h"

const double Dollar::EXCHANGE_RATE = 75.5;

Dollar::Dollar(int amt) : Currency(amt) {}

Dollar::Dollar(double decimalAmount) : Currency(dollarsToCents(decimalAmount)) {}

Dollar::Dollar(const Dollar& other) : Currency(other) {}

Dollar::~Dollar() {}

Dollar& Dollar::operator=(const Dollar& other) {
    if (this != &other) {
        Currency::operator=(other);
    }
    return *this;
}

double Dollar::toRubles() const {
    return centsToDollars(getAmount()) * EXCHANGE_RATE;
}

void Dollar::display(std::ostream& os) const {
    os << getDecimalAmount() << " USD = " << toRubles() << " RUB";
}

void Dollar::input(std::istream& is) {
    double dollars;
    is >> dollars;
    setAmount(dollarsToCents(dollars));
}

void Dollar::output(std::ostream& os) const {
    os << getDecimalAmount();
}

std::string Dollar::getCurrencyName() const {
    return "Доллар (USD)";
}

double Dollar::getExchangeRate() const {
    return EXCHANGE_RATE;
}

int Dollar::getSmallestUnit() const {
    return SMALLEST_UNIT;
}

double Dollar::getDecimalAmount() const {
    return centsToDollars(getAmount());
}

double Dollar::getDollarRate() {
    return EXCHANGE_RATE;
}

int Dollar::dollarsToCents(double dollars) {
    return static_cast<int>(dollars * SMALLEST_UNIT + 0.5);
}

double Dollar::centsToDollars(int cents) {
    return static_cast<double>(cents) / SMALLEST_UNIT;
}