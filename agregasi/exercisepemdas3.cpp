#include <iostream>																				
#include <vector>																				
using namespace std;																			

class pengarang;																				
class penerbit {																				
public:																							
	string nama_penerbit;																		
	vector<pengarang*> daftar_pengarang;														
	penerbit(string pNama) : nama_penerbit(pNama) {												
		cout << "penerbit \"" << nama_penerbit << "\" \n";										
	}

	void TambahPengarang(pengarang*);															
	void cetakPengarang();																		
};


// Kelas penerbit memiliki atribut nama_penerbit yang menyimpan nama penerbit.
// daftar_pengarang adalah vektor yang menyimpan pointer ke objek pengarang, merepresentasikan daftar pengarang yang terkait dengan penerbit ini.
// Konstruktor penerbit menerima parameter pNama yang digunakan untuk menginisialisasi atribut nama_penerbit.
// Metode TambahPengarang dan cetakPengarang dideklarasikan di dalam kelas penerbit dan akan diimplementasikan di luar kelas.


class pengarang {																				
public:																							
	string nama_pengarang;																		
	vector<penerbit*> daftar_penerbit;									-0						
	pengarang(string pNama) : nama_pengarang(pNama) {											
		cout << "pengarang \"" << nama_pengarang << "\" \n";									
	}

	void TambahPenerbit(penerbit*);																
	void cetakPenerbit();																		
};

// Kelas pengarang memiliki atribut nama_pengarang yang menyimpan nama pengarang.
// daftar_penerbit adalah vektor yang menyimpan pointer ke objek penerbit, merepresentasikan daftar penerbit yang diikuti oleh pengarang ini.
// Konstruktor pengarang menerima parameter pNama yang digunakan untuk menginisialisasi atribut nama_pengarang.
// Metode TambahPenerbit dan cetakPenerbit dideklarasikan di dalam kelas pengarang dan akan diimplementasikan di luar kelas


void penerbit::TambahPengarang(pengarang* pPengarang) {											
  daftar_pengarang.push_back(pPengarang);														
}


// Metode TambahPengarang diimplementasikan di luar kelas penerbit dan digunakan untuk menambahkan objek pengarang ke daftar_pengarang.
// Metode cetakPengarang diimplementasikan di luar kelas penerbit dan digunakan untuk mencetak daftar pengarang yang terkait dengan penerbit ini.

void penerbit::cetakPengarang() {																
	cout << "\nDaftar pengarang yang menaungi penerbit \"" << this->nama_penerbit << "\":\n";	
	for (auto& a : daftar_pengarang) {														
		cout << a->nama_pengarang << "\n";														
	}
	cout << endl;																				
}

void pengarang::TambahPenerbit(penerbit* pPenerbit) {										
	daftar_penerbit.push_back(pPenerbit);													
	pPenerbit->TambahPengarang(this);															

}

void pengarang::cetakPenerbit() {																
	cout << "Daftar penerbit yang diikuti pengarang \"" << this->nama_pengarang << "\":\n";		
	for (auto& a : daftar_penerbit) {															
		cout << a->nama_penerbit << "\n";
	}
	cout << endl;																				
}


int main() {                                                                                    // letak agregasi
	penerbit* VarPenerbit1 = new penerbit("Gama Press");										
	penerbit* VarPenerbit2 = new penerbit("Intan Pariwara");							
	pengarang* VarPengarang1 = new pengarang("Giga");											
	pengarang* VarPengarang2 = new pengarang("Joko");																		
	pengarang* VarPengarang3 = new pengarang("Asroni");											
	pengarang* Varpengarang4 = new pengarang("Lia");											

	VarPenerbit1->TambahPengarang(VarPengarang2);												
	VarPenerbit1->TambahPengarang(Varpengarang4);											
	VarPenerbit1->TambahPengarang(VarPengarang1);												
	VarPenerbit2->TambahPengarang(VarPengarang3);											
	VarPenerbit2->TambahPengarang(VarPengarang1);												
	VarPengarang1->TambahPenerbit(VarPenerbit2);											
	VarPengarang1->TambahPenerbit(VarPenerbit1);											

	VarPenerbit1->cetakPengarang();																
	VarPenerbit2->cetakPengarang();																
	VarPengarang1->cetakPenerbit();																


	return 0;																			
}
