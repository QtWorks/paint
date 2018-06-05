# Paint with Qt

In this program I implemented a simple drawing interface.
The interface contains a menu bar that allows the users to:

1. Create a new Image    
2. Open an existing BMP image
3. Save an image that is being worked on
4. Customize the background of a new image.
5. Change the color of the pen by changing the foreground color
6. Supports 1 level of undo and redo
7. Has a tool bar for easy access to tools

Thee are three tools implemented in this simple drawing program:
    
1. Pen
2. Line
3. Eraser

There are two types of Line that the program supports:
    
1. Single (the default)   
2. Poly

To switch between the line modes you have to go through the "Line Properties" in the Tools section.

To view the customize window for these tools you can go to the Tools section of menu, \
for example Tools->Pen Properties to see what you can change about your pen. 

If you are currently using a tool, you can change its properties by doing a right click anywhere on
the screen. For convenience you can leave the property window open and still be able to draw on the canvas and go
between the two windows.

# Build Instruction
To compile this program make sure you have qt install which you can do on an ubuntu machine with

<code>
sudo apt-get install qt5-default
</code>

Once the dependencies are installed you can run my installed script to compile

<code>
./install.sh
</code>

This will create the executable in ./paint

# Run Instructions
Run the executable either by double clicking with a GUI or running the executable through a terminal \
that has GUI capabilities.
