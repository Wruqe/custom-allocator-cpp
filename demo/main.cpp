#include <iostream>
#include "BumpAllocator.hpp"

int main()
{
    BumpAllocator arena(32);

    std::cout << "Arena Capacity: " << arena.capacity() << "bytes \n";

    int *a = static_cast<int *>(arena.alloc(sizeof(int)));
    *a = 123;
    std::cout << "a = " << a << " | bytes used so far: " << arena.used() << "\n";

    double *b = static_cast<double *>(arena.alloc(sizeof(double)));
    *b = 12.20;
    std::cout << "b = " << b << " | bytes used so far: " << arena.used() << "\n";

    void *c = arena.alloc(200);

    if (c == nullptr)
    {
        std::cout << "Out of memory \n";
    }

    std::cout << "remaining memory = " << arena.remaining() << " bytes \n";

    arena.debug_print(8);
}