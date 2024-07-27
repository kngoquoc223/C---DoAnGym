#include"nhanvien.h"
void initNhanVien(NODEPTRNHANVIEN &list) {
	list = NULL;
}
int ktRongNhanVien(NODEPTRNHANVIEN list) {
	return list == NULL ? 1 : 0;
}
void giaiPhongNhanVien(NODEPTRNHANVIEN &list) {
	NODEPTRNHANVIEN p;
	p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
bool ktTrungMaNhanVien(NODEPTRNHANVIEN list, string ma) {
	NODEPTRNHANVIEN p = list;
	while (p != NULL) {
		if (p->data.Manhanvien == ma)
			return true;
		p = p->link;
	}
	return false;
}
NODEPTRNHANVIEN taoNodeNhanVien(NHANVIEN data) {
	NODEPTRNHANVIEN p = new NODENHANVIEN();
	p->data = data;
	p->link = NULL;
	return p;
}
NODEPTRNHANVIEN themDauNhanVien(NODEPTRNHANVIEN &list, NHANVIEN data) {
	NODEPTRNHANVIEN p;
	p = taoNodeNhanVien(data);
	p->link = list;
	list = p;
	return p;
}
NODEPTRNHANVIEN themCuoiNhanVien(NODEPTRNHANVIEN &list, NHANVIEN data) {
	NODEPTRNHANVIEN p;
	p = taoNodeNhanVien(data);
	if (list == NULL) {
		list = p;
		return p;
	}
	else {
		NODEPTRNHANVIEN q = list;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
	return p;
}
void ghiNhanVien(NHANVIEN nv) {
	ofstream file;
	file.open("nhanvien.txt", ios::app | ios::out);
	file << nv.Manhanvien << ", " << nv.Hoten << ", ";
	Ghi_Ngaythangnam(file, nv.Ngaysinh);
	file << ", ";
	Ghi_Ngaythangnam(file, nv.Ngaybatdau);
	file << ", ";
	Ghi_Gio(file, nv.Giobatdaulamviec);
	file << "-";
	Ghi_Gio(file, nv.Gioketthuclamviec);
	file << ", " << nv.Sdt;
	file << endl;
	file.close();
}
void ghiDsNhanVien(NODEPTRNHANVIEN list)
{
	ofstream file;
	file.open("nhanvien.txt", ios::out);
	while (list != NULL) {
		file << list->data.Manhanvien << ", " << list->data.Hoten << ", ";
		Ghi_Ngaythangnam(file, list->data.Ngaysinh);
		file << ", ";
		Ghi_Ngaythangnam(file, list->data.Ngaybatdau);
		file << ", ";
		Ghi_Gio(file, list->data.Giobatdaulamviec);
		file << "-";
		Ghi_Gio(file, list->data.Gioketthuclamviec);
		file << ", " << list->data.Sdt;
		file << endl;
		list = list->link;
	}
}
void doc1NhanVien(ifstream &file, NHANVIEN &nv)
{
	getline(file, nv.Manhanvien, ',');
	file.seekg(1, 1);
	getline(file, nv.Hoten, ',');
	file.seekg(1, 1);
	Doc_Ngaythangnam(file, nv.Ngaysinh);
	file.seekg(2, 1);
	Doc_Ngaythangnam(file, nv.Ngaybatdau);
	file.seekg(2, 1);
	Doc_Gio(file, nv.Giobatdaulamviec);
	file.seekg(1, 1);
	Doc_Gio(file, nv.Gioketthuclamviec);
	file.seekg(2, 1);
	getline(file, nv.Sdt);
}
void docDsNhanVien(NODEPTRNHANVIEN &dsnv) {
	string tam = "";
	ifstream file;
	file.open("nhanvien.txt", ios::in);
	while (!file.eof())
	{
		NHANVIEN nv;
		doc1NhanVien(file, nv);
		if (tam == nv.Manhanvien)
			break;
		NODEPTRNHANVIEN p = taoNodeNhanVien(nv);
		themCuoiNhanVien(dsnv, nv);
	}
	file.close();
}
void themNhanVien(NODEPTRNHANVIEN &list)
{
	NHANVIEN nhanVien;
	cout << "\nNhap ma nhan vien:";
	getline(cin, nhanVien.Manhanvien);
	while (ktTrungMaNhanVien(list, nhanVien.Manhanvien)) {
		cout << "\n\t\tERROR:Ma nhan vien bi trung";
		cout << "\nNhap lai ma nhan vien:";
		getline(cin, nhanVien.Manhanvien);
	}
	cout << "Ten nhan vien:";
	getline(cin, nhanVien.Hoten);
	do {
		cout << "Ngay sinh(dd/mm/yyyy):";
		cout << "Ngay:";
		cin >> nhanVien.Ngaysinh.ngay;
		cout << "Thang:";
		cin >> nhanVien.Ngaysinh.thang;
		cout << "Nam:";
		cin >> nhanVien.Ngaysinh.nam;
		if (!KT_ngay(nhanVien.Ngaysinh.ngay, nhanVien.Ngaysinh.thang, nhanVien.Ngaysinh.nam)) {
			cout << "\t\tERROR:Ngay thang nam khong hop le";
			cout << endl;
		}
	} while (!KT_ngay(nhanVien.Ngaysinh.ngay, nhanVien.Ngaysinh.thang, nhanVien.Ngaysinh.nam));
	cin.ignore();
	cout << "So dien thoai:";
	getline(cin, nhanVien.Sdt);
	do {
		cout << "Ngay bat dau lam viec(dd/mm/yyyy):";
		cout << "Ngay:";
		cin >> nhanVien.Ngaybatdau.ngay;
		cout << "Thang:";
		cin >> nhanVien.Ngaybatdau.thang;
		cout << "Nam:";
		cin >> nhanVien.Ngaybatdau.nam;
		if (!KT_ngay(nhanVien.Ngaybatdau.ngay, nhanVien.Ngaybatdau.thang, nhanVien.Ngaybatdau.nam)) {
			cout << "\t\tERROR:Ngay thang nam khong hop le";
			cout << endl;
		}
	} while (!KT_ngay(nhanVien.Ngaybatdau.ngay, nhanVien.Ngaybatdau.thang, nhanVien.Ngaybatdau.nam));
	do {
		cout << "Gio bat dau lam viec(gio:phut):";
		cout << "Gio:";
		cin >> nhanVien.Giobatdaulamviec.gio;
		cout << "Phut:";
		cin >> nhanVien.Giobatdaulamviec.phut;
		if (!KT_gio(nhanVien.Giobatdaulamviec.gio, nhanVien.Giobatdaulamviec.phut)) {
			cout << "\t\tERROR:Gio phut khong hop le";
			cout << endl;
		}
	} while (!KT_gio(nhanVien.Giobatdaulamviec.gio, nhanVien.Giobatdaulamviec.phut));
	do {
		cout << "Gio ket thuc lam viec(gio:phut):";
		cout << "Gio:";
		cin >> nhanVien.Gioketthuclamviec.gio;
		cout << "Phut:";
		cin >> nhanVien.Gioketthuclamviec.phut;
		if (!KT_gio(nhanVien.Gioketthuclamviec.gio, nhanVien.Gioketthuclamviec.phut)) {
			cout << "\t\tERROR:Gio phut khong hop le";
			cout << endl;
		}
	} while (!KT_gio(nhanVien.Gioketthuclamviec.gio, nhanVien.Gioketthuclamviec.phut));
	cin.ignore();
	ghiNhanVien(nhanVien);
	//Them_Dau_NhanVien(list, nhanVien);
	themCuoiNhanVien(list, nhanVien);
}
void xoaNhanVien(NODEPTRNHANVIEN &list,string ma)
{
	if (list->data.Manhanvien == ma)
	{
		NODEPTRNHANVIEN p = list;
		list = list->link;
		delete p;
	}
	else {
		NODEPTRNHANVIEN p = list;
		NODEPTRNHANVIEN q = p;
		while (p != NULL && ma != p->data.Manhanvien)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			q->link = p->link;
			delete p;
		}
		else
			cout << "\n\t\tMA NHAN VIEN KHONG TON TAI";
	}
}
void capNhatNhanVien(NODEPTRNHANVIEN &list, string ma)
{
	NODEPTRNHANVIEN p = list;
	while (p != NULL && p->data.Manhanvien != ma)
		p = p->link;
	if (p != NULL)
	{
		string maNhanVienMoi;
		cout << "Nhap ma nhan vien moi:";
		getline(cin, maNhanVienMoi);
		while (ktTrungMaNhanVien(list,maNhanVienMoi)) {
			cout << "\n\t\tERROR:Ma nhan vien bi trung";
			cout << "\nNhap lai ma nhan vien:";
			getline(cin, maNhanVienMoi);
		}
		p->data.Manhanvien = maNhanVienMoi;
	}
	else
		cout << "\n\t\tMA NHAN VIEN KHONG TON TAI";
}
void traThongTinNhanVien(NODEPTRNHANVIEN list, string ma)
{
	NODEPTRNHANVIEN p = list;
	while (p != NULL && p->data.Manhanvien != ma)
		p = p->link;
	if (p != NULL)
	{
		cout << "\n-THONG TIN NHAN VIEN-";
		cout << "\nMa nhan vien:" << "\t" << "Ten nhan vien:" << "\t" << "Ngay sinh:" << "\t" << "So dien thoai:" << "\t" << "Ngay bat dau lam viec:" << "\t" << "Ca lam viec:" << endl;
		cout << p->data.Manhanvien << "\t\t" << p->data.Hoten << "\t" << p->data.Ngaysinh.ngay << "/" << p->data.Ngaysinh.thang << "/" << p->data.Ngaysinh.nam << "\t" << p->data.Sdt << "\t" << p->data.Ngaybatdau.ngay << "/" << p->data.Ngaybatdau.thang << "/" << p->data.Ngaybatdau.nam << "\t\t" << p->data.Giobatdaulamviec.gio << ":" << p->data.Giobatdaulamviec.phut << "-" << p->data.Gioketthuclamviec.gio << ":" << p->data.Gioketthuclamviec.phut << endl;
	}
	else
		cout << "\n\t\tMA NHAN VIEN KHONG TON TAI";
}
void nhapNhanVien(NODEPTRNHANVIEN &list) {
	int flag = 0;
	NHANVIEN nhanVien;
	do {
		cout << "Nhap ma nhan vien(thoat 0):";
		getline(cin, nhanVien.Manhanvien);
		while (ktTrungMaNhanVien(list, nhanVien.Manhanvien)) {
			cout << "\n\t\tERROR:Ma nhan vien bi trung";
			cout << "\nNhap lai ma nhan vien(thoat 0):";
			getline(cin, nhanVien.Manhanvien);
		}
		if (nhanVien.Manhanvien == "0") {
			break;
		}
		cout << "Ten nhan vien:";
		getline(cin, nhanVien.Hoten);
		do {
			cout << "Ngay sinh(dd/mm/yyyy):";
			cout << "Ngay:";
			cin >> nhanVien.Ngaysinh.ngay;
			cout << "Thang:";
			cin >> nhanVien.Ngaysinh.thang;
			cout << "Nam:";
			cin >> nhanVien.Ngaysinh.nam;
			if (!KT_ngay(nhanVien.Ngaysinh.ngay, nhanVien.Ngaysinh.thang, nhanVien.Ngaysinh.nam)) {
				cout << "\t\tERROR:Ngay thang nam khong hop le";
				cout << endl;
			}
		} while (!KT_ngay(nhanVien.Ngaysinh.ngay, nhanVien.Ngaysinh.thang, nhanVien.Ngaysinh.nam));
		cin.ignore();
		cout << "So dien thoai:";
		getline(cin, nhanVien.Sdt);
		do {
			cout << "Ngay bat dau lam viec(dd/mm/yyyy):";
			cout << "Ngay:";
			cin >> nhanVien.Ngaybatdau.ngay;
			cout << "Thang:";
			cin >> nhanVien.Ngaybatdau.thang;
			cout << "Nam:";
			cin >> nhanVien.Ngaybatdau.nam;
			if (!KT_ngay(nhanVien.Ngaybatdau.ngay, nhanVien.Ngaybatdau.thang, nhanVien.Ngaybatdau.nam)) {
				cout << "\t\tERROR:Ngay thang nam khong hop le";
				cout << endl;
			}
		} while (!KT_ngay(nhanVien.Ngaybatdau.ngay, nhanVien.Ngaybatdau.thang, nhanVien.Ngaybatdau.nam));
		do {
			cout << "Gio bat dau lam viec(gio:phut):";
			cout << "Gio:";
			cin >> nhanVien.Giobatdaulamviec.gio;
			cout << "Phut:";
			cin >> nhanVien.Giobatdaulamviec.phut;
			if (!KT_gio(nhanVien.Giobatdaulamviec.gio, nhanVien.Giobatdaulamviec.phut)) {
				cout << "\t\tERROR:Gio phut khong hop le";
				cout << endl;
			}
		} while (!KT_gio(nhanVien.Giobatdaulamviec.gio, nhanVien.Giobatdaulamviec.phut));
		do {
			cout << "Gio ket thuc lam viec(gio:phut):";
			cout << "Gio:";
			cin >> nhanVien.Gioketthuclamviec.gio;
			cout << "Phut:";
			cin >> nhanVien.Gioketthuclamviec.phut;
			if (!KT_gio(nhanVien.Gioketthuclamviec.gio, nhanVien.Gioketthuclamviec.phut)) {
				cout << "\t\tERROR:Gio phut khong hop le";
				cout << endl;
			}
		} while (!KT_gio(nhanVien.Gioketthuclamviec.gio, nhanVien.Gioketthuclamviec.phut));
		cin.ignore();
		ghiNhanVien(nhanVien);
		//Them_Dau_NhanVien(list, nhanVien);
		themCuoiNhanVien(list, nhanVien);
	} while (1);
}
void xuatNhanVien(NODEPTRNHANVIEN list) {
	while (list != NULL) {
		cout << "\n-THONG TIN NHAN VIEN-";
		cout << "\nMa nhan vien:" << "\t" << "Ten nhan vien:" << "\t" << "Ngay sinh:" << "\t" << "So dien thoai:" << "\t" << "Ngay bat dau lam viec:" << "\t" << "Ca lam viec:" << endl;
		cout << list->data.Manhanvien << "\t\t" << list->data.Hoten << "\t" << list->data.Ngaysinh.ngay << "/" << list->data.Ngaysinh.thang << "/" << list->data.Ngaysinh.nam << "\t" << list->data.Sdt << "\t" << list->data.Ngaybatdau.ngay << "/" << list->data.Ngaybatdau.thang << "/" << list->data.Ngaybatdau.nam << "\t\t" << list->data.Giobatdaulamviec.gio << ":" << list->data.Giobatdaulamviec.phut << "-" << list->data.Gioketthuclamviec.gio << ":" << list->data.Gioketthuclamviec.phut << endl;
		list = list->link;
	}
}