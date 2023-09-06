#include <iostream>
#include "Algo.h"

using namespace std;
using namespace Algo;

int main()
{
    double left = -10.0; // Set the left boundary
    double right = 10.0; // Set the right boundary

    double result = ternary_search(left, right);

    cout << "The maximum is at: " << result << endl;
    return 0;
}