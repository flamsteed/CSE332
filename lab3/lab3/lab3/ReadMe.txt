========================================================================
    CONSOLE APPLICATION : lab3 Project Overview
========================================================================

no error or warning met during programming

testcase1

lab3.exe TTT

please input: 2 commands
Usage lab3.exe <game_file_name>


tesrcase2(include invalid location not empoty location and a winning result)

lab3.exe TicTacToe

4
3
2
1
0
 01234
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move

3,4
Invalid input
Please enter 'quit' to quit the game or enter a valid coordinate to do the move

1,1
4
3
2
1 X
0
 01234

Player X: 1,1;
PlayerO's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move

1,2
4
3
2 O
1 X
0
 01234

Player O: 1,2;
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move

1,2
Invalid input
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
2,1
4
3
2 O
1 XX
0
 01234

Player X: 1,1; 2,1;
PlayerO's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move

2,2
4
3
2 OO
1 XX
0
 01234

Player O: 1,2; 2,2;
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move

3,1
4
3
2 OO
1 XXX
0
 01234

Player X: 1,1; 2,1; 3,1;
Player X won the game.


testcase3(someone quit the game)

lab3.exe TicTacToe
4
3
2
1
0
 01234
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
quit
Player X quitted the game.

testcase4(draw condition)

lab3.exe TicTacToe
4
3
2
1
0
 01234
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
1,2
4
3
2 X
1
0
 01234

Player X: 1,2;
PlayerO's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
1,1
4
3
2 X
1 O
0
 01234

Player O: 1,1;
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
2,2
4
3
2 XX
1 O
0
 01234

Player X: 1,2; 2,2;
PlayerO's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
3,2
4
3
2 XXO
1 O
0
 01234

Player O: 1,1; 3,2;
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
2,1
4
3
2 XXO
1 OX
0
 01234

Player X: 1,2; 2,2; 2,1;
PlayerO's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
1,3
4
3 O
2 XXO
1 OX
0
 01234

Player O: 1,1; 3,2; 1,3;
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
3,1
4
3 O
2 XXO
1 OXX
0
 01234

Player X: 1,2; 2,2; 2,1; 3,1;
PlayerO's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
2,3
4
3 OO
2 XXO
1 OXX
0
 01234

Player O: 1,1; 3,2; 1,3; 2,3;
PlayerX's turn:
Please enter 'quit' to quit the game or enter a valid coordinate to do the move
3,3
4
3 OOX
2 XXO
1 OXX
0
 01234

Player X: 1,2; 2,2; 2,1; 3,1; 3,3;
9 turns played; the game comes to a draw.

