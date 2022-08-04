#pragma once

#include "Priceable.h"

class ZeroCouponBond : public Priceable {
public:

	double maturity;

	/* Computes the price of the security in the Black Scholes world */

	virtual double price(const BlackScholesModel& model) const {
		return exp(-model.riskFreeRate * maturity);
	}

};