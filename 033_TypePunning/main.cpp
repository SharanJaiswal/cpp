#include <iostream>

int main()
{
    #include "../fileio.h"

    int a = 5;
    double val = a; // this will convert the value '5' into '5.00000000...' at the different memory location named val
    std::cout << val << std::endl;
    // We want to use the same memory byte of 'a' to be treated as double. Both of the below code lines will have extremly high potential to crash
    double pung = *(double *)&a;    // This will take int memoery of 4 bytes referenced by 'a'; makes new double variable 'pung'
                                    // 'pung' will point to 8 bytes of memory which includes 4 bytes of same int memory
                                    // This will crash because, we are reading memory which is not completely ours,
                                    // Secondly, if we'll assign any other value to 'pung', we could potentially be writing to the memory that is not ours
    double& pun = *(double *)&a;    // Here, new double variable is not created, instead we are referencing the same int memory as double w/o adding 4 more byte to treat it as double
                                    // If we decide to write anything to pun, this will crash because writing will require 8 bytes, but originally we have 4 bytes

    
    std::cout << pung << std::endl;
    return 0;
}