#include <iostream>
using namespace std;

class Items
{
    public:
        int id,price;
        string itemname;
    void setdata(int i,string name,int p)
    {
        id = i;
        itemname = name;
        price = p;
    }
    void display() const
    {
        cout <<  id << "\t";
        cout << itemname << "\t";
        cout << price << "\t";
    }
};

void intro();
void menu(Items *i,int *x);
void menuIntro();
void addItem(Items *i,int *x);
void displayItems(Items *i,int *x);
void updateItem(Items *i,int *x);
void updateItemPrice(Items *i,int *x);
void deleteItem(Items *i,int *x);
void getOrder(Items *i,int *x,int *b);
void genBill(Items *i,int *x,int id,int count,int *b);
void displayBill(int *b);

int main() {
    cout << "\n\nRestaurant\n\n";
    Items i[50];
    int totalbill=0;
    int n,x=2;
    i[0].setdata(101,"Simple Tea",25);
    i[1].setdata(102,"Simple Coffee",100);
    while(1)
    {
        intro();
        cin >> n;
        switch(n) 
        {
            case 1:
                menu(i,&x);
                break;
            case 2:
                getOrder(i,&x,&totalbill);
                break;
            case 3:
                displayBill(&totalbill);
                break;
            case 4:
                exit(0);
            default:
                cout << "Enter valid choice : ";
                break;
        }
    }
}

void intro() {
    cout << "1. Menu Management \n";
    cout << "2. Get Order\n";
    cout << "3. Generate Bill\n";
    cout << "4. Exit\n";
    cout << "Enter the choice : ";
}

void menu(Items *i,int *x) {
    char ch = 'y';
    while(ch=='y' || ch=='Y'){
        menuIntro();
        int n;
        cin >> n;
        switch(n) 
        {
            case 1:
                addItem(i,x);
                break;
            case 2:
                displayItems(i,x);
                break;
            case 3:
                updateItem(i,x);
                break;
            case 4:
                updateItemPrice(i,x);
                break;
            case 5:
                deleteItem(i,x);
                break;
            case 6:
                return;
            default:
                cout << "Enter valid choice : ";
                break;
        }
    }
}

void menuIntro() {
    cout << "\nMenu Operations \n";
    cout << "1. Add new item\n";
    cout << "2. Display all items\n";
    cout << "3. Update item\n";
    cout << "4. Update item price\n";
    cout << "5. Delete item\n";
    cout << "6. Return to menu\n";
    cout << "Enter the choice : ";
}

void addItem(Items *i,int *x) {
    int d,p;
    string name;
    cout << "Enter id of item : ";
    cin >> d;
    cout << "Enter name of item : ";
    cin >> name;
    cout << "Enter price of item : ";
    cin >> p;
    i[*x].setdata(d,name,p);
    (*x)++;
}

void displayItems(Items *i,int *x) {
    int j;
    if(*x < 1)
    {
        cout << "Record Not Found";
    }
    else
    {
        cout << "\nItem Id\tItem Name\tItem Price\n\n";
        for(j=0;j<*x;j++)
        {
            i[j].display();
            cout << "\n=============================\n";
        }
    }
}

void updateItem(Items *i,int *x) {
    int a=0,k=0,flag=0;
    cout << "\nEnter id of item : ";
    cin >> a;
    for(int j=0;j<*x;j++)
    {
        if(a==i[j].id)
        {
            flag = 1;
            k = j;
            break;
        }
    }
    if(flag==0)
    {
        cout << "\nItem Not Found";
    }
    else
    {
        string name;
        int p;
        cout << "\nEnter name of item : ";
        cin >> name;
        cout << "Enter price of item : ";
        cin >> p;
        i[k].setdata(i[k].id,name,p);
    }
    
}

void updateItemPrice(Items *i,int *x) {
    int a=0,k=0,flag=0;
    cout << "\nEnter id of item : ";
    cin >> a;
    for(int j=0;j<*x;j++)
    {
        if(a==i[j].id)
        {
            flag=1;
            k = j;
            break;
        }
    }
    if(flag==0)
    {
        cout << "\nItem Not Found";
    }
    else
    {
        int p;
        cout << "\nEnter price of item : ";
        cin >> p;
        i[k].setdata(i[k].id,i[k].itemname,p);
    }
}

void deleteItem(Items *i,int *x) {
    int id,j=0,k=0,flag=0;
    cout << "\nEnter id : ";
    cin >> id;
    for(j=0;j<*x;j++)
    {
        if(id==i[j].id)
        {
            flag = 1;
            k = j;
            break;
        }
    }
    if(flag==0)
    {
        cout << "\nItem not found";
        return;
    }
    else
    {
        if(j<*x)
        {
            for(j=k;j<*x;j++)
            {
                i[j] = i[j+1];
            }
        }
        (*x)--;
        cout << "\nItem Record deleted successfully";
    }
}

void getOrder(Items *i,int *x,int *b) {
    cout << "\n\nRestaurant Menu \n\n";
    displayItems(i,x);
    char ch='y';
    while(ch=='y' or ch=='Y') {
        int id,num;
        cout << "Enter Id : ";
        cin >> id;
        cout << "Enter Number of Items : ";
        cin >> num;
        genBill(i,x,id,num,b);
        cout << "Do you want to add more : (y/n) : ";
        cin >> ch;
    }
}

void genBill(Items *i,int *x,int id,int count,int *b)
{
    int totalbill=0;
    int j=0,k=0;
    for(j=0;j<*x;j++)
    {
        if(id==i[j].id)
        {
            totalbill = totalbill + (i[j].price * count);
        }
    }
    *b =  *b + totalbill;
}

void displayBill(int *b) {
    cout << "Your Total Bill is : " << *b << "\n\n";
}