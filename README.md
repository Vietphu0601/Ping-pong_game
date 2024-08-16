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

## ***Game Structure***

The project structure is organized as follows:

- game.cpp:
  
          Contains the core game logic, including the game loop, handling of game states, and interactions between different game entities.

- menu.cpp:
  
          Manages the main menu, including difficulty levels, player selection, game instructions, and the option to quit the game.

- keyboard.cpp:
  
          Handles player input through the keyboard, mapping key presses to in-game actions such as moving the paddle or pausing the game.
- ai.cpp:

          Implements the AI logic for controlling the computer player, including decision-making and movement in response to the ball's position.

- ball.cpp:

          Manages the ball's behavior, including movement, collision detection with paddles, walls, and scoring when the ball crosses the screen boundaries.

- wall.cpp:

          Represents the game walls, handling collisions with the ball and ensuring the ball bounces back when it hits a wall.

- player.cpp:

        Manages the player's paddle, including movement and collision detection with the ball.

- entity.cpp:

        Provides a base class or common functionality for all game entities, such as the ball, paddles, and AI player, including properties like position, velocity, and rendering.


## ***Installation Instructions***

- Step 1 :  Download the file to your computer.

- Step 2 : Extract the contents of the file.

- Step 3 : Locate the `pong.exe` file, open it, and enjoy the game.

## ***Techniques Used***

 - Utilized several features in SFML: image processing, collision detection, movement, text rendering, sound, timing, mouse and keyboard handling, etc.

 - Employed various classes, vectors, arrays, variables, file separation, operator overloading, etc.

 - Created character, monster objects, and buttons.

 - Used Photoshop to edit some images as needed.

 - Created custom menus and buttons by displaying frames and overlaying text.

 - Applied mathematical and physical knowledge to calculate cooldown times, velocities, and the direction of monster movements following the character, etc.

 - Separated files and used a state machine.


## ***References***

