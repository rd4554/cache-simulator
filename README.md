# Direct-Mapped Cache Simulator

A C++ implementation of a **Direct-Mapped Cache Simulator** that models the behavior of a CPU cache by simulating memory accesses, cache hits, cache misses, and cache state updates. The simulator demonstrates fundamental computer architecture concepts such as **cache mapping**, **tag comparison**, and **valid-bit management**.

---

## Features

- Direct-Mapped Cache simulation
- Configurable cache size and block size
- Memory access simulation using input files
- Cache hit and miss detection
- Valid bit and tag implementation
- Real-time cache state visualization
- Hit rate and miss rate calculation
- Input from file
- Output automatically saved to a file
- Modular Object-Oriented C++ design

---

## Project Structure

```
Cache-Simulator/
│
├── src/
│   ├── main.cpp
│   ├── Cache.cpp
│   └── Cache.h
│
├── input/
│   └── sample_input.txt
│
├── output/
│   └── output.txt
│
├── screenshots/
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## How Direct-Mapped Cache Works

A Direct-Mapped Cache allows every memory block to be stored in exactly **one cache line**.

For every memory address:

1. Calculate the Block Number
2. Compute the Cache Index
3. Compute the Tag
4. Check whether the cache line is valid
5. Compare the stored tag with the requested tag
6. Determine whether it is a **Cache Hit** or **Cache Miss**

---

## Formulae Used

### Number of Cache Lines

```
Number of Cache Lines = Cache Size / Block Size
```

### Block Number

```
Block Number = Memory Address / Block Size
```

### Cache Index

```
Cache Index = Block Number % Number of Cache Lines
```

### Tag

```
Tag = Block Number / Number of Cache Lines
```

---

## Example Input

### Cache Configuration

```
Cache Size : 16 Bytes
Block Size : 4 Bytes
```

### sample_input.txt

```
0
4
8
12
0
16
4
20
```

---

## Sample Output

```
Address 0 -> Miss
Address 4 -> Miss
Address 8 -> Miss
Address 12 -> Miss
Address 0 -> Hit
Address 16 -> Miss
Address 4 -> Hit
Address 20 -> Miss

========== Cache Statistics ==========
Total Accesses : 8
Hits           : 2
Misses         : 6
Hit Rate       : 25.00%
Miss Rate      : 75.00%
```

---

## Technologies Used

- C++
- Standard Template Library (STL)
- Object-Oriented Programming
- File Handling (`ifstream`, `ofstream`)

---

## Learning Outcomes

This project demonstrates understanding of:

- Cache Memory Organization
- Direct Mapping Technique
- Memory Hierarchy
- Cache Hits and Cache Misses
- Tag and Valid Bit Mechanism
- Object-Oriented Programming in C++
- File Input/Output
- Modular Software Design

---

## How to Compile

Using **g++**:

```bash
g++ src/main.cpp src/Cache.cpp -o cache
```

Run the program:

### Windows

```bash
.\cache
```

### Linux / macOS

```bash
./cache
```

---

## Future Improvements

- Fully Associative Cache
- Set-Associative Cache
- LRU Replacement Policy
- FIFO Replacement Policy
- Random Replacement Policy
- Average Memory Access Time (AMAT) Calculation
- Interactive Menu System
- Graphical Cache Visualization

---

## Author

**Reecha**

---

## License

This project is licensed under the MIT License.
