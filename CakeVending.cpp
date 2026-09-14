#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structura care reprezintă o prăjitură
struct Cake {
	string name;
	double price;

	Cake(const string& n, double p) : name(n), price(p) {}
};

class CakeVendingMachine {
private:
	int cakeCount;
	vector<Cake> cakeList;

public:
	CakeVendingMachine(int initialCount) : cakeCount(initialCount) {
		// Adăugăm câteva prăjituri în lista
		cakeList.push_back(Cake("Prajitura cu ciocolata", 2.50));
		cakeList.push_back(Cake("Cheesecake", 3.00));
		cakeList.push_back(Cake("Prajitura cu fructe", 2.75));
	}

	void displayMenu() {
		cout << "Bine ati venit la automatul de prajituri!\n";
		cout << "Meniu:\n";
		cout << "1. Cumpara prajitura\n";
		cout << "2. Verifica stocul\n";
		cout << "3. Inchide\n";
	}

	void displayCakeMenu() {
		cout << "Meniu Prajituri:\n";
		for (size_t i = 0; i < cakeList.size(); ++i) {
			cout << i + 1 << ". " << cakeList[i].name << " - " << cakeList[i].price << " Lei\n";
		}
	}

	void sellCake(size_t choice) {
		if (choice >= 1 && choice <= cakeList.size()) {
			if (cakeCount > 0) {
				cout << "Ai cumparat o prajitura " << cakeList[choice - 1].name << ". Pofta buna!\n";
				cakeCount--;
			}
			else {
				cout << "Ne pare rau, nu mai sunt prajituri disponibile.\n";
			}
		}
		else {
			cout << "Optiune invalida.\n";
		}
	}

	void checkStock() {
		cout << "Stocul curent de prajituri: " << cakeCount << "\n";
	}
};

int main() {
	CakeVendingMachine vendingMachine(10);

	int mainChoice, cakeChoice;

	do {
		vendingMachine.displayMenu();
		cout << "Alege o optiune: ";
		cin >> mainChoice;

		switch (mainChoice) {
		case 1:
			vendingMachine.displayCakeMenu();
			cout << "Alege prajitura: ";
			cin >> cakeChoice;
			vendingMachine.sellCake(cakeChoice);
			break;
		case 2:
			vendingMachine.checkStock();
			break;
		case 3:
			cout << "Multumim pentru vizita!\n";
			break;
		default:
			cout << "Optiune invalida. Te rugam sa alegi din nou.\n";
		}
	} while (mainChoice != 3);

	return 0;
}
