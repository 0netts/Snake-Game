#include <iostream>
#include <conio.h>
#include <windows.h>


//create variables
const int height = 20;
const int weight = 20;
int source = 0;
bool GameOver;
int x, y, FruitX, FruitY;

//The function starts here. I'm initializing my variables 
void setup()
{
    GameOver = false; 
    //Move the player to the center 

    x = height / 2; 
    y = weight / 2;
    //for the random position of Fruit X Y
    FruitX = rand() % (height - 2) + 1; 
    FruitY = rand() % (weight - 2) + 1; 
}

void draw()
{
    system("cls");
    //draw a map, fruit and player
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < weight; j++)
        {
            if ((i == 0) || (i == height - 1) || (j == 0) || (j == weight - 1))
            {
                std::cout << "#";
            }
            else if (i == x && j == y)
            {
                std::cout << "@"; //Player
            }
            else if (i == FruitX && j == FruitY)
            {
                std::cout << "F"; //Fruit
            }
            else if (x == FruitX && y == FruitY)
            {
                //If the player is on the same square as the fruit, add 10 coins and move the fruit to another spot
                source += 10;
                FruitX = rand() % (height - 2) + 1;
                FruitY = rand() % (weight - 2) + 1;
            } else if (x < 0 || x > weight -1 || y < 0 || y > height-1) { //checks whether the player has crossed the map's boundary; if so, the game ends
                GameOver = true;            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "coin: " << source; //show how much cash  you have
}

void inputPlayer()
{
    if (_kbhit()) //if the player pressed a key  (true)
    {
        char ky = _getch(); //get the key
        switch (ky)
        {//if press W move  up
        case 'w':
            x--;
            break;
        case 's': //if press S move down
            x++;
            break; 
        case 'a': // if press A move left
            y--;
            break;
        case 'd': // if press D move right
            y++;
            break;
        default: //if not WSAD do not move
            std::cout << "KEY NOT FOUND \n";
            break;
        }
    }
}

//the main function calls all the other functions
int main()
{
    setup();

     while (!GameOver)  //For now, let's keep playing until it becomes true
    {
        draw();
        inputPlayer();
        Sleep(50);
    }
    return 0;
}