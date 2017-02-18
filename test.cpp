#include <bits/stdc++.h>
#include "cg2d.hpp"
#include "c++11.hpp"

using namespace std;
using namespace hobo;

vector<int> q;

int main() {
    for (int i = 0; i < 100; i++)
        q.push_back(i);
    ContainerPrint(ContainerShuffle(q));
    return 0;
}
