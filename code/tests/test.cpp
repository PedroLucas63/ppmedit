#include <iostream>
#include "../libs/Test.hpp"
using namespace std;

int main() {
   Test galinhos { "../assets/imgs/galinhos.ppm" };
   Test flowers { "../assets/imgs/flowers.ppm" };

   galinhos.test("../assets/imgs/blur.ppm", Blurring);
   flowers.test("../assets/imgs/bill.ppm", "../assets/imgs/combine.ppm", Combine);
   galinhos.test("../assets/imgs/sharp-e.ppm", Edge_Sharpening);
   galinhos.test("../assets/imgs/embossing.ppm", Embossing);
   galinhos.test("../assets/imgs/enlarge.ppm", Enlarge);
   galinhos.test("../assets/imgs/gray.ppm", Gray);
   galinhos.test("../assets/imgs/invert.ppm", Invert);
   galinhos.test("../assets/imgs/negative.ppm", Negative);
   galinhos.test("../assets/imgs/reduce.ppm", Reduce);
   galinhos.test("../assets/imgs/rotate-l.ppm", Rotate_Left);
   galinhos.test("../assets/imgs/rotate.ppm", Rotate_Right);
   galinhos.test("../assets/imgs/sharp.ppm", Sharpening);
   galinhos.test("../assets/imgs/solid.ppm", Border_Solid);
   galinhos.test("../assets/imgs/polaroid.ppm", Border_Polaroid);
}
