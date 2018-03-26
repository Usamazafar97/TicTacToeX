#include "stdafx.h"
#include<iostream>
using namespace std;
#include<conio.h>
#include<string>

////////////////////////Declaration of variables///////////////////////////
string name_for_player_1;
string name_for_player_2;
int column = 0;
int row = 0;
int columns = 0;
int rows = 0;
int board[3][3] = {
	{ 0,0,0 },
	{ 0,0,0 },
	{ 0,0,0 } };
int chk_horizontal__for_player_1 = 0;
int chk_vertical__for_player_1 = 0;
int chk_diogonal__for_player_1 = 0;
int chk_horizontal__for_player_2 = 0;
int chk_vertical__for_player_2 = 0;
int chk_diogonal__for_player_2 = 0;
int chk_sub_diogonal__for_player_1 = 0;
int chk_sub_diogonal__for_player_2 = 0;
int chk_for_draw = 0;
//int count = 0;
////////////////////////////////////////////////////////////////////////////

void Display()
{
	for (rows = 0;rows < 3;rows++)
	{
		for (columns = 0;columns < 3;columns++)
		{
			cout << board[rows][columns];
		}
		cout << endl;
	}
}

int  check_horizontally_for_player_1()
{
	for (rows = 0;rows < 3;rows++)
	{
		int count = 0;
		for (columns = 0;columns < 3;columns++)
		{
			if (board[rows][columns] ==1)
			{
				count++;				
			}			
		}
		if (count==3)
		{
			return 1;
			//cout << "Player 1 Wins";
		}
		
	}
	return 0;
	
}

int  check_horizontally_for_player_2()
{
	for (rows = 0;rows < 3;rows++)
	{
		int count = 0;
		for (columns = 0;columns < 3;columns++)
		{
			if (board[rows][columns] == 2)
			{
				count++;
			}
		}
		if (count == 3)
		{
			return 1;
			//cout << "Player 2 Wins";
		}
			
	}
	return 0;
}
int check_vertically_for_player_1()
{
	for (rows = 0;rows < 3;rows++)
	{
		int count = 0;
		for (columns = 0;columns < 3;columns++)
		{
			if (board[columns][rows] == 1)
			{
				count++;
			}
		}
		if (count == 3)
		{
			return 1;
			//cout << "Player 1 Wins";
		}			
	}
	return 0;
}

int  check_vertically_for_player_2()
{
	for (rows = 0;rows < 3;rows++)
	{
		int count = 0;
		for (columns = 0;columns < 3;columns++)
		{
			if (board[columns][rows] == 2)
			{
				count++;
			}
		}
		if (count == 3)
		{
			return 1;
			//cout << "Player 2 Wins";
		}		
	}
	return 0;
}
int  check_diogonally_for_player_1()
{
	int count = 0;
	for (rows = 0;rows < 3;rows++)
	{
		for (columns = 0;columns < 3;columns++)
		{
			if (rows==columns)
			{
				if (board[rows][columns] == 1)
				{
					count++;
				}
			}
		}
		
	}
	if (count==3)
	{
		return 1;
		//cout << "Player 1 Wins";
	}
	else
	{
		return 0;
	}
}
int  check_diogonally_for_player_2()
{
	int count = 0;
	for (rows = 0;rows < 3;rows++)
	{
		for (columns = 0;columns < 3;columns++)
		{
			if (rows == columns)
			{
				if (board[rows][columns] == 2)
				{
					count++;
				}
			}
		}

	}
	if (count == 3)
	{
		return 1;
		//cout << "Player 2 Wins";
	}
	else
	{
		return 0;
	}
}

