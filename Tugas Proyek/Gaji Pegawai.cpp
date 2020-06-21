#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct data{
int NIP,
	gajiPokok,
	golongan,
	jamWajib,
	totalJamKerja,
	lembur,
	tunjangan,
	pajak,
	gajiBersih,
	totalGaji;
string nama;
};

int total (int jamLembur, int gol){
	if (gol == 1){
	return 500000 + (jamLembur*5000);
	}else if(gol == 2){
	return 300000 + (jamLembur*3000);
	}else if(gol == 3){
	return 250000 + (jamLembur*2000);
	}else if(gol == 4){
	return 100000 + (jamLembur*1500);
	}else if(gol == 5){
	return 50000 + (jamLembur*1000);
	}
}

bool perbandingan(data a, data b){
return a.NIP<b.NIP;
}

int main() {
int jumlahPegawai;
cout<<"Jumlah Pegawai : ";cin>>jumlahPegawai;
data pegawai [jumlahPegawai];
int objek, baris, flag;

//Menginput data pegawai
for(int i=0; i<jumlahPegawai; i++){
cout<<"\nNIP : ";cin>> pegawai[i].NIP;
cout<<"Nama Pegawai : ";cin>> pegawai[i].nama;
cout<<"Gaji Pokok : ";cin>> pegawai[i].gajiPokok;
cout<<"Golongan : ";cin>> pegawai[i].golongan;
cout<<"Jam Kerja Wajib: ";cin>> pegawai[i].jamWajib;
cout<<"Total Jam Kerja : ";cin>> pegawai[i].totalJamKerja;


cout<<endl;

//Menghitung tunjangan
pegawai[i].tunjangan = pegawai[i].gajiPokok*15/100;

//Menghitung pajak
pegawai[i].pajak = (pegawai[i].gajiPokok + pegawai[i].tunjangan)*10/100;

//Menghitung gaji bersih
pegawai[i].gajiBersih = pegawai[i].gajiPokok + pegawai[i].tunjangan - pegawai[i].pajak;

//Menghitung jam lembur
pegawai[i].lembur = pegawai[i].totalJamKerja - pegawai[i].jamWajib;

//Menghitung Total Gaji 
pegawai[i].totalGaji = total(pegawai[i].lembur, pegawai[i].golongan);

}
//Sorting pegawai berdasarkan NIP secara asc
sort(pegawai, pegawai+jumlahPegawai , perbandingan);

//Menampilkan data gaji pegawai
cout<<"\n\n\n\t\t\t\t\t\t====Data Gaji Pegawai====\n\n";
cout<<"No.\t"<<"NIP\t"<<"Nama\t"<<"Gaji Pokok\t"<<"Golongan\t"<<"Total Jam Kerja\t"<<"Jam Lembur\t"<<"Gaji Bersih\t"<<"Total Gaji\n";
		
		for(int j=0; j<jumlahPegawai; j++){
		cout<<j+1<<"\t"
			<<pegawai[j].NIP<<"\t"
			<<pegawai[j].nama<<"\t"
			<<pegawai[j].gajiPokok<<"\t\t"
			<<pegawai[j].golongan<<"\t\t"
			<<pegawai[j].totalJamKerja<<"\t\t"
			<<pegawai[j].lembur<<"\t\t"
			<<pegawai[j].gajiBersih<<"\t\t"
			<<pegawai[j].totalGaji<<"\n";
		
		}

//Mencari data
cout<<"\n\nMasukkan NIP untuk mengetahui letak datanya : ";
cin>>objek;
	for (int k=0; k<jumlahPegawai; k++){
		if(pegawai[k].NIP == objek){
		flag=1;
		baris=k + 1;
	}
	
	}
	if(flag==1){
		cout<<"Data ditemukan pada baris ke- "<<baris;
		}else{
			cout<<"Data tidak ditemukan!";
		}
}
	

