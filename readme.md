# 🧑‍🎓 Student Directory Hash Table (C)

This is a simple C program that implements a **hash table** for storing student records using **chaining to handle collisions**. Each student has a name and a grade, and students are stored in a hash table with linked lists in each bucket.

---

## 📂 Project Structure

- **Data Structures Used**
  - `Student` — stores student `name` and `grade`
  - `Node` — used to handle collisions via linked lists
  - `StudentDirectory[]` — an array of `Node*` buckets (size 100)

- **Hashing**
  - A simple hash function based on summing ASCII values of the student’s name and using modulo operation.

- **Collision Handling**
  - Chaining with singly linked lists.

---

## 🛠️ Features

- Create student objects dynamically.
- Insert students into a hash table.
- Handle collisions using linked lists.
- Print the entire directory, showing all students by bucket.

---

## 🧪 How to Run

### 🔧 Compile the code:

```bash
gcc main.c -o main
./main 
``` 

### Alternative way to build on Macos 
```bash 
make 
./main 
```