//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11
// <chrono>

#include <complex>
#include <type_traits>
#include <cassert>

#include "test_macros.h"

int main(int, char**)
{
    using namespace std::literals::complex_literals;

//  Make sure the types are right
    static_assert ( std::is_same<decltype( 3.0il ), std::complex<long double>>::value, "" );
    static_assert ( std::is_same<decltype( 3il   ), std::complex<long double>>::value, "" );
    static_assert ( std::is_same<decltype( 3.0i  ), std::complex<double>>::value, "" );
    static_assert ( std::is_same<decltype( 3i    ), std::complex<double>>::value, "" );
    static_assert ( std::is_same<decltype( 3.0if ), std::complex<float>>::value, "" );
    static_assert ( std::is_same<decltype( 3if   ), std::complex<float>>::value, "" );

    {
    std::complex<long double> c1 = 3.0il;
    assert ( c1 == std::complex<long double>(0, 3.0));
    auto c2 = 3il;
    assert ( c1 == c2 );
    }

    {
    std::complex<double> c1 = 3.0i;
    assert ( c1 == std::complex<double>(0, 3.0));
    auto c2 = 3i;
    assert ( c1 == c2 );
    }

    {
    std::complex<float> c1 = 3.0if;
    assert ( c1 == std::complex<float>(0, 3.0));
    auto c2 = 3if;
    assert ( c1 == c2 );
    }

  return 0;
}
