#include "Test.hpp"

int main() {
   Test galinhos { "src/assets/imgs/galinhos.ppm" };
   Test flowers { "src/assets/imgs/flowers.ppm" };

   galinhos.test("src/assets/imgs/blur.ppm", Blurring);
   flowers.test(
      "src/assets/imgs/bill.ppm", 
      "src/assets/imgs/combine.ppm", 
      Combine
   );
   galinhos.test("src/assets/imgs/sharp-e.ppm", Edge_Sharpening);
   galinhos.test("src/assets/imgs/embossing.ppm", Embossing);
   galinhos.test("src/assets/imgs/enlarge.ppm", Enlarge);
   galinhos.test("src/assets/imgs/gray.ppm", Gray);
   galinhos.test("src/assets/imgs/invert.ppm", Invert);
   galinhos.test("src/assets/imgs/negative.ppm", Negative);
   galinhos.test("src/assets/imgs/reduce.ppm", Reduce);
   galinhos.test("src/assets/imgs/rotate-l.ppm", Rotate_Left);
   galinhos.test("src/assets/imgs/rotate.ppm", Rotate_Right);
   galinhos.test("src/assets/imgs/sharp.ppm", Sharpening);
   galinhos.test("src/assets/imgs/solid.ppm", Border_Solid);
   galinhos.test("src/assets/imgs/polaroid.ppm", Border_Polaroid);
}
