# So_Long Project Documentation
So_Long with Minilibx: Navigate through dynamic environments with immersive gameplay powered by efficient graphics handling.

## Introduction

"So_Long" is a simple 2D game project implemented in C using the MinilibX graphical library. The objective of the game is for the player to navigate through a map, collect collectibles, and reach the exit while avoiding obstacles. It serves as an introductory project to graphics programming and game development in the context of personal or team projects.

The primary goal of the "So_Long" project is to familiarize us with basic game mechanics, graphics rendering, and user input handling in C programming. By completing this project, we gain hands-on experience in implementing game logic, rendering graphics, and managing game states using the MinilibX library.

Through "So_Long," we have the opportunity to explore fundamental concepts in game development, such as game loops, collision detection, sprite rendering, and map parsing. Additionally, we can apply our programming skills to create engaging and interactive experiences within the constraints of a simple 2D game environment.

## Execution

### Cloning the Repository

To run the "So_Long" project, clone the repository containing the project files from GitHub:

```bash
git clone https://github.com/dansylvain/42_so_long so_long
```

### Compiling the Project

Navigate to the project directory and compile the project using the provided Makefile. Here's how:

```bash
cd so_long
make
```

This will compile the project and generate an executable file named so_long.

## Dependencies

My implementation of the "so_long" project includes all necessary dependencies within the source code, requiring no additional installations.

## System Configurations

Before compiling and running the "So_Long" project, ensure that your system meets the following requirements:

- **X11 and OpenGL Libraries**: The MinilibX library relies on the X11 and OpenGL libraries for graphics rendering. Ensure that these libraries are installed on your system and properly configured. On Linux systems, you may need to install the `libx11-dev` and `libxext-dev` packages to provide the necessary dependencies for MinilibX.

```bash
```bash
# Install libx11-dev
sudo apt-get install libx11-dev

# Install libxext-dev
sudo apt-get install libxext-dev
```

- **Graphics Hardware Support**: Make sure that your system's graphics hardware supports the features required by MinilibX and OpenGL for graphics rendering. Ensure that the appropriate graphics drivers are installed and up-to-date.

Once you have verified that your system meets these requirements, you can proceed with compiling and running the "So_Long" project as described in the execution section.
```bash
# Check OpenGL support
glxinfo | grep "OpenGL version"

# Check graphics driver information
lspci -k | grep -A 2 -E "(VGA|3D)"
```
The first command (glxinfo | grep "OpenGL version") checks for the OpenGL version supported by the system, which is essential for MinilibX. The second command (lspci -k | grep -A 2 -E "(VGA|3D)") lists information about the graphics hardware and associated drivers, allowing users to verify if the appropriate graphics drivers are installed and up-to-date.

## Running the Game
Once compiled successfully, you can run the game by executing the generated so_long executable:
```bash
./so_long maps/map1.ber
```
Replace **<maps/map1.ber>** with the path to the map file you want to use for the game. The map file must have a **.ber** extension and follow the specified format.

### Controls
Use the arrow keys (⬅️, ➡️, ⬆️, ⬇️) to move the player character within the game window. Press the **ESC** key to exit the game at any time.

**Have fun with so_long!** 🎮
