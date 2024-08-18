# PINGPONG (SFML game)

## ***About me***

- **Full Name:** Phùng Viết Phú
- **Student ID:** 21020474
- **Course:** 2324H_INT2215_70

## ***Game Introduction***

*PingPong is a classic game that simulates table tennis. Players control a paddle to hit the ball back and forth with an opponent. The objective of the game is to hit the ball in such a way that the opponent cannot return it, thereby scoring points.*

Game introduction video:

## ***How to play***

1. **Starting the Game:** The game begins when one of the two players serves the ball. Players can use control keys (e.g., up/down arrows or W/S keys) to move their paddle.

2. **Controlling the Paddle:** Use the control keys to move the paddle up or down, block the ball, and hit it back towards the opponent.

3. **Scoring Points:** A player scores a point when the ball passes the opponent's paddle and hits the back of the play area. The game ends when one of the players reaches a certain number of points (e.g., 10 points).

4. **Strategy:** Players can change the direction and speed of the ball by hitting it at different positions on their paddle.

Enjoy the game and aim for a high score!

## ***A few images of the game***

Version 1:
- *Menu*

![](imageReview/menu_ver1.png)

- *Play*

![](imageReview/play_ver1.png)

Version 2: This version has fixed issues with the ball not running smoothly and has added images and sound to enhance the gameplay experience.

- *Menu*

![](imageReview/menu_ver2.png)

- *Play*

![](imageReview/play_ver2.png)

## ***Game Structure***

The project structure is organized as follows:

- main.cpp:
  
          The main entry point of the game. It initializes the game environment, manages the main game loop, and handles overall game state transitions.

- menu.cpp:
  
          Manages the main menu, including difficulty levels, player selection, game instructions, and the option to quit the game.
- ai.cpp:

          Implements the artificial intelligence (AI) for controlling the opponent paddle, including logic for movement and difficulty levels.

- pongball.cpp:

          Manages the ball's behavior, including movement, collision detection with paddles, walls, and scoring when the ball crosses the screen boundaries.

- background.cpp:

          Manages the background graphics of the game, including loading the image, setting its position, and rendering it to the screen.

- player.cpp:

          Manages the player's paddle, including movement and collision detection with the ball.

- funcs.cpp:

          Contains various utility functions used throughout the game, such as helper functions for calculations, configurations, or other repetitive tasks.

- sound.cpp:

          Manages audio effects in the game, including loading sound files, controlling playback, and adjusting volume.

- window.cpp:

          Responsible for creating and managing the game window, including setting up display parameters, handling window events, and rendering game graphics.        
        


## ***Installation Instructions***

Method 1 : Without Code

- Step 1 : Download the game (compressed in a .zip file) from the following link: https://github.com/Vietphu0601/ping_pong

- Step 2 : Unzip the game into a directory

- Step 3 : Locate the `pong.exe` file in folder bin, run, and enjoy the game.


Method 2 : With Code and Buildable

- Step 1 : Clone this repository or select Code -> Download Zip

![](imageReview/git.png)

- Step 2 : Install MinGW. I used the MinGW-W64 GCC-14.2.0 version (build by MSYS2).

- Step 3 : Install GNU make and Cmake

- Step 4 : Open the command prompt in the directory containing the Makefile and run the command make.

- Step 5 : Run pong.exe and enjoy!!

## ***Techniques Used***

 - Utilized several features in SFML: image processing, collision detection, movement, text rendering, sound, timing, mouse and keyboard handling, etc.

 - Applied numerous techniques including classes, vectors, arrays, variables, file separation, and operator overloading.

 - Created game objects such as characters, paddles, and buttons.

 - Designed custom menus and buttons by displaying frames and overlaying text.

 - Implemented file separation and state management.

 - Used GitHub for version control.


## ***References***

 - SFML Installation: https://www.youtube.com/watch?v=7sg88N_bDI0&t=1025s

 - SFML tutorials: https://www.youtube.com/playlist?list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up

 - Github tutorials: https://www.youtube.com/watch?v=tRZGeaHPoaw

 - Source images, sounds, and fonts from Pinterest and itch.io.

 - File organization and management techniques: PitiIT

 ## ***Conclution***

 ### ***Key Takeaways*** ###

 - Developed the project entirely from scratch, with no code copied from external sources.

 - Acquired valuable skills in file management and optimization, which facilitates easier updates and modifications.

 - Gained a better understanding of game logic, state management, and improved code management and writing skills.

  ### ***Limitations*** ###

 - Code is not yet clean and organized.

 - File separation is not fully optimized, and folders are not used effectively.

 - Limited time resulted in only partial implementation of the desired game features.

  ### ***Future Development*** ###

 - Add a powerShot feature for more excitement and surprise.

 - Implement ball curving mechanics for more dynamic gameplay.

 - Enhance AI to be smarter, increasing difficulty beyond just speeding up the ball.

 ## **Desired grade: 8.5++/10**##


