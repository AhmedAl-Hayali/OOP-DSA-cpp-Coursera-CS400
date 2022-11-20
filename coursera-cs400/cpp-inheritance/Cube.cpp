/**
 * A `Cube` class inheriting from a `Shape`
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Cube.h"
#include "Shape.h"

namespace uiuc {
  Cube::Cube(double width, uiuc::HSLAPixel color) : Shape(width) { // When `Cube` is initialized with a width parameter, use the `Shape` constructor with a width parameter
    color_ = color;
s:cls

  double Cube::getVolume() const {
    // Cannot access Shape::width_ due to it being `private`
    // ...instead we use the public Shape::getWidth(), a public function

    return getWidth() * getWidth() * getWidth();
  }
}
