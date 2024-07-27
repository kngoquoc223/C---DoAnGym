#include"hoivien.h"
#include"nhanvien.h"
#include"thietbi.h"
void menu(NODEPTRHOIVIEN dshv,NODEPTRNHANVIEN dsnv,NODEPTRTHIETBI dstb){
	string maTheTap;
	char maTheTap1[30];
	char tenHoiVien1[30];
	string maHoiVien;
	string maThietBi;
	string maNhanVien;
	string tenHoiVien;
	int chon, chon1, chon2, chon3;
	do {
		system("cls");
		cout << "\n-----------------QUAN LY PHONG TAP-------------------";
		cout << "\n========================MENU=========================";
		cout << "\nI                                                   I";
		cout << "\nI               1.Thao Tac Hoi Vien                 I";
		cout << "\nI               2.Thao Tac Nhan Vien                I";
		cout << "\nI               3.Thao Tac Thiet Bi                 I";
		cout << "\nI               0.Thoat                             I";
		cout << "\nI                                                   I";
		cout << "\n=====================================================";
		cout << "\nNhap chuc nang->";
		cin >> chon;
		switch (chon)
		{
		case 1:
			do
			{
				system("cls");
				cout << "\n==============THAO TAC HOI VIEN===============";
				cout << "\n|                                            |";
				cout << "\n|    1.Nhap Danh Sach Hoi Vien               |";
				cout << "\n|    2.Xuat Danh Sach Hoi Vien Va The Tap    |";
				cout << "\n|    3.Them Hoi Vien                         |";
				cout << "\n|    4.Xoa Hoi Vien                          |";
				cout << "\n|    5.Sua Ma Hoi Vien                       |";
				cout << "\n|    6.Tra Thong Tin Hoi Vien                |";
				cout << "\n|    7.Dang Ky The Tap                       |";
				cout << "\n|    8.Xuat Danh Sach The Tap                |";
				cout << "\n|    9.Tra Thong Tin The Tap                 |";
				cout << "\n|    10.Xoa The Tap                          |";
				cout << "\n|    11.Sua Ma The Tap                       |";
				//cout << "\n|    12.Tim Theo Ten Hoi Vien                |";
				cout << "\n|    0.Quay Ve Menu Chinh                    |";
				cout << "\n|                                            |";
				cout << "\n==============================================";
				cout << "\nNhap chuc nang->";
				cin >> chon1;
				cin.ignore();
				switch (chon1)
				{
				case 1:
					system("cls");
					nhapHoiVien(dshv);
					system("pause");
					break;
				case 2:
					system("cls");
					xuatHoiVienVaTheTap(dshv);
					system("pause");
					break;
				case 3:
					system("cls");
					themHoiVien(dshv);
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "\nNhap ma hoi vien muon xoa:";
					getline(cin, maHoiVien);
					xoaHoiVien(dshv, maHoiVien);
					cout << endl;
					system("pause");
					break;
				case 5:
					system("cls");
					cout << "\nNhap ma hoi vien can sua:";
					getline(cin, maHoiVien);
					capNhatMaHoiVien(dshv, maHoiVien);
					cout << endl;
					system("pause");
					break;
				case 6:
					system("cls");
					cout << "\nNhap ma hoi vien can tra thong tin:";
					getline(cin, maHoiVien);
					ktHoiVien(dshv, maHoiVien);
					cout << endl;
					system("pause");
					break;
				case 7:
					system("cls");
					cout << "\nNhap ma hoi vien muon dang ky the tap:";
					getline(cin, maHoiVien);
					dangKyTheTap(dshv, maHoiVien);
					cout << endl;
					system("pause");
					break;
				case 8:
					system("cls");
					xuatDanhSachTheTap(dshv);
					system("pause");
					break;
				case 9:
					system("cls");
					cout << "\nNhap ma the tap can xuat thong tin:";
					getline(cin, maTheTap);
					ktTheTap(dshv, maTheTap);
					cout << endl;
					system("pause");
					break;
				case 10:
					system("cls");
					cout << "\nNhap ma the tap can xoa:";
					getline(cin, maTheTap);
					xoaTheTap(dshv, maTheTap);
					cout << endl;
					system("pause");
					break;
				case 11:
					system("cls");
					cout << "\nNhap ma the tap can sua:";
					cin.getline(maTheTap1, 30);
					capNhatMaTheTap(dshv, maTheTap1);
					cout << endl;
					system("pause");
					break;
				//case 12:
				//	system("cls");
				//	//cout << "\nNhap ten hoi vien can tim:";
				//	//getline(cin, tenHoiVien);
				//	//ktHoiVienTen(dshv, tenHoiVien);
				//	//xuatHoiVienTheoTen(dshv, tenHoiVien);
				//	cout << "\nNhap ten hoi vien can tim:";
				//	cin.getline(tenHoiVien1, 30);
				//	xuatHoiVienTheoTen1(dshv, tenHoiVien1);
				//	cout << endl;
				//	system("pause");
				}
			} while (chon1 != 0);
			break;
		case 2:
			do
			{
				system("cls");
				cout << "\n===========THAO TAC NHAN VIEN===========";
				cout << "\n|                                      |";
				cout << "\n|    1.Nhap Nhan Vien                  |";
				cout << "\n|    2.Xuat Danh Sach Nhan Vien        |";
				cout << "\n|    3.Them Nhan Vien                  |";
				cout << "\n|    4.Xoa Nhan Vien                   |";
				cout << "\n|    5.Sua Ma Nhan Vien                |";
				cout << "\n|    6.Tra Thong Tin Nhan Vien         |";
				cout << "\n|    0.Quay Ve Menu Chinh              |";
				cout << "\n|                                      |";
				cout << "\n========================================";
				cout << "\nNhap chuc nang->";
				cin >> chon2;
				cin.ignore();
				switch (chon2)
				{
				case 1:
					system("cls");
					nhapNhanVien(dsnv);
					system("pause");
					break;
				case 2:
					system("cls");
					xuatNhanVien(dsnv);
					system("pause");
					break;
				case 3:
					system("cls");
					themNhanVien(dsnv);
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "\nNhap ma nhan vien can xoa:";
					getline(cin, maNhanVien);
					xoaNhanVien(dsnv, maNhanVien);
					cout << endl;
					system("pause");
					break;
				case 5:
					system("cls");
					cout << "\nNhap ma nhan vien can sua:";
					getline(cin, maNhanVien);
					capNhatNhanVien(dsnv, maNhanVien);
					cout << endl;
					system("pause");
					break;
				case 6:
					system("cls");
					cout << "\nNhap ma nhan vien can tra:";
					getline(cin, maNhanVien);
					traThongTinNhanVien(dsnv, maNhanVien);
					cout << endl;
					system("pause");
					break;
				}
			} while (chon2 != 0);
				break;
		case 3:
			do 
			{
				system("cls");
				cout << "\n===========THAO TAC THIET BI============";
				cout << "\n|                                      |";
				cout << "\n|    1.Nhap Thiet Bi                   |";
				cout << "\n|    2.Xuat Danh Sach Thiet Bi         |";
				cout << "\n|    3.Them Thiet Bi                   |";
				cout << "\n|    4.Xoa Thiet Bi                    |";
				cout << "\n|    5.Sua Ma Thiet Bi                 |";
				cout << "\n|    6.Tra Thong Tin Thiet Bi          |";
				cout << "\n|    0.Quay Ve Menu Chinh              |";
				cout << "\n|                                      |";
				cout << "\n========================================";
				cout << "\nNhap chuc nang->";
				cin >> chon3;
				cin.ignore();
				switch (chon3)
				{
				case 1:
					system("cls");
					nhapThietBi(dstb);
					system("pause");
					break;
				case 2:
					system("cls");
					xuatThietBi(dstb);
					system("pause");
					break;
				case 3:
					system("cls");
					themThietBi(dstb);
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "\nNhap ma thiet bi can xoa:";
					getline(cin, maThietBi);
					xoaThietBi(dstb, maThietBi);
					cout << endl;
					system("pause");
					break;
				case 5:
					system("cls");
					cout << "\nNhap ma thiet bi can sua:";
					getline(cin, maThietBi);
					capNhatThietBi(dstb,maThietBi);
					cout << endl;
					system("pause");
					break;
				case 6:
					system("cls");
					cout << "\nNhap ma thiet bi can tra:";
					getline(cin, maThietBi);
					traThongTinThietBi(dstb, maThietBi);
					cout << endl;
					system("pause");
					break;
				}
			} while (chon3 != 0);
		}
	} while (chon != 0);
	ghiDsHoiVien(dshv);
	ghiDsNhanVien(dsnv);
	ghiDsThietBi(dstb);
}
int main() {
	NODEPTRHOIVIEN dshv;
	NODEPTRNHANVIEN dsnv;
	NODEPTRTHIETBI dstb;
	khoiTaoBangBam();
	initHoiVien(dshv);
	initThietBi(dstb);
	initNhanVien(dsnv);
	docDsHoiVien(dshv);
	docDsNhanVien(dsnv);
	docDsThietBi(dstb);
	menu(dshv,dsnv,dstb);
	giaiPhongHoiVien(dshv);
	giaiPhongNhanVien(dsnv);
	giaiPhongThietBi(dstb);
	system("pause");
	return 0;
}