#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int roadWidth = 200; // Width of the road
int carX = 200, carY = 350; // Player car position
int obsX, obsY = -100; // Obstacle position
int score = 0;
bool gameOver = false;

// Function to draw the road
void drawRoad() {
    setcolor(WHITE);
    line(150, 0, 150, 500); // Left boundary
    line(350, 0, 350, 500); // Right boundary
}

// Function to draw player's car
void drawCar(int x, int y, int color) {
    setcolor(color);
    rectangle(x, y, x + 40, y + 60);
    floodfill(x + 20, y + 30, color);
}

// Function to draw obstacles
void drawObstacle(int x, int y) {
    setcolor(RED);
    rectangle(x, y, x + 40, y + 60);
    floodfill(x + 20, y + 30, RED);
}

// Function to move obstacles
void moveObstacle() {
    obsY += 10; // Move obstacle down
    if (obsY > 500) {
        obsY = -100;
        obsX = 160 + rand() % (roadWidth - 40); // Randomize obstacle position
        score++;
    }
}

// Function to check collision
bool checkCollision() {
    return (carX < obsX + 40 && carX + 40 > obsX && carY < obsY + 60 && carY + 60 > obsY);
}

// Main function
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics

    srand(time(0)); // Seed for random obstacle generation
    obsX = 160 + rand() % (roadWidth - 40);

    while (!gameOver) {
        cleardevice(); // Clear screen

        drawRoad();
        drawCar(carX, carY, GREEN);
        drawObstacle(obsX, obsY);
        moveObstacle();

        if (checkCollision()) {
            gameOver = true;
        }

        delay(100); // Game speed

        if (kbhit()) {
            char ch = getch();
            if (ch == 75 && carX > 160) carX -= 50; // Left arrow key
            if (ch == 77 && carX < 310) carX += 50; // Right arrow key
        }
    }

    // Game over screen
    cleardevice();
    setcolor(RED);
    settextstyle(3, 0, 4);
    outtextxy(200, 200, "GAME OVER!");
    char scr[10];
    sprintf(scr, "Score: %d", score);
    outtextxy(200, 250, scr);
    
    getch();
    closegraph();
    return 0;
}
