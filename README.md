🏦 Bank Customer Service Management System

«A complete Data Structures project written in C that simulates a real-world bank customer service system using Queue, Stack, Dynamic Memory Allocation, File Handling, and Undo functionality.»

---

<details>
<summary>🎯 <b>Overview</b></summary><br>This project is a Command-Line Interface (CLI) application that simulates how customers are managed inside a bank. The system organizes customers using a Queue, records completed services inside a Stack to support Undo, and permanently stores customer data in text files.

The project focuses on applying core Data Structures concepts together with Dynamic Memory Management and File Handling in a realistic software scenario.

</details>---

<details>
<summary>✨ <b>Key Features</b></summary><br>- 🎟️ Queue Management – Organize customers based on the FIFO (First-In, First-Out) principle.
- 🔄 Undo Operation – Restore the last served customer back to the front of the queue using a Stack (LIFO).
- 🔍 Linear Search – Search for customers by ID or Name.
- 📁 Persistent Storage – Automatically save and load customer data using "customers.txt".
- 🧹 Memory Safety – Efficient memory management with automatic cleanup to prevent memory leaks.

</details>---

<details>
<summary>🧩 <b>Data Structures & Technologies</b></summary><br>Data Structure| Implementation| Principle| Purpose
🎟️ Queue| Linked List| FIFO| Manage waiting customers
🥞 Stack| Linked List| LIFO| Store completed services for Undo
📁 Files| File I/O| Persistent Storage| Save customer records permanently

</details>---

<details>
<summary>⚡ <b>Memory Management & Optimization</b></summary><br>🔹 Node Reuse

Instead of freeing and reallocating memory, the system transfers the existing "Node*" directly between the Queue and Stack, improving performance and reducing unnecessary memory allocations.

🔹 Stack Size Limitation

The Undo Stack maintains a maximum of 20 records.

When the limit is exceeded, the oldest node is automatically removed and its memory is released to prevent uncontrolled memory growth.

</details>---

<details>
<summary>📂 <b>Project Structure</b></summary><br>bank-system/
├── bank.h        # Data structures and function declarations
├── ds.c          # Queue, Stack, and Linked List implementation
├── files.c       # File handling and searching operations
├── main.c        # Main program and interactive menu
└── README.md     # Project documentation

</details>---

<details>
<summary>🎓 <b>Educational Purpose</b></summary><br>This project was developed as an educational practice project to strengthen practical knowledge of Data Structures in C.

It demonstrates the use of:

- Pointers
- Linked Lists
- Queue
- Stack
- Dynamic Memory Allocation ("malloc", "free")
- File Handling
- Memory Optimization
- Algorithm Design
- Modular Programming

The goal is to simulate a realistic banking service system while following clean programming practices and efficient memory management.

</details>
