# 🏦 Sistema ATM - Proyecto de Programación Avanzada

<div align="center">

![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)
![Python](https://img.shields.io/badge/Python-3.8+-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Flask](https://img.shields.io/badge/Flask-2.0+-000000?style=for-the-badge&logo=flask&logoColor=white)

**Sistema de Cajero Automático con Arquitectura Cliente-Servidor**

[Ver Repositorio Completo →](https://github.com/nikkaoyy/Cajero-ATM)

</div>

---

## 📖 Sobre el Proyecto

Sistema bancario completo de cajero automático (ATM) desarrollado como proyecto final para el curso de **Programación Avanzada** en la Universidad Distrital. El proyecto implementa una arquitectura cliente-servidor profesional con REST API, aplicando patrones de diseño y principios SOLID.

### 🎯 Objetivos de Aprendizaje Cumplidos

✅ Implementación de patrones de diseño (Singleton, Factory, MVC)  
✅ Desarrollo de API REST con Flask  
✅ Persistencia de datos con ORM (SQLAlchemy)  
✅ Arquitectura en capas (Presentation, Business, Data)  
✅ Aplicación de principios SOLID  
✅ Frontend SPA con JavaScript vanilla  
✅ Gestión de seguridad (bcrypt, sesiones)  
✅ Testing y validación de API  

---

## 🚀 Acceso Rápido

### 🔗 Repositorio Principal del Proyecto

👉 **[github.com/nikkaoyy/Cajero-ATM](https://github.com/nikkaoyy/Cajero-ATM)**

El repositorio completo contiene:
- 📂 Código fuente completo (Backend + Frontend)
- 📘 Documentación técnica detallada
- 🧪 Suite de pruebas automatizadas
- 📊 Diagramas de arquitectura
- 🎓 Guías de instalación y uso
- 📝 Documentación de API

---

## ✨ Características Principales

### 💳 Funcionalidades Implementadas

| Característica | Descripción | Estado |
|----------------|-------------|--------|
| 🔐 **Autenticación** | Login con tarjeta y PIN (bcrypt) | ✅ |
| 💰 **Consulta de Saldo** | Ver saldo y límites disponibles | ✅ |
| 💸 **Retiros** | Retiro con validación de límites diarios | ✅ |
| 💵 **Depósitos** | Depósito en efectivo y cheque | ✅ |
| 🧾 **Pago de Recibos** | Pago de servicios públicos | ✅ |
| 🎟️ **Compra de Entradas** | Compra con código generado | ✅ |
| 📊 **Historial** | Registro completo de operaciones | ✅ |
| 🏧 **Múltiples Cajeros** | Sistema con varios cajeros | ✅ |

### 🔒 Seguridad

- Hash de PINs con **bcrypt**
- Sesiones con timeout automático (30 min)
- Bloqueo tras 3 intentos fallidos
- Validación de entrada en backend y frontend
- CORS configurado restrictivamente

---

## 🏗️ Arquitectura Técnica

```
┌─────────────────────────────────────────┐
│         FRONTEND (JavaScript)            │
│  • SPA con Fetch API                    │
│  • Interfaz ATM interactiva             │
│  • Validación de entrada                │
└──────────────┬──────────────────────────┘
               │ REST API (HTTP/JSON)
               ▼
┌─────────────────────────────────────────┐
│         BACKEND (Flask + Python)         │
│                                          │
│  ┌────────────────────────────────┐    │
│  │      API Layer (routes.py)     │    │
│  │   12 endpoints REST            │    │
│  └──────────┬─────────────────────┘    │
│             │                            │
│  ┌──────────▼─────────────────────┐    │
│  │   Services (Business Logic)    │    │
│  │ • AutentificacionService       │    │
│  │ • BancoService                 │    │
│  └──────────┬─────────────────────┘    │
│             │                            │
│  ┌──────────▼─────────────────────┐    │
│  │   Models (SQLAlchemy ORM)      │    │
│  │ 6 modelos + herencia           │    │
│  └──────────┬─────────────────────┘    │
└─────────────┼──────────────────────────┘
              │ SQL
              ▼
    ┌──────────────────┐
    │  MySQL Database  │
    │   6 tablas       │
    └──────────────────┘
```

### Tecnologías Utilizadas

**Backend:**
- Python 3.8+
- Flask 3.0 (Framework web)
- SQLAlchemy 2.0 (ORM)
- bcrypt (Hashing de PINs)
- Flask-CORS (CORS management)

**Frontend:**
- HTML5 + CSS3
- JavaScript ES6+ (Vanilla)
- Fetch API (HTTP requests)

**Base de Datos:**
- MySQL 5.7+
- 6 tablas relacionales
- Constraints de integridad

---

## 📊 Patrones y Principios Aplicados

### 🎨 Patrones de Diseño

| Patrón | Implementación | Ubicación |
|--------|----------------|-----------|
| **Singleton** | Instancia única para registro de operaciones | `RegistroOperaciones.py` |
| **Factory** | Creación centralizada de tarjetas | `Banco.emitir_tarjeta()` |
| **MVC** | Separación Modelo-Vista-Controlador | Todo el backend |
| **Repository** | Abstracción de acceso a datos | Modelos SQLAlchemy |
| **Decorator** | Validación de autenticación | `@requiere_autenticacion` |

### 🧱 Principios SOLID

✅ **Single Responsibility**: Cada clase tiene una única responsabilidad  
✅ **Open/Closed**: Extensible sin modificar código existente  
✅ **Liskov Substitution**: Subclases de `Operacion` son intercambiables  
✅ **Interface Segregation**: Interfaces específicas por necesidad  
✅ **Dependency Inversion**: Dependencia de abstracciones (Services)  

---

## 📈 Resultados de Pruebas

El sistema incluye una suite completa de pruebas automatizadas:

```bash
python scripts/test_api.py
```

**Resultado:**
```
============================================================
  RESUMEN DE PRUEBAS
============================================================
Health Check...................................... ✅ PASS
Listar Cajeros.................................... ✅ PASS
Login............................................. ✅ PASS
Consultar Saldo................................... ✅ PASS
Realizar Retiro................................... ✅ PASS
Realizar Depósito................................. ✅ PASS
Pago de Recibo.................................... ✅ PASS
Compra de Entradas................................ ✅ PASS
Historial de Operaciones.......................... ✅ PASS
Estadísticas...................................... ✅ PASS
Logout............................................ ✅ PASS

Total: 12/12 pruebas exitosas ✅
```

---

## 🎓 Conceptos de Programación Avanzada

### POO (Programación Orientada a Objetos)
- ✅ Encapsulamiento con atributos privados
- ✅ Herencia (Operacion → Retiro, Deposito, etc.)
- ✅ Polimorfismo (método `ejecutar()` en subclases)
- ✅ Abstracción (clases base abstractas)

### Arquitectura de Software
- ✅ Arquitectura en 3 capas (Presentation, Business, Data)
- ✅ REST API con endpoints documentados
- ✅ Cliente-Servidor
- ✅ ORM para abstracción de persistencia

### Buenas Prácticas
- ✅ Código documentado con docstrings
- ✅ Type hints en Python
- ✅ Manejo de excepciones robusto
- ✅ Validación de entrada en múltiples capas
- ✅ Transacciones con rollback automático

---

## 📸 Capturas de Pantalla

### Pantalla de Login
```
┌─────────────────────────────────────┐
│    🏦 BANCO DEL SOL - ATM           │
├─────────────────────────────────────┤
│                                     │
│  Número de Tarjeta:                 │
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
│  [    Iniciar Sesión    ]          │
│  [       Cancelar       ]          │
└─────────────────────────────────────┘
```

### Menú Principal
```
┌─────────────────────────────────────┐
│  Hola, Juan                         │
│  Seleccione una operación      [⎋] │
├─────────────────────────────────────┤
│                                     │
│  ┌──────────┐  ┌──────────┐       │
│  │    💰    │  │    💸    │       │
│  │  Saldo   │  │  Retiro  │       │
│  └──────────┘  └──────────┘       │
│                                     │
│  ┌──────────┐  ┌──────────┐       │
│  │    💵    │  │    🧾    │       │
│  │ Depósito │  │   Pago   │       │
│  └──────────┘  └──────────┘       │
│                                     │
│  ┌──────────┐  ┌──────────┐       │
│  │    🎟️    │  │    ❓    │       │
│  │ Entradas │  │  Ayuda   │       │
│  └──────────┘  └──────────┘       │
└─────────────────────────────────────┘
```

---

## 📚 Documentación Completa

Para más información, consulta el **[repositorio principal](https://github.com/nikkaoyy/Cajero-ATM)** que incluye:

📖 **Documentación técnica completa**
- Arquitectura detallada
- Diagramas UML (clases, secuencia, ER)
- Explicación de cada componente
- Guía de desarrollo

🚀 **Guías de instalación**
- Setup paso a paso
- Configuración de base de datos
- Troubleshooting

📡 **API Documentation**
- Todos los endpoints documentados
- Ejemplos de requests/responses
- Códigos de error

🧪 **Testing**
- Suite de pruebas automatizadas
- Instrucciones para ejecutar tests
- Casos de prueba documentados

---

## 👨‍💻 Equipo de Desarrollo

**Desarrolladores:**
- Nicolás Martínez Pineda ([@nikkaoyy](https://github.com/nikkaoyy))
- Samuele Leonardo Acosta Cruz
- David Mateo Días Pérez

**Institución:**  
Universidad Distrital Francisco José de Caldas  
Facultad de Ingeniería  
Ingeniería de Sistemas

**Curso:**  
Programación Avanzada - 2025-1

---

## 📊 Métricas del Proyecto

| Métrica | Valor |
|---------|-------|
| **Líneas de código** | ~5,000+ |
| **Archivos** | 30+ |
| **Commits** | 50+ |
| **Tiempo de desarrollo** | 4 semanas |
| **Tests automatizados** | 12 |
| **Endpoints API** | 12 |
| **Modelos ORM** | 6 |
| **Tablas BD** | 6 |

---

## 🔗 Enlaces Importantes

- 🏠 **[Repositorio Principal](https://github.com/nikkaoyy/Cajero-ATM)** - Código fuente completo
- 📘 **[Documentación Técnica](https://github.com/nikkaoyy/Cajero-ATM/blob/master/DOCUMENTACION.md)** - Arquitectura detallada
- 🐛 **[Issues](https://github.com/nikkaoyy/Cajero-ATM/issues)** - Reportar bugs o sugerencias
- 📧 **Contacto**: nmartinezp@udistrital.edu.co

---

## 🌟 Logros del Proyecto

✅ Sistema funcional al 100%  
✅ 12/12 pruebas automatizadas pasadas  
✅ Arquitectura escalable y mantenible  
✅ Código documentado y seguimiento de estándares  
✅ Seguridad implementada (bcrypt, sesiones, validaciones)  
✅ API REST completamente funcional  
✅ Frontend responsive e intuitivo  
✅ Patrones de diseño aplicados correctamente  

---

## 📜 Licencia

Este proyecto está bajo la **GNU General Public License v3.0 (GPL-3.0)**.

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

### Resumen de la Licencia

✅ **Software Libre**: Puedes usar, estudiar, compartir y mejorar este software  
🔓 **Código Abierto**: Todo el código fuente está disponible públicamente  
↩️ **Copyleft**: Las modificaciones deben compartirse bajo la misma licencia  
🎓 **Uso Académico**: Perfecto para aprendizaje y enseñanza  

Para detalles completos, consulta el [repositorio principal](https://github.com/nikkaoyy/Cajero-ATM/blob/master/LICENSE).

---

<div align="center">

**⭐ [Ver Código Completo →](https://github.com/nikkaoyy/Cajero-ATM) ⭐**

---

*Proyecto desarrollado como parte del curso de Programación Avanzada*  
*Universidad Distrital Francisco José de Caldas - 2025*

</div>
