#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"ngaygio.h"
using namespace std;
struct THIETBI
{
	string Tenthietbi;
	string Maso;
	DATE Ngaynhapve;
	string Xuatxu;
	string Tinhtrang;
};
struct NODETHIETBI {
	THIETBI data;
	NODETHIETBI *link;
};
typedef struct NODETHIETBI *NODEPTRTHIETBI;
void nhapThietBi(NODEPTRTHIETBI &list);
void xuatThietBi(NODEPTRTHIETBI list);
void docDsThietBi(NODEPTRTHIETBI &dstb);
void initThietBi(NODEPTRTHIETBI &list);
void themThietBi(NODEPTRTHIETBI &list);
void xoaThietBi(NODEPTRTHIETBI &list, string ma);
void capNhatThietBi(NODEPTRTHIETBI &list, string ma);
void traThongTinThietBi(NODEPTRTHIETBI list, string ma);
void ghiDsThietBi(NODEPTRTHIETBI list);
void giaiPhongThietBi(NODEPTRTHIETBI &list);