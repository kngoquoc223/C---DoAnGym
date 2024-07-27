#include"hoivien.h"
#pragma region bang bam
struct NODE {
	char key[11];
	NODE* link;
};
typedef NODE *NODEPTR;
NODEPTR bucket[M];
void khoiTaoBangBam() {
	int b;
	for (b = 0; b < M; b++) {
		bucket[b] = NULL;
	}
}
int ktRongBangBam() {
	int b = 0;
	for (; b < M; b++) {
		if (bucket[b] != NULL)
			return false;
	}
	return true;
}
int ktViTriBangBamRong(int b) {
	return bucket[b] == NULL ? 1 : 0;
}
int hamBam(char *s, int n)
{
	int sum = 0;
	while (n--) {
		sum = sum + *s;
		*s++;
	}
	return sum % M;
}
NODEPTR taoNodeBangBam(char *ma) {
	NODEPTR p = new NODE();
	for (int i = 0; i < strlen(ma); i++) {
		p->key[i] = ma[i];
	}
	p->link = NULL;
	return p;
}
//void themMaBangBam(char *ma) {
//	int b;
//	b = hamBam(ma, strlen(ma));
//	if (bucket[b] == NULL) {
//		NODEPTR p;
//		p = taoNodeBangBam(ma);
//		p->link = bucket[b];
//		bucket[b] = p;
//	}
//	else
//	{
//		NODEPTR p = bucket[b];
//		while (p != NULL) {
//			p = p->link;
//		}
//		NODEPTR q = taoNodeBangBam(ma);
//		p->link = q;
//	}
//}
void themMaBangBam(char *ma) {
	int b;
	b = hamBam(ma, strlen(ma));
	NODEPTR p = taoNodeBangBam(ma);
	p->link = bucket[b];
	bucket[b] = p;
}

