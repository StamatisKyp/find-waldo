# 🔍 Find Waldo — C++ Project

This is a simple C++ program that searches for a special number in a square matrix (board). The special number — called "Waldo" — is **the largest in its column** and **the smallest in its row**.

---

## 🧠 How It Works

1. The user enters the size of the board (N x N).
2. The user inputs all the numbers in the matrix.
3. The program checks each number to see if it satisfies:
   - Largest in its column
   - Smallest in its row
4. If found, it prints Waldo's position. If not, it displays "No solutions!"

---

## 🛠️ How to Compile and Run

### Using g++:

```bash
g++ -o find_waldo find_waldo.cpp
./find_waldo
