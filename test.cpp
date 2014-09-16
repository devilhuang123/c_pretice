#include <iostream>
#include <stdio.h>
#include "Stack.cpp"
#include <vector>
using namespace std;

int main()
{
   int iarr[] = {1, 2, 3, 4, 5};

    vector<int> ivector(iarr, iarr + 5);

    for(int i = 0; i < ivector.size(); i++) {
        cout << ivector[i] << " ";
    }
    cout << endl;
    return 0;
}
