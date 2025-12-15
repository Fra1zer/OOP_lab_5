#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include <iostream>
#include <vector>

void printCurrencyInfo(const Currency& currency) {
    std::cout << "\nИнформация о валюте:\n";
    std::cout << "Валюта: " << currency.getCurrencyName() << std::endl;
    std::cout << "Курс: " << currency.getExchangeRate() << " RUB" << std::endl;
    currency.output(std::cout);
    std::cout << std::endl;
}

int main() {
    
    Dollar dollar1(100.0);
    Euro euro1(50.0);
    double t1, t2;
    t1 = 0.1;
    t2 = 0.3;
    t1 += 0.1;
    t1 += 0.1;
    std::cout.precision(20);
    std::cout << std::fixed << (t1 == t2) << " " << t1 << " " << t2 << std::endl;
    std::vector<Currency*> currencies;
    currencies.push_back(&dollar1);
    currencies.push_back(&euro1);
    
    for (size_t i = 0; i < currencies.size(); ++i) {
        std::cout << "\nВалюта " << i + 1 << ":\n";
        currencies[i]->display(std::cout);
        std::cout << "\nВывод через output(): ";
        currencies[i]->output(std::cout);
        std::cout << "\nСумма в рублях: " << currencies[i]->toRubles() << " RUB\n";
    }
    std::cout << "----------------" << std::endl;

    printCurrencyInfo(dollar1);
    printCurrencyInfo(euro1);
    
    std::cout << "------------------" << std::endl;
    
    Dollar dollar2;
    Euro euro2;
    
    dollar2 = dollar1;
    
    euro2.input(std::cin);
    
    printCurrencyInfo(dollar2);
    printCurrencyInfo(euro2);
    
    std::cout << "--------------" << std::endl;

    std::cout << "Текущие курсы валют:\n";
    std::cout << "Курс доллара: " << Dollar::getDollarRate() << " RUB/USD\n";
    std::cout << "Курс евро: " << Euro::getEuroRate() << " RUB/EUR\n";
    
    return 0;
}