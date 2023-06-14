#include <iostream>
#include <vector>
using namespace std;


class buku
{
	string judul;

public:
	buku setJudul(string judul)
	{
		this->judul = judul;
		return *this; // chain fucntion
	}
	string getJudul()
	{
		return this->judul;
	}

} bukunya;

class penerbit {
public:
	string nama;
	penerbit(string pNama) :nama(pNama) {
		cout << "penerbit \"" << nama << "\" tidak ada\n";
	}
	~penerbit() {
		cout << "penerbit \"" << nama << "\" tidak ada\n";
	}
};

class pengarang {
public:
	string nama;
	pengarang(string pNama) :nama(pNama) {
		cout << "pengarang \"" << nama << "\" ada";
	}
	~pengarang() {
		cout << "pengarang \"" << nama << "\" tidak ada\n";
	}
};

int main() {
	cout << bukunya.setJudul("GamaPress").getJudul();
	penerbit;
	pengarang;

	return 0;
};
