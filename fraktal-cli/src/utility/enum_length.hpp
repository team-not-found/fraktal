#pragma once

#include "fractal_type.hpp"

template <typename T> int enumLength() { return 0; }

template <> int enumLength<FractalType>() { return FractalType::NumberOfTypes; }
