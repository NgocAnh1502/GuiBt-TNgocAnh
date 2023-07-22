#include<iostream>
using namespace std;
class SoThuc{
	private:
		int Tuso, Mauso;
		float Sothuc;
	public:
		void nhap(){
			cout<<"Nhap tu so: ";
			cin>>Tuso;
			cout<<"Nhap mau so: ";
			cin>>Mauso;
			while(Mauso == 0){
				cout<<"Nhap lai mau so: ";
				cin>>Mauso;
			}
		}
		void xuat(){
			cout<<"\nSo thuc: "<<Tuso<<"/"<<Mauso<<endl;
		}
};
int main(){
	SoThuc n;
	n.nhap();
	n.xuat();
}
