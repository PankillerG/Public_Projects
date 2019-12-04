#include <cstddef>
#include <utility>
#include <memory>

template <typename T, typename Deleter = std::default_delete<T>>
class UniquePtr {
 private:
std::tuple<T*, Deleter> ptr;

 public:
    UniquePtr() {
        std::get<0>(ptr) = nullptr;
    }
    UniquePtr(T* new_ptr) {
        std::get<0>(ptr) = new_ptr;
    }
    UniquePtr(T* new_ptr, Deleter num) {
        std::get<0>(ptr) = new_ptr;
        std::get<1>(ptr) = num;
    }
    UniquePtr(const UniquePtr&) = delete;
        UniquePtr(UniquePtr&& other) : ptr(other.ptr) {
        std::get<0>(other.ptr) = nullptr;
    }
    UniquePtr& operator= (std::nullptr_t other) noexcept {
        std::get<1>(ptr)(std::get<0>(ptr));
        std::get<0>(ptr) = nullptr;
        return *this;
    }
    UniquePtr& operator= (UniquePtr&& other) noexcept {
        std::get<1>(ptr)(std::get<0>(ptr));
        ptr = other.ptr;
        std::get<0>(other.ptr) = nullptr;
        return *this;
    }
    UniquePtr& operator=(const UniquePtr&) = delete;
    ~UniquePtr() noexcept {
    if (std::get<0>(ptr) != nullptr) {
            std::get<1>(ptr)(std::get<0>(ptr));
        }
    }
    T& operator*() const noexcept {
        return *(std::get<0>(ptr));
    }
    T* operator->() const noexcept {
        return std::get<0>(ptr);
    }
    T * release() noexcept {
        T* ptr1 = std::get<0>(ptr);
        std::get<0>(ptr) = nullptr;
        return ptr1;
    }
    void reset(T * new_ptr = nullptr) noexcept {
        std::get<1>(ptr)(std::get<0>(ptr));
        std::get<0>(ptr) = new_ptr;
        new_ptr = nullptr;
    }
    void swap(UniquePtr& other) noexcept {
        std::swap(ptr, other.ptr);
    }
    T * get() const noexcept {
        return std::get<0>(ptr);
    }
    explicit operator bool() const noexcept {
        if (std::get<0>(ptr) != nullptr) {
            return true;
        }
        return false;
    }
    const Deleter& get_deleter() const {
        return std::get<1>(ptr);
    }
    Deleter& get_deleter() {
        return std::get<1>(ptr);
    }
};
