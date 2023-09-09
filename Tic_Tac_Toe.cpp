#include<iostream>
#include<windows.h>
#include <unistd.h>
#include<stdlib.h>
#include<string>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

char Space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string n1,n2;
int row , column;
char token = 'X';
bool tie  = false;

bool Check()
{
    for(int i=0 ; i<3 ; i++)
    {
        if(Space[i][0]==Space[i][1] && Space[i][0]==Space[i][2] || Space[0][i]==Space[1][i] && Space[0][i]==Space[2][i])
        {
            return true;
        }
    }

    if(Space[0][0]==Space[1][1] && Space[1][1]==Space[2][2] || Space[0][2]==Space[1][1] && Space[1][1]==Space[2][0])
    {
        return true;
    }

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(Space[i][j]!='X' && Space[i][j]!='O')
            {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

void Start()
{
    cout<<"       |       |       "<<endl;
    cout<<"   "<<Space[0][0]<<"   "<<"|   "<<Space[0][1]<<"   "<<"|   "<<Space[0][2]<<"   "<<endl;
    cout<<"       |       |       "<<endl;
    cout<<"-------+-------+-------"<<endl;
    cout<<"       |       |       "<<endl;
    cout<<"   "<<Space[1][0]<<"   "<<"|   "<<Space[1][1]<<"   "<<"|   "<<Space[1][2]<<"   "<<endl;
    cout<<"       |       |       "<<endl;
    cout<<"-------+-------+-------"<<endl;
    cout<<"       |       |       "<<endl;
    cout<<"   "<<Space[2][0]<<"   "<<"|   "<<Space[2][1]<<"   "<<"|   "<<Space[2][2]<<"   "<<endl;
    cout<<"       |       |       "<<endl;

    cout<<endl;
    cout<<endl;
}

void functionTwo()
{
    string ch;
    int digit;
    if(token=='X')
    {
        cout<<n1<<" Please Enter: ";
        cin>>ch;
        getchar();
        while(ch.length() > 1 || ch[0] > 57 || ch[0] < 49)
        {
            cout<<"Invalid Input !!!"<<endl;
            cout<<n1<<" Please Enter: "<<endl;
            cin>>ch;
            getchar();
        }
        digit = (int)ch[0] - 48;
    }

    if(token=='O')
    {
        cout<<n2<<" Please Enter: ";
        cin>>ch;
        getchar();
        while(ch.length() > 1 || ch[0] > 57 || ch[0] < 49)
        {
            cout<<"Invalid Input !!!"<<endl;
            cout<<n2<<" Please Enter: "<<endl;
            cin>>ch;
            getchar();
        }
        digit = (int)ch[0] - 48;
    }

    switch (digit) 
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
            cout<<"Invalid Input !!!"<<endl;
            functionTwo();
            break;
            // if(digit>=97 && digit<=122 || digit>=65 && digit<=90)
            // {
                 
            // }
            
    }

    if(token=='X' &&  Space[row][column]!='X' && Space[row][column]!='O')
    {
        Space[row][column]='X';
        token='O';
    }
    else if(token=='O' &&  Space[row][column]!='X' && Space[row][column]!='O')
    {
        Space[row][column]='O';
        token='X';
    }
    else
    {
        cout<<"There is no Empty Space !!"<<endl;
        Check();
        if(tie==true)
        {
            return;
        }
        functionTwo();
    }
    //Start();
}


int main()
{
    for(int i=0; i<5; i++)
    {
      //SetConsoleTextAttribute( , i);
      SetConsoleTextAttribute(console, i);
      cout<<("                          ***           ***   **********   ***          **********   *********   *****        *****   **********  \n");
	  cout<<("                          ***           ***   **********   ***          **********   *********   ******      ******   **********   \n");
      cout<<("                          ***     *     ***   ***          ***          ***          ***   ***   *** ***    *** ***   ***          \n");
      cout<<("                          ***    ***    ***   ******       ***          ***          ***   ***   ***  ***  ***  ***   ******       \n");
      cout<<("                          ***   ** **   ***   ******       ***          ***          ***   ***   ***   ******   ***   ******       \n");
      cout<<("                          *** ***   *** ***   ***          ***          ***          ***   ***   ***    ****    ***   ***          \n");
      cout<<("                          ******     ******   **********   **********   **********   *********   ***            ***   **********    \n");
      cout<<("                          *****       *****   **********   **********   **********   *********   ***            ***   **********    \n\n");                                      
    
      usleep(500000);
      system("cls");
      usleep(5000);

    }

    //clr screen
    cout<<"Enter the name of the Player-1 : ";
    SetConsoleTextAttribute(console, 15);
    cin>>n1;
    SetConsoleTextAttribute(console, 6);

    cout<<"Enter the name of the Player-2 : ";
    SetConsoleTextAttribute(console, 15);
    cin>>n2;

    //clear screen 
    //color screen
    cout<<n1<<" will PLay First !! \n";
    cout<<n2<<" will Play Second !! \n";
    while(!Check())
    {
        Start();
        functionTwo();
        Check();
        if(tie==true)
        {
            break;
        }
        system("cls");
    }

    if(token =='X' && tie == false )
    {
        Start();
        cout<<n2<<" Wins !!"<<endl;
        usleep(50000000);
    
    }
    else if(token=='O' && tie == false)
    {
        Start();
        cout<<n1<<" Wins !!"<<endl;
        usleep(50000000);

    }
    else
    {
        Start();
        cout<<"It's a Draw!!"<<endl;
        usleep(50000000);

    }

    return 0;
}
