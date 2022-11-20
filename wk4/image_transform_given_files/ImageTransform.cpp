#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
(Begin multi-line comment...)

Write your name and email address in the comment space here:

Name:
Email:

(...end multi-line comment.)
******************** */

using uiuc::PNG;
using uiuc::HSLAPixel;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a reference to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly. No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
  
  using std::sqrt;
  using std::abs;

   for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // Distance between pixel's X/Y coordinate and center X/Y argument
      int dist_X = abs((int) x - centerX);
      int dist_Y = abs((int) y - centerY);

      // Euclidean distance between pixel and center coordinates
      double dist = sqrt(dist_X*dist_X + dist_Y*dist_Y);

      // If the distance is greater than or equal to 160 pixels, make it 80% darker
      if (dist >= 160) {
        pixel.l *= 0.2;
        // pixel.l = pixel.l - 0.8*pixel.l = pixel.l - dist*0.005*pixel.l
      }
      // Otherwise, reduce the luminance by .5% (=.005) for every pixel away it is
      else {
        pixel.l -= .005*dist*pixel.l;
      }
      // Ensuring luminance isn't less than 0, turns out it's redundant
      // pixel.l = pixel.l < 0 ? 0 : pixel.l;

    }
   }

  return image;
  
}
 

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
PNG illinify(PNG image) {
  
  // Traverse all pixels of the image
   for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      double hue = std::fmod(pixel.h, 360); // Modulo operator for floats

//      // If the original hue value is closer to 11 (Illini Orange) than 216 (Illini Blue), set it to Illini Orange.
//      if (std::abs(hue - 11) < std::abs(hue - 216)) { pixel.h = 11; }
//      
//      // If the hue value is equally distant from both colours or is closer to Illini Blue, set it to Illini Blue.
//      else { pixel.h = 216; }

      if (hue > 293.5 or hue < 113.5) { pixel.h = 11; }
      else { pixel.h = 216; }

    }
   }


  return image;
}
 

/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs, which is the base image.
* @param secondImage The second of the two PNGs, which acts as the stencil.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {

  using std::min;
  
  // Only allowing iteration over defined overlapping regions of the images, i.e. minimal width and length image
  unsigned int w = min(firstImage.width(), secondImage.width());
  unsigned int h = min(firstImage.height(), secondImage.height());

   for (unsigned x = 0; x < w; x++) {
    for (unsigned y = 0; y < h; y++) {
      // Differentiating pixels in 1st vs 2nd image
      HSLAPixel & firstImgPixel = firstImage.getPixel(x, y);
      HSLAPixel & secondImgPixel = secondImage.getPixel(x, y);

      // Increase luminance of pixel on first image if second image's pixel at same coordinate is max luminance.
      firstImgPixel.l = secondImgPixel.l == 1.0 ? firstImgPixel.l + 0.2 : firstImgPixel.l;

      firstImgPixel.l = firstImgPixel.l > 1.0 ? 1.0 : firstImgPixel.l;

    }
   }

  return firstImage;
}
