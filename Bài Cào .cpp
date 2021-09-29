#include <iostream>
using namespace std;
bool kiemTra3La(char laBai[], int n) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (laBai[i] == 'J' || laBai[i] == 'Q' || laBai[i] == 'K') {
			dem += 1;
		}
	}
	if(dem==3)
		return 1;
	return 0;
}
int max(int diem[], int n) {
	int max = diem[0];	
	for (int i = 1; i < n; i++) {
		if (diem[i] > max)
			max = diem[i];
	}
	return max;
}

int main() {
	int i = 0, j = 0;
	int diem[6] = {0};
	char laBai[4];
	int chay = 0;
	char ten[6][6] = { "Su", "Lu", "Bu","Ti","Teo" };
	do {
		cout << "\nNhap ten ban thu " << i + 1 << endl;

		cout << "Nhap vao 3 la bai: ";
		char s[10];
		cin.getline(s, 11);
		j = 0;
		for (int r = 0; r < size(s); r++) {
			if (s[r] == 'A' || s[r] == 'J' || s[r] == 'Q' || s[r] == 'K' || (s[r] >= '2' && s[r] <= '10')) {
				if (s[r] == 'A')
					diem[i] += 1;
				else if (s[r] == 'J' || s[r] == 'Q' || s[r] == 'K')
					diem[i] += 10;
				else if ((s[r] >= '2' && s[r] <= '10'))
					diem[i] += int(s[r] - '0');
				laBai[j++] = s[r];
			}
		}
		if (kiemTra3La(laBai, j) == 1) diem[i] = 10;
		else {

			cout << "diem[i] = " << diem[i] << endl;
			diem[i] = diem[i] % 10;
		}
		
		cout << "\nDiem cua ban " << i + 1 << " la: " << diem[i] << endl;
		i++;

	} while (i < 5);
	int diemMax = max(diem, i);
	cout << endl;

	for (int k = 0; k < i; k++) {
		if (diem[k] == diemMax) {
			cout << ten[k] << " ";
		}
	}
	cout << endl;
}
