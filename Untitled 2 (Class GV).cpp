#include<iostream>
#include<string.h>
using namespace std;
class GV{
	private:
		char HT[30], BC[15], CN[20];
		int T;
		float BL;
		
	// em chua hieu y cho sap xep theo chuyen nganh	
	public:
		GV(){
			strcpy(HT, "Chua nhap");
			T = 0;
			strcpy(BC, "Chua nhap");
			strcpy(CN, "Chua nhap");
			BL = 0;
		}	
		~GV(){}
		void Nhap(){
			cout<<"Nhap ho ten cua giao vien: ";
			cin.getline(HT, 30);
			
			cout<<"Nhap tuoi cua giao vien: ";
			cin>>T;
			fflush(stdin);
			
			cout<<"Nhap bang cap cua giao vien: ";
			cin.getline(BC, 15);
			
			cout<<"Nhap chuyen nganh cua giao vien: ";
			cin.getline(CN, 30);
			
			cout<<"Nhap bac luong cua giao vien: ";
			cin>>BL;
			fflush(stdin);
		}
		float TinhLCB(){
			return this->BL * 610;
		}
		void Xuat(){
			cout<<"Ho ten: "<<HT<<endl
				<<"Tuoi: "<<T<<endl
				<<"Bang cap: "<<BC<<endl
				<<"Chuyen nganh: "<<CN<<endl
				<<"Bac luong: "<<BL<<endl
				<<"Luong co ban: "<<this->TinhLCB()<<endl;
		}
};
void Nhap(GV gv[], int &n){
	cout<<"\n\n\n----------------NHAP THONG TIN GIAO VIEN----------------"<<endl;
	for(int i=0; i<n; i++){
			cout<<"\nGiao vien thu "<<i+1<<": "<<endl;
			gv[i].Nhap();
		}
}
void Xuat(GV gv[], int n){
	cout<<"\n\n\n\n--------------Danh sach thong tin giao vien--------------"<<endl;
		for(int i=0; i<n; i++){
			cout<<"\nGiao vien thu "<<i+1<<": "<<endl;
			gv[i].Xuat();
		}
}
void Xuatduoi2k(GV gv[], int n){
	cout<<"\n\n\n\n--------------Danh sach luong duoi 2000--------------"<<endl;
		for(int i=0; i<n; i++){
			if(gv[i].TinhLCB() < 2000){
				cout<<"\nGiao vien thu "<<i+1<<": "<<endl;
				gv[i].Xuat();
			}
		}
}
int main(){
	int n;
	do{
		cout<<"Nhap so giao vien: ";
		cin>>n;
		if(n<=0){
			cout<<"Nhap lai so giao vien: ";
			cin>>n;
		}
		fflush(stdin);
	}while(n<=0);
	GV *gv = new GV[n];		
Nhap(gv, n);
Xuat(gv, n);
Xuatduoi2k(gv, n);
	return 0;
}
