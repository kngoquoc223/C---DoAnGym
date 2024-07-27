#include"thietbi.h"
void initThietBi(NODEPTRTHIETBI &list) {
	list = NULL;
}
int ktRongThietBi(NODEPTRTHIETBI list) {
	return list == NULL ? 1 : 0;
}
void giaiPhongThietBi(NODEPTRTHIETBI &list) {
	NODEPTRTHIETBI p;
	p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
bool ktTrungMaThietBi(NODEPTRTHIETBI list, string ma) {
	NODEPTRTHIETBI p = list;
	while (p != NULL) {
		if (p->data.Maso == ma)
			return true;
		p = p->link;
	}
	return false;
}
NODEPTRTHIETBI taoNodeThietBi(THIETBI data) {
	NODEPTRTHIETBI p = new NODETHIETBI();
	p->data = data;
	p->link = NULL;
	return p;
}
NODEPTRTHIETBI themDauThietBi(NODEPTRTHIETBI &list, THIETBI data) {
	NODEPTRTHIETBI p;
	p = taoNodeThietBi(data);
	p->link = list;
	list = p;
	return p;
}
NODEPTRTHIETBI themCuoiThietBi(NODEPTRTHIETBI &list, THIETBI data) {
	NODEPTRTHIETBI p;
	p = taoNodeThietBi(data);
	if (list == NULL) {
		list = p;
		return p;
	}
	else {
		NODEPTRTHIETBI q = list;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
	return p;
}
void ghiThietBi(THIETBI tb) {
	ofstream file;
	file.open("thietbi.txt", ios::app | ios::out);
	file << tb.Maso << ", " << tb.Tenthietbi << ", ";
	Ghi_Ngaythangnam(file, tb.Ngaynhapve);
	file << ", " << tb.Xuatxu << ", " << tb.Tinhtrang;
	file << endl;
	file.close();
}
void ghiDsThietBi(NODEPTRTHIETBI list)
{
	ofstream file;
	file.open("thietbi.txt", ios::out);
	while (list != NULL) {
		file << list->data.Maso << ", " << list->data.Tenthietbi << ", ";
		Ghi_Ngaythangnam(file, list->data.Ngaynhapve);
		file << ", " << list->data.Xuatxu << ", " << list->data.Tinhtrang;
		file << endl;
		list = list->link;
	}
}
void doc1ThietBi(ifstream &file, THIETBI &tb)
{
	getline(file, tb.Maso, ','); //doc ten den dau "," dung
	file.seekg(1, 1);
	getline(file, tb.Tenthietbi, ',');
	file.seekg(1, 1);
	Doc_Ngaythangnam(file, tb.Ngaynhapve);
	file.seekg(2, 1);
	getline(file, tb.Xuatxu, ',');
	file.seekg(1, 1);
	getline(file, tb.Tinhtrang);
}
void docDsThietBi(NODEPTRTHIETBI &dstb) {
	string tam = "";
	ifstream file;
	file.open("thietbi.txt", ios::app);
	while (!file.eof())
	{
		THIETBI tb;
		doc1ThietBi(file, tb);
		if (tam == tb.Maso)
			break;
		NODEPTRTHIETBI p = taoNodeThietBi(tb);
		themCuoiThietBi(dstb, tb);
	}
	file.close();
}
void themThietBi(NODEPTRTHIETBI &list) 
{
	THIETBI thietBi;
	cout << "\nNhap ma thiet bi:";
	getline(cin, thietBi.Maso);
	while (ktTrungMaThietBi(list, thietBi.Maso)) {
		cout << "\n\t\tERROR:Ma thiet bi trung";
		cout << "\nNhap lai ma thiet bi:";
		getline(cin, thietBi.Maso);
	}
	cout << "Ten thiet bi:";
	getline(cin, thietBi.Tenthietbi);
	do {
		cout << "Ngay nhap ve(dd/mm/yyyy):";
		cout << "Ngay:";
		cin >> thietBi.Ngaynhapve.ngay;
		cout << "Thang:";
		cin >> thietBi.Ngaynhapve.thang;
		cout << "Nam:";
		cin >> thietBi.Ngaynhapve.nam;
		if (!KT_ngay(thietBi.Ngaynhapve.ngay, thietBi.Ngaynhapve.thang, thietBi.Ngaynhapve.nam)) {
			cout << "Ngay thang nam khong hop le";
			cout << endl;
		}
	} while (!KT_ngay(thietBi.Ngaynhapve.ngay, thietBi.Ngaynhapve.thang, thietBi.Ngaynhapve.nam));
	cin.ignore();
	cout << "Tinh trang thiet bi:";
	getline(cin, thietBi.Tinhtrang);
	cout << "Xuat xu cua thiet bi:";
	getline(cin, thietBi.Xuatxu);
	ghiThietBi(thietBi);
	themCuoiThietBi(list, thietBi);
}
void xoaThietBi(NODEPTRTHIETBI &list, string ma) 
{
	if (list->data.Maso == ma) 
	{
		NODEPTRTHIETBI p = list;
		list = list->link;
		delete p;
	}
	else {
		NODEPTRTHIETBI p = list;
		NODEPTRTHIETBI q = p;
		while (p != NULL && ma != p->data.Maso)
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
			cout << "\n\t\tMA THIET BI KHONG TON TAI";
	}
}
void capNhatThietBi(NODEPTRTHIETBI &list, string ma) 
{
	NODEPTRTHIETBI p = list;
	while (p != NULL && p->data.Maso != ma)
		p = p->link;
	if (p != NULL)
	{
		string maThietBiMoi;
		cout << "Nhap ma thiet bi moi:";
		getline(cin, maThietBiMoi);
		while (ktTrungMaThietBi(list, maThietBiMoi)) {
			cout << "\n\t\tERROR:Ma thiet bi trung";
			cout << "\nNhap lai ma thiet bi:";
			getline(cin, maThietBiMoi);
		}
		p->data.Maso = maThietBiMoi;
	}
	else
		cout << "\n\t\tMA THIET BI KHONG TON TAI";
}
void traThongTinThietBi(NODEPTRTHIETBI list, string ma) 
{
	NODEPTRTHIETBI p = list;
	while (p != NULL && p->data.Maso != ma)
		p = p->link;
	if (p != NULL)
	{
		cout << "\n-THONG TIN THIET BI-";
		cout << "\nMa so:" << "\t" << "Ten thiet bi:" << "\t" << "Ngay nhap ve:" << "\t" << "Tinh trang:" << "\t" << "Xuat xu:" << endl;
		cout << p->data.Maso << "\t" << p->data.Tenthietbi << "\t" << p->data.Ngaynhapve.ngay << "/" << p->data.Ngaynhapve.thang << "/" << p->data.Ngaynhapve.nam << "\t\t" << p->data.Tinhtrang << "\t\t" << p->data.Xuatxu;
	}
	else
		cout << "\n\t\tMA THIET BI KHONG TON TAI";
}
void nhapThietBi(NODEPTRTHIETBI &list) {
	THIETBI thietBi;
	int flag = 0;
	do {
		cout << "Nhap ma thiet bi(thoat 0):";
		getline(cin, thietBi.Maso);
		while (ktTrungMaThietBi(list, thietBi.Maso)) {
			cout << "\n\t\tERROR:Ma thiet bi trung";
			cout << "\nNhap lai ma thiet bi(thoat 0):";
			getline(cin, thietBi.Maso);
		}
		if (thietBi.Maso == "0") {
			break;
		}
		cout << "Ten thiet bi:";
		getline(cin, thietBi.Tenthietbi);
		do {
			cout << "Ngay nhap ve(dd/mm/yyyy):";
			cout << "Ngay:";
			cin >> thietBi.Ngaynhapve.ngay;
			cout << "Thang:";
			cin >> thietBi.Ngaynhapve.thang;
			cout << "Nam:";
			cin >> thietBi.Ngaynhapve.nam;
			if (!KT_ngay(thietBi.Ngaynhapve.ngay, thietBi.Ngaynhapve.thang, thietBi.Ngaynhapve.nam)) {
				cout << "Ngay thang nam khong hop le";
				cout << endl;
			}
		} while (!KT_ngay(thietBi.Ngaynhapve.ngay, thietBi.Ngaynhapve.thang, thietBi.Ngaynhapve.nam));
		cin.ignore();
		cout << "Tinh trang thiet bi:";
		getline(cin, thietBi.Tinhtrang);
		cout << "Xuat xu cua thiet bi:";
		getline(cin, thietBi.Xuatxu);
		ghiThietBi(thietBi);
		themCuoiThietBi(list, thietBi);
	} while (1);
}
void xuatThietBi(NODEPTRTHIETBI list) {
	while (list != NULL) {
		cout << "\n-THONG TIN THIET BI-";
		cout << "\nMa so:" << "\t\t" << "Ten thiet bi:" << "\t\t" << "Ngay nhap ve:" << "\t\t" << "Tinh trang:" << "\t" << "Xuat xu:" << endl;
		cout << list->data.Maso << "\t\t" << list->data.Tenthietbi << "\t\t" << list->data.Ngaynhapve.ngay << "/" << list->data.Ngaynhapve.thang << "/" << list->data.Ngaynhapve.nam << "\t\t" << list->data.Tinhtrang << "\t\t" << list->data.Xuatxu << endl;
		list = list->link;
	}
}