#ifndef ERGASIAEX_H
#define ERGASIAEX_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ncurses.h>
#include <locale.h>


using namespace std;

//κλάση μέλους τμήματος, ώστε να δέχεται και φοιτητές και καθηγητές

class Member{
private:
	char * id;

protected:
    string onep;
	int fylo;


public:

	//setters
	void set_id(const char * a);
	void set_onep(string a);
	void set_fylo(int a);

	//getters
	const char * get_id();
	string get_onep();
	int get_fylo();

	virtual void printall(WINDOW* w, int currow, int curcol);



	//operator =
	Member& operator= (const Member& other);

	//constructors
	Member();
	Member(const char * a);
	Member(const char * a, string b, int c);

	//copy constructor
	Member(const Member& other);
	//destructor
	virtual ~Member();


};

class Kathigitis; //αρχικοποίηση που απαιτείται για να μπορεί να δηλωθεί το μάθημα

class Mathima{
private:
	char * id;
	string description;
	int semester;
	Kathigitis* professor;

public:
	//Συναρτήσεις getter
	const char * get_id();
	string get_desc();
	int get_sem();
	string get_prof();

	//Συναρτήσεις setter
	void set_id(const char * new_id);
	void set_desc(string desc);
	void set_sem(int sem);
	void set_prof(Kathigitis* prof);

	//συναρτηση εκτυπωσης
	void printall(WINDOW* w, int currow, int curcol) ;

	//υπερφόρτωση τελεστή =
	Mathima& operator=(const Mathima& other);

	//constructors - destructor
	Mathima(); //κενος constructor
	Mathima(const char * a, int sem);
	Mathima(const char * a, string desc, int sem);
	Mathima(const char * a, string desc,int sem, Kathigitis* prof);
	Mathima(const Mathima& other); //copy constructor
	~Mathima(); //destructor

};


class Foititis : public Member{

	private:

		unsigned int eksamino;
		vector<Mathima> mathimata;

	public:
		Foititis(); // κενός constructor
		Foititis(const char * a, string b);
		Foititis(const char * a, string b, int c, unsigned int d) ;
		Foititis(const Foititis& foit); // copy constructor
	    ~Foititis(); //αποδομητής - destructor


		void printall(WINDOW* w, int currow, int curcol) override; //εκτύπωση όλων των δεδομένων
		void sinena(); //προσθήκη ενός εξαμήνου,  sinena = συν ενα
		void add_mathima(Mathima neo); //προσθηκη μαθηματος
		void print_mathimata(); //εκτύπωση μαθημάτων

		Foititis& operator ++(int n); //αύξηση ενός εξαμήνου   x++
		Foititis& operator ++();      // ομοίως, αλλά για προσαύξηση ++x
		Foititis& operator +=(int n); //αύξηση κατά n εξάμηνα
		Foititis& operator -=(int n); //μείωση κατά n εξάμηνα
		Foititis& operator -(); //αλλαγή φύλου
		Foititis& operator = (const Foititis& other);

		unsigned int get_eksamino();
		void set_eksamino(unsigned int a);


};

class Kathigitis : public Member{
private:

	string specialty;
	vector<Mathima> mathimata;
public:

	//Constructors
	Kathigitis(); // κενός constructor, καμία παράμετρος
	Kathigitis(const char* a, string b); //constructor με κωδικό και ειδικότητα
	Kathigitis(const char* a,string b, int c, string d); // constructor με όλους τις παραμέτρους
	Kathigitis(const Kathigitis& prof); // copy constructor
	~Kathigitis(); // αποδομητής - destructor

	//λοιπές συναρτήσεις
	void printall(WINDOW * w, int currow, int curcol); //εκτύπωση στοιχείων καθηγητή
	void add_mathima(Mathima neo); //προσθήκη μαθήματος
	void print_mathimata(); //εκτύπωση μαθημάτων

	//Συναρτήσεις getter
	//const char get_id();
	string get_specialty();

	//Συναρτήσεις getter
	//void set_id(const char* new_id);
	void set_specialty(string new_spec);

   	//operator =
	Kathigitis& operator= (const Kathigitis& other);

};


