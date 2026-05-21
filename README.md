# CPP — 42 C++ Modules (CPP00–CPP09)

A complete walkthrough of the 42 school C++ curriculum, covering the language from first principles to advanced standard-library usage.
No AI was used at any point for writing code or researching concepts. This README was redacted by AI (Claude) based on handwritten notes taken during learning, available on Notion: https://www.notion.so/C-Notes-25a27294b6fd802d9d42ffd08628f75e?source=copy_link

---

## Resources

- **C++ Primer (5th ed., free online):** https://cpp-primer.pages.dev/book/000-cpp_primer_fifth_edition.html — the primary reference throughout the entire curriculum
- **cppreference:** https://en.cppreference.com/ — used for standard-library specifics, type traits, and container APIs
- **CPP09/ex02 merge-insertion sort reference:** https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
- **Copy-and-swap idiom (SO):** https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom/3279616#3279616
- **Forward declarations explained (SO):** https://stackoverflow.com/questions/4757565/what-are-forward-declarations-in-c

---

## CPP00 — Namespaces, Classes, and Static Members

**Core notion:** The very basics of C++ as a departure from C — how to organise code into classes, manage access, and reason about class-level state.

**What was implemented**
- `megaphone` — trivial string-to-uppercase program using `std::string`.
- `PhoneBook` / `Contact` — a fixed-size phonebook (max 8 contacts) with formatted console output. Demonstrates class design, private members, constructors, and getters.
- `Account` — recreation of a banking account log file byte-for-byte. Heavy use of static member variables (`_nbAccounts`, `_totalAmount`, `_totalNbDeposits`, `_totalNbWithdrawals`) and static methods to track class-wide state.

**Key practices**
- Separating declaration (`.hpp`) from definition (`.cpp`).
- Orthodox Canonical Form introduced: default constructor, copy constructor, copy-assignment operator, destructor — even when not strictly needed, to build the habit.
- Static members initialised in the `.cpp` file, not the header.

**Notes & theory — Constructors**

*Default arguments:* A function can declare default parameter values, allowing it to be called with or without those arguments:
```cpp
string screen(int height = 24, int width = 80, char background = ' ');
window = screen();       // uses all defaults
window = screen(66);     // equivalent to screen(66, 80, ' ')
```

