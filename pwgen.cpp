#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Eingabeformat: pwgen [anzahl zeichen]" << endl;
        exit(-1);
    }
    string vorrat = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" \
                    "1234567890!%$&()=?+";
    time_t t;
    srand((unsigned long) &t);
    for (unsigned int i = 0; i < atoi(*(argv + 1)); cout << vorrat[rand() % vorrat.length()], i++);
    cout << endl;
    return 0;
}

