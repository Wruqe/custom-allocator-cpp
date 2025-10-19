#pragma once
#include <cstddef>
#include <cstdint>
#include <new>
#include <type_traits>

class BumpAllocator
{
public:
    BumpAllocator(std::size_t capacity_);

    BumpAllocator(const BumpAllocator &) = delete;
    BumpAllocator &operator=(const BumpAllocator &) = delete;
    ~BumpAllocator();

    void *alloc(std::size_t bytes, std::size_t alignment = alignof(std::max_align_t));

    void reset();

    std::size_t remaining();

    std::size_t capacity() const { return capacity_; }
    std::size_t used() const { return offset_; }

    void debug_print(std::size_t bytes_per_row = 16) const;

private:
    uint8_t *base_;
    size_t capacity_;
    size_t offset_;
};