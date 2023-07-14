#include <iostream>

using namespace std;

int solution(int X, int Y, int D);

int main()
{
    int x = 10;
    int y = 85;
    int d = 30;
    cout << "Output is: " << solution(x, y, d) << endl;
}

int solution(int X, int Y, int D)
{
    // check for valid input
    if (D <= 0)
    {
        return 0;
    }

    if (X > Y)
    {
        return 0;
    }

    int distance_to_cover = Y - X;

    // if the distance cannot be covered perfectly with a certain number of movements
    if ((distance_to_cover % D) > 0)
    {
        // return the number of movements needed plus one for the partial movement
        return ((distance_to_cover / D) + 1);
    }

    // return the number of movements needed
    return (distance_to_cover / D);
}
