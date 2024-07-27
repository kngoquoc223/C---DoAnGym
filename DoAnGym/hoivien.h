#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"ngaygio.h"
#include<ctime>
int const M = 101;
using namespace std;
struct THETAP
{
	string Mathe;
	string Tengoitap;
	int Sotien;
	DATE Ngaydangky;
	DATE Ngayhethan;
};
struct NODETHETAP
{
	THETAP data;
	NODETHETAP *link;
};
typedef struct NODETHETAP *NODEPTRTHETAP;
struct HOIVIEN
{
	string Mahoivien;
	string Hoten;
	DATE Ngaysinh;
	string sdt;
	NODEPTRTHETAP Thetap;
};
struct NODEHOIVIEN {
	HOIVIEN data;
	NODEHOIVIEN *link;
};
typedef NODEHOIVIEN *NODEPTRHOIVIEN;
void khoiTaoBangBam();
void duyetBangBam();
void nhapTheTap(NODEPTRTHETAP &list);
void initTheTap(NODEPTRTHETAP &list);
void ktTheTap(NODEPTRHOIVIEN list, string ma);
void capNhatMaHoiVien(NODEPTRHOIVIEN list, string maHoiVien);
void capNhatMaTheTap(NODEPTRHOIVIEN list, char* maTheTap);
void dangKyTheTap(NODEPTRHOIVIEN &list, string ma);
void ktTheTap(NODEPTRHOIVIEN list, string ma);
void xoaTheTap(NODEPTRHOIVIEN &list, string ma);
void xuatDanhSachTheTap(NODEPTRHOIVIEN list);
void nhapHoiVien(NODEPTRHOIVIEN &list);
void initHoiVien(NODEPTRHOIVIEN &list);
void themHoiVien(NODEPTRHOIVIEN &list);
void docDsHoiVien(NODEPTRHOIVIEN &dshv);
void ktHoiVien(NODEPTRHOIVIEN list, string ma);
void xoaHoiVien(NODEPTRHOIVIEN &list, string ma);
void xuatHoiVienVaTheTap(NODEPTRHOIVIEN list); 
NODEPTRHOIVIEN timHoiVien(NODEPTRHOIVIEN list, string ma);
void ghiDsHoiVien(NODEPTRHOIVIEN list);
//void xoaTheTapHetHan(NODEPTRHOIVIEN list);
void giaiPhongHoiVien(NODEPTRHOIVIEN &list);
void giaiPhongTheTap(NODEPTRTHETAP &list);
void ktHoiVienTen(NODEPTRHOIVIEN list, string ten);
void xuatHoiVienTheoTen(NODEPTRHOIVIEN list, string ten);
void xuatHoiVienTheoTen1(NODEPTRHOIVIEN list, char* ten);