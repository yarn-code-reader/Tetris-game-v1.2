# 🌿 Forest Tetris

A fully playable Tetris game built in **C++ with SFML** as a second-semester OOP project. The game features a hand-crafted forest art style, animated block interactions, multi-state UI buttons, and background music — all structured around core object-oriented design principles.

---

## Features

**Core gameplay**
- Standard Tetris rules — move, rotate, soft drop, hard drop
- Real-time score, level, and line counter
- Speed increases with each level

**Visuals**
- Forest-themed art — AI-generated base images refined in Adobe Photoshop
- Button states: idle, hover, and pressed — all distinct
- Animation when a block is placed
- Animation when a complete line clears
- Upcoming piece preview panel

**Audio**
- Background music on both the menu and gameplay screens

---

## OOP Design

| Concept | How it's used |
|---|---|
| **Classes & Objects** | `Game`, `Board`, `Piece`, `Button`, `ScoreManager` — each owns its own data and behavior |
| **Encapsulation** | Board grid and game state are private; only exposed through controlled methods |
| **Inheritance** | All seven tetromino types derive from a base `Piece` class |
| **Polymorphism** | Piece rotation and rendering use virtual methods, resolved at runtime |
| **Abstraction** | Game logic, rendering, and UI are separated into distinct layers |

---

## Tech Stack

| | |
|---|---|
| Language | C++17 |
| Multimedia | [SFML 2.5](https://www.sfml-dev.org/) — graphics, audio, windowing |
| Art | Adobe Photoshop + AI image generation |

---

## Project Structure

```
ForestTetris/
├── assets/
│   ├── images/         # Backgrounds, buttons, block sprites
│   ├── fonts/
│   └── audio/          # Music tracks
├── src/
│   ├── main.cpp
│   ├── Game.h / Game.cpp
│   ├── Board.h / Board.cpp
│   ├── Piece.h / Piece.cpp
│   ├── Button.h / Button.cpp
│   └── ScoreManager.h / ScoreManager.cpp
└── README.md
```

---

## Build & Run

**Prerequisites**
- C++17 compiler (g++ or MSVC)
- SFML 2.5+ installed

**Linux / macOS**
```bash
git clone https://github.com/yourusername/forest-tetris.git
cd forest-tetris
g++ src/*.cpp -o ForestTetris -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
./ForestTetris
```

**Windows**
Open in your IDE (Visual Studio / Code::Blocks), link the SFML `.lib` files, and place the `.dll` files alongside the executable.

---

## Controls

| Key | Action |
|-----|--------|
| `←` `→` | Move left / right |
| `↑` | Rotate |
| `↓` | Soft drop |
| `Space` | Hard drop |
| `Esc` | Pause / menu |

---

*2nd semester OOP project — CS undergraduate*
