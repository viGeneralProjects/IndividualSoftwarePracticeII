# A1: 1D Cellular Automata

A C++ command-line program that simulates 1D cellular automata, generating visual patterns from simple rules applied across generations of cells.

## Tech Stack

- **Language:** C++
- **Environment:** Docker (Ubuntu Linux), VSCode
- **Team:** Solo Project

## Features

- Prompts the user for a rule set number (0-255) and validates input
- Converts the rule number to an 8-element binary rule array
- Simulates 50 generations of a 64-cell automaton starting from a single active cell
- Renders each generation to the console using `#` for active cells and spaces for inactive cells
- Compiles to an executable via a single command in `compile.txt`

## Concepts Demonstrated

- C-style arrays and pointer-free array passing
- Binary number conversion and indexing
- Modular function design (`convertRuleSetNumberToRuleSetArray`, `displayCurrentGeneration`, `computeNextGeneration`, `convertNeighborhoodToIndex`)
- Console input/output and input validation

## Authors

Developed individually for CS 3505 (Software Practice II), University of Utah (Fall 2025).

---

# A2: Sine Curve Class

A C++ class that generates points along a sine curve using configurable amplitude, wavelength, and angle increment parameters.

## Tech Stack

- **Language:** C++
- **Environment:** Docker (Ubuntu Linux), VSCode
- **Team:** Solo Project

## Features

- `Sine` class with configurable amplitude, wavelength, and angle increment
- Pre-increment and post-increment operator overloading to step along the curve
- Overloaded `<<` insertion operator outputting `angle, height` pairs
- Getters for current angle and height (`currentAngle`, `currentHeight`)
- Test program that loops 361 times and outputs curve data, redirectable to a file
- Sine data plotted in a spreadsheet and saved as `SinePlot.jpg`

## Concepts Demonstrated

- C++ class design split across `.h` and `.cpp` files
- Operator overloading (pre/post increment, insertion operator)
- `<cmath>` usage including degree-to-radian conversion
- Command-line output redirection

## Authors

Developed individually for CS 3505 (Software Practice II), University of Utah (Fall 2025).

---

# A3: PDF Facade (Wavy Text Generator)

A C++ application that wraps the Haru PDF library behind a clean facade class and uses a sine curve to place text along a wavy path in a generated PDF.

## Tech Stack

- **Language:** C++
- **Libraries:** libharu (PDF generation)
- **Build System:** Makefile
- **Environment:** Docker (Ubuntu Linux), VSCode
- **Team:** Solo Project

## Features

- `HaruPDF` facade class that abstracts the Haru C library into a clean, easy-to-use interface for setting up a PDF, placing text, and saving the file
- Uses the `Sine` class from A2 to position individual characters along a sine curve on the PDF page
- Command-line argument specifies the text to render
- Outputs a PDF file `sinePDF.pdf` with text flowing along a wave
- Makefile with a `LIBHARU` variable for configurable library paths and a `clean` target

## Concepts Demonstrated

- Facade design pattern
- Linking against a third-party C library (`-I`, `-L`, `-l` flags)
- Makefile build management with configurable variables
- Combining multiple classes (`HaruPDF` + `Sine`) in a single application

## Authors

Developed individually for CS 3505 (Software Practice II), University of Utah (Fall 2025).

---

# A4: Trie Data Structure

A C++ implementation of a Trie (prefix tree) supporting word insertion, lookup, and prefix-based search, built with full Rule-of-Three memory management.

## Tech Stack

- **Language:** C++
- **Build System:** Makefile
- **Environment:** Docker (Ubuntu Linux), VSCode
- **Team:** Solo Project

## Features

- `Trie` class with a branching array of `Node*` pointers (26 branches per node for a-z)
- `addWord` — inserts a word into the trie
- `isWord` — returns whether a string is a complete word in the trie
- `allWordsStartingWithPrefix` — returns all words in the trie beginning with a given prefix
- Full Rule-of-Three: custom destructor, copy constructor, and assignment operator
- Test program `TrieTest` that reads a word list and query list from files and reports results
- Makefile with `clean` and `test` targets

## Concepts Demonstrated

- Tree data structures and pointer management in C++
- Recursive traversal for prefix search
- Rule-of-Three for classes managing heap memory
- File I/O and command-line argument handling

## Authors

Developed individually for CS 3505 (Software Practice II), University of Utah (Fall 2025).
