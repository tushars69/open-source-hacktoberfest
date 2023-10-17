#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

const int gridSize = 5;

struct Player {
    int x;
    int y;
};

struct Obstacle {
    int x;
    int y;
};

struct Goal {
    int x;
    int y;
};

void initializeGame(Player& player, Goal& goal, std::vector<Obstacle>& obstacles) {
    player.x = 0;
    player.y = 0;

    goal.x = gridSize - 1;
    goal.y = gridSize - 1;

    obstacles.clear();
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < gridSize; i++) {
        Obstacle obstacle;
        obstacle.x = std::rand() % gridSize;
        obstacle.y = std::rand() % gridSize;
        obstacles.push_back(obstacle);
    }
}

void printGrid(const Player& player, const Goal& goal, const std::vector<Obstacle>& obstacles) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (i == player.y && j == player.x) {
                std::cout << "P ";
            } else if (i == goal.y && j == goal.x) {
                std::cout << "G ";
            } else {
                bool isObstacle = false;
                for (const Obstacle& obstacle : obstacles) {
                    if (i == obstacle.y && j == obstacle.x) {
                        std::cout << "X ";
                        isObstacle = true;
                        break;
                    }
                }
                if (!isObstacle) {
                    std::cout << ". ";
                }
            }
        }
        std::cout << std::endl;
    }
}

bool isGameOver(const Player& player, const Goal& goal, const std::vector<Obstacle>& obstacles) {
    if (player.x == goal.x && player.y == goal.y) {
        std::cout << "Congratulations! You reached the goal!" << std::endl;
        return true;
    }

    for (const Obstacle& obstacle : obstacles) {
        if (player.x == obstacle.x && player.y == obstacle.y) {
            std::cout << "Game over! You hit an obstacle." << std::endl;
            return true;
        }
    }

    return false;
}

int main() {
    Player player;
    Goal goal;
    std::vector<Obstacle> obstacles;

    initializeGame(player, goal, obstacles);

    std::cout << "Welcome to the Grid Game!" << std::endl;

    while (true) {
        printGrid(player, goal, obstacles);
        char move;
        std::cout << "Enter your move (W/A/S/D): ";
        std::cin >> move;

        switch (move) {
            case 'W':
            case 'w':
                if (player.y > 0) {
                    player.y--;
                }
                break;
            case 'A':
            case 'a':
                if (player.x > 0) {
                    player.x--;
                }
                break;
            case 'S':
            case 's':
                if (player.y < gridSize - 1) {
                    player.y++;
                }
                break;
            case 'D':
            case 'd':
                if (player.x < gridSize - 1) {
                    player.x++;
                }
                break;
            default:
                std::cout << "Invalid move. Use W/A/S/D to move." << std::endl;
        }

        if (isGameOver(player, goal, obstacles)) {
            break;
        }
    }

    return 0;
}
