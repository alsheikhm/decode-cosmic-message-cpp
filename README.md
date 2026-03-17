# decode-cosmic-message-cpp
Decode Cosmic's Message

# Overview

Cosmic Signal Decoder is a C++ program that processes a series of binary transmissions and decodes a hidden message through multiple transformation stages. Each line of binary input is interpreted as encoded data, progressively refined through ASCII conversion, pattern extraction, filtering, and reversal to reveal meaningful text.

The program simulates a real-world data decoding pipeline, where raw signals are processed step-by-step to uncover structured information.

# Decoding Pipeline

The program performs a multi-stage transformation on each line of input:

### 1. Binary → ASCII Conversion
- Each line is split into 8-bit groups (bytes)
- Each byte is converted into its corresponding ASCII character
- The result is stored as a string for that line

### 2. Pattern Extraction
- Starting from the second character, every third character is selected
- This reduces noise and extracts relevant signal components

### 3. Filtering
- All non-alphanumeric characters are removed
- Only letters and numbers are retained

### 4. Reversal
- Each processed string is reversed
- This reveals the intended readable fragment

After all lines are processed, the decoded fragments combine to reveal the final hidden message.

# Data Structure Design

The program uses:

- `std::vector<std::string>` to store and process each line independently
- Each transformation stage updates the vector in-place
- A custom print function displays intermediate results after each stage

This design enables clear, step-by-step tracking of how raw data evolves into the final decoded message.

# Core Functionality

- Reads binary signals from an input file
- Converts binary data into ASCII text
- Applies structured transformation steps to each line
- Stores intermediate and final results in a vector of strings
- Prints output after each stage to visualize decoding progress

# Core Concepts Applied

- File I/O using input streams
- Binary-to-ASCII conversion
- String manipulation and parsing
- Vector-based data organization
- Iterative transformation pipelines
- Character filtering (`isalnum`)
- String reversal algorithms
- Stepwise data processing and debugging output

# How to Run

1. Ensure `signal.txt` is in the same directory as the program
2. Compile the program using a C++ compiler (ex. g++, clang++)
3. Run the executable
