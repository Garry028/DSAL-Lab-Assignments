// Read  the  marks  obtained  by  students  of  second  year  in  an  online  examination  of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.
#include <iostream>
using namespace std;
#define max 20
class Student
{
private:
    int Marks[max];

public:
    Student()
    {
        for (int i = 0; i < max; i++)
        {
            Marks[i] = 0;
        }
    }
    void InsertHeap(int Total_Students);
    void displayheap(int Total_Students);
    void showmax(int Total_Students);
    void showmin();
};

void Student::InsertHeap(int Total_Students)
{
    for (int i = 1; i <= Total_Students; i++)
    {
        cout << "Enter marks of the Students" << endl;
        cin >> Marks[i];

        int j = i;          // index is equal to j
        int Parent = j / 2; // j is index

        while (Marks[j] <= Marks[Parent] && j != 0) // while the new elements value is less than it's parent
        {
            int Temp = Marks[j]; // Swap the data of parent and the newly inserted element.
            Marks[j] = Marks[Parent];
            Marks[Parent] = Temp;

            j = Parent;     // now the j moves to parents position
            Parent = j / 2; 
        }
    }
}

void Student::displayheap(int Total_Students)
{

    cout << "Heap is ";
    for (int i = 1; i <= Total_Students; i++)
    {
        cout << " " << Marks[i];
    }
}

void Student::showmax(int Total_Students)
{
    int max1 = Marks[0]; // initially 1st element will be maxximum
    for (int i = 1; i <= Total_Students; i++)
    {
        if (max1 < Marks[i]) // if element greater than max1 found then change the max1 to element.
        {
            max1 = Marks[i];
        }
    }
    cout << "Maximum marks: " << max1;
}

void Student::showmin()
{
    cout << "Minimum marks: " << Marks[1]; // in the min heap the minimum element will be the 1st element
}

int main()
{
    Student s1;
    int n, choice, total;
    int flag = true;
    cout << endl;
    cout << "Welcome to Students Exam Data !!!!" << endl;
    cout << "What do you want to do??" << endl;
    cout << endl;
    while (flag)
    {
        cout << "\n1.Enter marks of the Student\n2.Display Min heap\n3.Find Max Marks\n4.Find Min Marks\n5.Exit\n\nSelect an Option" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many Students are there ?" << endl;
            cin >> total;
            s1.InsertHeap(total);
            break;
        case 2:
            s1.displayheap(total);

            break;
        case 3:
            s1.showmax(total);

            break;
        case 4:
            s1.showmin();
            break;
        case 5:
            exit(0);
        default:
            break;
        }
        char flag2;
        cout << endl;
        cout << "Do you want to continue(y or n) :" << endl;
        cin >> flag2;
        if (flag2 == 'n')
        {
            flag = false;
        }
    }
    return 0;
}
