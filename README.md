# Cub3D
Cub3D is a 42 school group project aiming to create a dynamic view inside a 3D maze in C. Using the Minilibx library, we have to implement a raycasting algorithm in the style of the earliest games of the kind like Wolfenstein 3D. \
Grade: 115%

# Compatibility
Cub3D has only ever been tested and run on a Linux environment. Running it on a MacOS environment would require some adaptations due to the MiniLibX.

# Usage
If you want to try it for yourself and play around with it, you can clone the repository :
```
git clone https://github.com/FenrisAQB/Cub3D.git cub3D
```
Compile the project with :
```
cd cub3D && make
```
And run it with :
```
./cub3D maps/valid/map0.cub
```
You can try out the other maps, or modify them to play around with it :
- By changing the texture path for NO/SO/EA/WE (North, South, East and West facing textures)
- By changing the RGB color codes for F/C (Floor and Ceiling colors)
- By changing the map layout
  - !No empty lines in the map or missing walls enclosing the map
  - '1' is a wall, '0' is an empty space and 'N/S/W/E' are the player's starting orientation \
As for the keybinds :
- W/A/S/D to move around
- Left/Right arrow, Q/E or the mouse cursor to rotate the view
- M to display the map

# Credit
As for my Minishell project [Minishell](https://github.com/FenrisAQB/Minishell), a huge thanks to my teammate [CDRX](https://github.com/CDRX2).
I mainly used this ressource for the raycasting part : [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)
