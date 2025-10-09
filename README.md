This is a basic framework for Conways Game of Life made in C++. This framework is temporarily rendered in terminal window as ASCII art. 
It is designed to be easily integrated into a system quickly and easily with a game array called grid and the render function should be easy to adapt.
The rules for the cellular automata are in the update() function under a switch - these are easily changed to variate on the orignal game of life
The initial grid size is set to 900 chars by 450 chars (approximately square shape).
grid is handled in a matrix where 0=dead and 1=alive and is continuously updated.
