// flatrate-math: benchmark math for flat-rate software subscriptions
// against the fully loaded cost of a senior developer hire.
//
// Copyright (C) 2026 James Verlander
//
// SPDX-License-Identifier: MIT
// This file is licensed under the MIT license; see the LICENSE file in
// this repository for the full text.

#ifndef FLATRATE_MATH_HPP
#define FLATRATE_MATH_HPP

#include <optional>

namespace flatrate {

/// Annual cost of a senior developer hire from the fully loaded monthly
/// figure (salary plus benefits, payroll taxes, bonus, retirement).
double loaded_annual(double monthly_loaded);

/// Yearly savings of a flat monthly subscription vs the loaded hire.
double yearly_savings(double flat_monthly, double loaded_annual_cost);

/// Break-even months where the subscription catches up to the hire.
/// std::nullopt when the monthly price is zero or negative.
std::optional<double> break_even_months(double flat_monthly,
                                        double loaded_annual_cost);

}  // namespace flatrate

#endif  // FLATRATE_MATH_HPP
