#include "Test.hpp"
using namespace std;

int main() {
   Test galinhos { "assets/imgs/galinhos.ppm" };
   Test flowers { "assets/imgs/flowers.ppm" };

   flowers.testCombine("assets/imgs/combine.ppm", 
      "assets/imgs/bill.ppm", 0, 0);

   cout << "\nEffects:\n";
   galinhos.testEffect("assets/imgs/blur.ppm", Blurring);
   galinhos.testEffect("assets/imgs/sharp-e.ppm", Edge_Sharpening);
   galinhos.testEffect("assets/imgs/embossing.ppm", Embossing);
   galinhos.testEffect("assets/imgs/enlarge.ppm", Enlarge);
   galinhos.testEffect("assets/imgs/gray.ppm", Gray);
   galinhos.testEffect("assets/imgs/invert.ppm", Invert);
   galinhos.testEffect("assets/imgs/negative.ppm", Negative);
   galinhos.testEffect("assets/imgs/reduce.ppm", Reduce);
   galinhos.testEffect("assets/imgs/rotate-l.ppm", Rotate_Left);
   galinhos.testEffect("assets/imgs/rotate.ppm", Rotate_Right);
   galinhos.testEffect("assets/imgs/sharp.ppm", Sharpening);

   cout << "\nBorders:\n";
   galinhos.testBorders("assets/imgs/solid.ppm", Solid);
   galinhos.testBorders("assets/imgs/polaroid.ppm", Polaroid);

   int tests { galinhos.getTests() + flowers.getTests() };
   int success { galinhos.getSuccessTests() + flowers.getSuccessTests() };

   cout << "\nResult: " << success << "/" << tests << " success tests.\n";
}
