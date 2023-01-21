# Backtracking-implementation-The-Knight-s-tour-problem-
Using the backtracking algorithm, build a C++ program to determine the path of the knight's piece from the chess game (Knight's tour)
Input Format

The program receives an integer  which representes a board with size , followed by two numbers in the next line. Those two numbers represent the initial position  of the Knight in the board in an empty board.

Move the piece according to the rules of the chess, knight must visit each cell exactly once.

Constraints

, in a new line the initial position .

Output Format

The board showing the order in which each cell is visited.

Sample Input 0

8
0 0
Sample Output 0

0 59 38 33 30 17 8 63
37 34 31 60 9 62 29 16
58 1 36 39 32 27 18 7
35 48 41 26 61 10 15 28
42 57 2 49 40 23 6 19
47 50 45 54 25 20 11 14
56 43 52 3 22 13 24 5
51 46 55 44 53 4 21 12
Explanation 0

With , define a  empty board. The knight start in position (0, 0).

The program should display an  matrix indicating the order of the path.

Sample Input 1

5
2 2
Sample Output 1

22 9 14 3 24
15 4 23 8 13
10 21 0 17 2
5 16 19 12 7
20 11 6 1 18
