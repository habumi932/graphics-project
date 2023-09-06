// #include "Color.h"
#include "Raster.h"
#include <iostream>
using namespace std;

int main() {

  // Testing Color struct
  // Color c1 = Color(1.0f, 0.25f, 0.25f);
  // Color c2 = Color(0.0f, 0.5f, 1.0f);
  // Color c3 = c1 * 2.0;
  // Color c3 = 2.0 * c1;
  //  Note: Color * float and not float * Color. Why ?
  //  The expression will find if an overload of the operator   //  is defined in the class of the variable on the left.
  //  class
  // cout << c3.red << endl;
  // cout << c3.green << endl;
  // cout << c3.blue << endl;
  
  // Testing Raster class
  Raster img = Raster(5, 3, Red);
  img.setColorPixel(1, 1, Green);
  img.writeToPPM();
}