#ifndef ERGASIA3_H
#define ERGASIA3_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>


/*

εχεις κανει το ερωτημα 1, με getter,setter,constr,destr
με την κλαση καθηγητης.
Προσθεσα λειτουργειες, να δουμε τι αλλο μπορουμε να βαλουμε


απο το 2 τα εχω ολα
και συναρτησεις (? εχω κανει μια, μπορει να ειναι και αρκετη)

απο το 3 εχω προσθεσει το vector με τα μαθηματα και συναρτησεις προσθηκης


απο το 4 εχω φτιαξει καταλογο φοιτ,καθ,μαθ, καθως και βασικες συναρτησεις, (προσθ, αφαιρ).


TRY/EXCEPT!

ΔΙΑΦΟΡΑ ΑΡΧΕΙΑ .h ΓΙΑ ΤΟ ΠΡΟΓΡΑΜΜΑ

*/




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

	virtual void printall();



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
	void printall();

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
		Foititis(const char * a, string b) : Member(a,b,1){}; //init list
		Foititis(const char * a, string b, int c, unsigned int d) : Member(a,b,c), eksamino(d){};
		Foititis(const Foititis& foit) : Member(foit),  eksamino(foit.eksamino), mathimata(foit.mathimata){}; // copy constructor
	        ~Foititis(); //αποδομητής - destructor


		void printall(); //εκτύπωση όλων των δεδομένων
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
	Kathigitis(const char* a, string b) : Member(a,b,1){}; //constructor με κωδικό και ειδικότητα
	Kathigitis(const char* a,string b, int c, string d) :Member(a,b,c), specialty(d){}; // constructor με όλους τις παραμέτρους
	Kathigitis(const Kathigitis& prof) : Member(prof),specialty(prof.specialty),mathimata(prof.mathimata){}; // copy constructor
	~Kathigitis(); // αποδομητής - destructor

	//λοιπές συναρτήσεις
	void printall(); //εκτύπωση στοιχείων καθηγητή
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
	void delete_eggegrameno(const char * id);
	void delete_mathima(const char * id);

	//συναρτήσεις εκτύπωσης
	void print_eggegramenoi();
	void print_mathimata();

	//συναρτήσεις αναζήτησης
	void search_eggegrameno(const char * id);
	void search_mathima(const char * id);

	//συναρτήσεις διόρθωσης
	void correct_onep(const string& idsearch, const string& nonep);
	void correct_fylo(const string& idsearch);
	void correct_id(const string& idsearch, const string& neoid);

	void correct_eksamino(const string& idsearch, unsigned int neoeks);
	void correct_specialty(const string& idsearch, string neospec);


	//συναρτήσεις αποστολής email
	void email_foitites(string email);
	void email_kathigites(string email);

	//συναρτήσεις εισαγωγής και εξαγωγής σε αρχείο
	//εισαγωγή
	void import_foitites_from_csv(const string& filename);
	void import_kathigites_from_csv(const string& filename);
	void import_mathimata_from_csv(const string& filename);

	//εξαγωγή
	void output_foitites_to_csv(const string& filename);
	void output_kathigites_to_csv(const string& filename);
	void output_mathimata_to_csv(const string& filename);

	~Foititologio(); //destructor
};






#endif

