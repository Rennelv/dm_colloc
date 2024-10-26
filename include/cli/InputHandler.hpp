#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "N/LongNatural.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

class InputHandler {
   public:
    LongNatural scanLongNatural();
    LongInteger scanLongInteger();
    Polynomial scanPolynomial();
    LongRational scanLongRational();
};

#endif  // INPUT_HANDLER_HPP