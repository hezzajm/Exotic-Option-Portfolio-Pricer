#pragma once

#include "stdafx.h"
#include "ContinuousTimeOptionBase.h"


class PathIndependentOption :
        public ContinuousTimeOptionBase {
public:
    virtual ~PathIndependentOption() {}
    /*  Returns the payoff at maturity */
    virtual double payoff( double finalStockPrice) const
        = 0;
    /*  Compute the payoff from a price path */
    double payoff(
            const std::vector<double>& stockPrices ) const {
        return payoff(stockPrices.back());
    }
    bool isPathDependent() const {
        return false;
    };
};