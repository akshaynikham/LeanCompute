# LeanCompute

LeanCompute is a lightweight, Linux-first system utility written in C that analyzes hardware capabilities and estimates readiness for modern AI workloads.

## 🚀 Overview

Many developers struggle to determine whether their system can efficiently run modern software such as large language models (LLMs) or resource-intensive applications. LeanCompute aims to solve this by inspecting system hardware and providing a structured view of compute capability.

## ⚙️ Current Features

* Detects OS architecture (32-bit / 64-bit)
* Identifies CPU architecture (e.g., x86_64)
* Calculates CPU parallelism:

  * Core count
  * Thread count
* Reads total system RAM from `/proc/meminfo`

## 🧠 Vision

LeanCompute is being built as a foundational tool to:

* Estimate AI readiness of a system
* Help developers choose compatible hardware/software
* Provide insights into system limitations
* Evolve into a scoring engine for AI workload suitability

## 🛠️ Tech Stack

* Language: C
* Platform: Linux (initial focus)
* Data Sources:

  * `/proc/cpuinfo`
  * `/proc/meminfo`
  * `uname` system call

## 📌 Status

🚧 Work in Progress — actively being developed with a focus on low-level systems understanding and performance.

## 🎯 Upcoming Features

* CPU instruction set detection (AVX / AVX2)
* AI Readiness Score (ARS)
* JSON report output
* Cross-platform support (Windows)

---

This project is part of a deeper exploration into systems programming, hardware awareness, and performance-oriented software design.

