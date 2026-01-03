# 🎓 Student Management System (C++)

An Enchanced **menu-driven Student Management System** developed in **C++** using **Object-Oriented Programming (OOP)** and **file handling**.  
The system allows efficient management of student records with persistent storage, validation, and enhanced usability.

---

## 📌 Project Overview

This project provides a **CLI-based application** to manage student data such as:
- Name
- Roll Number
- Branch
- Course
- Email ID

All records are stored persistently using a **CSV file**, making the data easy to maintain and portable.

---

## 🚀 Features

- Add new student records
- Display all student records
- Search students by **Roll Number**
- Search students by **Name**
- Edit existing student records
- Delete student records with confirmation
- Automatic file saving after every operation
- ANSI-colored CLI interface
- Cross-platform screen clearing (Windows / Linux / macOS)

---

## 🛠️ Enhancements Implemented

| No. | Enhancement | Description |
|----|------------|-------------|
| 1 | Duplicate Roll Number Check | Prevents adding students with existing roll numbers |
| 2 | Proper Input Handling | Uses `cin.ignore()` safely to avoid skipped inputs |
| 3 | Pass by Reference | Improves performance by avoiding unnecessary copying |
| 4 | Auto-Save Mechanism | Automatically saves data after add/edit/delete |
| 5 | Search by Name | Allows partial name-based searching |
| 6 | Delete Confirmation | Asks user confirmation before deleting records |
| 7 | OOP Encapsulation | Uses a dedicated `Student` class with private members |
| 8 | CSV File Storage | Stores data in `Student.csv` (Excel-compatible) |
| 9 | Email Validation | Ensures valid email format before saving |
| 10 | Cross-Platform Support | Works on Windows, Linux, and macOS |

---

## 📂 File Structure

```

📁 Student-Management-System
├── Student.csv        # Data storage file
├── main.cpp           # Source code
└── README.md          # Project documentation

````

---

## ▶️ How to Run

### Compile
```bash
g++ main.cpp -o sms
````

### Execute

```bash
./sms
```

---

## 💡 Technologies Used

* C++
* STL (`vector`, `string`, `fstream`)
* File Handling (CSV)
* Object-Oriented Programming
* ANSI Escape Codes (CLI Colors)

---

## 🧑‍💻 Author Information

```
Name   : Mukul Sharma
Roll   : Bt22ece134
Branch : ECE
Course : B.Tech
Email  : bt22ece134@iiitn.ac.in
```

---

## 📈 Future Enhancements

* SQLite database integration
* Role-based login (Admin / Student)
* Sorting and filtering options
* Export reports (CSV / PDF)
* GUI or Web-based interface

---

## ⭐ Conclusion

This project demonstrates **strong fundamentals in C++**, including **OOP design, file handling, data validation, and user interaction**.
It is well-suited for **academic submission, resume projects, and interview discussions**.

---

⭐ *If you like this project, feel free to fork or enhance it further!*
