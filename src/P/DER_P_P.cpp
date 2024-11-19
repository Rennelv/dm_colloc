#include "P/DER_P_P.hpp"

#include <N/LongNatural.hpp>
#include <N/SUB_NN_N.hpp>
#include <Q/LongRational.hpp>
#include <Q/MUL_QQ_Q.hpp>
#include <Z/LongInteger.hpp>
#include <Z/TRANS_N_Z.hpp>

Polynomial DER_P_P(const Polynomial& a) {
    return a.derivative();
}
