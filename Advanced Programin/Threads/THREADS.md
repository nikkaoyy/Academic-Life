# 🧵 Java Threads – Concurrency Fundamentals

This repository contains examples and exercises demonstrating the use of **Threads** in Java.  
It explores how concurrent execution works, how multiple threads interact, and how thread coordination can affect program behavior.

---

## 🚀 Overview

A **thread** in Java represents a single path of execution within a program.  
Multithreading allows multiple tasks to run **simultaneously**, improving performance and responsiveness, especially in applications that involve waiting or background processing.

This repository includes examples covering:

- Thread creation using the `Thread` class.
- Concurrent execution (`start()` vs. `run()`).
- Thread scheduling and yielding (`Thread.yield()`).
- Sleep and synchronization basics.
- Practical examples showing interleaved output and race conditions.

---

## 🧩 Example Scenarios

- Employee attendance system: Multiple employees (threads) check in simultaneously.
- Race simulation: Turtle, rabbit, and hare compete concurrently, showing interleaved progress.
- Task distribution: Performing calculations or data processing in parallel.

## 🧠 Learning Outcomes

By exploring these examples, you will:

- Understand how threads are created and managed in Java.
- Observe how concurrent execution affects output.
- Learn to identify race conditions and manage shared resources.
- Gain a foundation for using more advanced concurrency tools like ExecutorService and synchronization primitives.
