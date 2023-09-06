#include "Raster.h"
#include <iostream>
#include <fstream>
using namespace std;

Raster::Raster() {
  width = 0;
  height = 0;
  pixels = NULL;
}

Raster::Raster(int pWidth, int pHeight, Color pFillColor) {
  width = pWidth;
  height = pHeight;
  pixels = new Color[width * height];
  for (int i = 0; i < width * height; i++) {
    pixels[i] = pFillColor;
  };
}

Raster::~Raster() { delete[] pixels; }

int Raster::getWidth() { return width; }

int Raster::getHeight() { return height; }

Color Raster::getColorPixel(int x, int y) {
  int target = width * (height - 1 - y) + x;
  return pixels[target];
}

void Raster::setColorPixel(int x, int y, Color pFillColor) {
  int target = width * (height - 1 - y) + x;
  pixels[target] = pFillColor;
}

void Raster::clear(Color pFillColor) {
  for (int i = 0; i < width * height; i++) {
    pixels[i] = pFillColor;
  }
}

void Raster::writeToPPM(){
  ofstream MyFile("FRAME_BUFFER.ppm");

  MyFile << "P3" << endl;
  MyFile << width << " " << height << endl;
  MyFile << 1.0 << endl;
  
  for (int i=0; i<width*height; i+=width) {
    for(int j=i; j<i+width; j++) {
      Color pixel = pixels[j];
      MyFile << pixel.red << " " << pixel.green << " " << pixel.blue << " "; 
    }
    MyFile << endl;
  }
  MyFile.close();
}
