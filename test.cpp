#include <bits/stdc++.h>

using namespace std;


double random1()
{
        return (double)rand() / RAND_MAX;
}

int main() {
    srand(time(0));
    double sum = 0;
    for (int i = 0; i < 10000; i++) {
        double t = random1();
        sum += t;
        cout << t << endl;
    }
    cout << (sum / 10000);
    return 0;

}
