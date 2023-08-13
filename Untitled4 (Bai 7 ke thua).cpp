#include<iostream>
#include<cstring>
#include<iomanip>
#include<conio.h>
using namespace std;	
class Nguoi{
	protected:
		string HT;
		int NamSinh;
	public:
		Nguoi(string HT = "", int NamSinh = 0){
			this->HT, HT;
			this->NamSinh = NamSinh;
		}
		~Nguoi(){} 
		
		void Nhap(){
			cout<<"Nhap ho ten: ";
			fflush(stdin);
			getline(cin, HT);
			while(HT.length() < 1){
				cout<<"		Nhap lai ho ten: ";
				getline(cin, HT);
			}
			
			cout<<"Nhap nam sinh: ";
			cin>>NamSinh; 
			while(NamSinh < 0){
				cout<<"		Nhap lai nam sinh: ";
				cin>>NamSinh;
			}
		}
		
		void Xuat()	{
			cout<<setw(30)<<HT
				<<setw(10)<<NamSinh; 
		}
}; 
class ThiSinh : public Nguoi{
	int SBD;
	float T, L, H;
	public:
		ThiSinh(string HT = "", int NamSinh = 0 ,int SBD = 0, float T = 0, float L = 0, float H = 0):Nguoi(HT, NamSinh){
			this->SBD = SBD;
			this->T = T;
			this->L = L;
			this->H = H;
		} 
		~ThiSinh(){} 
		void Nhap(){
			this->Nguoi::Nhap() ;
			
			cout<<"Nhap so bao danh: ";
			cin>>SBD;
			while(SBD < 0){
				cout<<"		Nhap lai so bao danh: ";
				cin>>SBD;
			}
			
			cout<<"Nhap diem toan: ";
			cin>>T;
			while(T < 0 || T > 10){
				cout<<"		Nhap lai diem toan: ";
				cin>>T;
			}
			
			cout<<"Nhap diem ly: ";
			cin>>L;
			while(L < 0 || L > 10){
				cout<<"		Nhap lai diem ly: ";
				cin>>L;
			}
			
			cout<<"Nhap diem hoa: ";
			cin>>H;
			while(H < 0 || H > 10){
				cout<<"		Nhap lai diem hoa: ";
				cin>>H;
			}	 
		}
		
		float TongDiem(){
			return T + L + H;
		}
		
		void Xuat(){
			Nguoi::Xuat(); 
			cout<<setw(10)<<SBD
				<<setw(10)<<T
				<<setw(10)<<L
				<<setw(10)<<H
				<<setw(10)<<TongDiem()<<endl; 
		} 
		
		void TimSBD(){
			int f;
				cout<<"Nhap so bao danh can tim: ";
				cin>>f;
			while(f < 0){
				cout<<"		Nhap lai so bao danh can tim: ";
				cin>>f;
			}
			if(f == SBD){
				cout<<"Thi sinh can tim: "<<endl;
				Xuat();
			}
			else{
				cout<<"Khong tim thay thi sinh !"<<endl;
			}
		}
		
		void DatYeuCau(int x=0){
			if(T >= 5 && L >= 5 && H >= 5){
				x+=1;
			}
			cout<<"\nSo thi sinh dat yeu cau la: "<<x<<endl;
		}
}; 

void nhap(ThiSinh TS[], int &n){
	cout<<"Nhap so thi sinh: ";
		cin>>n;
		while(n<1){
			cout<<"Nhap lai so thi sinh: ";
			cin>>n;
		}
	cout<<"\tNhap tt cho "<<n<<" thi sinh:"<<endl;
	for(int i=0; i<n; i++){
		cout<<"\nThi sinh thu "<<i+1<<": "<<endl;
		TS[i].Nhap();
	}
}

void Tieude(){
	cout<<setw(30)<<"Ho ten"
		<<setw(10)<<"Nam Sinh"
		<<setw(10)<<"So bao danh"
		<<setw(10)<<"Diem toan"
		<<setw(10)<<"Diem ly"
		<<setw(10)<<"Diem hoa"
		<<setw(10)<<"Tong diem"<<endl;
}

void Sapxep(ThiSinh TS[], int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(TS[i].TongDiem() > TS[j].TongDiem()){
				swap(TS[i], TS[j]);
			}
		}
	}
}

void xuat(ThiSinh TS[], int n){
	cout<<"\t\t\tDanh sach thi sinh co tong diem 3 mon tang dan"<<endl;
	Tieude();
	Sapxep(TS, n);
	for(int i=0; i<n; i++){
		TS[i].Xuat();
	}
}

void Timsbd(ThiSinh TS[], int n){
	for(int i=0; i<n; i++){
		TS[i].TimSBD();
	}
}

void Datyeucau(ThiSinh TS[], int n){
	for(int i=0; i<n; i++){
		TS[i].DatYeuCau();
	}
}

void Menu(){
	cout<<" ----------------------------------------------- "<<endl;
	cout<<"|                     MENU                      |"<<endl;
	cout<<" ----------------------------------------------- "<<endl;
	cout<<"|1. Nhap danh sach thi sinh                     |"<<endl;
	cout<<"|2. In danh sach thi sinh tong diem tang dan    |"<<endl;
	cout<<"|3. Tim thi sinh                                |"<<endl;
	cout<<"|4. Thong ke thi sinh dat yeu cau               |"<<endl;
	cout<<"|5. Thoat chuong trinh                          |"<<endl; 
	cout<<" ----------------------------------------------- "<<endl;
}

void Nhaplai(){
	getch();
	system("cls");
}

int main(){
	bool check=true;
	int n=0, m;
	ThiSinh TS[100];
	while(1){
		Menu();
		loop:
			cout<<"\n\nNhap lua chon: ";
			cin>>m;
			if(check==true){ 			
				if(m==1 || m==6) 			
					check=false;
				else{ 					
					cout<<"Ban can nhap 1 truoc khi vao cac chuc nang khac" ;
					goto loop;	
				} 
			}
		switch(m){
			case 1:
				nhap(TS, n);
			break;
			case 2:
				xuat(TS, n);
			case 3:
				Timsbd(TS, n);
			break;
			case 4:
				Datyeucau(TS, n);
			break;	
			case 5:
				cout<<"                      END                     ";
				exit(0);
			default:
				cout<<"Khong hop le!	Moi nhap lai";
				Nhaplai();
			break;				
		}	
	}
	return 0;
}

