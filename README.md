# Hospital-Emergency-Triage-System-Priority-Queue-
A C++ console application that manages patients waiting in a hospital emergency room using a Priority Queue implemented with a singly linked list. Patients are treated by the severity of their condition rather than their arrival time, so a critical patient is always seen before a minor case, even if the minor case arrived first.
# 🏥 Hospital Emergency Triage System

![Language](https://img.shields.io/badge/language-C%2B%2B-blue)
![Standard](https://img.shields.io/badge/C%2B%2B-11%2B-green)
![Data Structure](https://img.shields.io/badge/data%20structure-Priority%20Queue-orange)

A C++ console application that manages emergency room patients using a **Priority Queue** built on a singly linked list. Patients are treated by the severity of their condition, not by arrival time.

---

## 📑 Table of Contents

- [Overview](#-overview)
- [Problem Statement](#-problem-statement)
- [Why a Priority Queue?](#-why-a-priority-queue)
- [Priority Levels](#-priority-levels)
- [How It Works](#-how-it-works)
- [Data Structure Design](#-data-structure-design)
- [Getting Started](#-getting-started)
- [Sample Output](#-sample-output)
- [Complexity Analysis](#-complexity-analysis)
- [Concepts Demonstrated](#-concepts-demonstrated)
- [Project Structure](#-project-structure)
- [Author](#-author)

---

## 📌 Overview

This project is **Part B (Individual Project)** of **Lab 04: Priority Queue**. It applies the Priority Queue data structure to a real-world scenario: triaging patients in a hospital emergency room.

## ❗ Problem Statement

In an emergency room, patients arrive continuously with conditions of varying severity. Serving them in arrival order could delay life-saving treatment for critical patients. The system must:

- Assign every patient a severity-based priority
- Always treat the most critical patient first
- Treat patients with equal severity in the order they arrived

## 💡 Why a Priority Queue?

A standard queue only considers arrival order. A Priority Queue orders items by urgency, which is exactly what triage requires. The most critical patient is always at the front, so the next patient to treat is available in constant time.

## 🚦 Priority Levels

| Priority | Severity | Example |
|----------|----------|---------|
| 1 | Critical | Heart attack, severe bleeding |
| 2 | Serious | Broken arm, high fever |
| 3 | Minor | Sprained ankle, minor cut |

> A **smaller number means higher priority**.

## ⚙️ How It Works

Patients arrive in this order:

```
Usman → Sprained ankle  → Priority 3
Sara  → Heart attack    → Priority 1
Hina  → Broken arm      → Priority 2
Zain  → Severe bleeding → Priority 1
```

The queue arranges them as:

```
FRONT
  ↓
Sara (P1) → Zain (P1) → Hina (P2) → Usman (P3)
                                       ↑
                                     REAR
```

Treatment order: **Sara → Zain → Hina → Usman**

## 🧱 Data Structure Design

### `PatientNode`

| Field | Type | Description |
|-------|------|-------------|
| `patientID` | `int` | Unique patient identifier |
| `patientName` | `string` | Patient's name |
| `condition` | `string` | Medical condition |
| `priority` | `int` | Severity level (1–3) |
| `next` | `PatientNode*` | Pointer to the next node |

### `PatientPriorityQueue`

| Operation | Description |
|-----------|-------------|
| `Add()` | Inserts a patient at the correct position by priority (FIFO among equals) |
| `Remove()` | Removes and returns the highest-priority patient |
| `Peek()` | Views the next patient without removing them |
| `Size()` | Returns the number of waiting patients |
| `IsEmpty()` / `IsNotEmpty()` | Checks the queue status |
| `PrintQueue()` | Prints all waiting patients in priority order |
| Copy constructor | Deep copy of the queue |
| Assignment operator | Deep copy with cleanup of existing nodes |
| Destructor | Frees all dynamically allocated memory |

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting C++11 or later (g++, clang++, or MSVC)

### Clone the Repository

```bash
git clone https://github.com/[your-username]/[your-repo-name].git
cd [your-repo-name]
```

### Compile and Run

**Linux / macOS**

```bash
g++ -std=c++11 main.cpp -o triage_system
./triage_system
```

**Windows**

```bash
g++ -std=c++11 main.cpp -o triage_system.exe
triage_system.exe
```

## 🖥️ Sample Output

```
===== Waiting Patients =====
ID: 2 | Name: Sara | Condition: Heart attack | Priority: 1
ID: 4 | Name: Zain | Condition: Severe bleeding | Priority: 1
ID: 3 | Name: Hina | Condition: Broken arm | Priority: 2
ID: 1 | Name: Usman | Condition: Sprained ankle | Priority: 3

===== Treating Next Patient =====
Sara (Heart attack) - Priority 1

===== Remaining Patients =====
ID: 4 | Name: Zain | Condition: Severe bleeding | Priority: 1
ID: 3 | Name: Hina | Condition: Broken arm | Priority: 2
ID: 1 | Name: Usman | Condition: Sprained ankle | Priority: 3
```

## ⏱️ Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Add | O(n) |
| Remove | O(1) |
| Peek | O(1) |
| Display | O(n) |
| Size / status check | O(1) |

## 📚 Concepts Demonstrated

- Priority Queue implemented with a linked list
- Priority-based insertion that preserves FIFO order among equal priorities
- Dynamic memory allocation and deallocation
- Rule of Three (copy constructor, assignment operator, destructor)
- Applying a data structure to a real-world problem

## 📂 Project Structure

```
├── main.cpp
└── README.md
```

## 👤 Author

**[Your Name]**
[Your Roll Number / Student ID]
[Your University / Department]
Data Structures, Lab 04: Priority Queue
