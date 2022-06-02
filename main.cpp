#include <iostream>
#include "Directory.h"

int main() {
    File f;
    Directory D = Directory("path");
    D.add(f);
    std::cout << D;
    return 0;
}
