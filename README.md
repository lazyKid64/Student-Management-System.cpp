
# 🎓 Student Management System — IIT Roorkee

A console-based **C++ Student Management System** designed for managing Mechanical Engineering students at IIT Roorkee. It reads student data from a flat text file and provides a rich menu-driven interface for querying, sorting, and analyzing records.

---

## 📁 Project Structure

```
├── sms.cpp          # Main source file (C++ application)
├── students.txt     # Student data file (150 records)
└── sms.exe          # Pre-compiled Windows executable
```

---

## ✨ Features

| # | Feature | Description |
|---|---------|-------------|
| 1 | **View All Students** | Lists all enrolled students with their details |
| 2 | **Sort by CGPA** | Displays students ranked from highest to lowest CGPA |
| 3 | **Filter by CGPA Threshold** | Shows students at or above a given CGPA |
| 4 | **Count Above CGPA** | Counts students meeting a CGPA cutoff |
| 5 | **Average CGPA** | Computes the batch average CGPA |
| 6 | **Top N Students** | Lists the top N performers |
| 7 | **Search by Name** | Partial/full name search across all records |
| 8 | **Department Rank List** | Department-wise rank listing |
| 9 | **Grade Distribution** | Breakdown by grade category (A+, B+, B, C+, Probation) |
| 10 | **Probation List** | Lists all students with CGPA below 6.0 |
| 11 | **Placement Eligibility** | Checks if a student (by enrollment no.) meets the 7.0 CGPA cutoff |

---

## 🗂️ Data Format (`students.txt`)

Each line follows this format:

```
<EnrollmentNo> <Full Name> (<Branch>) <CGPA>
```

**Example:**
```
25117007 Adarsh Pandey (Mechanical Engineering) 9.6
25117082 Rahul Nambiar (Mechanical Engineering) 9.8
```

The dataset currently contains **150 students** from the Mechanical Engineering department (Batch 2025, Roll Numbers: 25117001–25117150).

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (g++ / MSVC / Clang) supporting C++11 or later
- `students.txt` must be in the **same directory** as the executable

### Compile

```bash
g++ sms.cpp -o sms
```

### Run

**Linux / macOS:**
```bash
./sms
```

**Windows:**
```bash
sms.exe
```
> A pre-compiled `sms.exe` is included for Windows users.

---

## 🧠 Implementation Details

- **Language:** C++
- **Data Storage:** Plain text file (`students.txt`), loaded into memory at startup
- **Data Structure:** `std::vector<Student>`
- **Sorting Algorithm:** Bubble Sort (descending by CGPA)
- **OOP Design:**
  - `Student` class — encapsulates enrollment number, name, branch, and CGPA; custom `>>` stream operator for file parsing
  - `StudentManager` class — handles file I/O, all queries, and the interactive menu loop

### Grade Distribution Thresholds

| Grade | Label | CGPA Range |
|-------|-------|------------|
| A+ | Excellent | ≥ 9.0 |
| B+ | Very Good | 8.0 – 8.9 |
| B  | Good | 7.0 – 7.9 |
| C+ | Average | 6.0 – 6.9 |
| — | Probation | < 6.0 |

---

## 📌 Notes

- The application reads `students.txt` from the **current working directory** — ensure this file is present before running.
- Placement eligibility threshold is set at **CGPA ≥ 7.0**.
- The system is currently scoped to a single department (Mechanical Engineering). Multi-department support would require extending the data model.

---

## 👨‍💻 Author

Made with ❤️ for IIT Roorkee — *Thank you :)*
