#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void  intro();
int getcomp();
void display(int c,int u);

int main() {
    char ch = 'y';
    int u=0,c=0;
    cout << "\n\nRock Paper Scissor Game\n\n";
    while(ch=='y' || ch=='Y')
    {
        intro();
        int us,co;
        cout << "Enter the choice : ";
        cin >> us;
        co = getcomp();
        display(co,us);
        if(us == co)
        {
            cout << "It's a tie";
        }
        else if(us == 1 && co == 3 || us == 2 && co == 1 || us == 3 && co == 2) 
        {
            cout << "\nUser Wins";
            u++;
        }
        else
        {
            cout << "\nComputer Wins";
            c++;
        }
        cout << "\n===================\n";
        cout << "\nTotal Wins\n";
        cout << "User : " << u << endl;
        cout << "Computer : " << c << endl;
        cout << "===================\n";
        cout << "\nDo You want to play more : (y/n) ";
        cin >> ch;
    }
}

void intro() {
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissor\n";    
}

int getcomp() {
    int c;
    srand(time(0));
    c = rand() % 3;
    return c;
}

void display(int c,int u) {
    if(u==1)
    {
        cout << "\nUsers Choice : Rock\n";
    }
    else if(u==2)
    {
        cout << "\nUsers Choice : Paper\n";
    }
    else
    {
        cout << "\nUsers Choice : Scissor\n";
    }
    if(c==1)
    {
        cout << "Computers Choice : Rock\n";
    }
    else if(c==2)
    {
        cout << "Computers Choice : Paper\n";
    }
    else
    {
        cout << "Computers Choice : Scissor\n";
    }
}