class Foititologio{

private:
	vector<Member*>eggegramenoi;
	vector<Mathima*>mathimata;

public:

	//συναρτήσεις εισαγωγής
	void add_eggegrameno(Member* to_add);
	void add_mathima(Mathima* to_add);

	//συναρτήσεις διαγραφής
	void delete_eggegrameno(WINDOW* w,const char * id);
	void delete_mathima(WINDOW* w,const char * id);

	//συναρτήσεις εκτύπωσης
	void print_eggegramenoi(WINDOW* w);
	void print_mathimata(WINDOW* w);

	//συναρτήσεις αναζήτησης
	void search_eggegrameno(WINDOW* w, const char * id);
	void search_mathima(WINDOW* w, const char * id);

	//συναρτήσεις διόρθωσης
	void correct_onep(WINDOW* w, const string& idsearch, const string& nonep);
	void correct_fylo(WINDOW* w,const string& idsearch);
	void correct_id(WINDOW* w,const string& idsearch, const string& neoid);

	void correct_eksamino(WINDOW* w,const string& idsearch, unsigned int neoeks);
	void correct_specialty(WINDOW* w,const string& idsearch, string neospec);


	//συναρτήσεις αποστολής email
	void email_foitites(WINDOW* w, string email);
	void email_kathigites(WINDOW* w,string email);

	//συναρτήσεις ελέγχου
    bool is_emptyegg();
    bool is_emptymath();
    int eggsize();
    int mathsize();
	Kathigitis* getkath(string& id);


	//συναρτήσεις εισαγωγής και εξαγωγής σε αρχείο
	//εισαγωγή
	void import_foitites_from_csv(WINDOW* w, const string& filename);
	void import_kathigites_from_csv(WINDOW* w, const string& filename);
	void import_mathimata_from_csv(WINDOW* w, const string& filename);

	//εξαγωγή
	void export_foitites_to_csv(WINDOW* w, const string& filename);
	void export_kathigites_to_csv(WINDOW* w, const string& filename);
	void export_mathimata_to_csv(WINDOW* w, const string& filename);

	~Foititologio(); //destructor
};


//συναρτήσεις παραθύρων
void gotoviewegg(WINDOW* w, Foititologio& f);
void gotosearchegg(WINDOW* w, Foititologio& f);
void gotoedit(WINDOW* w, Foititologio& f);
void gotoviewmath(WINDOW* w, Foititologio& f);
void gotosearchmath(WINDOW* w, Foititologio& f);
void gotoeditmath(WINDOW* w, Foititologio& f);
void gotoemail(WINDOW* w, Foititologio& f);
void gotoexport(WINDOW* w, Foititologio& f);

string inputuser(WINDOW* w, int y, int x, string pr);

void gotoaddfoit(WINDOW* w, Foititologio& f);
void gotoaddkath(WINDOW* w, Foititologio& f);
void gotoaddmath(WINDOW* w, Foititologio& f);

void dioam(WINDOW* w, Foititologio& f );
void dioonep(WINDOW* w, Foititologio& f);
void diofy(WINDOW* w,Foititologio& f);
void dioeks(WINDOW* w, Foititologio& f);
void diospe(WINDOW* w, Foititologio& f);

void gotoeditegg(WINDOW* w, Foititologio& f);
void gotoeditmath(WINDOW* w, Foititologio& f);

void gotodelegg(WINDOW* w, Foititologio& f);
void gotodelmath(WINDOW* w, Foititologio &f);

void gotoemailfoit(WINDOW* w, Foititologio& f);
void gotoemailkath(WINDOW* w, Foititologio& f);

void exportcsv(WINDOW* w, Foititologio& f);
void exportfoit(WINDOW* w, Foititologio& f );
void exportkath(WINDOW* w, Foititologio& f );
void exportmath(WINDOW* w, Foititologio& f );

void importcsv(WINDOW* w, Foititologio& f);
void importfoit(WINDOW* w, Foititologio& f );
void importkath(WINDOW* w, Foititologio& f );
void importmath(WINDOW* w, Foititologio& f );









#endif

