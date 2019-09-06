#include <iostream>
#include "test/tester.h"
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;
    vector<int>  nuevo;
    auto iterador = nuevo.begin();
    Tester::execute();
    return EXIT_SUCCESS;
}
