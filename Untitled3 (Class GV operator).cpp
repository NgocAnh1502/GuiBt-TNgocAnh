#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class GiaoVien {
	private:
		char HT[30], BC[15], CN[20];
		int T;
		float BL;
		
	public:
		GiaoVien(){
			strcpy(HT, "Chua nhap");
			T = 0;
			strcpy(BC, "Chua nhap");
			strcpy(CN, "Chua nhap");
			BL = 0;
		}
		~GiaoVien(){}
	
	char *get_BC(){
		return BC;
	}
		
	friend istream& operator >> (istream& in, GiaoVien &GV){
		cout<<"Nhap ho ten giao vien: ";
		fflush(stdin);
		in.getline(GV.HT, 30);
			while(strlen(GV.HT) < 1  || strlen(GV.HT) > 29){
				cout<<"		Nhap lai ho ten giao vien: ";
				in.getline(GV.HT, 30);
			}
			
		cout<<"Nhap tuoi cua giao vien: ";
		in>>GV.T;
			while(GV.T < 0){
				cout<<"		Nhap lai tuoi cua giao vien: ";
				in>>GV.T;
			}
		fflush(stdin);
		
		cout<<"Nhap bang cap cua giao vien: ";
		in.getline(GV.BC, 15);
			while(strlen(GV.BC) < 1 || strlen(GV.BC) > 14){
				cout<<"		Nhap lai bang cap cua giao vien: ";
				in.getline(GV.BC, 15);
			}
			
		cout<<"Nhap chuyen nganh cua giao vien: ";
		in.getline(GV.CN, 20);
			while(strlen(GV.CN) < 1 || strlen(GV.CN) > 19){
				cout<<"		Nhap lai chuyen nganh cua giao vien: ";
				in.getline(GV.CN, 20);
			}
			
		cout<<"Nhap bac luong: ";
		in>>GV.BL;
			while(GV.BL < 0){
				cout<<"		Nhap lai bac luong: ";
				in>>GV.BL;
			}
			
		return in;
	}
	
	friend ostream& operator << (ostream& out, GiaoVien &GV){
		out<<setw(35)<<left<<GV.HT
		   <<setw(10)<<GV.T
		   <<setw(25)<<left<<GV.BC
		   <<setw(30)<<left<<GV.CN
		   <<setw(10)<<left<<GV.BL
		   <<setw(15)<<left<<GV.BL * 610 <<endl;
		
		return out;
	}
	
	bool operator == (GiaoVien GV){
		return strcmpi(this->BC, GV.BC) == 0;
	}
};


void TieuDe(){
	cout<<"\n\n---------------------------------------DANH SACH GIAO VIEN----------------------------------------\n\n"<<endl;
	cout<<setw(30)<<left<<"HO TEN"
		<<setw(10)<<"TUOI"
		<<setw(25)<<"BANG CAP"
		<<setw(30)<<"CHUYEN NGANH"
		<<setw(10)<<left<<"BAC LUONG"
		<<setw(15)<<right<<"LUONG CO BAN"<<endl;
}

void Nhap(GiaoVien GV[], int&n){
	for(int i=0; i<n; i++){
		cout<<"\nNhap tt giao vien thu "<<i+1<<": "<<endl;
		cin>>GV[i];
	}
}

void Xuat(GiaoVien GV[], int n){
	for(int i=0; i<n; i++){
		cout<<GV[i];
	}
}

void XuatBC(GiaoVien GV[], int n){
	cout<<"\n\n------------------------------DANH SACH GIAO VIEN THEO BANG CAP------------------------------\n\n"<<endl;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(GV[i].get_BC(), GV[j].get_BC())>0){
				swap(GV[i], GV[j]);
			}
		}
	}
Xuat(GV, n);	
}

int main(){
	int n;
		do{
			cout<<"Nhap n giao vien: ";
			cin>>n;
				if(n<1){
					cout<<"   Nhap lai n giao vien: ";
					cin>>n;
				}
		}while(n<1);
	GiaoVien GV[n];
Nhap(GV, n);
TieuDe();
Xuat(GV, n);
XuatBC(GV, n);
	
	return 0;
}
