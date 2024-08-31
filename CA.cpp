// CA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include "CA.h"
using namespace   std;
bool GamoOver;
const int width = 50;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
int tailX[100], tailY[100];
int nTail;
eDirection dir;
void waitkey();
void Setup()
{
	GamoOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{

			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == fruitY & j == fruitX)
			{
				cout << "*";
			}
			else
			{
					bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;

					}
				}
					if (!print)
					{

						cout << " ";
					}
			}

			if (j == width - 1)
			{
				cout << "#";
			}

		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}cout << endl;
	
	cout << "Score: " << score << endl;
	cout << "\nBy ImBahmanRanjbar\n";
	cout << "                                  | W |" << endl;
	cout << "                             | A || S || D | \n" << endl;
	cout << "               for restart        | x |" << endl;

}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;

		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			GamoOver = true;
			break;

		}
	}


}
void Logic()
{
	int previewX = tailX[0];
	int previewY = tailY[0];
	int preview2X, preview2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		preview2X = tailX[i];
		preview2Y = tailY[i];
		tailX[i] = previewX;
		tailY[i] = previewY;
		previewX = preview2X;
		previewY = preview2Y;
	}
	switch (dir)
	{

	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;


	}
	if (x > width || x<0 || y>height || y < 0)
	{
		GamoOver = true;
	}
	if (x == fruitX && y == fruitY)
	{
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;

	}
}
int main()
{
	Setup();
	while (true)
	{
		Draw();
		Input();
		Logic();
		if (GamoOver)
		{
			cout << "\a";
			score = 0;
			GamoOver = false;
			Setup();
			nTail = 0;
			

		}

	}
	




	return 0;
}
