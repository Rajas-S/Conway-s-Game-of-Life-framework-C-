# Conways game of life sample code - By Rajas Sharma
# this is a framework with the basic logic of the 
# original conways game of life. in this program the
#/ visuals are rendeder in the console and
# is designed to be a framework that can be adapted into
# a system.
# learn more at:
# https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
#--------------------------------------------------

import time
import random
# ----- declare variables ------
#these are parameters
wallx = 40
wally = wallx
framerate = 60
randtemp = 15

#these are config variables
world = ""
tileset = "'S"
bufferline = ""
grid = [[0 for i in range(wallx+1)] for i in range(wally+1)]
gridhold = [[0 for i in range(wallx+1)] for i in range(wally+1)]
# ---- methods ----
def _init():#initialiser for the world
    global grid
    global bufferline
    for i in range(wally):
        for j in range(wallx):
            if(random.randint(1,100)<=randtemp):
                grid[j][i]=1
    for i in range(wallx):
        bufferline+=" "
    bufferline+='\n'


def formatIndex(inp,end):#add wraparound
    if(inp>end-1):
        inp = 0
    elif(inp<0):
        inp = wallx-1
    return inp

def update(): #update cells according to traditional CGOL rules
    for i in range(wally):
        for j in range(wallx):
            match (grid[formatIndex(j-1,wallx)][formatIndex(i-1,wally)]+grid[j][formatIndex(i-1,wally)]+grid[formatIndex(j+1,wallx)][formatIndex(i-1,wally)]
                    +grid[formatIndex(j-1,wallx)][i]+grid[formatIndex(j+1,wallx)][i]
                    +grid[formatIndex(j-1,wallx)][formatIndex(i+1,wally)]+grid[j][formatIndex(i+1,wally)]+grid[formatIndex(j+1,wallx)][formatIndex(i+1,wally)]):
                case 2: gridhold[j][i]=grid[j][i]
                case 3: gridhold[j][i]=1
                case _: gridhold[j][i]=0
    for i in range(wally):
        for j in range(wallx):
            grid[j][i]=gridhold[j][i]
                
    
    
def render():#prints world to scren using tileset
    global world
    global tileset
    global bufferline
    world = ""
    for i in range(wally):
        for j in range(wallx):
            world+=tileset[grid[j][i]]
            world+=tileset[grid[j][i]]
        world+='\n'
    world+=bufferline
    print(world,end="")
#------------------------------
#main function
#------------------------------
_init()
while True:
    time.sleep(1/framerate)
    render()
    update()
