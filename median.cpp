#include "median.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Median<int> med(1204);
    
    med.add(1);
    med.add(2);
    med.add(10);
    med.add(5);
    med.add(12);

    std::cout << med.getmedian() << std::endl;

    return 0;
}
