// Copyright David Abrahams 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <deel.boost.python/revise/boost/python/module.hpp>
#include <deel.boost.python/revise/boost/python/def.hpp>
#include <deel.boost.python/revise/boost/python/class.hpp>
#include <boost/mpl/list.hpp>

#include <complex>

struct M {M(const std::complex<double>&) {} };

BOOST_PYTHON_MODULE(bienstman5_ext)
{
  using namespace boost::python;

  class_<M>("M", init<std::complex<double> const&>())
      ;
}


