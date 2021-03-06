// Pointers1.cpp : Defines the entry point for the console application.
// Developed by Derek Flood


#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <cstdlib>

typedef void(*questionPtr)(void);

using namespace std;
void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question8();
void question9();
void question10();

int main()
{
    std::map<int, questionPtr> functions;
    functions[1] = question1;
    functions[2] = question2;
    functions[3] = question3;
    functions[4] = question4;
    functions[5] = question5;
    functions[6] = question6;
    functions[7] = question7;
    functions[8] = question8;
    functions[9] = question9;
    functions[10] = question10;
    int choice;
    do
    {
        cout << "Please select a question to view, -1 to exit " << endl;

        cin >> choice;
        cin.ignore(1000, '\n');
        if (functions.find(choice) != functions.end())
        {
            functions[choice]();
        }
        else if (choice != -1)
        {
            cout << "Function not found" << endl;
        }

    } while (choice != -1);

    return 0;
}


void question1()
{}

// Q2 ***********************************************************************

void increment(double *ptr_double)   // declare a "pointer to a double" parameter
{
    *ptr_double += 0.01;    // dereference the pointer (to access the variable it points to), and increment it.
}
void question2()
{
    double d = 3.14;
    cout << "Original Value: " << d << endl;
    increment(&d);  // get the address of d, and pass that address as an argument
    cout << "New Value: " << d << endl;
}

// Q3 ***********************************************************************

void increment_v2(double *ptr_double)
{
    cout << "in increment_v2() ...pointer contains address: " << ptr_double << endl;
    *ptr_double+= 0.01;
}
void question3()
{
    double d = 3.14;
    cout << "Original Value: " << d << endl;
    cout << "Original Address: " << &d << endl;
    increment_v2(&d);
    cout << "New Value: " << d << endl;
}

// Q4 ***********************************************************************

double divide(const int* p1, const  int* p2) // use const, as this function does not need to modify the values it points to
{
    return static_cast<double>(*p1) / *p2;   // must cast or we get integer division
}

void question4()
{
    int x, y;
    cout << "Enter an int value for x ";
    cin >> x;
    cout << "Enter an int value for y ";
    cin >> y;
    double result = divide(&x, &y);
    cout << "Result: " <<  result << endl;

}

// Q5 ***********************************************************************

double sum_array_notation(const double arr[], const int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

double sum_pointer_notation(const double *ptr_array, const int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += *ptr_array;  // dereference the pointer to get current element
        ptr_array++;          // increment the pointer, i.e. move it to next element in array
    }
    return total;
}

void question5()
{
    double d[5] = {1.1,2.2,3.3,4.4,5.5};
    cout << "Sum 1 (Array Notation): " << sum_array_notation(d, 5) << endl;
    cout << "Sum 2 (Pointer Notation) : " << sum_pointer_notation(d, 5) << endl;
}

// Q6  ***********************************************************************

void doubleValues(double * ptr_array, int size) // we do NOT use const, as we wish to change the values pointed at
{
    for (int i = 0; i < size; i++)
    {
        *ptr_array *= 2;    // double the value and assign it back into the element
        ptr_array++;
    }
}
void question6()
{
    double d[10] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.5};
    doubleValues(d, 10);
    for (int i = 0; i < 10; i++)
    {
        if (i != 0)
            cout << ", ";
        cout << d[i];

    }
    cout << endl;
}

// Q7 ***********************************************************************

int strcmp(const char * s1, const char * s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
    }
    return (*s1 - *s2) <0 ? -1 : (*s1 - *s2)==0?0:1;
}
void question7()
{
    char str1[] = "Are these the same ? or not";
    char str2[] = "Are these the same ? ";
    int result = strcmp(str1, str2);
    cout << "Result1 : " << result<<endl;

    char str12[] = "Are these the same ?";
    char str22[] = "Are these the same ?  or not";
    result = strcmp(str12, str22);
    cout << "Result 2: " << result << endl;

    char str13[] = "Are these the same ?";
    char str23[] = "Are these the same ?";
    result = strcmp(str13, str23);
    cout << "Result 3: " << result << endl;

    char str14[] = "Are these the same ?";
    char str24[] = "BAre these the same ?";
    result = strcmp(str14, str24);
    cout << "Result 4: " << result << endl;
}
void question8()
{}
void question9()
{}
void question10()
{}