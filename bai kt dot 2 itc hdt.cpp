#include<iostream>
#include<cstring>
using namespace std;
class doc_gia{
	protected:
		string ma_sach, ten_sach, tac_gia, nguoi_thue, ngay_thue, ngay_tra;
		int tuoi;
	public:
		virtual void nhap(){
			cout<<"Nhap ma sach: ";
			fflush(stdin);
			getline(cin, ma_sach);
			cout<<"Nhap ten sach: ";
			getline(cin, ten_sach);
			cout<<"Nhap ten tac gia: ";
			getline(cin, tac_gia);
			cout<<"Nhap ten nguoi thue: ";
			getline(cin, nguoi_thue);
			cout<<"Nhap tuoi nguoi thue: ";
			cin>>tuoi;
			fflush(stdin);
			cout<<"Nhap ngay thue: ";
			getline(cin, ngay_thue);
			cout<<"Nhap ngay tra: ";
			getline(cin, ngay_tra);
		}
		
		virtual void xuat(){
			cout<<"Ma sach: "<<ma_sach<<endl;
			cout<<"Ten sach: "<<ten_sach<<endl;
			cout<<"Tac gia: "<<tac_gia<<endl;
			cout<<"Ten nguoi thue: "<<nguoi_thue<<endl;
			cout<<"Tuoi: "<<tuoi<<endl;
			cout<<"Ngay thue: "<<ngay_thue<<endl;
			cout<<"Ngay tra: "<<ngay_tra<<endl; 	
		}
		
		virtual bool loai_doc_gia() = 0;
		
		string get_tac_gia(){
			return this->tac_gia;
		}
};

class tre_em : public doc_gia{
	string nguoi_giam_ho;
	int thanh_tien1 = 2;
	
	public:
		void nhap(){
			doc_gia::nhap();
			cout<<"Nhap ten nguoi giam ho: ";
			getline(cin, nguoi_giam_ho);
		}
		
		void xuat(){
			doc_gia::xuat();
			cout<<"Ten nguoi giam ho: "<<nguoi_giam_ho<<endl;
			cout<<"Thanh tien: "<<thanh_tien1<<"k"<<endl;
		}
		
		bool loai_doc_gia(){
			return true;
		}
};

class nguoi_lon : public doc_gia{
	int cmt;
	int thanh_tien2 = 3;
	
	public:
		void nhap(){
			doc_gia::nhap();
			cout<<"Nhap so chung minh thu: ";
			cin>>cmt;
			fflush(stdin);
		}
		
		void xuat(){
			doc_gia::xuat();
			cout<<"So chung minh thu: "<<cmt<<endl;
			cout<<"Thanh tien: "<<thanh_tien2<<"k"<<endl;
		}
		
		bool loai_doc_gia(){
			return false;
		}
};

class quan_ly_ho_so{
	private:
		doc_gia *ql[100];
		int n;
	public:
		void Nhap_danh_sach(){
			cout<<"Nhap so doc gia: ";
			cin>>n;
			
			cout<<"Nhap danh sach "<<n<<" doc gia:\n";
			for(int i=0; i<n; i++){
				cout<<"\t\t\t MENU \n"
					<<"\t\t 1. Doc gia tre em\n"
					<<"\t\t 2. Doc gia nguoi lon\n"
					<<"\t\t Nhap lua chon cua ban: ";
				int lc;
					cin>>lc;
				while(lc<1 || lc >2){
					cout<<"\t\t\t Lua chon nay khong ton tai, hay chon lai: ";
					cin>>lc;
				}
				if(lc == 1){
					ql[i] = new tre_em();
				}	
				else{
					ql[i] = new nguoi_lon();
				}
				ql[i]->nhap();
			}
		}	
		
		void Xuat_danh_sach(){
			cout<<"\t\tXuat danh sach "<<n<<" doc gia\n";
			for(int i=0; i<n; i++){
				cout<<"Doc gia "
					<<(ql[i]->loai_doc_gia() ? "tre em" : "nguoi lon")
					<<" thu "<<i+1<<endl;
				ql[i]->xuat();	
			}
		}
		
		void tinh_tien(){
			int x=0, y=0;
			for(int i=0; i<n; i++){
				if(ql[i]->loai_doc_gia() == true){
					x+=1;
				}
				else{
					y+=1;
				}
			}
			cout<<"Thanh tien doc gia tre em: "<<2*x<<"k"<<endl;
			cout<<"Thanh tien doc gia nguoi lon: "<<3*y<<"k"<<endl;
		}
		
		void Sap_xep_ten_tac_gia(){
			for (int i=0; i<n; i++){
				for (int j=i+1; j<n; j++){
					if (ql[i]->get_tac_gia() > ql[j]->get_tac_gia()) {
            			swap(ql[i], ql[j]);
        			}
				}		
			}
			Xuat_danh_sach();
		}
};

int main(){
	quan_ly_ho_so *ql = new quan_ly_ho_so();
	ql->Nhap_danh_sach();
	ql->Xuat_danh_sach();
	ql->Sap_xep_ten_tac_gia();
	ql->tinh_tien();
	return 0;
}