int  check_sub_diogonally_for_player_1()
{
	int count = 0;
	for (rows = 0;rows < 3;rows++)
	{				
				if (board[rows][2- rows] == 1)
				{
					count++;
				}
	}
	if (count == 3)
	{
		return 1;
		//cout << "Player 1 Wins";
	}
	else
	{
		return 0;
	}
}
int  check_sub_diogonally_for_player_2()
{
	int count = 0;
	for (rows = 0;rows < 3;rows++)
	{
		if (board[rows][2 - rows] == 2)
		{
			count++;
		}
	}
	if (count == 3)
	{
		return 1;
		//cout << "Player 2 Wins";
	}
	else
	{
		return 0;
	}
}
int main()
{
	cout << "\t\t\t Welcome to TIC TAC TOE"<<endl;
	cout << "\nboard\n" << endl;
	Display();
	cout << "\nPlayer 1 Please enter your name :";
	cin >> name_for_player_1;
	cout << "\nPlayer 2 Please enter your name :" ;
	cin >> name_for_player_2;
	
	for (int i = 0; i < 4; i++)
	{
		///////////////////////////////////For player 1//////////////////////////////
		if (i == 0) 
		{
			cout<< "\t\t\t   " <<name_for_player_1<<" please Start"<<endl;
		}
		else
		{
			cout << "\t\t\t   " << name_for_player_1 <<" your turn"<< endl; 
		}
		cout << "Alert :Rows and columns must ranges from 0 to 2";
		cout << "enter the row :";
		cin >> row;
		cout << "enter the column :";
		cin >> column;
		if (((column >= 0 && column < 3) && (row >= 0 && row < 3)) && (board[row][column]==0))
		{
			board[row][column] = 1;
			Display();
		}
		else
		{
			chk_for_draw = 1;
			cout << "\t\t\t   invalid input";
			break;
		}
		//checks for player 1
		chk_horizontal__for_player_1=check_horizontally_for_player_1();
		if (chk_horizontal__for_player_1 == 1)
		{
			chk_for_draw = 1;
			cout << "\t\t\t   " << name_for_player_1 << "  Wins";
			break;
		}
		chk_vertical__for_player_1=check_vertically_for_player_1();
		if (chk_vertical__for_player_1 == 1)
		{
			chk_for_draw = 1;
			cout << "\t\t\t   " << name_for_player_1 << "  Wins";
			break;
		}
		chk_diogonal__for_player_1=check_diogonally_for_player_1();
		if (chk_diogonal__for_player_1 == 1)
		{
			chk_for_draw = 1;
			cout << "\t\t\t   " << name_for_player_1 << "  Wins";
			break;
		}
		chk_sub_diogonal__for_player_1 =check_sub_diogonally_for_player_1();
		if (chk_sub_diogonal__for_player_1 == 1)
		{
			chk_for_draw = 1;
			cout << "\t\t\t   " << name_for_player_1 << "  Wins";
			break;
		}
		///////////////////////////////////For player 2//////////////////////////////
				
			cout << "\t\t\t   " << name_for_player_2 << " your turn" << endl;
			cout << "Alert :Rows and columns must ranges from 0 to 2";
			cout << "enter the row :";
			cin >> row;
			cout << "enter the column :";
			cin >> column;
			
			if (((column >= 0 && column < 3) && (row >= 0 && row < 3)) && (board[row][column] == 0))
			{
				board[row][column] = 2;
				Display();
			}
			else
			{
				chk_for_draw = 1;
				cout << "invalid input";
				break;
			}
			
		//checks for player 2
			chk_horizontal__for_player_2=check_horizontally_for_player_2();
			if (chk_horizontal__for_player_2 == 1)
			{
				chk_for_draw = 1;
				cout << "\t\t\t   "<<name_for_player_2 <<"  Wins";
				break;
			}
			chk_vertical__for_player_2=check_vertically_for_player_2();
			if (chk_vertical__for_player_2 == 1)
			{
				chk_for_draw = 1;
				cout << "\t\t\t   " << name_for_player_2 << "  Wins";
				break;
			}
			chk_diogonal__for_player_2=check_diogonally_for_player_2();
			if (chk_diogonal__for_player_2 == 1)
			{
				chk_for_draw = 1;
				cout << "\t\t\t   " << name_for_player_2 << "  Wins";
				break;
			}
			chk_sub_diogonal__for_player_2 = check_sub_diogonally_for_player_2();
			if (chk_sub_diogonal__for_player_2 == 1)
			{
				chk_for_draw = 1;
				cout << "\t\t\t   " << name_for_player_2 << "  Wins";
				break;
			}
	}	
	if (chk_for_draw == 0)
	{
		cout << "\t\t\t   Game Draw"; 
	}
	_getch();
	return 0;
}
