# 🗂️ Simple File Manager

A modern, lightweight, cross-platform **File Manager** built with **C++ and Qt 6**, designed to provide a smooth and intuitive navigation experience across the file system.
The project demonstrates strong understanding of **Qt Widgets** and **CMake-based** build systems.

---

## ✨ Overview

This project is a custom-built file explorer that replicates — and extends — core desktop file manager functionality while maintaining a clean and minimal interface.  
It focuses on **usability**, **performance**, and **code quality**.

---

## 🧩 Key Features

- 📝 **Entering path manually** — Users can type any valid filesystem path directly into the address bar to jump instantly to that directory.  
- ⏮️ **Returning to previous directories** — Navigate back to the previously visited directories with a single click.
- 📂 **Folder navigation** — Double-click a folder to open it and browse its contents.
- 📄 **Opening files** — Double-clicking a file launches it with the system’s default associated application.
- 🖼️ **Previewing images** — Displays image thumbnails directly in the file view for better visual context.
  
---

## Supported platforms
| Platform  | Supported?        |
| --------- | ----------------- |
| 🐧 Linux     | ✅ Yes |
| 🪟 Windows   | ⚠️ Partial - Some features doesn't work on Windows|
| 🍎 MacOS     | ❌ Currently not supported - Planned in the future|

## 🚀 Getting Started

### Prerequisites
- **Qt 6** - Graphical user interface framework
- **CMake ≥ 3.15** - For building project in a cross-platform way
- **C++17 compatible compiler** for target platform(such as clang or gcc for Linux/mingw or msvc for Windows)

### Build Instructions
```bash
git clone https://github.com/PlataTomasz/simple-file-manager
cd simple-file-manager
mkdir build && cd build
cmake ..
cmake --build .
```

## Run
After building, simply run the executable:

```bash
cd build
./SimpleFileManager
```