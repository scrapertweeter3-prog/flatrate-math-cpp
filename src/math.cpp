// flatrate-math: benchmark math for flat-rate software subscriptions
// against the fully loaded cost of a senior developer hire.
//
// Copyright (C) 2026 James Verlander
//
// SPDX-License-Identifier: MIT
// This file is licensed under the MIT license; see the LICENSE file in
// this repository for the full text.

#include "flatrate/math.hpp"

namespace flatrate {

double loaded_annual(double monthly_loaded) {
    return monthly_loaded * 12.0;
}

double yearly_savings(double flat_monthly, double loaded_annual_cost) {
    return loaded_annual_cost - flat_monthly * 12.0;
}

std::optional<double> break_even_months(double flat_monthly,
                                        double loaded_annual_cost) {
    if (flat_monthly <= 0.0) {
        return std::nullopt;
    }
    return loaded_annual_cost / flat_monthly;
}

}  // namespace flatrate
