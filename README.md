# Latin Square Automation Solver 🧩✨

**author:** Antonios Kalattas   
**author** Alexandros Georgiou  
 
### Summary 📝
This program is a solver for Latin Square puzzles of various sizes, employing backtracking and stack-based memory management
to navigate possible placements. It iterates through positions within the grid and applies the Latin Square constraints, such as that
each number must appear exactly once in each row and column. This automation provides an efficient solution for generating 
complete Latin Squares from partially filled grids
The program uses a stack to manage each board state, enabling smooth transitions between steps and efficient backtracking when
a conflict arises based on the constraints. Counters track all the steps, pushes and pops.
`push` (when a new configuration is stored) and `pop` (when backtracking occurs), 
providing insight into the solver's efficiency
### Program Functions ⚙️
The solver offers the following core functionalities:
- **Solve Latin Squares**: Given a partially filled Latin Square puzzle, the solver completes the puzzle while respecting Latin Square rules
- **Track Steps and Moves**: Tracks all moves made, including each recursive call's `push` and `pop` operations
- **Print Steps and Results**: Outputs each step in the Latin Square solution process and provides summary statistics at the end
### How to Use 🚀
The program is executed from the terminal and reads the initial Latin Square configuration from an input file
- **Usage**: `>./latinsolver <nameOfFIle.txt>`
- **Input Format**: The input file should contain the size of the Latin Square on the first line, followed by rows of integers (0 for empty cells)
### Design and Features 🛠️
The program is modular, with each functionality isolated into separate files:
- **File Handling**: Functions for reading the Latin Square configuration from an input file
- **Latin Square Operations**: Functions to check for conflicts, insert numbers, and verify solved states
- **Stack Management**: Stack operations to manage each board state during backtracking
- **Backtracking Solver**: Recursive function with backtracking to attempt placements in the grid
### Conclusion 🎉
This project showcases effective use of dynamic memory allocation and stack-based backtracking for solving Latin Square puzzles.
Proper memory management is ensured with valgrind-tested code. Furthermore, there's use of the graphviz tool that showcases how the files/functions are linked.
The modular structure allows easy debugging and maintenance.
 