void xoaMaBangBam(char *ma) {
	int b;
	b = hamBam(ma, strlen(ma));
	if (strcmp(ma, bucket[b]->key) == 0)
	{
		NODEPTR p = bucket[b];
		bucket[b] = bucket[b]->link;
		delete p;
	}
	else {
		NODEPTR p, q;
		p = bucket[b];
		q = bucket[b];
		while (p != NULL && strcmp(p->key, ma) != 0)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			q->link = p->link;
			delete p;
		}
	}
}
void duyetDsBangBam(int b) {
	NODEPTR p;
	p = bucket[b];
	while (p != NULL) {
		cout << b << ":" << p->key << endl;
		p = p->link;
	}
}
void duyetBangBam() {
	int b;
	cout << endl;
	for (b = 0; b < M; b++) {
		duyetDsBangBam(b);
	}
}
NODEPTR timKiemBangBam(char* k)
{
	NODEPTR p = new NODE();
	int b;
	b = hamBam(k, strlen(k));
	p = bucket[b];
	while (p != NULL) {
		if (strcmp(p->key, k) == 0) {
			return p;
		}
		p = p->link;
	}
	if (p == NULL)
		return NULL;
	else
		return p;
}
#pragma endregion
#pragma region the tap
void initTheTap(NODEPTRTHETAP &list) {
	list = NULL;
}
int ktRongTheTap(NODEPTRTHETAP list) {
	return list == NULL ? 1 : 0;
}
void giaiPhongTheTap(NODEPTRTHETAP &list) {
	NODEPTRTHETAP p;
	p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
bool ktTrungMaTheTap(NODEPTRTHETAP list, string ma) {
	NODEPTRTHETAP p = list;
	while (p != NULL) {
		if (p->data.Mathe == ma)
			return true;
		p = p->link;
	}
	return false;
}
NODEPTRTHETAP taoNodeTheTap(THETAP data) {
	NODEPTRTHETAP p = new NODETHETAP();
	p->data = data;
	p->link = NULL;
	return p;
}
NODEPTRTHETAP themDauTheTap(NODEPTRTHETAP &list, THETAP data) {
	NODEPTRTHETAP p;
	p = taoNodeTheTap(data);
	p->link = list;
	list = p;
	return p;
}
NODEPTRTHETAP themCuoiTheTap(NODEPTRTHETAP &list, THETAP data) {
	NODEPTRTHETAP p;
	p = taoNodeTheTap(data);
	if (list == NULL) {
		list = p;
	}
	else {
		NODEPTRTHETAP q = list;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
	return p;
}
NODEPTRTHETAP timTheTap(NODEPTRTHETAP list, string ma) {
	NODEPTRTHETAP p = list;
	while (p != NULL && p->data.Mathe != ma) {
		p = p->link;
	}
	if (p == NULL)
		return NULL;
	return p;
}
int demSoLuongTheTap(NODEPTRTHETAP list) {
	int dem = 0;
	while (list != NULL)
	{
		dem++;
		list = list->link;
	}
	return dem;
}
void doc1TheTap(ifstream &file, THETAP &tt) {
	char ma[11];
	string tam;
	getline(file, tt.Mathe, ',');
	file.seekg(1, 1);
	getline(file, tt.Tengoitap, ',');
	file.seekg(1, 1);
	file >> tt.Sotien;
	file.seekg(2, 1);
	Doc_Ngaythangnam(file, tt.Ngaydangky);
	tt.Ngayhethan.ngay = tt.Ngaydangky.ngay;
	if (tt.Ngaydangky.thang == 12) {
		tt.Ngayhethan.thang = 1;
		tt.Ngayhethan.nam = tt.Ngaydangky.nam + 1;
	}
	else {
		tt.Ngayhethan.thang = tt.Ngaydangky.thang + 1;
		tt.Ngayhethan.nam = tt.Ngaydangky.nam;
	}
	copy(tt.Mathe.begin(), tt.Mathe.end(), ma);
	ma[tt.Mathe.size()] = '\0';
	themMaBangBam(ma);
	getline(file, tam);
}
void docDsTheTap(ifstream &file, NODEPTRTHETAP &dstt) {
	THETAP tt;
	doc1TheTap(file, tt);
	NODEPTRTHETAP p = taoNodeTheTap(tt);
	themCuoiTheTap(dstt, tt);
}
void ghiTheTap(THETAP tt, ofstream &file)
{
	file << tt.Mathe << ", " << tt.Tengoitap << ", " << tt.Sotien << ", ";
	Ghi_Ngaythangnam(file, tt.Ngaydangky);
	file << ", ";
	Ghi_Ngaythangnam(file, tt.Ngayhethan);
}
int xoaTheTap1(NODEPTRTHETAP &list, string ma)
{
	static int flag5 = 0;
	char maXoa[30];
	if (list == NULL)
		return flag5;
	else {
		if (ma == list->data.Mathe) {
			NODEPTRTHETAP p = list;
			copy(p->data.Mathe.begin(), p->data.Mathe.end(), maXoa);
			maXoa[p->data.Mathe.size()] = '\0';
			xoaMaBangBam(maXoa);
			list = list->link;
			delete p;
			flag5 = 1;
		}
		else
		{
			NODEPTRTHETAP p = list;
			NODEPTRTHETAP q = p;
			while (p != NULL && p->data.Mathe != ma)
			{
				q = p;
				p = p->link;
			}
			if (p != NULL)
			{
				copy(p->data.Mathe.begin(), p->data.Mathe.end(), maXoa);
				maXoa[p->data.Mathe.size()] = '\0';
				xoaMaBangBam(maXoa);
				q->link = p->link;
				delete p;
				flag5 = 1;
			}
		}
		return flag5;
	}
}
void xoaTheTap(NODEPTRHOIVIEN &list, string ma)
{
	int flag = 0;
	NODEPTRHOIVIEN p = list;
	while (p != NULL)
	{
		flag = xoaTheTap1(p->data.Thetap, ma);
		if (flag)
			break;
		p = p->link;
	}
	if (flag == 0)
		cout << "\n\t\tMA THE TAP KHONG TON TAI";
}
void dangKyTheTap(NODEPTRHOIVIEN &list, string ma) {
	if (timHoiVien(list, ma) == NULL)
		cout << "\n\t\tMA HOI VIEN KHONG TON TAI";
	else
	{
		NODEPTRHOIVIEN p = timHoiVien(list, ma);
		char ma[30];
		THETAP theTap;
		cout << "\n-NHAP THONG TIN THE TAP HOI VIEN CAN DANG KY-";
		cout << "\nNhap ma the tap:";
		cin.getline(ma, 30);
		while ((timKiemBangBam(ma) != NULL))
		{
			cout << "\n\t\tERROR:Ma the tap bi trung";
			cout << "\n\nNhap lai ma the tap:";
			cin.getline(ma, 11);
		}
		themMaBangBam(ma);
		theTap.Mathe = ma;
		cout << "Nhap ten goi tap:";
		getline(cin, theTap.Tengoitap);
		cout << "Nhap so tien:";
		cin >> theTap.Sotien;
		do {
			cout << "Nhap ngay dang ky the tap(dd/mm/yyyy):";
			cout << "Ngay:";
			cin >> theTap.Ngaydangky.ngay;
			cout << "Thang:";
			cin >> theTap.Ngaydangky.thang;
			cout << "Nam:";
			cin >> theTap.Ngaydangky.nam;
			if (!KT_ngay(theTap.Ngaydangky.ngay, theTap.Ngaydangky.thang, theTap.Ngaydangky.nam)) {
				cout << "\t\tERROR:Ngay thang nam khong hop le";
				cout << endl;
			}
		} while (!KT_ngay(theTap.Ngaydangky.ngay, theTap.Ngaydangky.thang, theTap.Ngaydangky.nam));
		cin.ignore();
		theTap.Ngayhethan.ngay = theTap.Ngaydangky.ngay;
		if (theTap.Ngaydangky.thang == 12) {
			theTap.Ngayhethan.thang = 1;
			theTap.Ngayhethan.nam = theTap.Ngaydangky.nam + 1;
		}
		else {
			theTap.Ngayhethan.thang = theTap.Ngaydangky.thang + 1;
			theTap.Ngayhethan.nam = theTap.Ngaydangky.nam;
		}
		themCuoiTheTap(p->data.Thetap, theTap);
	}
}
void capNhatMaTheTap(NODEPTRHOIVIEN list, char* maTheTap)
{
	char maTheTapMoi[11];
	NODEPTRHOIVIEN p = list;
	NODEPTRTHETAP q = new NODETHETAP();
	while (p != NULL) {
		if (timTheTap(p->data.Thetap, maTheTap) == NULL)
			p = p->link;
		else
		{
			q = timTheTap(p->data.Thetap, maTheTap);
			break;
		}

	}
	if (p != NULL)
	{
		cout << "Nhap ma the tap moi:";
		cin.getline(maTheTapMoi, 11);
		while (timKiemBangBam(maTheTapMoi))
		{
			cout << "\n\t\tERROR:Ma the tap bi trung";
			cout << "\nNhap lai ma the tap:";
			cin.getline(maTheTapMoi, 11);
		}
		p->data.Thetap->data.Mathe = maTheTapMoi;
		themMaBangBam(maTheTapMoi);
		xoaMaBangBam(maTheTap);
	}
	else
		cout << "\n\t\tMA THE TAP KHONG TON TAI";
}
void ktTheTap(NODEPTRHOIVIEN list, string ma) {
	NODEPTRHOIVIEN p = list;
	NODEPTRTHETAP q = new NODETHETAP();
	while (p != NULL) {
		if (timTheTap(p->data.Thetap, ma) == NULL) {
			p = p->link;
		}
		else
		{
			q = timTheTap(p->data.Thetap, ma);
			break;
		}
	}
	if (p == NULL)
		cout << "\n\t\tMA THE TAP KHONG TON TAI";
	else
	{
		cout << "\nTHONG TIN THE TAP CUA HOI VIEN " << p->data.Hoten << ":";
		cout << "\nMa the:" << "\t" << "Ten goi tap:" << "\t" << "So tien:" << "\t" << "Ngay dang ky:" << "\t" << "Ngay het han:" << endl;
		cout << q->data.Mathe << "\t" << q->data.Tengoitap << "\t\t" << q->data.Sotien << "\t\t" << q->data.Ngaydangky.ngay << "/" << q->data.Ngaydangky.thang << "/" << q->data.Ngaydangky.nam << "\t" << q->data.Ngayhethan.ngay << "/" << q->data.Ngayhethan.thang << "/" << q->data.Ngayhethan.nam;
	}
}
void nhapTheTap(NODEPTRTHETAP &list) {
	initTheTap(list);
	THETAP theTap;
	int flag = 0;
	int dem = 0;
	char ma[11];
	do {
		cout << "\n-NHAP THE TAP LAN " << ++dem << "-";
		cout << "\nNhap ma the tap:";
		cin.getline(ma, 11);
		while ((timKiemBangBam(ma) != NULL))
		{
			cout << "\n\t\tERROR:Ma the tap bi trung";
			cout << "\n\nNhap lai ma the tap:";
			cin.getline(ma, 11);
		}
		themMaBangBam(ma);
		theTap.Mathe = ma;
		cout << "Nhap ten goi tap:";
		getline(cin, theTap.Tengoitap);
		cout << "Nhap so tien:";
		cin >> theTap.Sotien;
		do {
			cout << "Nhap ngay dang ky the tap(dd/mm/yyyy):";
			cout << "Ngay:";
			cin >> theTap.Ngaydangky.ngay;
			cout << "Thang:";
			cin >> theTap.Ngaydangky.thang;
			cout << "Nam:";
			cin >> theTap.Ngaydangky.nam;
			if (!KT_ngay(theTap.Ngaydangky.ngay, theTap.Ngaydangky.thang, theTap.Ngaydangky.nam)) {
				cout << "\t\tERROR:Ngay thang nam khong hop le";
				cout << endl;
			}
		} while (!KT_ngay(theTap.Ngaydangky.ngay, theTap.Ngaydangky.thang, theTap.Ngaydangky.nam));
		cin.ignore();
		theTap.Ngayhethan.ngay = theTap.Ngaydangky.ngay;
		if (theTap.Ngaydangky.thang == 12) {
			theTap.Ngayhethan.thang = 1;
			theTap.Ngayhethan.nam = theTap.Ngaydangky.nam + 1;
		}
		else {
			theTap.Ngayhethan.thang = theTap.Ngaydangky.thang + 1;
			theTap.Ngayhethan.nam = theTap.Ngaydangky.nam;
		}
		themCuoiTheTap(list, theTap);
		do {
			cout << "\n\t\tNhap them the tap (|1 co|0 khong|):";
			cin >> flag;
		} while (flag != 0 && flag != 1);
		cin.ignore();
		if (!flag)
			break;
	} while (1);
}
void xuatDanhSachTheTap(NODEPTRHOIVIEN list) {
	cout << "\n-DANH SACH THE TAP-";
	while (list != NULL) {
		NODEPTRTHETAP p = list->data.Thetap;
		while (p != NULL)
		{
			cout << "\nMa the:" << "\t\t" << "Ten goi tap:" << "\t\t" << "So tien:" << "\t" << "Ngay dang ky:" << "\t" << "Ngay het han:" << endl;
			cout << p->data.Mathe << "\t\t" << p->data.Tengoitap << "\t\t\t" << p->data.Sotien << "\t\t" << p->data.Ngaydangky.ngay << "/" << p->data.Ngaydangky.thang << "/" << p->data.Ngaydangky.nam << "\t" << p->data.Ngayhethan.ngay << "/" << p->data.Ngayhethan.thang << "/" << p->data.Ngayhethan.nam << endl;
			p = p->link;
		}
		list = list->link;
	}
}
void xuatTheTap(NODEPTRTHETAP list) {
	int dem = 1;
	while (list != NULL) {
		cout << "\n-THONG TIN THE TAP THU " << dem << "-";
		cout << "\nMa the:" << "\t\t" << "Ten goi tap:" << "\t\t" << "So tien:" << "\t" << "Ngay dang ky:" << "\t" << "Ngay het han:" << endl;
		cout << list->data.Mathe << "\t\t" << list->data.Tengoitap << "\t\t\t" << list->data.Sotien << "\t\t" << list->data.Ngaydangky.ngay << "/" << list->data.Ngaydangky.thang << "/" << list->data.Ngaydangky.nam << "\t" << list->data.Ngayhethan.ngay << "/" << list->data.Ngayhethan.thang << "/" << list->data.Ngayhethan.nam;
		list = list->link;
		dem++;
	}
}
#pragma endregion
#pragma region hoi vien
void initHoiVien(NODEPTRHOIVIEN &list) {
	list = NULL;
}
int ktRongHoiVien(NODEPTRHOIVIEN list) {
	return list == NULL ? 1 : 0;
}
void giaiPhongHoiVien(NODEPTRHOIVIEN &list) {
	NODEPTRHOIVIEN p;
	p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
bool ktTrungMaHoiVien(NODEPTRHOIVIEN list, string ma) {
	NODEPTRHOIVIEN p = list;
	while (p != NULL) {
		if (p->data.Mahoivien == ma)
			return true;
		p = p->link;
	}
	return false;
}
NODEPTRHOIVIEN taoNodeHoiVien(HOIVIEN data) {
	NODEPTRHOIVIEN p = new NODEHOIVIEN();
	p->data = data;
	p->link = NULL;
	return p;
}
NODEPTRHOIVIEN themDauHoiVien(NODEPTRHOIVIEN &list, HOIVIEN data) {
	NODEPTRHOIVIEN p;
	p = taoNodeHoiVien(data);
	p->link = list;
	list = p;
	return p;
}
NODEPTRHOIVIEN themCuoiHoiVien(NODEPTRHOIVIEN &list, HOIVIEN data) {
	NODEPTRHOIVIEN p;
	p = taoNodeHoiVien(data);
	if (list == NULL) {
		list = p;
	}
	else {
		NODEPTRHOIVIEN q = list;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
	return p;
}
void doc1HoiVien(ifstream &file, HOIVIEN &hv)
{
	string tam;
	int n;
	getline(file, hv.Mahoivien, ',');
	file.seekg(1, 1);
	getline(file, hv.Hoten, ',');
	file.seekg(1, 1);
	Doc_Ngaythangnam(file, hv.Ngaysinh);
	file.seekg(2, 1);
	getline(file, hv.sdt, ',');
	initTheTap(hv.Thetap);
	file.seekg(2, 1);
	file >> n;
	getline(file, tam);
	for (int i = 0; i < n; i++)
	{
		docDsTheTap(file, hv.Thetap);
	}
}
int demHoiVien(NODEPTRHOIVIEN dshv) {
	int dem = 0;
	while (dshv != NULL)
	{
		dshv = dshv->link;
		dem++;
	}
	return dem;
}
void docDsHoiVien(NODEPTRHOIVIEN &dshv) {
	ifstream file;
	string tam = "";
	file.open("hoivien.txt", ios::app);
	while (!file.eof())
	{
		HOIVIEN hv;
		doc1HoiVien(file, hv);
		if (tam == hv.Hoten)
			break;
		NODEPTRHOIVIEN p = taoNodeHoiVien(hv);
		themCuoiHoiVien(dshv, hv);
	}
	file.close();
}
void ghiHoiVien(HOIVIEN hv) {
	int soLuong;
	ofstream file;
	file.open("hoivien.txt", ios::app | ios::out);
	file << hv.Mahoivien << ", " << hv.Hoten << ", ";
	Ghi_Ngaythangnam(file, hv.Ngaysinh);
	file << ", " << hv.sdt << ", ";
	file << "-" << demSoLuongTheTap(hv.Thetap) << "-";
	soLuong = demSoLuongTheTap(hv.Thetap);
	for (int i = 0; i < soLuong; i++)
	{
		file << endl;
		ghiTheTap(hv.Thetap->data, file);
		hv.Thetap = hv.Thetap->link;
	}
	file << endl;
	file.close();
}
void ghiDsHoiVien(NODEPTRHOIVIEN list) 
{
	int soLuong;
	ofstream file;
	file.open("hoivien.txt", ios::out);
	while (list != NULL) {
		file << list->data.Mahoivien << ", " << list->data.Hoten << ", ";
		Ghi_Ngaythangnam(file, list->data.Ngaysinh);
		file << ", " << list->data.sdt << ", ";
		file << "-" << demSoLuongTheTap(list->data.Thetap) << "-";
		soLuong = demSoLuongTheTap(list->data.Thetap);
		for (int i = 0; i < soLuong; i++)
		{
			file << endl;
			ghiTheTap(list->data.Thetap->data, file);
			list->data.Thetap = list->data.Thetap->link;
		}
		file << endl;
		list = list->link;
	}
}
NODEPTRHOIVIEN timHoiVien(NODEPTRHOIVIEN list, string ma) {
	NODEPTRHOIVIEN p = list;
	while (p != NULL)
	{
		if (p->data.Mahoivien == ma)
			return p;
		p = p->link;
	}
	return NULL;
}
NODEPTRHOIVIEN timHoiVienTen(NODEPTRHOIVIEN list, string ten) {
	NODEPTRHOIVIEN p = list;
	while (p != NULL)
	{
		if (p->data.Hoten == ten)
			return p;
		p = p->link;
	}
	return NULL;
}
void ktHoiVien(NODEPTRHOIVIEN list, string ma) {
	int flag = 0;
	int dem = 0;
	NODEPTRHOIVIEN p = timHoiVien(list, ma);
	if (p == NULL) {
		cout << "\n\t\tMA HOI VIEN KHONG TON TAI";
	}
	else
	{
		cout << "\n-THONG TIN HOI VIEN-";
		cout << "\nMa hoi vien:" << "\t" << "Hoten:" << "\t\t" << "Ngay sinh:" << "\t" << "So dien thoai:" << endl;
		cout << p->data.Mahoivien << "\t\t" << p->data.Hoten << "\t" << p->data.Ngaysinh.ngay << "/" << p->data.Ngaysinh.thang << "/" << p->data.Ngaysinh.nam << "\t" << p->data.sdt << endl;
		if (p->data.Thetap == NULL) {
			do {
				cout << "\nHOI VIEN CHUA DANG KY THE TAP";
				cout << "\nHoi vien co muon dang ky the tap (|1 co|0 khong|):";
				cin >> flag;
			} while (flag != 0 && flag != 1);
			cin.ignore();
			if (flag)
				nhapTheTap(p->data.Thetap);
		}
		else
			xuatTheTap(p->data.Thetap);
	}
}
void ktHoiVienTen(NODEPTRHOIVIEN list, string ten) {
	int flag = 0;
	int dem = 0;
	NODEPTRHOIVIEN p = timHoiVienTen(list, ten);
	if (p == NULL) {
		cout << "\n\t\tTEN HOI VIEN KHONG TON TAI";
	}
	else
	{
		cout << "\n-THONG TIN HOI VIEN-";
		cout << "\nMa hoi vien:" << "\t" << "Hoten:" << "\t\t" << "Ngay sinh:" << "\t" << "So dien thoai:" << endl;
		cout << p->data.Mahoivien << "\t\t" << p->data.Hoten << "\t" << p->data.Ngaysinh.ngay << "/" << p->data.Ngaysinh.thang << "/" << p->data.Ngaysinh.nam << "\t" << p->data.sdt << endl;
		if (p->data.Thetap == NULL) {
			do {
				cout << "\nHOI VIEN CHUA DANG KY THE TAP";
				cout << "\nHoi vien co muon dang ky the tap (|1 co|0 khong|):";
				cin >> flag;
			} while (flag != 0 && flag != 1);
			cin.ignore();
			if (flag)
				nhapTheTap(p->data.Thetap);
		}
		else
			xuatTheTap(p->data.Thetap);
	}
}
void capNhatMaHoiVien(NODEPTRHOIVIEN list, string maHoiVien)
{
	string maHoiVienMoi;
	NODEPTRHOIVIEN p = list;
	while (p != NULL && p->data.Mahoivien != maHoiVien) {
		p = p->link;
	}
	if (p != NULL)
	{
		cout << "Nhap ma hoi vien moi:";
		getline(cin, maHoiVienMoi);
		while (ktTrungMaHoiVien(list, maHoiVienMoi)) {
			cout << "\n\t\tERROR:Ma hoi vien bi trung";
			cout << "\nNhap lai ma hoi vien:";
			getline(cin, maHoiVienMoi);
		}
		p->data.Mahoivien = maHoiVienMoi;
	}

	else
		cout << "\n\t\tMA HOI VIEN KHONG TON TAI";
}
void themHoiVien(NODEPTRHOIVIEN &list)
{
	HOIVIEN hoiVien;
	int flag = 0;
		cout << "\nNhap ma hoi vien:";
		getline(cin, hoiVien.Mahoivien);
		while (ktTrungMaHoiVien(list, hoiVien.Mahoivien)) {
			cout << "\n\t\tERROR:Ma hoi vien bi trung";
			cout << "\n\nNhap lai ma hoi vien:";
			getline(cin, hoiVien.Mahoivien);
		}
		cout << "Nhap ten hoi vien:";
		getline(cin, hoiVien.Hoten);
		do {
			cout << "Ngay sinh(dd/mm/yyyy):";
			cout << "Ngay:";
			cin >> hoiVien.Ngaysinh.ngay;
			cout << "Thang:";
			cin >> hoiVien.Ngaysinh.thang;
			cout << "Nam:";
			cin >> hoiVien.Ngaysinh.nam;
			if (!KT_ngay(hoiVien.Ngaysinh.ngay, hoiVien.Ngaysinh.thang, hoiVien.Ngaysinh.nam)) {
				cout << "\t\tERROR:Ngay thang nam khong hop le";
				cout << endl;
			}
		} while (!KT_ngay(hoiVien.Ngaysinh.ngay, hoiVien.Ngaysinh.thang, hoiVien.Ngaysinh.nam));
		cin.ignore();
		cout << "So dien thoai:";
		getline(cin, hoiVien.sdt);
		do
		{
			cout << "\n\t\tHoi vien co muon dang ky the tap (|1 co|0 khong|):";
			cin >> flag;
		} while (flag != 0 && flag != 1);
		cin.ignore();
		if (flag)
			nhapTheTap(hoiVien.Thetap);
		else
			initTheTap(hoiVien.Thetap);
		ghiHoiVien(hoiVien);
		themCuoiHoiVien(list, hoiVien);
}
void xoaHoiVien(NODEPTRHOIVIEN &list, string ma)
{
	char maXoa[11];
	if (ma == list->data.Mahoivien) {
		NODEPTRHOIVIEN p = list;
		while (p->data.Thetap != NULL)
		{
			copy(p->data.Thetap->data.Mathe.begin(), p->data.Thetap->data.Mathe.end(), maXoa);
			maXoa[p->data.Thetap->data.Mathe.size()] = '\0';
			xoaMaBangBam(maXoa);
			p->data.Thetap = p->data.Thetap->link;
		}
		list = list->link;
		delete p;
	}
	else {
		NODEPTRHOIVIEN p = list;
		NODEPTRHOIVIEN q = new NODEHOIVIEN();
		while (p != NULL && p->data.Mahoivien != ma)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			while (p->data.Thetap != NULL)
			{
				copy(p->data.Thetap->data.Mathe.begin(), p->data.Thetap->data.Mathe.end(), maXoa);
				maXoa[p->data.Thetap->data.Mathe.size()] = '\0';
				xoaMaBangBam(maXoa);
				p->data.Thetap = p->data.Thetap->link;
			}
			q->link = p->link;
			delete p;
		}
		else
			cout << "\n\t\tMA HOI VIEN KHONG TON TAI";
	}
}
void nhapHoiVien(NODEPTRHOIVIEN &list)
{
	HOIVIEN hoiVien;
	int flag = 0;
	do {
		cout << "\nNhap ma hoi vien(thoat 0):";
		getline(cin, hoiVien.Mahoivien);
		while (ktTrungMaHoiVien(list, hoiVien.Mahoivien)) {
			cout << "\n\t\tERROR:Ma hoi vien bi trung";
			cout << "\n\nNhap lai ma hoi vien(thoat 0):";
			getline(cin, hoiVien.Mahoivien);
		}
		if (hoiVien.Mahoivien == "0") {
			break;
		}
		cout << "Nhap ten hoi vien:";
		getline(cin, hoiVien.Hoten);
		do {
			cout << "Ngay sinh(dd/mm/yyyy):";
			cout << "Ngay:";
			cin >> hoiVien.Ngaysinh.ngay;
			cout << "Thang:";
			cin >> hoiVien.Ngaysinh.thang;
			cout << "Nam:";
			cin >> hoiVien.Ngaysinh.nam;
			if (!KT_ngay(hoiVien.Ngaysinh.ngay, hoiVien.Ngaysinh.thang, hoiVien.Ngaysinh.nam)) {
				cout << "\t\tERROR:Ngay thang nam khong hop le";
				cout << endl;
			}
		} while (!KT_ngay(hoiVien.Ngaysinh.ngay, hoiVien.Ngaysinh.thang, hoiVien.Ngaysinh.nam));
		cin.ignore();
		cout << "So dien thoai:";
		getline(cin, hoiVien.sdt);
		do
		{
			cout << "\n\t\tHoi vien co muon dang ky the tap (|1 co|0 khong|):";
			cin >> flag;
		} while (flag != 0 && flag != 1);
		cin.ignore();
		if (flag)
			nhapTheTap(hoiVien.Thetap);
		else
			initTheTap(hoiVien.Thetap);
		ghiHoiVien(hoiVien);
		themCuoiHoiVien(list, hoiVien);
	} while (1);
}
void xuatHoiVienVaTheTap(NODEPTRHOIVIEN list) {
	int dem = 0;
	while (list != NULL) {
		cout << "\n-THONG TIN HOI VIEN "<<++dem<<"-";
		cout << "\nMa hoi vien:" << "\t" << "Hoten:" << "\t\t" << "Ngay sinh:" << "\t" << "So dien thoai:" << endl;
		cout << list->data.Mahoivien << "\t\t" << list->data.Hoten << "\t" << list->data.Ngaysinh.ngay << "/" << list->data.Ngaysinh.thang << "/" << list->data.Ngaysinh.nam << "\t" << list->data.sdt << endl;
		if (list->data.Thetap != NULL)
		{
			cout << "--------------------THE TAP CUA HOI VIEN----------------------";
			xuatTheTap(list->data.Thetap);
		}
		list = list->link;
		cout << endl;
	}
}
void xuatHoiVien(NODEPTRHOIVIEN list) {
	int dem = 0;
	while (list != NULL) {
		cout << "\n-THONG TIN HOI VIEN " << ++dem << "-";
		cout << "\nMa hoi vien:" << "\t" << "Hoten:" << "\t\t" << "Ngay sinh:" << "\t" << "So dien thoai:" << endl;
		cout << list->data.Mahoivien << "\t\t" << list->data.Hoten << "\t" << list->data.Ngaysinh.ngay << "/" << list->data.Ngaysinh.thang << "/" << list->data.Ngaysinh.nam << "\t" << list->data.sdt << endl;
		list = list->link;
	}
}
void xuatHoiVienTheoTen(NODEPTRHOIVIEN list,string ten) {
	int dem = 0;
	while (list != NULL) {
		if (list->data.Hoten == ten) {
			cout << "\n-THONG TIN HOI VIEN " << ++dem << "-";
			cout << "\nMa hoi vien:" << "\t" << "Hoten:" << "\t\t" << "Ngay sinh:" << "\t" << "So dien thoai:" << endl;
			cout << list->data.Mahoivien << "\t\t" << list->data.Hoten << "\t" << list->data.Ngaysinh.ngay << "/" << list->data.Ngaysinh.thang << "/" << list->data.Ngaysinh.nam << "\t" << list->data.sdt << endl;
			if (list->data.Thetap != NULL)
			{
				cout << "--------------------THE TAP CUA HOI VIEN----------------------";
				xuatTheTap(list->data.Thetap);
			}
		}
		list = list->link;
	}
}
void xuatHoiVienTheoTen1(NODEPTRHOIVIEN list, char* ten) {
	int dem = 0;
	char ten1[30]; //ten danh sach
	char ten2[30]; //ten tim
	while (list != NULL) {
		copy(list->data.Hoten.begin(), list->data.Hoten.end(), ten1);
		ten1[list->data.Hoten.size()] = '\0';
		int i = 0;
		for (i = strlen(ten1); i >= 0; i--)
		{
			if (ten1[i] == ' ')
				break;
		}
		for (int j = 0; j < i; j++)
			ten2[j] = ten1[i];
		if (strcmp(ten,ten2)==0) 
		{
			cout << "\n-THONG TIN HOI VIEN " << ++dem << "-";
			cout << "\nMa hoi vien:" << "\t" << "Hoten:" << "\t\t" << "Ngay sinh:" << "\t" << "So dien thoai:" << endl;
			cout << list->data.Mahoivien << "\t\t" << list->data.Hoten << "\t" << list->data.Ngaysinh.ngay << "/" << list->data.Ngaysinh.thang << "/" << list->data.Ngaysinh.nam << "\t" << list->data.sdt << endl;
			if (list->data.Thetap != NULL)
			{
				cout << "--------------------THE TAP CUA HOI VIEN----------------------";
				xuatTheTap(list->data.Thetap);
			}
		}
		list = list->link;
	}
}
//void xoaTheTapHetHan(NODEPTRHOIVIEN list) 
//{
//	char maXoa[11];
//	time_t baygio = time(0);
//	tm *ltm = localtime(&baygio);
//	while (list != NULL)
//	{
//		NODEPTRTHETAP p = list->data.Thetap;
//		if (p != NULL) 
//		{
//			if (p->data.Ngayhethan.ngay == ltm->tm_mday && p->data.Ngayhethan.thang == ltm->tm_mon && p->data.Ngayhethan.nam == ltm->tm_year)
//			{
//				copy(p->data.Mathe.begin(), p->data.Mathe.end(), maXoa);
//				maXoa[p->data.Mathe.size()] = '\0';
//				xoaMaBangBam(maXoa);
//				list->data.Thetap = list->data.Thetap->link;
//				delete p;
//			}
//			else 
//			{
//				NODEPTRTHETAP q = p;
//				while (p != NULL && p->data.Ngayhethan.ngay == ltm->tm_mday && p->data.Ngayhethan.thang == ltm->tm_mon && p->data.Ngayhethan.nam == ltm->tm_year)
//				{
//					q = p;
//					p = p->link;
//				}
//				if (p != NULL) 
//				{
//					copy(p->data.Mathe.begin(), p->data.Mathe.end(), maXoa);
//					maXoa[p->data.Mathe.size()] = '\0';
//					xoaMaBangBam(maXoa);
//					q->link = p->link;
//					delete p;
//				}
//			}
//		}
//	else
//		list = list->link;
//	}
//}
#pragma endregion