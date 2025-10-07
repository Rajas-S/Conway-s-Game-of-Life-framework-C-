//Conways game of life sample code - By Rajas Sharma
// this is a framework with the basic logic of the 
// original conways game of life. in this program the
// visuals are rendeder in the console and
// is designed to be a framework that can be adapted into
// a system.
// learn more at:
// https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
//--------------------------------------------------

#include <iostream>
#include <ctime>
#include <thread>
//PARAMETERS
const int sidesize = 100;//gridsize
const int randomtemperature = 60;//randomseeding temperatire
const int framerate=1;
const std::string defaulttile = "..", alivetile = "[]";//tilings - render art

std::string worldtile = "";
std::string bufferline="";

const int wallx = sidesize;
int grid[wallx][wallx]{0};
int gridhold[wallx][wallx]{ 0 };
int i,j;
//initialise the game -- random starting seed
void _init_() {
	srand(std::time(0));
	for (i = 0; i < wallx; i++) {
		for (j = 0; j < wallx; j++) {
			if (rand() % 100 > randomtemperature)grid[j][i]=1;
		}
	}
	for (i = 0; i < wallx; i++) { bufferline += "  "; }
}
//custom starting seed
void custom() {
	grid[14][14] = 1;
	grid[14][15] = 1;
	grid[14][16] = 1;
	grid[13][16] = 1;
	grid[12][15] = 1;
}
//a function to format indexing to avoid out of bounds exception errors
//wraps around out of bounds indexing
int formatindex(int index) {
	if (index < 0)index=wallx-1;
	else if (index >= wallx)index=0;
	return index;
}
//each cell check neighbours and update according to original rules of CGOL
void update() {
	for (j = 0; j < wallx;j++) {
		for (i = 0; i < wallx; i++) {
			switch (grid[formatindex(i-1)][j] + grid[formatindex(i + 1)][j]
				+ grid[i][formatindex(j-1)] + grid[i][formatindex(j + 1)]
				+ grid[formatindex(i - 1)][formatindex(j-1)]
				+ grid[formatindex(i + 1)][formatindex(j - 1)] + grid[formatindex(i + 1)][formatindex(j + 1)]
				+ grid[formatindex(i - 1)][formatindex(j + 1)]) {
			case 0:gridhold[i][j] = 0; break;
			case 1:gridhold[i][j] = 0; break;
			case 2:gridhold[i][j] = grid[i][j]; break;
			case 3:gridhold[i][j] = 1; break;
			case 4:gridhold[i][j] = 0;break;
			case 5:gridhold[i][j] = 0;break;
			case 6:gridhold[i][j] = 0;break;
			case 7:gridhold[i][j] = 0;break;
			case 8:gridhold[i][j] = 0;break;
			}
		}
	}
	for (i = 0; i < wallx; i++) {
		for (j = 0; j < wallx; j++) {
			grid[j][i] = gridhold[j][i];
		}
	}
}
//rendering to console
void render() {
	for (i = 0; i < wallx; i++) {
		for (j = 0; j < wallx; j++) {
			switch (grid[j][i]) {
			case 0: worldtile += defaulttile; break;
			case 1: worldtile += alivetile; break;
			}
		}
		worldtile += '\n';
	}
	std::cout << worldtile;
	worldtile = "";
}

//-----------------------------------------------
// main function:
//-----------------------------------------------
int main() {
	_init_();
	while (true) {
		update();
		render();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000/framerate));
		std::cout << bufferline<<'\n';
		std::cout << bufferline << '\n';
	}
}
