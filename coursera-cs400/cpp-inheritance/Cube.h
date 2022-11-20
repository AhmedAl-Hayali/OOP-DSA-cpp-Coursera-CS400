/**
 * A `Cube` class inheriting from a `Shape`
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include "Shape.h"
#include "HSLAPixel.h"

namespace uiuc {
  class Cube : public Shape { // `class DerivedClassName : (modifier, usually public) SuperClassName` is the standard syntax for defining an inherited class.
    public:
      Cube(double width, uiuc::HSLAPixel color);
      double getVolume() const;

    private:
      uiuc::HSLAPixel color_;
  };
}
