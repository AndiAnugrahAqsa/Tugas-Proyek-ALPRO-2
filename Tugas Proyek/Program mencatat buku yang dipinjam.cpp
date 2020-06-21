#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct data {
	string kodeBuku, judulBuku, id_peminjam, nama_peminjam;
	int lama_peminjaman, jumlahDenda, keterlamabatan;
	
};

bool perbandingan(data a, data b){
return a.kodeBuku <  b.kodeBuku;
}

int main (){

int jumlahBuku;
int batasWaktu = 1;
int dendaPerminggu = 1000;
int flag;
int baris;
string objek;
cout<<"Jumlah buku : ";
cin>>jumlahBuku;
data peminjaman[jumlahBuku];

cout<<endl;

//Memasukkan identitas buku dan identitas peminjam
for (int i = 0; i<jumlahBuku; i++){	
cout<<"Kode Buku : ";cin>> peminjaman[i].kodeBuku;
cout<<"Judul Buku : ";cin>> peminjaman[i].judulBuku;
cout<<"ID Peminjam : ";cin>> peminjaman[i].id_peminjam;
cout<<"Nama Peminjam : ";cin >> peminjaman[i].nama_peminjam;
cout<<"Lama Peminjaman : ";cin >> peminjaman[i].lama_peminjaman;

cout<<endl;

//Menghitung keterlambatan pemingembalian buku
peminjaman[i].keterlamabatan = peminjaman[i].lama_peminjaman - batasWaktu;

//Menghitung jumlah denda
peminjaman[i].jumlahDenda = peminjaman[i].keterlamabatan * dendaPerminggu;
}

//Sorting berdasarkan kode buku secara asc
sort(peminjaman, peminjaman+jumlahBuku , perbandingan);

//Menampilkan data peminjaman
cout<<"\n\n\n\t\t\t\t\t\t====Data Peminjaman====\n\n";
cout<<"Kode Buku\t"<<"Judul Buku\t"<<"ID Peminjam\t"<<"Nama Peminjam\t"
	<<"Lama Peminjaman\t"<<"Batas Waktu\t"<<"Keterlambatan\t"<<"Jumlah Denda\n";

for (int j = 0; j<jumlahBuku; j++){
	cout<<peminjaman[j].kodeBuku<<"\t\t";
	cout<<peminjaman[j].judulBuku<<"\t\t";
	cout<<peminjaman[j].id_peminjam<<"\t\t";
	cout<<peminjaman[j].nama_peminjam<<"\t\t";
	cout<<peminjaman[j].lama_peminjaman<<" minggu\t";
	cout<<batasWaktu<<" minggu\t";
	cout<<peminjaman[j].keterlamabatan<<" minggu\t";
	cout<<peminjaman[j].jumlahDenda<<"\n";
	
}
cout<<"\n\nMasukkan Kode Buku untuk mengetahui letak data buku : ";
cin>>objek;
	for (int k=0; k<jumlahBuku; k++){
		if(peminjaman[k].kodeBuku == objek){
		flag=1;
		baris=k + 1;
		}	
	}
	if(flag==1){
		cout<<"Data ditemukan pada baris ke - "<<baris;
		}else{
			cout<<"Data tidak ditemukan!";
		}
}
