
# 🧠 Dining Philosophers Problem

## Overview

This project is an implementation of the classic **Dining Philosophers Problem** using multithreading in C. It focuses on **synchronization**, **deadlock avoidance**, and **race condition prevention** — all fundamental concepts in concurrent programming.

---

## 🧩 Problem Description

Five philosophers sit at a round table. Each philosopher alternates between the following actions:

- **Thinking**
- **Eating**
- **Sleeping**

Between each pair of philosophers is a **single fork**, and **each philosopher needs two forks** (left and right) to eat. Forks are shared resources and must be accessed safely to avoid:

- **Deadlocks**
- **Race conditions**
- **Starvation**

---

## ✅ Project Requirements (Subject Summary)

- Each philosopher is implemented as an independent thread.
- The philosopher’s lifecycle includes:
  1. Picking up forks
  2. Eating
  3. Putting down forks
  4. Sleeping
  5. Thinking
- A philosopher **dies** if they don't eat within `time_to_die` milliseconds.
- The simulation stops immediately when a philosopher dies.
- Input arguments:

  ```sh
  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  ```

---

## ⚙️ Compilation

```sh
make
```

---

## 🚀 How to Run

```sh
./philo 5 800 200 200
```

| Argument | Description |
|----------|-------------|
| `5`      | Number of philosophers |
| `800`    | Time to die (ms) |
| `200`    | Time to eat (ms) |
| `200`    | Time to sleep (ms) |
| `[opt]`  | Minimum times each philosopher must eat (optional) |

---

## 🧪 Sample Tests

```sh
./philo 4 410 200 200
./philo 5 800 200 200 3
```

---

## 🛠 Technologies

- C Language
- POSIX Threads (pthread)
- Mutex-based synchronization
- High-resolution time control (using `gettimeofday`)

---

## 🧠 Key Learning Points

- Thread-safe data structures
- Deadlock prevention strategies (e.g., odd/even fork ordering)
- Detection and prevention of race conditions (Helgrind)
- Monitoring threads for life/death management

---

## 🔍 Debugging Tip

To check for race conditions with Valgrind:

```sh
valgrind --tool=helgrind ./philo 5 800 200 200
```

---

## 📁 Example Directory Structure

```
philo/
├── Makefile
├── include/
│   └── philo.h
├── srcs/
│   ├── main.c
│   ├── init.c
│   ├── routine.c
│   ├── utils.c
└── README.md
```

---

## ⚠️ Notes

- Handle the **special case** when only one philosopher exists (only one fork).
- Make sure no two philosophers access the same fork at the same time.
- `usleep()` may not guarantee precise timing in very small values — consider adding custom timing adjustments.

---

## 📚 References

- [Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- POSIX pthreads documentation
- 42 school subject (internal)

---

## 👤 Author

Rento Yabuki  
Master’s Student in Applied Chemistry (on leave)  
System Developer at Nozomi AI | Student at 42Tokyo

---

