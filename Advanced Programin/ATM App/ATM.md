# 🏦 ATM System - Advanced Programming Project

<div align="center">

![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)
![Python](https://img.shields.io/badge/Python-3.8+-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Flask](https://img.shields.io/badge/Flask-2.0+-000000?style=for-the-badge&logo=flask&logoColor=white)

**Automated Teller Machine System with Client-Server Architecture**

[View Complete Repository →](https://github.com/nikkaoyy/Cajero-ATM)

</div>

---

## 📖 About the Project

Complete ATM banking system developed as a final project for the **Advanced Programming** course at Universidad Distrital. The project implements a professional client-server architecture with REST API, applying design patterns and SOLID principles.

### 🎯 Accomplished Learning Objectives

✅ Implementation of design patterns (Singleton, Factory, MVC)  
✅ REST API development with Flask  
✅ Data persistence with ORM (SQLAlchemy)  
✅ Layered architecture (Presentation, Business, Data)  
✅ Application of SOLID principles  
✅ SPA frontend with vanilla JavaScript  
✅ Security management (bcrypt, sessions)  
✅ API testing and validation  

---

## 🚀 Quick Access

### 🔗 Main Project Repository

👉 **[github.com/nikkaoyy/Cajero-ATM](https://github.com/nikkaoyy/Cajero-ATM)**

The complete repository contains:
- 📂 Complete source code (Backend + Frontend)
- 📘 Detailed technical documentation
- 🧪 Automated test suite
- 📊 Architecture diagrams
- 🎓 Installation and usage guides
- 📝 API documentation

---

## ✨ Main Features

### 💳 Implemented Functionalities

| Feature | Description | Status |
|---------|-------------|--------|
| 🔐 **Authentication** | Login with card and PIN (bcrypt) | ✅ |
| 💰 **Balance Inquiry** | View balance and available limits | ✅ |
| 💸 **Withdrawals** | Withdrawal with daily limit validation | ✅ |
| 💵 **Deposits** | Cash and check deposits | ✅ |
| 🧾 **Bill Payments** | Utility service payments | ✅ |
| 🎟️ **Ticket Purchases** | Purchase with generated code | ✅ |
| 📊 **History** | Complete operation log | ✅ |
| 🏧 **Multiple ATMs** | System with multiple ATMs | ✅ |

### 🔒 Security

- PIN hashing with **bcrypt**
- Sessions with automatic timeout (30 min)
- Blocking after 3 failed attempts
- Input validation on backend and frontend
- Restrictive CORS configuration

---

## 🏗️ Technical Architecture

```
┌─────────────────────────────────────────┐
│         FRONTEND (JavaScript)            │
│  • SPA with Fetch API                   │
│  • Interactive ATM interface            │
│  • Input validation                     │
└──────────────┬──────────────────────────┘
               │ REST API (HTTP/JSON)
               ▼
┌─────────────────────────────────────────┐
│         BACKEND (Flask + Python)         │
│                                          │
│  ┌────────────────────────────────┐    │
│  │      API Layer (routes.py)     │    │
│  │   12 REST endpoints            │    │
│  └──────────┬─────────────────────┘    │
│             │                            │
│  ┌──────────▼─────────────────────┐    │
│  │   Services (Business Logic)    │    │
│  │ • AuthenticationService        │    │
│  │ • BankService                  │    │
│  └──────────┬─────────────────────┘    │
│             │                            │
│  ┌──────────▼─────────────────────┐    │
│  │   Models (SQLAlchemy ORM)      │    │
│  │ 6 models + inheritance         │    │
│  └──────────┬─────────────────────┘    │
└─────────────┼──────────────────────────┘
              │ SQL
              ▼
    ┌──────────────────┐
    │  MySQL Database  │
    │   6 tables       │
    └──────────────────┘
```

### Technologies Used

**Backend:**
- Python 3.8+
- Flask 3.0 (Web framework)
- SQLAlchemy 2.0 (ORM)
- bcrypt (PIN hashing)
- Flask-CORS (CORS management)

**Frontend:**
- HTML5 + CSS3
- JavaScript ES6+ (Vanilla)
- Fetch API (HTTP requests)

**Database:**
- MySQL 5.7+
- 6 relational tables
- Integrity constraints

---

## 📊 Applied Patterns and Principles

### 🎨 Design Patterns

| Pattern | Implementation | Location |
|---------|----------------|----------|
| **Singleton** | Single instance for operation registry | `RegistroOperaciones.py` |
| **Factory** | Centralized card creation | `Banco.emitir_tarjeta()` |
| **MVC** | Model-View-Controller separation | Entire backend |
| **Repository** | Data access abstraction | SQLAlchemy Models |
| **Decorator** | Authentication validation | `@requiere_autenticacion` |

### 🧱 SOLID Principles

✅ **Single Responsibility**: Each class has a single responsibility  
✅ **Open/Closed**: Extensible without modifying existing code  
✅ **Liskov Substitution**: `Operation` subclasses are interchangeable  
✅ **Interface Segregation**: Specific interfaces per need  
✅ **Dependency Inversion**: Dependency on abstractions (Services)  

---

## 📈 Test Results

The system includes a complete automated test suite:

```bash
python scripts/test_api.py
```

**Result:**
```
============================================================
  TEST SUMMARY
============================================================
Health Check...................................... ✅ PASS
List ATMs......................................... ✅ PASS
Login............................................. ✅ PASS
Check Balance..................................... ✅ PASS
Perform Withdrawal................................ ✅ PASS
Perform Deposit................................... ✅ PASS
Bill Payment...................................... ✅ PASS
Ticket Purchase................................... ✅ PASS
Transaction History............................... ✅ PASS
Statistics........................................ ✅ PASS
Logout............................................ ✅ PASS

Total: 12/12 successful tests ✅
```

---

## 🎓 Advanced Programming Concepts

### OOP (Object-Oriented Programming)
- ✅ Encapsulation with private attributes
- ✅ Inheritance (Operation → Withdrawal, Deposit, etc.)
- ✅ Polymorphism (`execute()` method in subclasses)
- ✅ Abstraction (abstract base classes)

### Software Architecture
- ✅ 3-layer architecture (Presentation, Business, Data)
- ✅ REST API with documented endpoints
- ✅ Client-Server
- ✅ ORM for persistence abstraction

### Best Practices
- ✅ Code documented with docstrings
- ✅ Python type hints
- ✅ Robust exception handling
- ✅ Input validation at multiple layers
- ✅ Transactions with automatic rollback

---

## 📸 Screenshots

### Login Screen
```
┌─────────────────────────────────────┐
│    🏦 BANCO DEL SOL - ATM           │
├─────────────────────────────────────┤
│                                     │
│  Card Number:                       │
│  ┌───────────────────────────────┐ │
│  │ XXXX-XXXX-XXXX-XXXX          │ │
│  └───────────────────────────────┘ │
│                                     │
│  PIN:                               │
│  ┌───────────────────────────────┐ │
│  │ ••••                          │ │
│  └───────────────────────────────┘ │
│                                     │
│  ┌─┬─┬─┐                           │
│  │1│2│3│  Numpad                   │
│  ├─┼─┼─┤                           │
│  │4│5│6│                           │
│  ├─┼─┼─┤                           │
│  │7│8│9│                           │
│  ├─┼─┼─┤                           │
│  │⌫│0│C│                           │
│  └─┴─┴─┘                           │
│                                     │
│  [      Login       ]               │
│  [      Cancel      ]               │
└─────────────────────────────────────┘
```

### Main Menu
```
┌─────────────────────────────────────┐
│  Hello, Juan                        │
│  Select an operation           [⎋] │
├─────────────────────────────────────┤
│                                     │
│  ┌──────────┐  ┌──────────┐       │
│  │    💰    │  │    💸    │       │
│  │ Balance  │  │ Withdraw │       │
│  └──────────┘  └──────────┘       │
│                                     │
│  ┌──────────┐  ┌──────────┐       │
│  │    💵    │  │    🧾    │       │
│  │ Deposit  │  │ Payment  │       │
│  └──────────┘  └──────────┘       │
│                                     │
│  ┌──────────┐  ┌──────────┐       │
│  │    🎟️    │  │    ❓    │       │
│  │ Tickets  │  │   Help   │       │
│  └──────────┘  └──────────┘       │
└─────────────────────────────────────┘
```

---

## 📚 Complete Documentation

For more information, visit the **[main repository](https://github.com/nikkaoyy/Cajero-ATM)** which includes:

📖 **Complete technical documentation**
- Detailed architecture
- UML diagrams (classes, sequence, ER)
- Explanation of each component
- Development guide

🚀 **Installation guides**
- Step-by-step setup
- Database configuration
- Troubleshooting

📡 **API Documentation**
- All documented endpoints
- Request/response examples
- Error codes

🧪 **Testing**
- Automated test suite
- Test execution instructions
- Documented test cases

---

## 👨‍💻 Development Team

**Developers:**
- Nicolás Martínez Pineda ([@nikkaoyy](https://github.com/nikkaoyy))
- Samuele Leonardo Acosta Cruz ([@Samuelleon2810](https://github.com/Samuelleon2810))
- David Mateo Días Pérez

**Institution:**  
Universidad Distrital Francisco José de Caldas  
Faculty of Engineering  
Systems Engineering

**Course:**  
Advanced Programming - 2025-1

---

## 📊 Project Metrics

| Metric | Value |
|--------|-------|
| **Lines of code** | ~5,000+ |
| **Files** | 30+ |
| **Commits** | 50+ |
| **Development time** | 4 weeks |
| **Automated tests** | 12 |
| **API endpoints** | 12 |
| **ORM models** | 6 |
| **DB tables** | 6 |

---

## 🔗 Important Links

- 🏠 **[Main Repository](https://github.com/nikkaoyy/Cajero-ATM)** - Complete source code
- 📘 **[Technical Documentation](https://github.com/nikkaoyy/Cajero-ATM/blob/master/DOCUMENTACION.md)** - Detailed architecture
- 🐛 **[Issues](https://github.com/nikkaoyy/Cajero-ATM/issues)** - Report bugs or suggestions
- 📧 **Contact**: nmartinezp@udistrital.edu.co

---

## 🌟 Project Achievements

✅ 100% functional system  
✅ 12/12 automated tests passed  
✅ Scalable and maintainable architecture  
✅ Documented code following standards  
✅ Implemented security (bcrypt, sessions, validations)  
✅ Fully functional REST API  
✅ Responsive and intuitive frontend  
✅ Correctly applied design patterns  

---

## 📜 License

This project is under the **GNU General Public License v3.0 (GPL-3.0)**.

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

### License Summary

✅ **Free Software**: You can use, study, share, and improve this software  
🔓 **Open Source**: All source code is publicly available  
↩️ **Copyleft**: Modifications must be shared under the same license  
🎓 **Academic Use**: Perfect for learning and teaching  

For complete details, see the [main repository](https://github.com/nikkaoyy/Cajero-ATM/blob/master/LICENSE).

---

<div align="center">

**⭐ [View Complete Code →](https://github.com/nikkaoyy/Cajero-ATM) ⭐**

---

*Project developed as part of the Advanced Programming course*  
*Universidad Distrital Francisco José de Caldas - 2025*

</div>
