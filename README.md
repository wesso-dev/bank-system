# 🏦 Bank Customer Service Management System

> A complete **Data Structures** project built in **C** that simulates a real-world bank customer service system using **Queue**, **Stack**, **Linked Lists**, **Dynamic Memory Allocation**, **File Handling**, and **Undo** functionality.

---

## 🚀 Technologies & Concepts

<p align="left">

![C](https://img.shields.io/badge/C-Language-blue?style=for-the-badge&logo=c)

![Queue](https://img.shields.io/badge/Queue-FIFO-success?style=for-the-badge)

![Stack](https://img.shields.io/badge/Stack-LIFO-orange?style=for-the-badge)

![Linked%20List](https://img.shields.io/badge/Linked_List-Data_Structure-purple?style=for-the-badge)

![Pointers](https://img.shields.io/badge/Pointers-Memory-important?style=for-the-badge)

![Dynamic Memory](https://img.shields.io/badge/Dynamic-Memory-red?style=for-the-badge)

![File Handling](https://img.shields.io/badge/File-I/O-yellow?style=for-the-badge)

</p>

---

# 🎯 Overview

This project is a **Command-Line Interface (CLI)** application that simulates customer service inside a bank.

Customers are organized using a **Queue**, completed services are stored in a **Stack** to support **Undo**, and all customer data is automatically saved to text files.

The main goal of this project is to practice real-world implementation of **Data Structures** and **Memory Management** in C.

---

# ✨ Features

✅ Queue Management (FIFO)

✅ Undo Functionality using Stack (LIFO)

✅ Customer Search by ID or Name

✅ Automatic File Saving & Loading

✅ Dynamic Memory Allocation

✅ Memory Leak Prevention

---

# 🧩 Data Structures

| Structure | Implementation | Purpose |
|-----------|---------------|---------|
| 🎟 Queue | Linked List | Waiting customers |
| 🥞 Stack | Linked List | Undo operations |
| 📁 Files | File I/O | Permanent storage |

---

# ⚡ Memory Optimization

### 🔹 Node Reuse

Instead of allocating new memory every time, the system transfers existing nodes between the Queue and Stack.

This approach reduces allocations and improves performance.

---

### 🔹 Automatic Stack Cleanup

The Undo Stack stores up to **20 operations**.

Once the limit is reached, the oldest node is automatically removed and its memory is released.

---

# 📂 Project Structure

```text
bank-system/
│
├── bank.h
├── ds.c
├── files.c
├── main.c
└── README.md
```

---

# 📚 What I Learned

- 🧠 Pointers
- 🔗 Linked Lists
- 🎟 Queue (FIFO)
- 🥞 Stack (LIFO)
- 💾 Dynamic Memory Allocation (`malloc`, `free`)
- 📂 File Handling
- 🔍 Linear Search
- ⚡ Memory Optimization
- 🧩 Modular Programming
- 🏗 Building a Complete CLI Application

---

# 🎓 Educational Purpose

This project was built for learning and practicing **Data Structures in C**.

It demonstrates how multiple data structures work together inside a complete application while following clean code principles and efficient memory management.

---

## ⭐ If you like this project, consider giving it a star!
