#include <memory_resource>
#include <list>

class CustomAllocator : public std::pmr::memory_resource {
private:
    struct Block {
        void* address{ nullptr };
        size_t size{ 0 };
        bool is_free{ true };
    };

    std::list<Block> used_blocks;

protected:
    void* do_allocate(size_t bytes, size_t alignment) override;
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

public:
    ~CustomAllocator();
};
