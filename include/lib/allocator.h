#pragma once

// Custom memory allocator. The implementation is based on 
// Howard Hinnant's short_alloc 

namespace llibcc {

template <size_t N>
class MemPool {
  static constexpr size_t alignment = alignof(std::max_align_t);
public:
  MemPool() noexcept : ptr_(buffer_) {}
  ~MemPool() {ptr_ = nullptr;}
  MemPool(const MemPool&) = delete;
  MemPool& operator=(const MemPool&) = delete;

  std::byte* allocate(size_t n);
  void deallocate(std::byte* p, size_t n) noexcept;
  static constexpr size_t size() noexcept {return N;}
  size_t used() const noexcept {
    return static_cast<size_t>(ptr_ - buffer_);
  }
  void reset() noexcept {ptr_ = buffer_;}

private:
  // rounds up allignment requirement
  static size_t align_up(size_t n) noexcept {
    return (n + (alignment-1)) & ~(alignment-1);
  }
  // check if the pointer asked, actually belongs to allocated space
  // https://devblogs.microsoft.com/oldnewthing/20170927-00/?p=97095
  bool pointer_in_buffer(std::byte* p) noexcept {
    return std::uintptr_t(buffer_) <= std::uintptr_t(p) &&
           std::uintptr_t(p) <= std::uintptr_t(buffer_) + N;
  }

  alignas(alignment) std::byte buffer_[N];
  std::byte* ptr_{};
};

template <size_t N>
std::byte* MemPool<N>::allocate(size_t n) {
  const auto aligned_n = align_up(n);
  if (static_cast<decltype(aligned_n)>(buffer_ + N - ptr_) >= aligned_n) {
    auto* r = ptr_;
    ptr_ += aligned_n;
    return r;
  }
  return static_cast<std::byte*>(::operator new(n));
}

template <size_t N>
void MemPool<N>::deallocate(std::byte* p, size_t n) noexcept {
  if (pointer_in_buffer(p)) {
    n = align_up(n);
    if (p + n == ptr_)
      ptr_ = p;
  } else {
    ::operator delete(p);
  } 
}

template <class T, std::size_t N>
class Allocator {
  static constexpr size_t alignment = alignof(std::max_align_t);
public:
  using elem_type = T;
  static auto constexpr size = N;
  using pool_type = MemPool<size, alignment>;

  Allocator(Allocator& a) noexcept : a_{a} {}
  Allocator(const Allocator&) = default;
  Allocator& operator=(const Allocator&) = delete;

  T* allocate(size_t n) {
    return reinterpret_cast<T*>(a_.template allocate<alignof(T)>(n * sizeof(T)));
  }

  void deallocate(T* p, size_t n) noexcept {
    a_.deallocate(reinterpret_cast<std::byte*>(p), n * sizeof(T));
  }

private:
  pool_type& a_;    
};

}; // namespace llibcc 