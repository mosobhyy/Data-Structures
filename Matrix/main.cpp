#include <iostream>
#include "MyMatrix.cpp"

using namespace std;

int main()
{
    MyMatrix<string> M1(3, 2);
    MyMatrix<float> M2(4, 2);

    // Add elements to M1
    M1.addElementAt(0, 0, 'A');
    M1.addElementAt(0, 1, 'B');
    M1.addElementAt(1, 0, 'C');
    M1.addElementAt(1, 1, 'D');
    M1.addElementAt(2, 0, 'E');
    M1.addElementAt(2, 1, 'F');

    // Add elements to M2
    M2.addElementAt(0, 0, 1);
    M2.addElementAt(0, 1, 2);
    M2.addElementAt(1, 0, 3);
    M2.addElementAt(1, 1, 4);
    M2.addElementAt(2, 0, 5);
    M2.addElementAt(2, 1, 6);
    M2.addElementAt(3, 0, 7);
    M2.addElementAt(3, 1, 8);


    // Print elements using "getElementAt" member function
    cout << "\nPrint elements using \"getElementAt\" member function For M1\n";
    M1.getElementAt(0, 0);
    M1.getElementAt(0, 1);
    M1.getElementAt(1, 0);
    M1.getElementAt(1, 1);
    M1.getElementAt(2, 0);
    M1.getElementAt(2, 1);

    // Print elements using "displayMatrix" member function
    cout << "\n\n\nPrint elements using \"displayMatrix\" member function For M2\n";
    M2.displayMatrix();

    MyMatrix<float> M3(M2);

    cout << "\n\n\nPrint elements using \"displayMatrix\" member function For M3\n";
    M3.displayMatrix();

    return 0;
}
