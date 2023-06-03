# c-string-sprintf

Custom implementation of the C standard `string.h` functions with an additional `sprintf` function.

This project provides a self-contained set of string manipulation functions in C, including most of the standard `string.h` API and a custom implementation of `sprintf`. The repository is designed for educational purposes, portability, and as a lightweight alternative for environments where the standard library may not be available or needs to be extended.

## Prerequisites

- GCC or any C99-compatible compiler
- [Make](https://www.gnu.org/software/make/) (for building and testing with the provided Makefile)

## Contents

- `src/` — Source files with implementations of string functions and `sprintf`
- `tests/` — Unit tests for all implemented functions
- `Makefile` — Build and test automation
- `README.md` — Project documentation

## Setup and Usage

1. **Clone this repository:**
    ```
    git clone https://github.com/mirotvorecc/c-string-sprintf.git
    cd c-string-sprintf
    ```

2. **Build the project:**
    ```
    make
    ```

3. **Run tests to verify the implementation:**
    ```
    make test
    ```

4. **Integrate into your project:**
    - Copy the required source files from `src/` into your project.
    - Include the appropriate headers in your C source files.

## Features

- **Custom implementations of core `string.h` functions:**
    - `memchr`, `memcmp`, `memcpy`, `memmove`, `memset`
    - `strcat`, `strncat`, `strchr`, `strcmp`, `strncmp`
    - `strcpy`, `strncpy`, `strcspn`, `strerror`, `strlen`
    - `strpbrk`, `strrchr`, `strspn`, `strstr`, `strtok`
- **Custom `sprintf` implementation**: Formats and writes output to a string buffer, supporting standard format specifiers and flags.
- **Unit tests**: All functions are covered by tests for correctness and compatibility.
- **Portable and easy to integrate**: No external dependencies.

## Notes

- The custom `sprintf` implementation aims for compatibility with the standard C function, but may not cover all edge cases or platform-specific behaviors.
- Use care with buffer sizes to avoid overflows, especially with `sprintf`.
- The project structure is simple and conventional; adapt paths and build instructions as needed for your use case.