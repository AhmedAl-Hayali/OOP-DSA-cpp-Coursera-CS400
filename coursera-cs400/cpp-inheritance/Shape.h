/**
 * Generic `Shape` class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

class Shape {
  public:
    Shape();
    Shape(double width);
    double getWidth() const; // `const` keyword at the end means it doesn't change any member variables of the class

  private:
    double width_;
};
