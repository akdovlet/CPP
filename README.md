# CPP — 42 C++ Modules (CPP00–CPP09)

A complete walkthrough of the 42 school C++ curriculum, covering the language from first principles to advanced standard-library usage.
No AI was used at any point — neither for writing code nor for researching concepts.

---

## Resources

- **C++ Primer (5th ed., free online):** https://cpp-primer.pages.dev/book/000-cpp_primer_fifth_edition.html — the primary reference throughout the entire curriculum
- **cppreference:** https://en.cppreference.com/ — used for standard-library specifics, type traits, and container APIs
- **CPP09/ex02 merge-insertion sort reference:** https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort

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

**Core notion:** How operator overloading works, what the Orthodox Canonical Form demands, and how to represent fractional numbers without floating-point.

**What was implemented**
- `Fixed` — a fixed-point number class using a 32-bit integer with 8 fractional bits.
  - Conversion constructors from `int` and `float`.
  - Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`.
  - Arithmetic operators: `+`, `-`, `*`, `/`.
  - Pre- and post-increment/decrement (`++a`, `a++`, `--a`, `a--`).
  - Static `min()` and `max()` in both const and non-const variants.
  - `operator<<` for stream output.
- `Point` — a 2D point built from `Fixed` values, used in a Binary Space Partitioning function `bsp()` that determines whether a point lies strictly inside a triangle.

**Key practices**
- Fixed-point encoding: `int_val << 8` to encode, `raw >> 8` or `raw / 256.0f` to decode.
- `operator=` returns `*this` by reference to allow chaining (`a = b = c`).
- Post-increment saves a copy before incrementing and returns it; pre-increment modifies in place and returns `*this`.
- `min`/`max` have two overloads — one taking `Fixed&` and one taking `const Fixed&` — because the return type must match the const-ness of the argument.

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

**Key practices**
- A class with any virtual method must have a virtual destructor.
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

**Key practices**
- Exception classes override `what()` returning a `const char*` literal — no dynamic allocation in the exception path.
- `const std::string& _name` — const reference member forces initialisation in the member initialiser list.
- The template method pattern: `AForm::execute()` performs the common checks (signed, grade) then delegates to the pure virtual `executeAction()` in subclasses.
- `Intern` uses a function-pointer array to remain open for extension without modification (OCP lite).

**Tricks**
- `RobotomyRequestForm` uses `std::srand(std::time(0))` seeded once and `std::rand() % 2` for the coin-flip — kept simple and deterministic enough for test purposes.
- `ShrubberyCreationForm` opens the output file in the constructor of the action, not before — this keeps the exception well-scoped to the execute phase.

---

## CPP06 — C++ Casts and RTTI

**Core notion:** The four C++ cast operators, when each is appropriate, pointer serialisation, and runtime type identification without `std::typeinfo` abuse.

**What was implemented**
- `ScalarConverter` — a utility class (private constructor, all methods static) that parses a string literal and prints its value as `char`, `int`, `float`, and `double`, handling special cases (`nan`, `+inf`, `-inf`, non-displayable chars, overflows).
- `Serializer` — converts a `Data*` pointer to a `uintptr_t` via `reinterpret_cast` and back, proving the round-trip preserves the address.
- `Base` / `A` / `B` / `C` — a base class with a virtual destructor and three empty derived classes. `generate()` returns a randomly instantiated derived object as `Base*`; `identify(Base*)` and `identify(Base&)` detect the real type using `dynamic_cast`.

**Key practices**
- `static_cast` — for well-defined numeric conversions and up/down casts within a known hierarchy.
- `reinterpret_cast` — for raw memory reinterpretation (pointer ↔ integer); used only where semantics are explicitly understood.
- `dynamic_cast` — for safe polymorphic down-casts; returns `nullptr` on failure for pointers, throws `std::bad_cast` for references.
- `const_cast` — the fourth cast; not the focus of this module but discussed.
- Utility class pattern: private constructor + deleted copy constructor prevents instantiation.

**Tricks**
- `identify(Base&)` cannot check for a null result from `dynamic_cast`, so it wraps each attempt in a `try/catch(std::bad_cast&)` block instead.
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
- `std::sort` + `std::distance` used in `Span::shortestSpan()`: sort a copy, then find the minimum adjacent difference in one pass — O(n log n) overall.
- `std::min_element` / `std::max_element` are unnecessary when the vector is already sorted; using sorted order is both cleaner and faster.
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
- **`const` correctness** — getters are `const`, parameters passed by const reference when not modified, `const` member variables where semantically appropriate.
- **No raw `using namespace std;`** — types are always fully qualified to avoid name-pollution in headers.
- **Header guards** (`#ifndef / #define / #endif`) on every header.
- **Makefiles** with `$(NAME)`, `all`, `clean`, `fclean`, `re` targets, `-Wall -Wextra -Werror` flags, and no relink.
- Memory leaks checked with Valgrind throughout.
