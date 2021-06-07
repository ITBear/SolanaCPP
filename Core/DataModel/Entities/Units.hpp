#pragma once

#include "Enentities_global.hpp"

namespace Sol::Core {

class UnoSemuxUnitType_lamport;
using lamport_t = GpUnit<u_int_64, UnoSemuxUnitType_lamport, std::ratio<uintmax_t(1), uintmax_t(1)>, decltype("lamport"_template_str)>;

constexpr lamport_t operator""_lamport  (unsigned long long int aValue) {return lamport_t::SMake(aValue);}
constexpr lamport_t operator""_sol      (unsigned long long int aValue) {return lamport_t::SMake(aValue*1000000000);}

}//namespace Sol::Core
