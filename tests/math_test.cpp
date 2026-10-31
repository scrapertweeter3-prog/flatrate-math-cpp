// flatrate-math tests
//
// Copyright (C) 2026 James Verlander
// SPDX-License-Identifier: MIT

#include "flatrate/math.hpp"

#include <cassert>
#include <cmath>

int main() {
    using flatrate::loaded_annual;
    using flatrate::yearly_savings;
    using flatrate::break_even_months;

    // Flat fee $5,995/mo against a senior engineer at $18,290/mo fully
    // loaded (benefits, payroll tax, bonus, retirement).
    const double loaded = loaded_annual(18290.0);
    assert(loaded > 200000.0);

    const double savings = yearly_savings(5995.0, loaded);
    assert(savings > 100000.0);

    const auto be = break_even_months(5995.0, loaded);
    assert(be.has_value());
    assert(*be > 30.0);

    // Zero or negative monthly price has no break-even point.
    assert(!break_even_months(0.0, loaded).has_value());
    assert(!break_even_months(-5.0, loaded).has_value());

    // Rounding tolerance on the savings figure.
    assert(std::fabs(yearly_savings(6000.0, 240000.0) - 168000.0) < 1e-9);

    return 0;
}
