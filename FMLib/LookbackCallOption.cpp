#include "LookbackCallOption.h"
#include "PathIndependentOption.h"
#include "matlib.h"
#include "MonteCarloPricer.h"
#include "CallOption.h"


using namespace std;

//Fixed strike


double LookbackCallOption::payoff(
    const std::vector<double>& stockPrices
) const {
   
    double priceMax = max(stockPrices);

    if (priceMax > getStrike()) {
        return priceMax - getStrike();
    }
    else {
        return 0;
    }

}

void testMonteCarloPriceLookbackCall() {

    LookbackCallOption option;
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

    CallOption callOption;
    callOption.setMaturity(1.0);
    callOption.setStrike(100.0);
    double europeanPrice = callOption.price(model);

    assert(price > 0);
    assert(price > europeanPrice);


}

void testLookbackCallOption() {
    TEST(testMonteCarloPriceLookbackCall);
}

