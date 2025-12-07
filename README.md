# MutantStack - Stack with Iterator Support

A C++ template class extending `std::stack` with iterator functionality for element traversal.

> **⭐ 100% C++98 Compliant**
> 
> Template class exposing container iterators

## 📋 Description

**MutantStack** solves a fundamental problem: `std::stack` lacks iterators. By inheriting from `std::stack` and exposing the underlying container's iterators, this class enables iteration while preserving stack semantics.

### Core Features ✅
- **Template class** - Generic programming for any type
- **Iterator support** - Traverse stack elements
- **Stack operations** - push(), pop(), top(), size() inherited
- **STL compatibility** - Works with std::stack interface
- **C++98 standard** - No modern C++ features

## 🚀 Compilation & Usage

```bash
make          # Compile
make clean    # Clean objects
./mutantstack # Run
```

## 🧠 The Problem & Solution

**std::stack has no iterators:**
```cpp
std::stack<int> s;
// ❌ s.begin() doesn't exist!
```

**MutantStack exposes them:**
```cpp
MutantStack<int> ms;
for (auto it = ms.begin(); it != ms.end(); ++it)
    std::cout << *it << std::endl;  // ✅ Works!
```

By exposing the underlying container's iterators via `this->c.begin()` and `this->c.end()`.


## 📚 How It Works

**1. Inheritance from std::stack<T>**
- Inherits all stack operations: `push()`, `pop()`, `top()`, `size()`, `empty()`
- No need to reimplement stack behavior

**2. The Protected Container**
`std::stack<T>` internally uses a protected member `c` (default: `std::deque<T>`). Via inheritance, MutantStack can access it directly through `this->c`.

**3. Iterator Typedef**
The class defines iterator types that expose the underlying deque's iterators:
- `typename` keyword tells compiler this is a type name (context-dependent resolution)
- `std::stack<T>::container_type` gives us access to the underlying container type
- `::iterator` gets that container's iterator type
- Result: iterator type behaves exactly like `std::deque<T>::iterator`

**4. Exposing Iterators via begin()/end()**
Instead of keeping iterators hidden (like std::stack), MutantStack exposes them:
- `begin()` returns `this->c.begin()` - start of deque
- `end()` returns `this->c.end()` - end of deque
- Now you can iterate while maintaining all stack operations

**5. Const Overloads**
Provides const versions of begin()/end() for const MutantStack references, following const-correctness principles.


## 📁 Structure & Usage

**File structure:**
```
MutantStack/
├── includes/MutantStack.hpp  # Template header (all code here)
└── srcs/main.cpp             # Demo program
```

**Demo:**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);

// Stack operations (inherited)
std::cout << mstack.top();   // 17
mstack.pop();
std::cout << mstack.size();  // 1

// Iteration (new feature!)
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
while (it != ite)
{
    std::cout << *it << std::endl;
    ++it;
}

// Compatible with std::stack
std::stack<int> s(mstack);
```


## 📊 Specs & Learning

| Aspect | Details |
|--------|---------|
| **Time Complexity** | push/pop/top: O(1), iteration: O(n) |
| **Default Container** | std::deque<T> (fast push/pop both ends) |
| **Iterator Type** | Random access iterators from deque |
| **Compilation** | `-Wall -Wextra -Werror -std=c++98` |
| **Memory** | Zero overhead (same size as std::stack) |

**What you learn:**
- Template classes and generic programming
- STL container inheritance and adaptation
- Iterator traits and type resolution
- Header-only template libraries
- Accessing protected members via inheritance

## 👤 Author

[@itaharbo91](https://github.com/itaharbo91)

---

**GitHub Description**: C++98 template class extending std::stack with iterator support. Enables element traversal while preserving standard stack operations. Header-only implementation demonstrating advanced template techniques and STL container customization.