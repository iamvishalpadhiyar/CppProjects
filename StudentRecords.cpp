#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int mark[5];
    int obtainedmark;
    float percentage;
    string grade;
    
    void setdata(int id, const string& n,int m1,int m2,int m3,int m4,int m5) {
        roll = id;
        name = n;
        mark[0] = m1;
        mark[1] = m2;
        mark[2] = m3;
        mark[3] = m4;
        mark[4] = m5;
        obtainedmark = m1 + m2 + m3 + m4 + m5;
        percentage = obtainedmark / 5;
        findgrade();
    }
    void findgrade(){
        if(percentage > 90){ grade = " destination "; }
        else if(percentage > 75 && percentage <= 90){ grade = " first Class"; }
        else if(percentage > 60 && percentage <= 75){ grade = " second Class"; }
        else if(percentage > 50 && percentage <= 60){ grade = " third Class"; }
        else if(percentage > 33 && percentage <= 50){ grade = " Pass "; }
        else if(percentage > 0 && percentage <= 33) { grade = " fail "; }
        else { cout << "Invalid marks";}
    }
    void display() const {
        cout << "\nRoll no : " << roll << endl;
        cout << "Name : " << name << endl;
        cout << "Marks : " << mark[0]<< " " << mark[1]<< " " << mark[2]<< " " << mark[3]<< " " << mark[4] << endl;
        cout << "Obtained marks : " << obtainedmark <<" Total marks : 500 " << endl;
        cout << "Percentage : " << percentage << "% and Grade : " << grade << endl;
    }
};

void info();
void newdata(Student *s, int *i);
void onedisplay(const Student *s,int *i);
void alldisplay(const Student *s, int *i);
void deleteRecord(Student *s, int *i, int id);
void deleteAllRecords(Student *s, int *i);

int main() {
    Student s[50];
    int i = 2;
    for(int j=0;j<50;j++)
    {
        s[j].roll = -1;
    }
    s[0].setdata(101,"Peter Parker",75,80,90,64,85);
    s[1].setdata(102,"Elon Musk",80,70,90,95,85);

    while (true) {
        int ch;
        info();
        cin >> ch;
        switch (ch) {
            case 1:
                newdata(s, &i);
                break;
            case 2:
                onedisplay(s,&i);
                break;
            case 3:
                alldisplay(s, &i);
                break;
            case 4:
                int id;
                cout << "Enter roll number to delete: ";
                cin >> id;
                deleteRecord(s, &i, id);
                break;
            case 5:
                deleteAllRecords(s, &i);
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Enter a valid operation" << endl;
                break;
        }
    }
    return 0;
}

void info() {
    cout << "\n\nStudent Records : \n\n";
    cout << "1. Enter new record.\n";
    cout << "2. Display Specific Record\n";
    cout << "3. Display all records.\n";
    cout << "4. Delete specific record.\n";
    cout << "5. Delete all records.\n";
    cout << "6. Exit\n";
    cout << "Enter Operation : ";
}

void newdata(Student *s, int *i) {
    int id,m1,m2,m3,m4,m5;
    cout << "\nEnter the roll no: ";
    cin >> id;
    cin.ignore();
    for(int j = 0; j < *i; j++) {
        if(id == s[j].roll) {
            cout << "Record already entered.\n";
            return;
        }
    }
    cout << "Enter the name: ";
    string name;
    getline(cin, name);
    cout << "Enter five sub marks : \n";
    cin >> m1 >> m2 >> m3 >> m4 >> m5;
    s[*i].setdata(id,name,m1,m2,m3,m4,m5);
    (*i)++;
    cout << "Record Successfully Entered\n";
}

void alldisplay(const Student *s, int *i) {
    for (int j = 0; j < *i; j++) {
        s[j].display();
        cout << "-------------------" << endl;
    }
}

void onedisplay(const Student *s,int *i) {
    int id,j,k=0;
    cout << "Enter roll number to display: ";
    cin >> id;
    cin.ignore();
    for(j = 0;j < *i;j++) {
        if(s[j].roll == id) {
            k=1;
            s[j].display();
            break;
        }
    }
    if(k==0)
    {
        cout << "Record not found";
    }
}

void deleteRecord(Student *s, int *i, int id) {
    int j;
    for (j = 0; j < *i; j++) {
        if (s[j].roll == id) {
            break;
        }
    }
    if (j < *i) {
        for (int k = j; k < (*i) - 1; k++) {
            s[k] = s[k + 1];
        }
        (*i)--;
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

void deleteAllRecords(Student *s, int *i) {
    *i = 0;
    cout << "All records deleted successfully.\n";
}
