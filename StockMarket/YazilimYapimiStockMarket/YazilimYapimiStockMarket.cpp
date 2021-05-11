#include <iostream>
#include <string>

using namespace std;

struct Kullanici
{

	string ad = " ", soyad = " ", id = " ", password = " ", email = " ", adres = " ";
	long int tcno = 0;
	long int telno = 0;


}*kullanici;

struct tempProfil
{

	string tempUrunIsmi=" ", tempId=" ";
	int tempUrunKilosu=0, tempUrunFiyati=0, tempBakiye=0;

}*tempprofil;

struct Profil
{

	string urunIsmi = " ", id = " ";
	int urunKilosu = 0, urunFiyati = 0, bakiye = 0;

}*profil;

Kullanici VeriAl();

void sil(tempProfil*);

int main()
{
	Kullanici kllnc;
	int secim, aktifkullanici = 0, giris=0, onlinekullanici, m = 0, g = 0;

	kullanici = new Kullanici[100];
	tempprofil = new tempProfil[100];
	profil = new Profil[100];

	flag1:
	cout << "1-Login" << endl; 
	cout << "2-Alici ve Saticinin Bilgi Giris Ekrani" << endl;
	cout << "3-Admin Urun ve Para Onay" << endl;
	cout << "4-Kullancilar" << endl;
	cin >> secim;

	if (secim == 1) {
		string geciciid, gecicipassword;
		flag5:
		cout << "Id: " << endl;
		cin >> geciciid;
		cout << "Sifre: " << endl;
		cin >> gecicipassword;
		for (int i = 0; i < aktifkullanici;i++) {

			if (geciciid == kullanici[i].id && gecicipassword == kullanici[i].password) {
				cout << "Giris Basarili" << endl;
				giris = 1;
				onlinekullanici = i;
				goto flag2;
			}
			
		}

		if (giris == 0) {

			cout << "Yanlis Giris" << endl;
			goto flag5;
		
		}

	}

	else if (secim == 2) {
		kllnc = VeriAl();
		kullanici[aktifkullanici] = kllnc;
		aktifkullanici++;
		goto flag1;


	}

	else if (secim == 3) {

		int j = 0, k= sizeof(tempprofil);
		for (j = 0; j < k+1; j++) {
			if (tempprofil[j].tempId != " ") {
				cout << "Id:" << tempprofil[j].tempId << endl;
				cout << "Urun:" << tempprofil[j].tempUrunIsmi << endl;
				cout << "Kilosu:" << tempprofil[j].tempUrunKilosu << endl;
				cout << "Fiyati: " << tempprofil[j].tempUrunFiyati << endl;
				if (tempprofil[j].tempBakiye != 0) {
					cout << "Bakiye:" << tempprofil[j].tempBakiye << endl;
				}
				cout << "---------------------------------------------------" << endl;
			}
		}
		
			
			flag4:
			cout << "Kabul Ediyorsaniz 1 E, Kabul Etmiyorsaniz 2 Ye Basiniz" << endl;
			cin >> secim;

			if (secim == 1) {

				for (j = 0; j < k; j++) {
					if (tempprofil[j].tempId != " ") {
						profil[j].id=tempprofil[j].tempId;
						profil[j].urunIsmi=tempprofil[j].tempUrunIsmi;
						profil[j].urunKilosu=tempprofil[j].tempUrunKilosu;
						profil[j].urunFiyati = tempprofil[j].tempUrunFiyati;
					}

					if (tempprofil[j].tempBakiye != 0) {
						profil[j].bakiye=tempprofil[j].tempBakiye;
					}
				}
				tempProfil* array = tempprofil;

				sil(array);

				goto flag1;

			}
			else if (secim == 2) {

				tempProfil* array = tempprofil;

				sil(array);

				goto flag1;

			}
			else {

				cout << "Hatali Bir Secim Yaptiniz" << endl;
				goto flag4;

			}

		}
		

	

	else if (secim == 4) {

	for (m = 0; m < 100; m++) {
		if (kullanici[m].ad != " ") {
			cout << kullanici[m].id << endl;
		}
	}

	}

	else {
		cout << "Hatali Bir Secim Yaptiniz" << endl;
		goto flag1;
	}

flag2:
	if (giris == 1) {
		
		flag3:
		cout << "1-Urun Ekle" << endl;
		cout << "2-Para Yatir" << endl;
		cout << "3-Urun Al" << endl;
		cout << "4-Ana Ekrana Don" << endl;
		cin >> secim;
		if (secim == 1) {

			tempprofil[onlinekullanici].tempId = kullanici[onlinekullanici].id;
			cout << "Urun: " << endl;
			cin >> tempprofil[onlinekullanici].tempUrunIsmi;
			cout << "Urun Kac Kilo: " << endl;
			cin >> tempprofil[onlinekullanici].tempUrunKilosu;
			cout << "Urunun Fiyati: " << endl;
			cin >> tempprofil[onlinekullanici].tempUrunFiyati;
			goto flag3;

		}
		else if (secim == 2) {
			int gecicibak;
			tempprofil[onlinekullanici].tempId = kullanici[onlinekullanici].id;
			cout << "Yatirmak Istediginiz Tutar: " << endl;
			cin >> gecicibak;
			tempprofil[onlinekullanici].tempBakiye = +gecicibak;
			goto flag3;

		}
		else if (secim == 3) {
			int t = sizeof(profil);
			string alUrun;
			int alinmakIstenenKilo, y = 0;
			cout << "-------------------URUN LISTESI-------------------" << endl;
			
			for (y = 0; y < t+1; y++) {
				if (profil[y].id != " " && profil[y].urunKilosu != 0) {
					cout << "Id:" << profil[y].id << endl;
					cout << "Urun:" << profil[y].urunIsmi << endl;
					cout << "Kilosu:" << profil[y].urunKilosu << endl;
					cout << "Fiyati: " << profil[y].urunFiyati << endl;
					cout << "---------------------------------------------------" << endl;
				}				
			}
			
			cout << "Urununu Almak Istediginiz Saticinin Id'sini Giriniz: " << endl;
			cin >> alUrun;
			cout << "Almak Istediginiz Kilo: " << endl;
			cin >> alinmakIstenenKilo;
			
			for (y = 0; y < t+1; y++) {
				int res = alUrun.compare(profil[y].id);
				
				if (res == 0) {

					if (alinmakIstenenKilo <= profil[y].urunKilosu) {
						if (profil[y].urunKilosu * profil[y].urunFiyati <= profil[onlinekullanici].bakiye) {
							profil[y].bakiye = +profil[y].urunKilosu * profil[y].urunFiyati;
							profil[onlinekullanici].bakiye = profil[onlinekullanici].bakiye - profil[y].urunKilosu * profil[y].urunFiyati;
							profil[y].urunKilosu = profil[y].urunKilosu - alinmakIstenenKilo;
						}
						else {
							cout << "Yetersiz Bakiye" << endl;
							cout << "Bakiyeniz: " << profil[onlinekullanici].bakiye;
							goto flag3;
						}
					}
					else {
						cout << "Yetersiz Kilo" << endl;
						cout << "Bu satici " << profil[y].urunKilosu << " kilo " << alUrun << " bulundurmaktadır" << endl;
						goto flag3;
					}
					g++;
					cout << "Alim Islemi Gerceklesti" << endl;
					goto flag3;
					
				}
				
			}
		if (g == 0)
		{
			cout << "Aradiginiz Urun Bulunmamaktadir" << endl;
			goto flag3;
		}

		}
		else if (secim == 4) {

			goto flag1;

		}
		else {
			cout << "Hatali Bir Secim Yaptiniz" << endl;
			goto flag3;
		}


	}

	return 0;

}

Kullanici VeriAl() {

	Kullanici kl;
	cout << "Adiniz: " << endl;
	cin >> kl.ad;
	cout << "Soyadiniz: " << endl;
	cin >> kl.soyad;
	cout << "Id Belirleyiniz: " << endl;
	cin >> kl.id;
	cout << "Sifre Belirleyiniz: " << endl;
	cin >> kl.password;
	cout << "TC Kimlik No: " << endl;
	cin >> kl.tcno;
	cout << "Tel No: " << endl;
	cin >> kl.telno;
	cout << "Mail Adresiniz: " << endl;
	cin >> kl.email;
	cout << "Adresiniz: " << endl;
	cin >> kl.adres;
	cout << endl << "Kayit Oldunuz" << endl;
	return kl;

}

void sil(tempProfil* array) {

	delete[] array;

}