*Explicit constructors:* The `explicit` keyword prevents a single-argument constructor from being used for implicit conversions. It can only appear in the class declaration and only applies to single-argument constructors (multi-argument constructors can't do implicit conversions anyway):
```cpp
class Foo {
    explicit Foo(int n); // prevents implicit Foo f = 5;
};
```
Without `explicit`, the compiler is allowed to silently convert a bare integer into a `Foo` wherever one is expected — a source of subtle bugs.

**Tricks**
- `std::setw` / `std::setfill` / `std::right` for the right-aligned, pipe-delimited phonebook display without `printf`.
- Timestamps generated with `std::time` and formatted with `std::strftime` for the Account log, matching the reference output exactly.

---

## CPP01 — Memory, Pointers, and References

**Core notion:** Understanding the difference between stack and heap allocation, when to use pointers vs. references, and how to use file I/O and function pointers.

**What was implemented**
- `Zombie` — demonstrates stack-allocated vs. heap-allocated objects (`newZombie` returns a heap zombie; `zombieHorde` allocates an array with a single `new[]`).
- `HumanA` / `HumanB` with `Weapon` — `HumanA` holds its weapon by *reference* (weapon is mandatory and always present); `HumanB` holds it by *pointer* (weapon is optional and may change).
- `akSed` — replaces all occurrences of a substring in a file and writes the result to a new file, without using `std::string::replace`.
- `Harl` — dispatches to one of four complaint-level methods (`debug`, `info`, `warning`, `error`) using an array of **member-function pointers**, eliminating a chain of `if/else`.

**Notes & theory — Function pointers**

A pointer to a function points to a type — the type being determined by the function's return value and its parameter list. Declaring one requires parentheses around the pointer name; without them, the declaration reads as a function returning a pointer:
```cpp
bool (*pf)(const string &, const string &);  // pointer to function
bool  *pf (const string &, const string &);  // function returning bool*
```

Calling through a function pointer does not require explicit dereferencing — all three forms below are equivalent:
```cpp
bool b1 = pf("hello", "goodbye");
bool b2 = (*pf)("hello", "goodbye");
bool b3 = lengthCompare("hello", "goodbye");
```

For overloaded functions, the compiler selects which overload the pointer refers to based on the declared pointer type:
```cpp
void ff(int*);
void ff(unsigned int);
void (*pf1)(unsigned int) = ff;  // pf1 points to ff(unsigned)
```

When a function is passed as a parameter it is automatically converted to a pointer, so the explicit `*` in the parameter declaration is optional:
```cpp
void useBigger(const string &s1, const string &s2,
               bool pf(const string &, const string &));          // implicit pointer
void useBigger(const string &s1, const string &s2,
               bool (*pf)(const string &, const string &));       // explicit pointer
useBigger(s1, s2, lengthCompare); // function name decays to pointer automatically
```

**Key practices**
- Every `new` is paired with a `delete`; every `new[]` with a `delete[]`.
- References bind at construction and cannot be reseated — used to model "always has a weapon".
- Pointers can be null and reassigned — used to model "may or may not carry a weapon".
- Member-function pointer typedef: `typedef void (Harl::*funcPtr)() const;` — storing method addresses in an array and dispatching via index.

**Tricks**
- `zombieHorde` allocates `N` zombies in a single `new Zombie[N]` call; the destructor is therefore called `N` times automatically on `delete[]`.
- File replacement is done by reading the whole file into a `std::string`, then looping with `std::string::find` + `erase` + `insert` to avoid the forbidden `replace`.

---

## CPP02 — Operator Overloading and Fixed-Point Arithmetic

**Core notion:** How operator overloading works, what the Orthodox Canonical Form truly demands, and how to represent fractional numbers without floating-point.

**What was implemented**
- `Fixed` — a fixed-point number class using a 32-bit integer with 8 fractional bits.
  - Conversion constructors from `int` and `float`.
  - Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`.
  - Arithmetic operators: `+`, `-`, `*`, `/`.
  - Pre- and post-increment/decrement (`++a`, `a++`, `--a`, `a--`).
  - Static `min()` and `max()` in both const and non-const variants.
  - `operator<<` for stream output.
- `Point` — a 2D point built from `Fixed` values, used in a Binary Space Partitioning function `bsp()` that determines whether a point lies strictly inside a triangle.

**Notes & theory — Copy control**

*Copy constructor:* Takes a `const` reference to the class type (passing by value would cause infinite recursion). The compiler synthesises one even when other constructors are defined, but the synthesised version does a shallow memberwise copy — insufficient when the class owns heap resources. The compiler may also elide (bypass) the copy constructor in cases like `string book = "..."` rewriting it internally as `string book("...")`.

*Copy assignment operator:* An overloaded `operator=` that should return `*this` by reference to support chaining (`a = b = c`). The synthesised version is also memberwise and has the same shallow-copy problem.

*Copy initialisation vs. direct initialisation:*
```cpp
string s(dots);      // direct: simple constructor call
string s2 = dots;    // copy: compiler copies right-hand operand, converting if needed
```
Copy initialisation also occurs when passing by value, returning by value, and in brace-initialisation.

*Destructor:* Cannot be overloaded; takes no arguments. The function body executes first, then members are destroyed in reverse construction order. The destruction of members is implicit — there is no "destructor initialiser list". Built-in types (including raw pointers) have no destructor, so a raw pointer member is not freed unless the destructor explicitly calls `delete`.

*Rule of Three:* If a class needs a destructor (e.g. it owns heap memory), it almost certainly also needs a copy constructor and copy-assignment operator:
```cpp
// Without them, two objects end up holding the same pointer after a copy —
// double-free on destruction.
hasPtr function(HasPtr other) {
    hasPtr result = other; // copies pointer, not the data
    return result;         // both result and other call delete on the same address
}
```

Conversely, some classes need copy/assignment but no destructor (e.g. a class that assigns serial numbers — it needs a custom copy to generate a new serial, but owns no heap memory).

*C++11 `= default` / `= delete`:* `= default` asks the compiler to generate the synthesised version and removes its inline property. `= delete` declares a function but prevents its use anywhere; it can be applied to any function, not just special members, to guide overload resolution. A deleted destructor is a particularly dangerous mistake — the compiler will refuse to create objects of that type.

*`private` copy control (pre-C++11):* Before `= delete`, the standard way to prevent copying was to declare the copy constructor and assignment operator `private` without defining them. Users get a compile-time error; friends and members of the class get a link-time error (undefined reference).

*Value-like vs. pointer-like classes:* A value-like class (e.g. `std::string`) gives each object independent state — copying makes a full deep copy and the two objects are unrelated thereafter. A pointer-like class (e.g. `std::shared_ptr`) shares state — copies point to the same underlying data, managed via reference counting. The choice determines the design of all three copy-control members.

*Reference counting (pointer-like pattern):*
- Each non-copy constructor allocates a `size_t` counter, initialised to 1.
- The copy constructor copies the pointer to the counter and increments it.
- The destructor decrements the counter; when it reaches zero it deletes both the resource and the counter.
- The copy-assignment operator increments the right-hand counter *before* decrementing the left-hand counter — this correctly handles self-assignment.

*`swap` and the copy-and-swap idiom:*

A custom `swap` swaps pointers (cheap) rather than allocating temporaries (expensive). Inside the swap function, `using std::swap;` is written before calling `swap` so that type-specific overloads are preferred via ADL while `std::swap` acts as a fallback. Never call `std::swap` directly — it defeats the purpose for pointer members.

The copy-and-swap assignment operator takes its argument *by value* (the compiler makes the copy), then swaps `*this` with that copy:
```cpp
HasPtr& HasPtr::operator=(HasPtr rhs) { // rhs is a copy
    swap(*this, rhs);
    return *this; // old data is now in rhs and will be destroyed
}
```
This is automatically exception-safe: any throw happens in the copy (before `*this` is modified) and self-assignment is handled correctly because swapping an object with a fresh copy of itself is harmless.

**Key practices**
- Fixed-point encoding: `int_val << 8` to encode, `raw >> 8` or `raw / 256.0f` to decode.
- `operator=` returns `*this` by reference to allow chaining.
- Post-increment saves a copy before incrementing and returns it; pre-increment modifies in place and returns `*this`.
- `min`/`max` have two overloads — one taking `Fixed&` and one taking `const Fixed&` — so the return type matches the const-ness of the argument.

**Tricks**
- Integer constructor uses bit-shift (`_rawBits = val << _fractionalBits`); float constructor uses `roundf` to avoid silent truncation.
- BSP uses the sign of cross-products to test which side of each edge the point falls on, entirely in fixed-point arithmetic.

---

## CPP03 — Inheritance

**Core notion:** How to build class hierarchies, how constructors chain up the hierarchy, and what happens when multiple paths lead to the same base class (the diamond problem).

**What was implemented**
- `ClapTrap` — base robot with hit points, energy points, attack damage, and methods `attack()`, `takeDamage()`, `beRepaired()`.
- `ScavTrap` — inherits from `ClapTrap`; overrides stats and adds `guardGate()`.
- `FragTrap` — inherits from `ClapTrap`; overrides stats and adds `highFivesGuys()`.
- `DiamondTrap` — inherits from both `ScavTrap` and `FragTrap`, demonstrating the diamond problem. Has its own `name` (distinct from `ClapTrap::_name`) and a `whoAmI()` method.

**Notes & theory — Forward declarations**

A forward declaration tells the compiler a name exists (a class, function, etc.) without providing its full definition. This allows headers to reference types by pointer or reference without creating a circular include dependency. The full definition must be available by the time the type is used in a context that requires knowing its size (e.g. a member variable, not just a pointer).

**Key practices**
- Every base class has a virtual destructor so polymorphic deletion is safe.
- Derived constructors explicitly call the parent constructor in the member initialiser list.
- `using ScavTrap::attack;` in `DiamondTrap` disambiguates which inherited `attack` to use.
- Copy-and-swap idiom (`swap()` helper in the copy-assignment operator) for exception-safe assignment.

**Tricks**
- `DiamondTrap` initialises `ClapTrap` directly (even though `ScavTrap` and `FragTrap` both also derive from it) because without virtual inheritance the two paths create two separate `ClapTrap` sub-objects. The subject does not mandate virtual inheritance, so the double sub-object is accepted and the explicit `ClapTrap(name)` call in `DiamondTrap`'s initialiser list is the correct resolution.

---

## CPP04 — Polymorphism and Abstract Classes

**Core notion:** Virtual dispatch, pure virtual functions, abstract base classes, deep vs. shallow copy, and the beginning of design patterns (factory, interface).

**What was implemented**
- `Animal` / `Dog` / `Cat` / `WrongAnimal` / `WrongCat` — shows that without `virtual`, calling a method on a base pointer invokes the base version; with `virtual` it dispatches to the derived version.
- `Brain` — a compound object (array of 100 `std::string` ideas) owned by `Dog` and `Cat`; forces a proper deep copy in their copy constructors and assignment operators.
- Abstract `Animal` (ex02) — `makeSound()` becomes pure virtual (`= 0`), preventing direct instantiation of `Animal`.
- Materia system (ex03): `AMateria` (abstract), `Ice` and `Cure` (concrete), `ICharacter` (interface), `Character` (implements interface, inventory of 4 materias), `MateriaSource` (factory). Dropped materias are tracked in a static singly-linked list (`Floor`) to prevent memory leaks.

**Notes & theory — Virtual functions and polymorphism**

When a derived class inherits from a base class, an object of the derived class may be referred to via a pointer or reference of the base class type. Whether the correct version of a method is called depends on whether that method is `virtual`:

- **Non-virtual (early binding):** the method is resolved at compile time based on the *declared type* of the pointer or reference. Calling through a `Base*` always invokes `Base::method`, even if the object is actually a `Derived`.
- **Virtual (late binding):** the method is resolved at runtime based on the *actual type* of the object. Calling through a `Base*` correctly dispatches to `Derived::method` if the object is a `Derived`.

```cpp
Base* ptr = new Derived();
ptr->Method1();  // non-virtual: calls Base::Method1
ptr->Method2();  // virtual:     calls Derived::Method2
```

The `override` specifier (C++11) is optional but strongly recommended — the compiler will emit an error if the decorated method does not actually override anything, catching typos and signature mismatches early.

*Overloading vs. overriding:*
- **Overloading** — two or more methods in the *same class* share a name but differ in parameter types. Resolved at compile time (function matching / early binding).
- **Overriding** — a derived class provides a method with the *same name and parameters* as a virtual method in the base class. Resolved at runtime (dynamic dispatch / late binding).

**Key practices**
- A class with any virtual method must have a virtual destructor so `delete basePtr` calls the correct chain of destructors.
- Deep copy: `Dog::Dog(const Dog& other)` allocates a new `Brain` and copies the content — not just the pointer.
- Pure virtual methods (`= 0`) make a class abstract and force subclasses to implement the interface.
- `ICharacter` is a pure-interface class: all methods pure virtual, no data members.

**Tricks**
- The `Floor` static linked-list collects every materia detached from a character so they can all be deleted at program exit without double-free.
- `AMateria::clone()` is the prototype pattern: each subclass returns `new Ice(*this)` (or `Cure`), allowing the factory to clone materias without knowing their concrete type.

---

## CPP05 — Exceptions

**Core notion:** How to design, throw, catch, and propagate exceptions; exception hierarchies inheriting from `std::exception`; const member variables; and more design-pattern practice.

**What was implemented**
- `Bureaucrat` — name (const `std::string`) and grade (1 = highest, 150 = lowest). `incrementGrade()` and `decrementGrade()` throw `GradeTooHighException` or `GradeTooLowException`, both inner classes inheriting from `std::exception`.
- `Form` / `AForm` — a signable, executable form with grade requirements. `beSigned()` throws if the bureaucrat's grade is too low; `execute()` throws `NotSignedException` if the form isn't signed.
- Concrete forms: `ShrubberyCreationForm` (writes ASCII trees to a file), `RobotomyRequestForm` (50 % chance of success via `std::rand`), `PresidentialPardonForm` (prints a message).
- `Intern` — a factory that maps form-name strings to constructor calls and returns the appropriate `AForm*`, using an array of `{name, creator-function}` pairs to avoid a long `if/else` chain.

**Notes & theory — Exceptions**

Exceptions transfer control from the point of throw to a matching `catch` handler. If no handler matches in the current function, the stack unwinds until one is found; if none is found in the entire call stack, `std::terminate` is called.

```cpp
try {
    throw 20;
} catch (int e) {
    std::cout << "int exception: " << e;
} catch (...) { // catches anything not caught above
    std::cout << "default handler";
}
```

The `catch (...)` ellipsis handler catches any exception type and is commonly used as a last-resort default. A bare `throw;` inside a catch block re-throws the current exception to the outer scope unchanged. After handling, execution resumes *after* the entire try-catch block, not after the throw site.

Any function declared `noexcept` will call `std::terminate` if an exception would propagate out of it.

*Function try-blocks* wrap an entire constructor — including its member-initialiser list — in a try block, which is the only way to catch exceptions thrown by base class constructors or member initialisers:
```cpp
B(int x) try : A{x}  // try covers the initialiser list
{
}
catch (...) {
    throw; // must rethrow or throw a new exception — cannot suppress it
}
```
A function-level catch on a constructor cannot resolve the exception by returning normally; it must throw.

*RAII (Resource Acquisition Is Initialisation):* To be exception-safe, resources must be tied to the lifespan of stack objects. When a function exits — normally or via exception — destructors for all fully constructed local objects are called automatically. `std::vector`, `std::string`, `std::unique_ptr`, and `std::shared_ptr` all follow RAII. Raw `new` without an RAII wrapper leaks if an exception fires before the matching `delete`.

*The three exception guarantees:*
1. **No-fail (no-throw):** the function will never allow an exception to propagate. The strongest guarantee; requires that all called functions are also no-fail or that all exceptions are caught internally.
2. **Strong guarantee:** if an exception occurs, program state is unchanged — commit-or-rollback semantics. The copy-and-swap idiom is the canonical way to achieve this in assignment operators.
3. **Basic guarantee:** if an exception occurs, no memory is leaked and the object remains in a valid (though possibly modified) state. The weakest acceptable guarantee; used when the strong guarantee would be too costly.

*Exception-safe classes:*
- Use RAII wrappers (smart pointers) rather than raw resource management in constructors, because if a constructor throws, its destructor is never called — any resources acquired before the throw must be owned by already-constructed sub-objects.
- Never let an exception escape from a destructor; wrap any potentially-throwing operations in a `try/catch` and swallow the exception.
- A base-class constructor exception caught in a derived-class function try-block must be re-thrown or replaced — it cannot be silently suppressed.

*`const` correctness:* Pass by `const` reference whenever a function does not modify its argument. Non-`const` references cannot bind to temporaries, so `const` references are necessary for functions that accept rvalue expressions. Apply `const` to member functions that do not modify the object — this allows them to be called on `const` instances.

**Key practices**
- Exception classes override `what()` returning a `const char*` literal — no dynamic allocation in the exception path.
- `const std::string& _name` — const reference member forces initialisation in the member initialiser list.
- The template method pattern: `AForm::execute()` performs the common checks (signed, grade) then delegates to the pure virtual `executeAction()` in subclasses.
- `Intern` uses a function-pointer array to remain open for extension without modification (OCP lite).

**Tricks**
- `RobotomyRequestForm` uses `std::srand(std::time(0))` seeded once and `std::rand() % 2` for the coin-flip.
- `ShrubberyCreationForm` opens the output file inside the execute action — this keeps any I/O exception well-scoped to the execute phase.

---

## CPP06 — C++ Casts and RTTI

**Core notion:** The four C++ cast operators, when each is appropriate, pointer serialisation, and runtime type identification without `std::typeinfo` abuse.

**What was implemented**
- `ScalarConverter` — a utility class (private constructor, all methods static) that parses a string literal and prints its value as `char`, `int`, `float`, and `double`, handling special cases (`nan`, `+inf`, `-inf`, non-displayable chars, overflows).
- `Serializer` — converts a `Data*` pointer to a `uintptr_t` via `reinterpret_cast` and back, proving the round-trip preserves the address.
- `Base` / `A` / `B` / `C` — a base class with a virtual destructor and three empty derived classes. `generate()` returns a randomly instantiated derived object as `Base*`; `identify(Base*)` and `identify(Base&)` detect the real type using `dynamic_cast`.

**Notes & theory — Casts**

*`static_cast`:* Performs conversions at compile time. For base/derived conversions the cast is valid only when:
- The lvalue is of type Base and the target is a reference to Derived (or vice-versa),
- Derived is a complete type,
- Base is an accessible base of Derived,
- The cv-qualification of the target is not greater than that of the source.
If the target type is `void`, the result is a discarded-value expression (no object produced).

*`reinterpret_cast`:* Reinterprets the underlying bit pattern of an expression as a different type. Like `const_cast`, it compiles to *no CPU instructions* (except when converting between integers and pointers) — it is purely a compile-time directive telling the compiler to treat the bits as a different type. Key permitted conversions:
- Any pointer to an integral type large enough to hold all pointer values (`std::uintptr_t` is the portable choice). A pointer converted to an integer and back to the same pointer type is guaranteed to recover the original value.
- Any `T1*` to any `T2*` (result is not safely dereferenceable unless the types are compatible).
- Any function pointer to a different function pointer type (calling through the reinterpreted pointer yields unspecified behaviour, but converting back is valid).
- An integer zero converted to a pointer is **not** guaranteed to produce a null pointer — use `static_cast<T*>(nullptr)` for that.

*`dynamic_cast`:* Performs a checked downcast at runtime using RTTI. Returns `nullptr` on failure when casting pointers; throws `std::bad_cast` on failure when casting references. Used in `identify(Base&)` with `try/catch` because the reference overload cannot return null.

*`const_cast`:* The only cast that can add or remove `const`/`volatile` qualifiers. Not the focus of CPP06 but important to know as the fourth cast operator.

**Key practices**
- `static_cast` for well-defined numeric conversions and known-hierarchy downcasts.
- `reinterpret_cast` for raw memory reinterpretation (pointer ↔ integer); used only where semantics are explicitly understood.
- `dynamic_cast` for safe polymorphic downcasts on types with at least one virtual function.
- Utility class pattern: private constructor + deleted copy constructor prevents instantiation.

**Tricks**
- `identify(Base&)` wraps each `dynamic_cast<A&>` in its own `try/catch(std::bad_cast&)` so the three types can be tested independently.
- `ScalarConverter` detects the input type by trying conversions in order (special literals first, then char, then int, then float/double by the presence of `.` or `f` suffix) using `strtol` / `strtof` / `strtod` with `errno` checks.

---

## CPP07 — Function Templates and Template Classes

**Core notion:** Writing generic code with function templates and class templates; template type deduction; and building a simple generic container.

**What was implemented**
- `swap`, `min`, `max` — function templates operating on any type that supports `<` and assignment.
- `iter` — a higher-order function template: `iter(T arr[], size_t len, F func)` applies `func` to every element of `arr`. Both `T` and `F` are deduced at the call site.
- `Array<T>` — a template class wrapping a heap-allocated array with bounds-checked `operator[]`, a size-returning `size()`, copy constructor, and copy-assignment operator. Throws `std::exception` on out-of-bounds access.

**Key practices**
- Function templates are defined entirely in headers (`.hpp`) because the compiler needs the definition at the point of instantiation.
- `operator[]` is provided in both const and non-const versions so `Array` can be used in const contexts.
- Copy constructor allocates a new buffer and copies elements individually — no shallow pointer copy.
- Template parameter constraints are implicit (duck typing): the type just needs to support the operations used.

**Tricks**
- `iter`'s second template parameter `F` allows passing plain function pointers, lambdas, or functors — no `std::function` overhead.
- `Array` stores the size as `unsigned int` (matching the constructor parameter), avoiding signed/unsigned comparison warnings in loops.

---

## CPP08 — STL Containers, Algorithms, and Iterators

**Core notion:** Using the standard template library containers and algorithms correctly; adapting containers; and writing code that works with any conforming iterator range.

**What was implemented**
- `easyfind<T>` — a one-liner template function that calls `std::find` on any container holding ints and throws if the value is not found. Works with `vector`, `list`, `deque`, etc.
- `Span` — wraps a `std::vector<int>` with a fixed maximum capacity. `addNumber()` inserts one value; a templated range-insert overload copies from any iterator pair. `shortestSpan()` and `longestSpan()` compute the minimum and maximum difference between any two stored values.
- `MutantStack<T>` — inherits from `std::stack<T>` and exposes the underlying container's iterators (`begin`, `end`, `cbegin`, `cend`, `rbegin`, `rend`, `crbegin`, `crend`), making the stack iterable without leaving the `std::stack` interface.

**Key practices**
- `std::sort` + adjacent difference used in `Span::shortestSpan()`: sort a copy, then find the minimum adjacent difference in one pass — O(n log n) overall.
- `MutantStack` accesses `std::stack::c` (the protected underlying container) to expose iterators — a legitimate use of the protected member that the standard explicitly provides for this purpose.
- Custom exception classes with descriptive `what()` messages for both `Span` overflow and insufficient-values conditions.

**Tricks**
- The templated `addNumbers(InputIt first, InputIt last)` in `Span` uses `std::distance` to check capacity before inserting, then `_data.insert(_data.end(), first, last)` to copy the whole range in one call.
- `MutantStack` requires no extra data members — all iterator types are aliased from `std::stack<T>::container_type`.

---

## CPP09 — Real-World Applications

**Core notion:** Applying everything learned — containers, algorithms, exceptions, file I/O, parsing — in more realistic, self-contained programs.

**What was implemented**
- `BitcoinExchange` (ex00) — reads a historical Bitcoin price database (CSV) into a `std::map<time_t, float>`, then processes an input file of `date | value` pairs. For each line it finds the closest earlier-or-equal date with `lower_bound`, validates the value range, and prints the result. Full date validation including leap years.
- `RPN` (ex01) — a Reverse Polish Notation calculator using `std::stack<double>`. Parses a space-separated expression from argv, pushes operands, applies operators, and throws descriptive errors on malformed input or stack underflow.
- `PmergeMe` (ex02) — implements the **Ford-Johnson merge-insertion sort** for both `std::vector<int>` and `std::deque<int>`. Reads integers from argv, sorts both containers, and prints before/after state and timing for each. The Ford-Johnson algorithm minimises the number of comparisons for sequences of any length by using optimal insertion order derived from Jacobsthal numbers.

**Key practices**
- `std::map::lower_bound` returns an iterator to the first key ≥ target; decrementing it gives the last key ≤ target — the canonical pattern for "find the most recent price on or before this date".
- RPN uses a `std::stack` exactly as intended: push operands, pop two operands per operator, push result.
- `PmergeMe` templates the sort over the container type so the same algorithm body runs on both `vector` and `deque` — the timing comparison is meaningful because the containers have different memory layouts.
- All three programs validate their input thoroughly and report actionable error messages rather than crashing on bad data.

**Tricks**
- `BitcoinExchange` converts date strings to `time_t` via `std::mktime` with `struct tm`, making date arithmetic and comparison trivially correct.
- Ford-Johnson uses Jacobsthal numbers (0, 1, 1, 3, 5, 11, 21, …) to determine the optimal insertion order of the "pend" elements into the main chain, minimising worst-case comparisons. CPP09/ex02 was heavily inspired by the Stack Overflow reference listed above.
- `PmergeMe` measures time with `clock()` before and after each sort and converts the difference to microseconds with `(double)(end - start) / CLOCKS_PER_SEC * 1e6`.

---

## General Practices Applied Throughout

- **Orthodox Canonical Form** (default ctor, copy ctor, copy-assignment, destructor) respected in every class, even when auto-generated behaviour would suffice.
- **`const` correctness** — getters are `const`, parameters passed by const reference when not modified, `const` member variables where semantically appropriate. Non-`const` references cannot bind to temporaries, so `const` references are necessary whenever rvalue expressions are passed.
- **No raw `using namespace std;`** — types are always fully qualified to avoid name-pollution in headers.
- **Header guards** (`#ifndef / #define / #endif`) on every header.
- **Makefiles** with `$(NAME)`, `all`, `clean`, `fclean`, `re` targets, `-Wall -Wextra -Werror` flags, and no relink.
- Memory leaks checked with Valgrind throughout.
