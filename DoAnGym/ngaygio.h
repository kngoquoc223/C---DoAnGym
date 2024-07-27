#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct DATE {
	int ngay;
	int thang;
	int nam;
};
struct TIME {
	int gio = 1;
	int phut = 1;
};
int KT_ngay(int ngay, int thang, int nam);
int KT_gio(int gio, int phut);
void Doc_Ngaythangnam(ifstream &file, DATE &date);
void Doc_Gio(ifstream &file, TIME &time);
void Ghi_Ngaythangnam(ofstream &file, DATE &date);
void Ghi_Gio(ofstream &file, TIME &time);