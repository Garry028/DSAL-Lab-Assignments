#include <bits/stdc++.h>
#include <string>
using namespace std;
class Student_DataBase;
class Student
{
private:
    string Roll_Number, Name, Div, Address;

public:
    Student()
    {
        Roll_Number = "";
        Name = "";
        Div = "";
        Address = "";
    }
    void Enter_Data()
    {
        cout << "Enter Your Name " << endl;
        getline(cin >> ws, Name);
        cout << "Enter Your Roll Number " << endl;
        getline(cin, Roll_Number);
        cout << "Enter your Division " << endl;
        cin >> Div;
        cout << "Enter Your Address " << endl;
        getline(cin >> ws, Address);
    }

    friend ofstream &operator<<(ofstream &ofs, Student s);
    friend ifstream &operator>>(ifstream &ifs, Student &s);
    friend ostream &operator<<(ostream &os, Student &s);
    friend class Student_DataBase;
};
class Student_DataBase
{
private:
    string Roll_Number, Name, Div, Address;

public:
    void Write_Data()
    {
        ofstream ofs;
        ofs.open("text_file.txt", ios::app);
        ofs << Name << endl;
        ofs << Roll_Number << endl;
        ofs << Div << endl;
        ofs << Address << endl;
        ofs.close();
    }
    void Read_Data()
    {
        ifstream ifs;
        ifs.open("text_file.txt");

        getline(ifs >> ws, Name);
        getline(ifs >> ws, Roll_Number);
        ifs >> Div;
        getline(ifs >> ws, Address);

        ifs.close();
    }
};
ofstream &operator<<(ofstream &ofs, Student s)
{
    ofs << s.Name << endl;
    ofs << s.Roll_Number << endl;
    ofs << s.Div << endl;
    ofs << s.Address << endl;
    return ofs;
}
ifstream &operator>>(ifstream &ifs, Student &s)
{

    getline(ifs >> ws, s.Name);
    getline(ifs >> ws, s.Roll_Number);
    ifs >> s.Div;
    getline(ifs >> ws, s.Address);

    return ifs;
}
ostream &operator<<(ostream &os, Student &s)
{
    os << "Name is " << s.Name << endl;
    os << "Roll Number is " << s.Roll_Number << endl;
    os << "Division is " << s.Div << endl;
    os << "Address is " << s.Address << endl;
    return os;
}
int main()
{
    Student s;
    Student_DataBase db;
    s.Enter_Data();
    db.Write_Data();
    db.Read_Data();

    ofstream ofs;
    ofs.open("text_file.txt");
    ofs << s;
    ofs.close();

    ifstream ifs;
    ifs.open("text_file.txt");
    ifs >> s;
    ifs.close();

    cout << s;

    return 0;
}