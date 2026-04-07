# Twixt

**Twixt** is a digital version of the classic two-player strategy board game, implemented in C. Players (Red and Black) compete to connect their respective sides of a $24 \times 24$ grid by placing pegs and forming "Knight's Move" links. The game features automated link detection, overlap prevention, and a winning condition check based on path connectivity.

---

## Features

### 1. Dynamic Gameplay
* **Peg Placement**: Players take turns placing markers on a $24 \times 24$ board.
* **Automatic Linking**: When a player places a peg that is a "Knight's Move" ($L$-shape) away from another of their own pegs, a link is automatically proposed.
* **Overlap Prevention**: The engine checks if a new link would physically cross an existing link and prevents the move if an overlap is detected.

### 2. Game Mechanics
* **Red Player**: Connects the Top (row 1) and Bottom (row 24) borders.
* **Black Player**: Connects the Left (column 1) and Right (column 24) borders.
* **Winning Engine**: Uses a "cluster" system to track connectivity. If a single connected path (cluster) touches both required borders, that player is declared the winner.

### 3. User Interface
* **Live Board Updates**: The grid is re-rendered after every turn to show current pegs and structure.
* **Active Link Log**: A list of all successfully formed links is displayed every turn.
* **Session Management**: Enter `0 0` at any time to reset the board for a new game or exit the application.

---

## Project Structure

| File | Description |
| :--- | :--- |
| `main.c` | The main game loop handling player input, turn switching, and game state management. |
| `functions.c` | Core logic including board rendering, link overlap math, and cluster-based win detection. |
| `functions.h` | Definitions for the `Link` structure and function prototypes used across the project. |

---

## Technical Specifications

* **Language**: C (Standard I/O).
* **Board Size**: $24 \times 24$ playable area (represented internally as $25 \times 25$ to accommodate labels).
* **Pathfinding**: Implements a cluster-tracking algorithm (`link_join_or_not`) to determine if two disparate segments of pegs have become part of a single continuous path.
* **Link Validation**: Uses coordinate geometry to determine if a new link $(r1, c1) \rightarrow (r2, c2)$ intersects any existing active links.

---

## How to Run

### 1. Compilation
Use `gcc` to compile the source files into an executable named `twixt`:
```bash
gcc -o twixt main.c functions.c
