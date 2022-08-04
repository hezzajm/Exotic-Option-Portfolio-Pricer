#pragma once

#include "stdafx.h"
#include "ContinuousTimeOption.h"
#include "BlackScholesModel.h"

class MonteCarloPricer {
public:
    MonteCarloPricer();
    int nScenarios;
    int nSteps;

    double price( const ContinuousTimeOption& option,
                  const BlackScholesModel& model );

};

void testMonteCarloPricer();

