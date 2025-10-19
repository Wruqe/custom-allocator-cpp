#include "BumpAllocator.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>

BumpAllocator::BumpAllocator(std::size_t capacity)
    : base_(nullptr), capacity_(capacity), offset_(0) // init
{
    base_ = static_cast<u_int8_t *>(std::malloc(capacity));
}

void *BumpAllocator::alloc(std::size_t bytes, std::size_t alignment)
{

    std::size_t alignedOffset = (offset_ + (alignment - 1)) & ~(alignment - 1);

    if (!base_ || alignedOffset + bytes > capacity_)
    {
        return nullptr;
    }

    void *ptr = base_ + alignedOffset;

    offset_ = alignedOffset + bytes;

    return ptr;
}

void BumpAllocator::reset()
{
    offset_ = 0;
}

BumpAllocator::~BumpAllocator()
{
    std::free(base_);
    base_ = nullptr;
    capacity_ = 0;
    offset_ = 0;
}

std::size_t BumpAllocator::remaining()
{

    return capacity_ - offset_;
}

void BumpAllocator::debug_print(std::size_t bytes_per_row) const
{
    std::cout << "\nArena Memory Layout (" << capacity_ << " bytes):";

    for (std::size_t i = 0; i < capacity_; ++i)
    {

        // Print address at start of each row
        if (i % bytes_per_row == 0)
        {
            std::cout << "\n0x" << std::hex
                      << reinterpret_cast<std::size_t>(base_ + i)
                      << "  ";
        }

        // Print used or free marker
        std::cout << (i < offset_ ? "# " : ". ");
    }

    std::cout << "\n\n";
}