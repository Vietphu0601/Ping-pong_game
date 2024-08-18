#include "Game.h"
#include <sstream>

Game::Game()
    : window(sf::VideoMode(800, 600), "Pong Game"), player1(50, 200), player2(700, 200),
      ball(400, 200), topWall(0, 0, 800, 10), bottomWall(0, 590, 800, 10),
      player1Score(0), player2Score(0), multiplayer(false) {
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    if (!font.loadFromFile("res/arial.ttf")) exit(1);
    score.setFont(font);
    score.setCharacterSize(30);
    score.setPosition(250, 10);

    credits.setFont(font);
    credits.setCharacterSize(15);
    credits.setPosition(400, 10);
    credits.setString("Press Numbers For change Skins not numlock numbers\n1-football Ball by gothicfan95\n2-Cannonball by Dansevenstar\n3-Egg Blast by OnTheBus\n4-Sky background by PauR\n5-Background Night by Alekei\n6-Starfield background by Sauer2\n7-Multiplayer W&S Player1- Up&Down Player2\nall res from opengameart.org");

    if (!buffer.loadFromFile("res/hit.wav")) exit(-1);
    hitSound.setBuffer(buffer);

    // Tải texture và thiết lập cho các đối tượng
    if (!textPlayer.loadFromFile("res/player.png")) exit(-1);
    if (!textBall.loadFromFile("res/ball.png")) exit(-1);
    if (!textBackground.loadFromFile("res/sky.png")) exit(-1);

    background.setSize(sf::Vector2f(800, 600));
    background.setTexture(&textBackground);

    player1.getShape().setTexture(&textPlayer);
    player2.getShape().setTexture(&textPlayer);
    ball.getShape().setTexture(&textBall);
}


void Game::update() {
    if (keyboardHandler.isWPressed() && !keyboardHandler.isSPressed()) player1.setVelocity(-5);
    if (keyboardHandler.isSPressed() && !keyboardHandler.isWPressed()) player1.setVelocity(5);
    if (!keyboardHandler.isWPressed() && !keyboardHandler.isSPressed()) player1.setVelocity(0);

    player1.update();
    player2.update(ball.getShape().getPosition().y);

    if (player1.getShape().getPosition().y < 0) player1.getShape().setPosition(50, 0);
    if (player1.getShape().getPosition().y > 500) player1.getShape().setPosition(50, 500);

    if (player2.getShape().getPosition().y < 0) player2.getShape().setPosition(700, 0);
    if (player2.getShape().getPosition().y > 500) player2.getShape().setPosition(700, 500);

    if (ball.getShape().getPosition().x < -50) {
        player2Score++;
        ball.getShape().setPosition(300, 200);
    }
    if (ball.getShape().getPosition().x > 750) {
        player1Score++;
        ball.getShape().setPosition(300, 200);
    }
    if (ball.getShape().getPosition().y < 0 || ball.getShape().getPosition().y > 550) ball.reverseYVelocity();

    if (ball.getShape().getGlobalBounds().intersects(player1.getShape().getGlobalBounds())) {
        ball.reverseXVelocity();
        hitSound.play();
    }
    if (ball.getShape().getGlobalBounds().intersects(player2.getShape().getGlobalBounds())) {
        ball.reverseXVelocity();
        hitSound.play();
    }

    if (!multiplayer) {
        if (ball.getShape().getPosition().y < player2.getShape().getPosition().y) player2.setVelocity(-2);
        if (ball.getShape().getPosition().y > player2.getShape().getPosition().y) player2.setVelocity(2);
    } else {
        if (keyboardHandler.isUpPressed() && !keyboardHandler.isDownPressed()) player2.setVelocity(-5);
        if (keyboardHandler.isDownPressed() && !keyboardHandler.isUpPressed()) player2.setVelocity(5);
        if (!keyboardHandler.isUpPressed() && !keyboardHandler.isDownPressed()) player2.setVelocity(0);
    }

    ball.move();
    player1.move();
    player2.move();
}

void Game::render() {
    window.clear();
    window.draw(background);
    window.draw(player1.getShape());
    window.draw(player2.getShape());
    window.draw(ball.getShape());
    score.setString(std::to_string(player1Score) + " : " + std::to_string(player2Score));
    window.draw(score);
    window.draw(credits);
    window.display();
}