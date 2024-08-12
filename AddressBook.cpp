#include <iostream>
using namespace std;

class Contact {
    public:
        int num;
        string name,mail,mobile;
    void setdata(int i,string n,string m,string e) {
        num = i;
        name = n;
        mobile = m;
        mail = e;
    }
    void display() {
        cout << "\n" << (num+1) << ". " << name << "\t" << mobile << "\t" << mail;
    }
};

void intro();
void addContact(Contact *c,int *i);
void displayAll(Contact *c,int *i);
void displayOne(Contact *c,int *i);
void deleteOne(Contact *c,int *i);

int main() {
    cout << "\n\nAddress Book\n\n";
    int i=0;
    Contact c[100];
    while(1)
    {
        intro();
        int m;
        cout << "Enter the choice : ";
        cin >> m;
        switch(m) {
            case 1:
                addContact(c,&i);
                break;
            case 2:
                displayOne(c,&i);
                break;
            case 3:
                displayAll(c,&i);
                break;
            case 4:
                deleteOne(c,&i);
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Enter valid choice";
                break;
        }
    }
}

void intro() {
    cout << "\n\n1. Enter new contact\n";
    cout << "2. Display Specific\n";
    cout << "3. Display all contacts\n";
    cout << "4. Delete specific contact\n";
    cout << "5. exit\n";
}

void addContact(Contact *c,int *i) {
    string na,mo,ma;
    cout << "Enter the name : ";
    cin >> na;
    cout << "Enter the mobile no : ";
    cin >> mo;
    cout << "Enter the email : ";
    cin >> ma;
    c[*i].setdata(*i,na,mo,ma);
    (*i)++;
}

void displayAll(Contact *c,int *i) {
    int j;
    cout << "Id\tName\tMobie\tMail\n";
    for(j=0;j<*i;j++)
    {
        c[j].display();
    }
}

void displayOne(Contact *c,int *i) {
    int id,j,k=-1;
    cout << "Enter the id : ";
    cin >> id;
    cout << "Id\tName\tMobie\tMail\n";
    for(j=0;j<*i;j++)
    {
        if((id-1)==c[j].num)
        {
            k = j;
            break;
        }
    }
    if(k==-1)
    {
        cout << "Record not found";
    }
    else
    {
        c[k].display();
    }
}

void deleteOne(Contact *c,int *i)
{
    int id,j,k=-1,flag=0;
    cout << "Enter id : ";
    cin >> id;
    for(j=0;j<*i;j++)
    {
        if((id-1)==c[j].num)
        {
            k=j;
        }
        if(k==-1)
        {
            flag = 1;
        }
        else
        {
            for(int x=k;x<*i;x++)
            {
                c[k] = c[k+1];
            }
        }
    }
    (*i)--;
    if(flag == 1)
    {
        cout << "Record not found";
    }
}