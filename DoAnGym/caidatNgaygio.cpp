#include"ngaygio.h"
int KT_ngay(int ngay, int thang, int nam) {
	if (ngay > 31 || thang > 12 || nam < 0 || ngay == 0 || thang == 0 || nam == 0)
		return 0;
	else {
		if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))           //nam nhuan
		{
			if (thang == 2) {
				if (ngay > 29)
					return 0;
				else
					return 1;
			}
			else
				return 1;
		}
		else {
			if (thang == 2)
			{
				if (ngay > 28)
					return 0;
				else
					return 1;
			}
			else
				return 1;
		}
	}
}
int KT_gio(int gio, int phut) {
	if (gio > 24 || phut > 60 || gio <= 0 || phut <= 0) {
		return 0;
	}
	else
		return 1;
}
void Ghi_Gio(ofstream &file, TIME &time) {
	file << time.gio << ":" << time.phut;
}
void Ghi_Ngaythangnam(ofstream &file, DATE &date) {
	file << date.ngay << "/" << date.thang << "/" << date.nam;
}
void Doc_Ngaythangnam(ifstream &file, DATE &date) {
	file >> date.ngay;
	file.seekg(1, 1); //tai vi tri hien tai cua con tro dich sang 1 byte
	file >> date.thang;
	file.seekg(1, 1);
	file >> date.nam;
}
void Doc_Gio(ifstream &file, TIME &time) {
	file >> time.gio;
	file.seekg(1, 1); //tai vi tri hien tai cua con tro dich sang 1 byte
	file >> time.phut;
}