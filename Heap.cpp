// Read  the  marks  obtained  by  students  of  second  year  in  an  online  examination  of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.
#include <iostream>
using namespace std;
#define max 20
class Student
{
private:
    int Marks_Min_Heap[max];
    int Marks_Max_Heap[max];

public:
    Student()
    {
        for (int i = 0; i < max; i++)
        {
            Marks_Min_Heap[i] = 0;
        }
    }
    void InsertMinHeap(int Total_Students);
    void InsertMaxHeap(int Total_Students);
    void Display_Min_Heap(int Total_Students);
    void Display_Max_Heap(int Total_Students);
    void showmax(int Total_Students);
    void showmin();
};

void Student::InsertMinHeap(int Total_Students)
{
    for (int i = 0; i <= Total_Students; i++)
    {
        cout << "Enter marks of the Students" << endl;
        cin >> Marks_Min_Heap[i];

        int j = i;          // index is equal to j
        int Parent = j / 2; // j is index

        while (Marks_Min_Heap[j] < Marks_Min_Heap[Parent] && j != 0) // while the new elements value is less than it's parent
        {
            int Temp = Marks_Min_Heap[j]; // Swap the data of parent and the newly inserted element.
            Marks_Min_Heap[j] = Marks_Min_Heap[Parent];
            Marks_Min_Heap[Parent] = Temp;

            j = Parent; // now the j moves to parents position
            Parent = j / 2;
        }
    }
}
void Student::InsertMaxHeap(int Total_Students)
{
    for (int i = 0; i <= Total_Students; i++)
    {
        cout << "Enter marks of the Students" << endl;
        cin >> Marks_Max_Heap[i];

        int j = i;          // index is equal to j
        int Parent = j / 2; // j is index

        while (Marks_Max_Heap[j] > Marks_Max_Heap[Parent] && j != 0) // while the new elements value is less than it's parent
        {
            int Temp = Marks_Max_Heap[j]; // Swap the data of parent and the newly inserted element.
            Marks_Max_Heap[j] = Marks_Max_Heap[Parent];
            Marks_Max_Heap[Parent] = Temp;

            j = Parent; // now the j moves to parents position
            Parent = j / 2;
        }
    }
}

void Student::Display_Min_Heap(int Total_Students)
{

    cout << "Heap is ";
    for (int i = 0; i <= Total_Students; i++)
    {
        cout << " " << Marks_Min_Heap[i];
    }
}

void Student::Display_Max_Heap(int Total_Students)
{

    cout << "Heap is ";
    for (int i = 0; i <= Total_Students; i++)
    {
        cout << " " << Marks_Max_Heap[i];
    }
}

void Student::showmax(int Total_Students)
{

    cout << "Maxximum marks in Min Heap: " << Marks_Max_Heap[0];
}

void Student::showmin()
{
    cout << "Minimum marks in Min Heap: " << Marks_Min_Heap[0]; // in the min heap the minimum element will be the 1st element
}

int main()
{
    Student s1;
    Student s2;
    int n, choice, total;
    int flag = true;
    cout << endl;
    cout << "Welcome to Students Exam Data !!!!" << endl;
    cout << "What do you want to do??" << endl;
    cout << endl;
    while (flag)
    {
        cout << "\n1.Enter marks of the Student to Min Heap\n2.Enter marks of the Student to Max Heap\n3.Display Min heap\n4.Display Max heap\n5.Find Min Marks_Min_Heap\n6.Find Max Marks_Max_Heap\n7.Exit\n\nSelect an Option" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many Students are there ?" << endl;
            cin >> total;
            s1.InsertMinHeap(total);
            break;
        case 2:
            cout << "How many Students are there ?" << endl;
            cin >> total;
            s2.InsertMaxHeap(total);
            break;
        case 3:
            s1.Display_Min_Heap(total);
            break;
        case 4:
            s2.Display_Max_Heap(total);
            break;
        case 5:
            s1.showmin();
            break;
        case 6:
            s2.showmax(total);
            break;
        case 7:
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
