#include "LookbackPutOption.h"
#include "PathIndependentOption.h"
#include "matlib.h"
#include "MonteCarloPricer.h"
#include "PutOption.h"


using namespace std;

//Fixed strike


double LookbackPutOption::payoff(
    const std::vector<double>& stockPrices
) const {

    double priceMin = min(stockPrices);

    if (priceMin < getStrike()) {
        return getStrike() - priceMin;
    }
    else {
        return 0;
    }

}

void testMonteCarloPriceLookbackPut() {

    LookbackPutOption option;
    option.setMaturity(1.0);
    option.setStrike(100.0);
    BlackScholesModel model;
    model.stockPrice = 95;
    model.volatility = 0.1;
    model.riskFreeRate = 0.0;

    MonteCarloPricer pricer;
    pricer.nSteps = 100;
    pricer.nScenarios = 10000;
    double price = pricer.price(option, model);

    PutOption putOption;
    putOption.setMaturity(1.0);
    putOption.setStrike(100.0);
    double europeanPrice = putOption.price(model);

    assert(price > 0);
    assert(price > europeanPrice);

}

void testLookbackPutOption() {
    TEST(testMonteCarloPriceLookbackPut);
}

