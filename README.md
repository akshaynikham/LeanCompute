# 🚀 LeanCompute

LeanCompute is a lightweight, Linux-first CLI tool written in C that analyzes your system hardware and evaluates its readiness to run modern AI workloads.

---

## 🎯 Purpose

Many developers struggle with hardware limitations when trying to run modern applications (especially AI/LLMs).
LeanCompute helps you:

* Understand your system capabilities
* Evaluate AI readiness
* Identify hardware limitations
* Get clear, human-readable insights

---

## ⚙️ Features

* 🔍 Detect system architecture (32-bit / 64-bit)
* 🧠 CPU analysis (cores, threads)
* 💾 RAM detection
* ⚡ CPU feature detection (AVX / AVX2)
* 📊 AI Readiness Score (ARS)
* 🧾 Human-readable system summary
* ❗ Explanation engine (reasons for limitations)

---

## 🧠 AI Readiness Score (ARS)

LeanCompute classifies your system into:

| Score         | Meaning                        |
| ------------- | ------------------------------ |
| ❌ NOT CAPABLE | Cannot run modern AI workloads |
| ⚠ LIMITED     | Can run with constraints       |
| ✔ GOOD        | Suitable for AI workloads      |

---

## 🖥️ Example Output

```
System Summary
--------------
CPU: x86_64 (3 cores / 3 threads)
RAM: 7 GB
AVX: Yes
AVX2: Yes

AI Readiness: ⚠ LIMITED

Reasons:
- RAM is below recommended (8GB)
- CPU threads are below recommended (4)
```

---

## 🛠️ Installation & Usage

### 1️⃣ Clone the repository

```
git clone https://github.com/akshaynikham/LeanCompute.git
cd LeanCompute
```

---

### 2️⃣ Build the project

```
make
```

---

### 3️⃣ Run the tool

```
./leancompute
```

---

### 4️⃣ Clean build files

```
make clean
```

---

## 📁 Project Structure

```
LeanCompute/
│
├── src/                # Source files (.c)
├── include/            # Header files (.h)
├── Makefile            # Build automation
├── README.md
```

---

## 🧩 How It Works

```
Hardware → Detection → Analysis → Formatting → Output
```

1. System data is collected from `/proc`
2. Hardware capabilities are evaluated
3. AI Readiness Score is computed
4. Reasons for limitations are generated
5. Output is formatted for user readability

---

## 🚧 Future Improvements

* JSON output (`--json`)
* CLI arguments (`--help`, flags)
* Recommendation engine
* GPU detection
* Cross-platform support (Windows)

---

## 👨‍💻 Author

Akshay Nikham

---

## 🌟 Vision

LeanCompute aims to become a minimal, efficient, and intelligent system analyzer that helps developers understand and optimize their hardware for modern computing workloads.

---
