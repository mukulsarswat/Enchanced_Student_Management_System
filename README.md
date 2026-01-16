# 🔐 Enchanced Student Management System 

A simple **Login + Admin-based Student Management System** built in **C++** using **Object-Oriented Programming (OOP)** principles.  
This project demonstrates **file handling, encapsulation, modular design, and access control**.

---

## 🎯 Features

- **Admin Login (username + password stored in file)**
  - Add new students
  - Edit student details
  - Delete students

- **General User (anyone logged in)**
  - View all students
  - Search students by roll number

- **Data Persistence**
  - Students stored in `Student.txt`
  - Admin credentials stored in `Admin.txt`

---

## 🗂️ Project Structure

```
StudentManagementSystem/
│
├── main.cpp              # Entry point (menu + program flow)
├── Student.h             # Student class (attributes + print method)
├── Student.cpp           # Implementation of Student class
├── StudentManager.h      # StudentManager class (CRUD operations)
├── StudentManager.cpp    # Implementation of StudentManager
├── Login.h               # Login class (admin authentication)
├── Login.cpp             # Implementation of Login class
│
├── Student.txt           # Student database (pipe-separated records)
└── Admin.txt             # Admin credentials (username password)
```

---

## 🧠 System Logic

### Login Flow
```
Login Menu
│
├── Admin Login
│     ├── username & password check (from Admin.txt)
│     └── If success → Admin Menu
│
└── Exit
```

### Admin Menu
```
1. Add Student
2. Display Students
3. Search Student
4. Edit Student
5. Delete Student
6. Exit
```

---

## 👨‍💻 Classes Overview

### `Student`
- Attributes: `name, rollNo, branch, course, email`
- Methods:
  - Constructor
  - `print()` → Display student details

### `StudentManager`
- Maintains a `vector<Student>`
- Methods:
  - `loadFromFile()` → Load students from `Student.txt`
  - `saveToFile()` → Save students to `Student.txt`
  - `addStudent()` → Add new student
  - `displayStudents()` → Show all students
  - `searchStudent()` → Search by roll number
  - `editStudent()` → Update student details
  - `deleteStudent()` → Remove student

### `Login`
- Method:
  - `adminLogin()` → Authenticate using `Admin.txt`

---

## 📝 File Formats

### `Admin.txt`
```
admin mukulsarswat
```

### `Student.txt`
```
Mukul Sharma|BT22ECE134|ECE|B.Tech|mk2739sarswat@gmail.com
```

---

## 🚀 Compilation & Execution

### Compile
```bash
g++ main.cpp Student.cpp StudentManager.cpp Login.cpp -o sms
```

### Run
```bash
./sms
```

---

## 📖 Example Run

```
1. Admin Login
2. Exit
Choice: 1
Username: mukulsarswat
Password: mukul

1.Add 2.Display 3.Search 4.Edit 5.Delete 6.Exit
Choice: 1
Name: Mukul Sharma
Roll: BT22ECE134
Branch: ECE
Course: B.Tech
Email: mk2739sarswat@gmail.com
```

---

## 🧩 Key Concepts Demonstrated

- **Encapsulation** → Student data hidden inside `Student` class
- **Abstraction** → `StudentManager` provides high-level operations (CRUD)
- **File Handling** → Persistent storage in `.txt` files
- **Access Control** → Only admin can modify student records
- **Modularity** → Separate `.h` and `.cpp` files for clean design

---

## ✅ Future Improvements

- Add **multiple user roles** (e.g., Student login--> Read and Search only)
- Encrypt admin password instead of plain text
- Database (MySQL)
