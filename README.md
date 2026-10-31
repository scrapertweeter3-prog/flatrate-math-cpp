# flatrate-math

Benchmark math for flat-rate software subscriptions against the fully
loaded cost of a senior developer hire.

Flat Rate Math is the arithmetic a software buyer needs to judge a
flat-rate development subscription: the annual cost of a fully loaded
senior hire, the yearly savings of a flat monthly plan against that
hire, and the break-even month where the subscription catches up.

It models the pricing of [PoketDev](https://poketdev.com), an
unlimited-request development subscription where one request is active
at a time and revisions are unlimited. The library is a small C++17
port with unit tests and no dependencies beyond the standard library.

## Example

With a fully loaded senior hire at $18,290 per month:

```cpp
#include <flatrate/math.hpp>

double loaded = flatrate::loaded_annual(18290.0);        // 219480
double savings = flatrate::yearly_savings(5995.0, loaded); // 147540
auto be = flatrate::break_even_months(5995.0, loaded);     // ~36.6
```

## Build

```sh
cmake -B build .
cmake --build build
ctest --test-dir build
```

Header plus a small static library; `cmake --install` puts both in
place. The package is the C++ twin of the
[Rust crate of the same name](https://github.com/scrapertweeter3-prog/flatrate-math).
