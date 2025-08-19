
# Create and Save Call of Cthulhu 7e Characters

This project aims to create a system to generate, customize, and save characters for the tabletop RPG **Call of Cthulhu 7th Edition**. It is being developed with the help of artificial intelligence, including **GitHub Copilot** (that's me, hello everyone! 👋), directly in Visual Studio Code.

## What the project is right now

Currently, the project is in its early development stage, focusing on:
- Creating characters with random and non-random attributes.
- Allowing skill point distribution.
- Adding backgrounds and equipment to characters.
- Implementing a functional terminal menu.
- Saving characters in JSON files for easy access and editing.

## What the project aims to become

The final goal is to turn this system into a complete and efficient tool, with:
- Two executable files:
	- One for players, where it will be possible to create characters as they wish, following the game rules. These rules will be explained as the user creates the character. In the end, the program will generate a `.json` file containing the character's data.
	- Another for the game master, which will allow loading the `.json` files sent by the players. This program will display the character sheets as needed and allow the master to make changes to them.
- Graphical interface to make usage easier.

## Project origin

This project is an improved version of an old work developed in the first semester of college. It has been redesigned and expanded to meet the needs of **Call of Cthulhu 7e** players, with new features and a more professional approach.

Feel free to follow the progress and contribute with ideas or suggestions. Let's create something amazing together!

## Requirements

- Have [CMake](https://cmake.org/download/) installed.
- Have a C++ compiler (g++ or MSVC) installed.

## How to clone the project

```bash
git clone https://github.com/DuarteFrugoli/coc7e-character-tool.git
cd coc7e-character-tool
```

## How to run the project

1. Create a folder for the build files:
```bash
mkdir build
cd build
```

2. Generate the build files using CMake:
```bash
cmake ..
```

3. Build the project:
```bash
cmake --build .
```

4. Run the program:

- On Windows:
```bash
jogador\jogador.exe
```

- On Linux:
```bash
./jogador/jogador
```

## License

MIT License

Copyright (c) 2025 Duarte Frugoli

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.