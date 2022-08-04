#include "AsianOption.h"
#include "PathIndependentOption.h"
#include "matlib.h"
#include "MonteCarloPricer.h"
#include "CallOption.h"


using namespace std;

//arithmetic mean (Call Option)

double AsianOption::payoff(
    const std::vector<double>& stockPrices
) const {
    double m = mean(stockPrices);
    if (m > getStrike()) {
        return m - getStrike();
    }
    else {
        return 0;
    }
}


void testMonteCarloPriceAsian () {
    
    AsianOption option;
    option.setMaturity(1.0);
    option.setStrike(100.0);
    BlackScholesModel model;
    model.stockPrice = 95;
    model.volatility = 0.1;
    model.riskFreeRate = 0.0;

    MonteCarloPricer pricer;
    pricer.nSteps = 100;
    pricer.nScenarios = 3;
    double price = pricer.price(option, model);

    CallOption callOption;
    callOption.setMaturity(1.0);
    callOption.setStrike(100.0);
    double europeanPrice = callOption.price(model);

    assert(price > 0);
    assert(price < 2 * europeanPrice);

}

void testAsianOption() {
    TEST(testMonteCarloPriceAsian);
}