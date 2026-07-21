# 🏦 Bank Management System in C

A simple **Bank Management System** developed in **C** using **Structures** and **File Handling**. This project demonstrates basic banking operations such as account creation, deposits, withdrawals, balance enquiry, and displaying all account records. It stores account information permanently using binary files.

---

## 📌 Features

- ✅ Create a New Account
- 💰 Deposit Money
- 💸 Withdraw Money
- 🔍 Balance Enquiry
- 📋 Display All Accounts
- 💾 Permanent Data Storage using File Handling
- 📂 Uses Binary Files (`accounts.dat`)

---

## 🛠️ Technologies Used

- C Programming Language
- Structures (`struct`)
- Functions
- File Handling (`fopen()`, `fread()`, `fwrite()`, `fclose()`)
- Loops and Conditional Statements
- Switch Case

---

## 📁 Project Structure

```
Bank-Management-System/
│
├── main.c              # Main source code
├── accounts.dat        # Binary file storing account records (generated automatically)
├── accounts.txt        # Optional readable backup (if implemented)
└── README.md
```

---

## 📚 Concepts Covered

This project demonstrates the following C programming concepts:

- Structures
- Functions
- Menu Driven Programming
- Binary File Handling
- Reading and Writing Files
- Updating Records using Temporary File
- Searching Records
- Loops
- Switch Case
- Modular Programming

---

## ⚙️ How It Works

1. User selects an option from the menu.
2. The program calls the corresponding function.
3. Account information is stored using structures.
4. Records are saved permanently in `accounts.dat`.
5. During Deposit and Withdrawal:
   - All records are copied to a temporary file.
   - The required account is updated.
   - The original file is deleted.
   - The temporary file is renamed to `accounts.dat`.

This ensures that all account records remain safe while updating only the required account.

---

## 🖥️ Menu

```
========== BANK MANAGEMENT SYSTEM ==========

1. Create Account
2. Deposit Money
3. Withdraw Money
4. Balance Enquiry
5. Display All Accounts
6. Exit
```

---

## 💡 Example

### Creating an Account

```
Enter Account Number : 1001
Enter Customer Name  : Karan
Enter Initial Balance: 5000
```

### Deposit

```
Account Number : 1001
Amount : 500
```

Updated Balance

```
5500
```

---

## 🚀 How to Compile

Using GCC

```bash
gcc main.c -o bank
```

Run

```bash
./bank
```

For Windows

```bash
gcc main.c -o bank.exe
bank.exe
```

---

## 📖 Learning Outcomes

This project helped in understanding:

- C Programming Fundamentals
- Structures
- File Handling
- Binary Files
- Menu Driven Programs
- Modular Programming
- Record Management

---

## 🔮 Future Improvements

- Login Authentication
- Account Deletion
- Money Transfer Between Accounts
- Interest Calculation
- Password Protected Accounts
- Transaction History
- Search by Customer Name
- Graphical User Interface (GUI)

---

## 👨‍💻 Author

**Karan Angane**

CSE (Artificial Intelligence & Machine Learning)

---

## ⭐ If you found this project useful, don't forget to star the repository!
