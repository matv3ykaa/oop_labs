#include "allocator.h"
#include <new>

void* CustomAllocator::do_allocate(size_t bytes, size_t alignment) {
    for (auto& block : used_blocks) {
        if (block.is_free && block.size >= bytes) {
            block.is_free = false;
            return block.address;
        }
    }

    void* ptr = ::operator new(bytes);
    used_blocks.emplace_back(Block{ ptr, bytes, false });
    return ptr;
}

void CustomAllocator::do_deallocate(void* ptr, size_t bytes, size_t alignment) {
    for (auto it = used_blocks.begin(); it != used_blocks.end(); ++it) {
        if (it->address == ptr) {
            it->is_free = true;
            return;
        }
    }
}

bool CustomAllocator::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}

CustomAllocator::~CustomAllocator() {
    for (auto& block : used_blocks) {
        if (!block.is_free) {
            ::operator delete(block.address);
        }
    }
}
