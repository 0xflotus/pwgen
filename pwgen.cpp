#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Eingabeformat: pwgen [anzahl zeichen]" << endl;
		exit(-1);
	}
	string vorrat = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" \
		"1234567890!%$&()=?+";
	int anz = atoi(*(argv + 1));
	char *erg = new char[anz];
	time_t t;
	srand((unsigned long)&t);

	for (unsigned int i = 0; i < anz; erg[i] = vorrat[rand() % vorrat.length()], i++);

	bool ziffer = false, buchstabe = false, sonder = false;
	for (unsigned int i = 0; i < anz; i++) {
		ziffer = !(erg[i]<'0' || erg[i]>'9');
		buchstabe = (erg[i]<'A' || erg[i]>'z');
		sonder = (erg[i]<'!' || erg[i]>'&');
	}

	for (unsigned int i = 0; i < anz; cout << *(erg + i), i++);
	delete[] erg;
	erg = nullptr;
	cout << endl;

	return 0;
}

