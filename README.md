# 🚀 Custom C++ Bump Allocator (Arena Allocator)

This project is a **custom memory allocator written in modern C++**, inspired by low-level memory systems used in **game engines, embedded systems, and defense software**. Unlike `malloc` or `new`, which can be slow or unpredictable, this allocator is **fast, deterministic, cache-friendly, and alignment-aware**.

It works by **pre-allocating a fixed block of memory and handing out memory linearly** (also known as a **bump allocator**). Memory can be reset in O(1) time.

---

## ✅ Features

- ⚡ **Fast O(1) allocations**
- 🧠 **Zero malloc after initialization**
- 🔧 **Alignment support** (`alignof(T)`)
- ♻️ **Reusable memory buffer via `reset()`**
- 🔬 **Memory visualization (`debug_print`)**
- ✅ Clean C++ design (RAII destructor safety)

---

## 📦 How It Works

The allocator maintains:

| Member      | Purpose                           |
| ----------- | --------------------------------- |
| `base_`     | Pointer to start of memory buffer |
| `capacity_` | Total bytes available             |
| `offset_`   | Current allocation pointer        |

Allocation is done by **bumping** the offset forward:

```cpp
void* alloc(std::size_t bytes, std::size_t alignment = alignof(std::max_align_t));
```
