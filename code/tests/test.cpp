#include <iostream>
#include "../libs/Test.hpp"
using namespace std;

int main() {
   Test galinhos { "./imgs/galinhos.ppm" };
   Test flowers { "./imgs/flowers.ppm" };

   galinhos.test("./imgs/blur.ppm", Blurring);
   flowers.test("./imgs/bill.ppm", "./imgs/combine.ppm", Combine);
   galinhos.test("./imgs/sharp-e.ppm", Edge_Sharpening);
   galinhos.test("./imgs/embossing.ppm", Embossing);
   galinhos.test("./imgs/enlarge.ppm", Enlarge);
   galinhos.test("./imgs/gray.ppm", Gray);
   galinhos.test("./imgs/invert.ppm", Invert);
   galinhos.test("./imgs/negative.ppm", Negative);
   galinhos.test("./imgs/reduce.ppm", Reduce);
   galinhos.test("./imgs/rotate-l.ppm", Rotate_Left);
   galinhos.test("./imgs/rotate.ppm", Rotate_Right);
   galinhos.test("./imgs/sharp.ppm", Sharpening);
   galinhos.test("./imgs/border-solid.ppm", Border_Solid);
   galinhos.test("./imgs/border-polaroid.ppm", Border_Polaroid);
}
