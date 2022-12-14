#include "matlib.h"
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "UpAndOutOption.h"
#include "DownAndOutOption.h"
#include "Portfolio.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "AsianOption.h"
#include "LookbackCallOption.h"
#include "LookbackPutOption.h"


using namespace std;

int main() {


    testMatlib();
    testCallOption();
    testPutOption();
    testBlackScholesModel();
    testMonteCarloPricer();
    testUpAndOutOption();
    testDownAndOutOption();
    testContinuousTimeOptionBase();
    testPortfolio();
	testDigitalCallOption();
	testDigitalPutOption();
    testAsianOption();
    testLookbackCallOption();
    testLookbackPutOption();

    return 0;
}