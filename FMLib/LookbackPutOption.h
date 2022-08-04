#pragma once

#include "PathIndependentOption.h"


class LookbackPutOption :public ContinuousTimeOptionBase {
public:
	virtual double payoff(const std::vector<double>& stockPrices) const;

	bool isPathDependent() const {
		return true;
	}
};

void testLookbackPutOption();