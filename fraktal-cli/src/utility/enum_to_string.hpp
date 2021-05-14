#pragma once

#include <string>

#include "fractal_type.hpp"

template <typename T> std::string enumToString(T value) { return ""; }

template <> std::string enumToString<FractalType>(FractalType value) {
    switch (value) {
    case FractalType::FernFractal:
        return "Fern";
    case FractalType::MandelbrotFractal:
        return "Mandelbrot";
    default:
        return "";
    }
}