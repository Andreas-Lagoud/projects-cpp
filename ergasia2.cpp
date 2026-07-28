#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Foititis{

	private:
		char * am;
		string onep;
		int fylo; //0 άνδρας   1 γυναίκα
		unsigned int eksamino;

	public:
		Foititis(); // κενός constructor
		Foititis(const char * a, string b);
		Foititis(const char * a, string b, int c, unsigned int d);
		Foititis(const Foititis& foit); // copy constructor
	        ~Foititis(); //αποδομητής


		void Printall(); //εκτύπωση όλων των δεδομένων
		void Sinena(); //προσθήκη ενός εξαμήνου,  sinena = συν ενα

		Foititis& operator ++(int n); //αύξηση ενός εξαμήνου   x++
		Foititis& operator ++();      // ομοίως, αλλά για προσαύξηση ++x
		Foititis& operator +=(int n); //αύξηση κατά n εξάμηνα
		Foititis& operator -=(int n); //μείωση κατά n εξάμηνα
		Foititis& operator -(); //αλλαγή φύλου
		Foititis& operator = (const Foititis& other);

		//συναρτήσεις getters & setters

		const char* get_am();
		string get_onep();
		int get_fylo();
		unsigned int get_eksamino();

		void set_am(const char * a);
		void set_onep(string a);
		void set_fylo(int a);
		void set_eksamino(unsigned int a);

};

Foititis::Foititis(){

	am = new char[16];
	strcpy(am,"-1");
	onep = "Ανώνυμος/η Ανωνύμου";
	fylo = -1;
	eksamino = 1;

}

Foititis::Foititis(const char * a, string b){ //ΑΜ και ονοματεπωνυμο

	am = new char[strlen(a)+1];
	strcpy(am,a);
	onep = b;
	fylo = 1;
	eksamino = 1; //αρχικοποιώ εξάμηνο 1
}


Foititis::Foititis(const char * a, string b, int c, unsigned int d){ //ολα τα χαρακτηριστικά


	am = new char[strlen(a)+1];
	strcpy(am,a);
	onep = b;
	fylo = c;
	eksamino = d;


}



Foititis::Foititis(const Foititis& foit){ //copy constructor

	am = new char[strlen(foit.am)+1];
	strcpy(am,foit.am); //μεταφορά ΑΜ του φοιτητή στο ΑΜ του νέου αντικειμένου 
	onep = foit.onep; //ομρίως εδώ και στα υπόλοιπα
	fylo = foit.fylo;
	eksamino = foit.eksamino;

}



Foititis::~Foititis(){
	delete[] am;

}


const char * Foititis::get_am(){
	return am;

}

string Foititis::get_onep(){
	return onep;

}

int Foititis::get_fylo(){
	return fylo;

}

unsigned int Foititis::get_eksamino(){
	return eksamino;

}


void Foititis::set_am(const char * a){

	delete[] am;

	am = new char[strlen(a) + 1 ];
	strcpy(am,a);
}

void Foititis::set_onep(string a){
	onep = a;
}

void Foititis::set_fylo(int a){
	fylo = a;
}

void Foititis::set_eksamino(unsigned int a){
	eksamino = a;

}


void Foititis::Printall(){
	string fy = (fylo==0) ? "Άνδρας" : "Γυναίκα";
	cout << "Αριθμός Μητρώου: " << am << " Ονοματεπώνυμο: " << onep << " ("<<onep.length()<<") " << "Φύλο: " << fy  << " Εξάμηνο: " << eksamino << endl;

}

void Foititis::Sinena(){
	++eksamino;
	cout<<"Επιτυχής αύξηση του εξαμήνου του φοιτητή. Τρέχον εξάμηνο:  " << eksamino << endl;

}

Foititis& Foititis::operator++(int n){
	Sinena();
	return *this;
}

Foititis& Foititis::operator++(){
	Sinena();
	return *this;

}

Foititis& Foititis::operator +=(int n){
	eksamino+=n;
	cout << "Επιτυχής αύξηση του εξαμήνου του φοιτητή. Τρέχον εξάμηνο:    " <<eksamino << endl;
	return *this;
}

Foititis& Foititis::operator -=(int n){
	int  test=eksamino-n; //με αυτή τη τιμή θα ελεγχθεί αν το εξάμηνο που πρόκειται να αλλάξει θα είναι μικρότερο του 1
	if (test>0){		 //έλεγχος μήπως το εξάμηνο είναι μικρότερο του  1, ώστε να μην πέσουμε σε 0,-1,-2, κλπ
		eksamino-=n;
		cout << "Επιτυχής μείωση του εξαμήνου του φοιτητή. Τρέχον εξάμηνο:    " <<eksamino << endl;
	}
	else{
		cout << "Το εξάμηνο είναι μικρότερο του 1!" << endl;
		eksamino=1;

	}

	return *this;
}

Foititis& Foititis::operator -(){

	string fy = (fylo==0) ? "Γυναίκα" : "Ανδρας";
	cout << "Αλλαγή φύλου του φοιτητή σε " << fy << endl;
	if (fylo == 0)
		fylo = 1;
	else
		fylo = 0;
	return *this;
}

Foititis& Foititis::operator= (const Foititis& other){

    if (this == &other) return *this; // ελεγχος για το λεγομενο self assignement

	delete[] am;

	am = new char[strlen(other.am) +1];
	strcpy(am, other.am);

	onep=other.onep;
	fylo=other.fylo;
	eksamino=other.eksamino;


	return *this;


}


int main(){

	Foititis* Assignment = new Foititis[5]; //εργασία που θα ανατεθεί σε 5 φοιτητές
	Assignment[0]=Foititis("1312","Χρήστος Κουραμπάς",0,2);
	Assignment[1]=Foititis("24","Μπρούνο Άλικο",0,2);
	Assignment[2]=Foititis("2438","Παναγιώτης Αμπάβης",0,14); //αιώνιος φοιτητής
	Assignment[3]=Foititis("7","Σοφία Κοφσανίδου"); //Δεν έβαλα φύλο ή εξάμηνο
	Assignment[4]=Foititis("666","Μιχάλης Κατζουράκης ",0,4);


	Foititis copy =  Assignment[0]; //copy constructor

	Assignment[3].Printall(); //εκτυπώνει τα χαρακτηριστικά

	Assignment[2]+=2; //αύξηση κατά δύο εξάμηνα

	-Assignment[4]; //Αλλαγή φύλου σε γυναίκα

	Assignment[1]-=(3); //δεν θα λειτουργήσει

	Assignment[1]++; //Αύξηση εξαμήνων κατά 1

	

	delete[] Assignment; //διαγραφή του πίνακα

	return 0;

}
