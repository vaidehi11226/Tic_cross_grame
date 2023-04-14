#include<iostream>
#include<stdlib.h>
using namespace std;
char d2[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw=false;
void display_d2()
{
    system("cls");
   cout<<"      T i c k   C r o s s   G a m e"<<endl<<endl;
    cout<<"\tPlayer1 [X] \n\tPlayer2 [0]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t"<<d2[0][0]<<"    |"<<d2[0][1]<<"    |"<<d2[0][2]<<"    \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t"<<d2[1][0]<<"    |"<<d2[1][1]<<"    |"<<d2[1][2]<<"     \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t"<<d2[2][0]<<"    |"<<d2[2][1]<<"    |"<<d2[2][2]<<"     \n";
    cout<<"\t\t     |     |     \n";
}
void display_turn()
{

int choice;
if(turn=='X')
    cout<<" \t player 1[X] turn:"<<endl;
 if(turn=='0')
        cout<<"\t player 2[0] turn:"<<endl;

    cin>>choice;
    switch(choice)
    {

case 1:
    row=0;
    column=0;
    break;
case 2:
    row=0;
    column=1;
    break;
case 3:
    row=0;
    column=2;
    break;
case 4:
    row=1;
    column=0;
    break;
case 5:
    row=1;
    column=1;
    break;
case 6:
    row=1;
    column=2;
    break;
case 7:
    row=2;
    column=0;
    break;
case 8:
    row=2;
    column=1;
    break;
case 9:
    row=2;
    column=2;
    break;
default:
    cout<<"invalid choice\n";
    break;
}
if(turn=='X'&& d2[row][column]!='X'&& d2[row][column]!='O')
{
    d2[row][column]='X';
    turn='0';
}
else if(turn=='0'&&d2[row][column]!='X'&& d2[row][column]!='O')
{
        d2[row][column]='0';
            turn='X';
}
else{
      cout<<"Box already filled"<<endl<<"Please try again"<<endl;
      display_turn();
    }
    display_d2();
}

bool gameover()
{
    //check win
    for(int i=0;i<3;i++)
        if(d2[i][0]==d2[i][1]&&d2[i][0]==d2[i][2]||d2[0][i]==d2[1][i]&&d2[0][i]==d2[2][i])
        return false;

        if(d2[0][0]==d2[1][1] && d2[0][0]==d2[2][2]&& d2[0][2]==d2[1][1]&&d2[0][0]==d2[2][0])
            return false;

            for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            if(d2[i][j]!='X'&& d2[i][j]!='0')
            return true;
draw=true;
return false;
}

int main()
{

    while(gameover())
{
    display_d2();
    display_turn();
    gameover();
}
if(turn=='X'&& draw==false)
    cout<<"Player2[0] Wins!! Congratulations"<<endl;
else if(turn=='0'&& draw==false)
    cout<<"Player1[X] Wins!! Congratulations"<<endl;
else
    cout<<"GAME DRAW!!!"<<endl;
}
