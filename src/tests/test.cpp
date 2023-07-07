#include "Test.hpp"
using namespace std;

int main() {
   Test galinhos { "src/assets/imgs/galinhos.ppm" };

   cout << "\nEffects:\n";
   galinhos.testEffect("src/assets/imgs/blur.ppm", Blurring);
   galinhos.testEffect("src/assets/imgs/sharp-e.ppm", Edge_Sharpening);
   galinhos.testEffect("src/assets/imgs/embossing.ppm", Embossing);
   galinhos.testEffect("src/assets/imgs/enlarge.ppm", Enlarge);
   galinhos.testEffect("src/assets/imgs/gray.ppm", Gray);
   galinhos.testEffect("src/assets/imgs/invert.ppm", Invert);
   galinhos.testEffect("src/assets/imgs/negative.ppm", Negative);
   galinhos.testEffect("src/assets/imgs/reduce.ppm", Reduce);
   galinhos.testEffect("src/assets/imgs/rotate-l.ppm", Rotate_Left);
   galinhos.testEffect("src/assets/imgs/rotate.ppm", Rotate_Right);
   galinhos.testEffect("src/assets/imgs/sharp.ppm", Sharpening);

   int tests { galinhos.getTests() };
   int success { galinhos.getSuccessTests() };

   cout << "\nResult: " << success << "/" << tests << " success tests.\n";
}
