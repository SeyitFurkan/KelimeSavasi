//KELİME_SAVAŞI

// Tanımlanmış Kütüphaneler

#include <iostream>
#include <string>
#include <ctime>
#include <string>	
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//Ana Sınıf
class Game {
public:
	string question;
	string answer;

};

//Bu sınıf, ana sınıf oyundan türetilmiştir

class Player : public Game {
private:
	string name;

public:
	string getName() {
		return name;
	}

	void setName(string n) {
		name = n;
	}
};

int main()
{
	cout << "Welcome to Word War." << endl;
	Player numberOne, numberTwo; // türetilmiş sınıftan oluşturulan nesneler
	string nameO, nameT;
	Game wordWar;
	int status = 1, row = 0;

	// Kullanıcı Girişi Alınıyor 

	cout << "Please enter the 1st Player's name: ";
	cin >> nameO;
	//Set / get işlevlerini kullandım çünkü ad değişkenleri özel olarak belirtildi
	numberOne.setName(nameO);

	cout << "Please enter the 2nd Player's name:";
	cin >> nameT;

	numberTwo.setName(nameT);

	while (status != 0) // Bu döngüde oyunculardan biri başarısız olana kadar oyuna başladım.Bunlardan biri başarısız olursa, durum değişkeni 0 olur ve döngü kesilir
	{
		string* question = new string[5]; // soru bulmak için string pointer dizisi kullandık

		question[0] = "Pantolon Paca Türleri";
		question[1] = "Yere Serilebilen Seyler";
		question[2] = "Gezegenler";
		question[3] = "Matematiksel Terimler";
		question[4] = "Mavi Tonlari";
		string output;

		// Cevapları depolamak için vektör kütüphanesini kullandım
		std::vector<std::vector<string>> answers = {
			{"dar", "duz", "boru","ispanyol"},
			{"hali", "kilim", "yaygı","yolluk","paspas"},
			{"merkür", "venüs", "dünya", "mars", "jüpiter","satürn","uranüs","neptün","plüton"},
			{"toplama","çıkarma", "çarpma","bölme","üs","kök","logaritma","limit","türev","integral"},
			{"açık","koyu","lacivert","turkuaz","gök mavisi"}
		};
		int i;

		// rastgele soru seçmek için rasgele sayı 0 ila 5 üretmek
		srand(time(NULL));

		i = (rand() % 5);


		// Mermiler ve ben orada bir oyuncu değiştiğinde
		if ((row + 1) % 2 == 0) {
			cout << numberTwo.getName() << "'s Turn ->" << endl;
		}
		else if ((row + 1) % 2 != 0)
		{
			cout << numberOne.getName() << "'s Turn ->" << endl;
		}

		cout << "Question " << row + 1 << ":" << endl << question[i] << ": ";
		cin >> output;

		row = row + 1;


		//Cevabı ve kullanıcıların girişini kontrol etmek için algoritma kütüphanesini kullandım
		if (std::find(answers[i].begin(), answers[i].end(), output) != answers[i].end()) {
			cout << "Correct!";

		}

		else
		{
			cout << "Wrong...";
			status = 0;
			if ((row + 1) % 2 == 0) {
				cout << numberOne.getName() << " is failed " << numberTwo.getName() << " is the WINNER!";
			}
			else
			{
				cout << numberTwo.getName() << " is failed " << numberOne.getName() << " is the WINNER";
			}
		}
	}


	return 0;
}

