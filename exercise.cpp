#include <iostream>
#include <vector>

using namespace std;

class pengarang;
class penerbit;

class buku {
public:
	string namaBuku;
	buku(string pNamaBuku) : namaBuku(pNamaBuku){}
};

class penerbit {
public:
	string namaPenerbit;
	vector<pengarang*>daftar_Pengarang;

	penerbit(string pNamaPenerbit) : namaPenerbit(pNamaPenerbit){}

	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

class pengarang {
public:
	string namaPengarang;
	vector<penerbit*>daftar_Penerbit;
	vector<buku*>daftar_Buku;

	pengarang(string pNamaPengarang) : namaPengarang (pNamaPengarang){}

	void tambahPenerbit(penerbit*);
	void cetakPenerbit();

	void tambahBuku(buku*);
	void cetakBuku();
};


void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_Pengarang.push_back(pPengarang);
}

void penerbit::cetakPengarang() {
	cout << "Daftar pengarang pada penerbit \"" << this -> namaPenerbit << "\":\n";
	for (auto& a : daftar_Pengarang) {
		cout << a->namaPengarang << "\n";
	}
	cout << endl;
}


void pengarang::tambahPenerbit(penerbit* pPenerbit){
	daftar_Penerbit.push_back(pPenerbit);
}

void pengarang::cetakPenerbit() {
	cout << "Daftar Daftar penerbit yang diikuti \"" << this->namaPengarang << "\":\n";
	for (auto& a : daftar_Penerbit) {
		cout << a->namaPenerbit << "\n";
	}
	cout << endl;
}

void pengarang::tambahBuku(buku* pBuku) {
	daftar_Buku.push_back(pBuku);
}

void pengarang::cetakBuku() {
	cout << "Daftar buku yang dikarang \"" << this -> namaPengarang << "\":\n";
	for (auto& a : daftar_Buku) {
		cout << a->namaBuku << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varPenerbit1 = new penerbit("Gama Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");

	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Giga");
	pengarang* varPengarang4 = new pengarang("Asroni");

	buku* varBuku1 = new buku("Fisika");
	buku* varBuku2 = new buku("Algoritma");
	buku* varBuku3 = new buku("Basisdata");
	buku* varBuku4 = new buku("Dasar Pemrograman");
	buku* varBuku5 = new buku("Matematika");
	buku* varBuku6 = new buku("Multimedia 1");

	varPenerbit1->tambahPengarang(varPengarang1);
	varPenerbit1->tambahPengarang(varPengarang2);
	varPenerbit1->tambahPengarang(varPengarang3);
	
	varPenerbit2->tambahPengarang(varPengarang4);
	varPenerbit2->tambahPengarang(varPengarang3);

	varPengarang3->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit2);

	varPengarang1->tambahBuku(varBuku1);
	varPengarang1->tambahBuku(varBuku2);
	varPengarang2->tambahBuku(varBuku3);
	varPengarang4->tambahBuku(varBuku4);
	varPengarang3->tambahBuku(varBuku5);
	varPengarang3->tambahBuku(varBuku6);

	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();

	varPengarang3->cetakPenerbit();

	varPengarang1->cetakBuku();
	varPengarang2->cetakBuku();
	varPengarang4->cetakBuku();
	varPengarang3->cetakBuku();

	return 0;

}
