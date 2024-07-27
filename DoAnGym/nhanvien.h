#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"ngaygio.h"
using namespace std;
struct NHANVIEN {
	string Hoten;
	DATE Ngaysinh;
	string Sdt;
	string Manhanvien;
	DATE Ngaybatdau;
	TIME Giobatdaulamviec;
	TIME Gioketthuclamviec;
};
struct NODENHANVIEN
{
	NHANVIEN data;
	NODENHANVIEN *link;
};
typedef struct NODENHANVIEN *NODEPTRNHANVIEN;
void nhapNhanVien(NODEPTRNHANVIEN &list);
void xuatNhanVien(NODEPTRNHANVIEN list);
void docDsNhanVien(NODEPTRNHANVIEN &dsnv);
void initNhanVien(NODEPTRNHANVIEN &list);
void themNhanVien(NODEPTRNHANVIEN &list);
void xoaNhanVien(NODEPTRNHANVIEN &list, string ma);
void capNhatNhanVien(NODEPTRNHANVIEN &list, string ma);
void traThongTinNhanVien(NODEPTRNHANVIEN list, string ma);
void ghiDsNhanVien(NODEPTRNHANVIEN list);
void giaiPhongNhanVien(NODEPTRNHANVIEN &list);