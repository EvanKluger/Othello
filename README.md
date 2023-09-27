# Othello AI Terminal Game 

Welcome to the Othello AI Terminal Game! Dive into the classic board game of Othello and challenge yourself against a formidable AI opponent.

## Features 

- **Interactive Terminal Interface**: Experience Othello right from your terminal.
  
- **Expert Level AI**: Square off against my custom-built AI bot designed to challenge even seasoned Othello players.

- **Advanced AI Strategy**: The AI strategizes using the renowned Mini-Max Algorithm combined with Alpha Beta Pruning.

- **Unique Heuristic Function**: This AI's decisions are guided by a specially crafted heuristic function, ensuring every game is a unique challenge.

## Getting Started

### Game Basics:

- **Player 1 (Blue)**: Always goes first when starting a new game.

- **Player 2 (White)**: Follows Player 1.

### Setup and Execution:

1. Run the `MAKEFILE` to compile the project. This creates an executable named `othello.exe`.
2. To play the game, type `./othello` in the terminal.

### Using a Custom Game Layout:

1. Inside the repository, there's a `test.txt` file which serves as a template for game layouts. The layout consists of an 8x8 matrix with values 0, 1, and 2.
   - `0` Represents an empty spot.
   - `1` Represents a Blue piece.
   - `2` Represents a White piece.
2. To use your own game setup, edit the `test.txt` file to your desired board layout.
3. When the game prompts you, provide the time limit and indicate whose turn it is. No need to include this info in the `test.txt` file.

## Contribution

If you have any feedback or if you managed to beat the AI, I'd love to hear from you! Please raise an issue or submit a pull request.

Happy gaming!

