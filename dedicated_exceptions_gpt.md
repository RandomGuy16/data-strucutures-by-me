C++ provides a set of standard exceptions in the `<stdexcept>` and `<exception>` headers. Here are some of the most common dedicated exceptions:

---

### **1. General Standard Exceptions (From `<exception>`)**
These are the base classes for all exceptions in C++.

- **`std::exception`** → Base class for all standard exceptions.  
  ```cpp
  throw std::exception();
  ```

- **`std::bad_alloc`** → Thrown when `new` fails to allocate memory.  
  ```cpp
  throw std::bad_alloc();
  ```

- **`std::bad_cast`** → Thrown when a `dynamic_cast` fails.  
  ```cpp
  throw std::bad_cast();
  ```

- **`std::bad_typeid`** → Thrown when using `typeid` on a null pointer to a polymorphic type.  
  ```cpp
  throw std::bad_typeid();
  ```

---

### **2. Runtime Errors (From `<stdexcept>`)**
These exceptions occur during program execution.

- **`std::runtime_error`** → Generic runtime error.  
  ```cpp
  throw std::runtime_error("Runtime error occurred");
  ```

- **`std::range_error`** → Used for errors related to numeric range issues.  
  ```cpp
  throw std::range_error("Range error");
  ```

- **`std::overflow_error`** → Indicates arithmetic overflow.  
  ```cpp
  throw std::overflow_error("Overflow detected");
  ```

- **`std::underflow_error`** → Indicates arithmetic underflow.  
  ```cpp
  throw std::underflow_error("Underflow detected");
  ```

- **`std::logic_error`** → Base class for logical errors (invalid use of code).  
  ```cpp
  throw std::logic_error("Logic error");
  ```

---

### **3. Logic Errors (From `<stdexcept>`)**
These are errors in the logic of the program that can be detected before execution.

- **`std::invalid_argument`** → Thrown when passing an invalid argument to a function.  
  ```cpp
  throw std::invalid_argument("Invalid argument passed");
  ```

- **`std::domain_error`** → Thrown when a mathematical function gets an invalid domain value.  
  ```cpp
  throw std::domain_error("Domain error");
  ```

- **`std::length_error`** → Thrown when trying to exceed the maximum allowed size of a container.  
  ```cpp
  throw std::length_error("Too large length");
  ```

- **`std::out_of_range`** → Thrown when accessing an element outside of valid bounds (e.g., vector out-of-bounds).  
  ```cpp
  throw std::out_of_range("Out of range error");
  ```

---

### **4. Other Notable Exceptions**
- **`std::ios_base::failure`** → Thrown when an I/O operation fails (file read/write errors).  
  ```cpp
  throw std::ios_base::failure("I/O operation failed");
  ```

- **`std::system_error`** → Represents system-related errors (such as file system failures).  
  ```cpp
  throw std::system_error(std::error_code(), "System error");
  ```

- **`std::future_error`** → Thrown when dealing with `std::future` and `std::promise` failures in multithreading.  
  ```cpp
  throw std::future_error(std::make_error_code(std::future_errc::no_state));
  ```

---

### **Which Exception to Use?**
| **Exception**            | **Use Case** |
|--------------------------|-------------|
| `std::invalid_argument`  | Bad function argument |
| `std::out_of_range`      | Accessing an invalid index |
| `std::bad_alloc`         | Memory allocation failure |
| `std::runtime_error`     | Generic runtime issues |
| `std::overflow_error`    | Arithmetic overflow |
| `std::ios_base::failure` | I/O operations fail |

Would you like an example of handling these exceptions with `try` and `catch`? 🚀