#include "ergasia3.h"

#include <fstream>
#include <sstream>
#include <stdexcept>


// κλάσεις της Member

//getters
const char * Member::get_id(){
	return id;
}

string Member::get_onep(){
	return onep;

}

int Member::get_fylo(){

	return fylo;

}

//setters

void Member::set_id(const char * a){

    id = new char[strlen(a)+1];
	strcpy(id,a);

}

void Member::set_onep(string a){
	onep = a;
}

void Member::set_fylo(int a){
	fylo = a;
}




//constructors

Member::Member(){

	id = new char[16];
	strcpy(id,"-1");
    onep =  "Ανώνυμος";
    fylo=1;

}

Member::Member(const char * a){

	id = new char[strlen(a)+1];
	strcpy(id,a);
    	onep = "Ανώνυμος";
    	fylo=1;

}

Member::Member(const char * a, string b, int c){

    id = new char[strlen(a)+1];
    strcpy(id,a);
    onep = b;
    fylo = c;



}


//copy constructor

Member::Member(const Member& other){

	id = new char[strlen(other.id)+1];
	strcpy(id,other.id);
    onep=other.onep;
    fylo=other.fylo;

}

void Member::printall(){
    cout << "Για να προβληθούν όλες οι πληροφορίες, θα πρέπει το αντικείμενο να είναι φοιτητής ή καθηγητής, όχι απλά ένας εγγεγραμένος του τμήματος" << endl;
}


//destructor


Member::~Member(){


	delete[] id;

}

Member& Member::operator= (const Member& other){

    if (this == &other) {return *this;} // ελεγχος για το λεγομενο self assignement

	delete[] id;

	//id=other.id;
	id = new char[strlen(other.id)+1];
	strcpy(id,other.id);
	onep=other.onep;
	fylo=other.fylo;

	return *this;


}


/*


Εδώ ορίζονται οι συναρτήσεις  της κλάσης Φοιτητής (Foititis)



*/

//constructors

Foititis::Foititis(){

	//id = new char[16];
	//strcpy(id,"-1");
	onep = "Ανώνυμος/η Ανωνύμου";
	fylo = -1;
	eksamino = 1;

}
/*
Foititis::Foititis(const char * a, string b){ //ΑΜ και ονοματεπωνυμο

	id = new char[strlen(a)+1];
	strcpy(id,a);
	onep = b;
	fylo = 1;
	eksamino = 1; //αρχικοποιώ εξάμηνο 1
}


Foititis::Foititis(const char * a, string b, int c, unsigned int d){ //ολα τα χαρακτηριστικά


	id = new char[strlen(a)+1];
	strcpy(id,a);
	onep = b;
	fylo = c;
	eksamino = d;


}



Foititis::Foititis(const Foititis& foit){ //copy constructor

    Member(foit);
	eksamino = foit.eksamino;
	mathimata = foit.mathimata;
}

*/

Foititis::~Foititis(){


}

//getters

/*
const char * Foititis::get_am(){
	return am;

}
*/


unsigned int Foititis::get_eksamino(){
	return eksamino;

}

//setters

/*
void Foititis::set_am(const char * a){

	delete[] am;

	am = new char[strlen(a) + 1 ];
	strcpy(am,a);
}
*/




void Foititis::set_eksamino(unsigned int a){
	eksamino = a;

}


//συναρτήσεις με διάφορες λειτουργίες


void Foititis::printall(){
	string fy = (fylo==0) ? "Άνδρας" : "Γυναίκα";
	cout << "-=ΠΛΗΡΟΦΟΡΙΕΣ ΦΟΙΤΗΤΗ=-\n"<<"Αριθμός Μητρώου: " << get_id() << "\nΟνοματεπώνυμο: " << onep << " ("<<onep.length()<<") " << "\nΦύλο: " << fy  << "\nΕξάμηνο: " << eksamino << endl;

}

void Foititis::sinena(){
	++eksamino;
	cout<<"Επιτυχής αύξηση του εξαμήνου του φοιτητή. Τρέχον εξάμηνο:  " << eksamino << endl;

}

void Foititis::add_mathima(Mathima neo){
	mathimata.push_back(neo);
} 

void Foititis::print_mathimata(){

	for(auto math : mathimata){
		math.get_desc();


	}


}



//συναρτήσεις με τελεστές - operator overloading

Foititis& Foititis::operator++(int n){
	sinena();
	return *this;
}

Foititis& Foititis::operator++(){
	sinena();
	return *this;

}

Foititis& Foititis::operator +=(int n){
	eksamino+=n;
	cout << "Επιτυχής αύξηση του εξαμήνου του φοιτητή. Τρέχον εξάμηνο:" <<eksamino << "o εξάμηνο" << endl;
	return *this;
}

Foititis& Foititis::operator -=(int n){
	int  test=eksamino-n; //με αυτή τη τιμή θα ελεγχθεί αν το εξάμηνο που πρόκειται να αλλάξει θα είναι μικρότερο του 1
	if (test>0){		 //έλεγχος μήπως το εξάμηνο είναι μικρότερο του  1, ώστε να μην πέσουμε σε 0,-1,-2, κλπ
		eksamino-=n;
		cout << "Επιτυχής μείωση του εξαμήνου του φοιτητή. Τρέχον εξάμηνο: " <<eksamino << "ο εξάμηνο" << endl;
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

    if (this == &other) {return *this;} // ελεγχος για το λεγομενο self assignement
    
    /*
    delete[] id;

	id = new char[strlen(other.id) +1];
	strcpy(id, other.id);
    */

	Member::operator=(other);
	eksamino=other.eksamino;


	return *this;


}

/*


Από εδώ ορίζονται οι συναρτήσεις της κλάσεως Καθηγητής


*/


//getters



string Kathigitis::get_specialty(){
	return specialty;
}



//setters
/*
void Kathigitis::set_id(const char * new_id){
	delete[] id;
	id = new char[strlen(new_id) +1];
	strcpy(id,new_id);
}
*/


void Kathigitis::set_specialty(string new_spec){
	specialty = new_spec;

}

void Kathigitis::printall(){
	cout << "-=ΠΛΗΡΟΦΟΡΙΕΣ ΚΑΘΗΓΗΤΗ=-\nΟνοματεπώνυμο: "<< onep << "\nΚωδικός: " << get_id() << "\nΦύλο: ";
	if (fylo==0){
		cout << "Άνδρας";
	}else if (fylo==1){
		cout << "Γυναίκα";
	}else{
		cout << "Απροσδιόριστο/Άλλο";
	}

	cout << "\nΕιδικότητα: " << specialty << endl;

}

void Kathigitis::add_mathima(Mathima neo){
	mathimata.push_back(neo);
	//neo.set_prof(this); ΑΦΑΙΡΕΣΗ ΛΟΓΩ STACK OVERFLOW ορισμός του μαθήματος στον καθηγητή
}


void Kathigitis::print_mathimata(){

	for(auto math : mathimata){
		cout << math.get_desc() <<endl;


	}


}


//constructors

Kathigitis::Kathigitis(){
	//id = new char[3];
	//strcpy(id,"-1");

	onep = "Ανώνυμος";
	fylo = -1;
	specialty =  "Καμία ειδικότητα ορισμένη";


}
/*
Kathigitis::Kathigitis(const char*a ,string b){

	id = new char[strlen(a) +1];
	strcpy(id,a);

	onep=b;


}



Kathigitis::Kathigitis(const char* a, string b, int c, string d){

	id = new char[strlen(a)+1];
	strcpy(id,a);

	onep=b;
	fylo=c;
	specialty=d;


}


Kathigitis::Kathigitis(const Kathigitis& other){

	id = new char[strlen(other.id)+1];
	strcpy(id,other.id);

	onep=other.onep;
	fylo=other.fylo;
	speciality=other.specialty;
	mathimata = other.mathimata;
}
*/


Kathigitis::~Kathigitis(){




}

Kathigitis& Kathigitis::operator= (const Kathigitis& other){

    	if (this == &other) return *this; // ελεγχος για το λεγομενο self assignement

	//delete[] id;

	//id = new char[strlen(other.id) +1];
	//strcpy(id, other.id);

	Member::operator=(other);
	specialty=other.specialty;


	return *this;


}






//εδώ ορίζονται οι συναρτήσεις της κλάσης "Μάθημα"


//getters

const char * Mathima::get_id(){
	return id;

}

string Mathima::get_desc(){
	return description;
}

int Mathima::get_sem(){
	return semester;
}

string Mathima::get_prof(){

	if(professor==nullptr){return "Κανένας" ;}
	else{ return professor->get_onep();}
}

//setters

void Mathima::set_id(const char * new_id){
	//τα μαθήματα του προγράμματος σπουδών συνήθως έχουν είτε τριψήφιο είτε τετραψήφιο νούμερο και ποτέ πενταψήιο
    /*
	if(new_id >9999)
		cout << "Ο κωδικός του μαθήματος είναι ανώτερος του ορίου (10000) "<< endl;
	else
		id = new char[strlen(new_id)+1];

    comment λογω προκλησης error
    */
	strcpy(id,new_id);
}

void Mathima::set_desc(string desc){
	description = desc;


}

void Mathima::set_sem(int sem){

	if(semester >=1 && semester <=10)
		semester = sem;
	else
		cout << "Το εξάμηνο "<< sem << " είναι εκτός του εύρους! "<< endl;
}

void Mathima::set_prof(Kathigitis* prof){
	professor = prof;
	prof->add_mathima(*this);

}


//print function
void Mathima::printall(){

	cout << "-= ΠΛΗΡΟΦΟΡΙΕΣ ΜΑΘΗΜΑΤΟΣ=-\n" << "Κωδικός μαθήματος: " << get_id() << "\nΠεριγραφή Μαθήματος: " << description << "\nΕξάμηνο διδασκαλείας: " << semester << "ο εξάμηνο" << "\nΥπεύθυνος καθηγητής: ";

    if(professor==nullptr){cout << "Κανένας" << endl;}
    else {cout << professor->get_onep() << endl;} 



}



Mathima& Mathima::operator=(const Mathima& other){

	if (this == &other) {return *this;}
	delete[] id;

	id = new char[strlen(other.id)+1];
	strcpy(id,other.id);
	semester=other.semester;
	description=other.description;
	professor=other.professor;



	return *this;

}


//constructors
Mathima::Mathima(){

	id = new char[3]; //οι χαρακτηρες - 1 \n αντιστοιχουν σε 3 bytes, γιαυτο και δεσμευω 3
	strcpy(id,"-1");
	description = " ";
	semester = 0;
	professor = nullptr;

}

Mathima::Mathima(const char * a, int sem){

	id = new char[strlen(a)+1];
	strcpy(id,a);
	description = " ";
	semester = sem;
	professor = nullptr;


}

Mathima::Mathima(const char * a, string desc, int sem){

	id = new char[strlen(a)+1];
	strcpy(id,a);
	description = desc;
	semester = sem;
	professor = nullptr;




}




Mathima::Mathima(const char * a, string desc, int sem, Kathigitis* prof){
	id = new char[strlen(a)+1];
	strcpy(id,a);
	description=desc;
	semester = sem;
	professor = prof;

}

//copy constructor

Mathima::Mathima(const Mathima& other){

	id = new char[strlen(other.id)+1];
	strcpy(id,other.id);
	description=other.description;
	semester=other.semester;
	professor= other.professor;

}


//destructor

Mathima::~Mathima(){

	delete[] id;

}


// συναρτήσεις Φοιτητολογίου
void Foititologio::add_eggegrameno(Member* to_add){
	eggegramenoi.push_back(to_add);

}


void Foititologio::add_mathima(Mathima* to_add){

	mathimata.push_back( to_add);


}

void Foititologio::delete_eggegrameno(const char * id){
	int pos=0;
	for(auto melos = eggegramenoi.begin() ; melos != eggegramenoi.end() ; melos++){
		if(strcmp( (*melos)->get_id(), id) == 0 ) {
			eggegramenoi.erase(eggegramenoi.begin() + pos); //αν δεν ειναι διευθυνση μνημης βγαζει σφαλμα
			cout << "Το μέλος με ΑΜ " << id << " διαγράφηκε επιτυχώς. " << endl;
 			return;
	}
		//else{pos++;}


	}
	cout << "Δεν βρέθηκε εγγεγραμένος  με ΑΜ " << id << endl;
}

void Foititologio::delete_mathima(const char * id){
	int pos=0;
	for(auto math = mathimata.begin() ; math !=mathimata.end() ; math++){
		if(strcmp( (*math)->get_id() , id ) == 0){ 
			mathimata.erase(mathimata.begin()+pos); //αν δεν ειναι διευθυνση μνημης βγαζει σφαλμα
			cout << "Το μάθημα με ΑΜ " << id << " διαγράφηκε επιτυχώς. " << endl;
 			return;
	}
		//else{pos++;}


	}

	cout << "Δεν βρέθηκε μάθημα με ΑΜ " << id << endl;

}

void Foititologio::print_eggegramenoi(){

	cout << "Ακολουθούν τα στοιχεία ΌΛΩΝ των εγγεγραμένων του τμήματος:  " << endl;

	for (auto eg : eggegramenoi){
		eg->printall();
		//cout << "ΑΜ: " << eg->get_id() << " Ονοματεπώνυμο: " << eg->get_onep() << "



	}

}

void Foititologio::print_mathimata(){

	cout << "Ακολοθούν τα στοιχεία ΌΛΩΝ των μαθημάτων του τμήματος:  " << endl;

	for (auto math : mathimata){
		math->printall();


	}


}


void Foititologio::search_eggegrameno(const char * id){

	for (auto memb: eggegramenoi){

		if(strcmp(memb->get_id(),  id  ) == 0 ) //δηλαδη, αν βρω ιδιο φοιτητη με τον ιδιο ΑΜ
		{
			cout << "Βρέθηκε μέλος του τμήματος με ΑΜ " << id << endl;

			/*
			Foititis* foitptr = dynamic_cast<Foititis*>(memb); //εδω κανω dynamic cast με τελικο σκοπο να δω αν το μελος ειναι φοιτητης η καθηγητης.
			if(foitptr !=  nullptr){ //ελεγχω αν είναι φοιτητής
				foitptr->printall();
			}else{ //αλλιως, πρεπει να ειναι καθηγητης
				Kathigitis* kathptr = dynamic_cast<Kathigitis*>(memb);
                		kathptr->printall();
			}

			*/

			memb->printall();
			return ;
		}



	}

	cout << "Δεν βρέθηκε εγγεγραμένο μέλος του τμήματος με ΑΜ " << id << endl;
}


void Foititologio::search_mathima(const char * id){

	for(auto math : mathimata){

		if(strcmp(math->get_id()  , id) == 0 ) //αν βρω ιδιο μαθημα με τον κωδικο της παραμετρου
		{
			cout << "Βρέθηκε μάθημα του τμήματος με κωδικό " << id << endl;
			math->printall();
			return ;

		}

	}

	cout << " Δεν βρέθηκε μάθημα με τον κωδικό " << id << endl;
}


void Foititologio::correct_onep(const string& idsearch, const string& nonep){

	for (auto memb: eggegramenoi){

			if(strcmp(memb->get_id(),idsearch.c_str() ) == 0 ) //δηλαδη, αν βρω ιδιο μελος  με τον ιδιο ΑΜ
				{
				cout << "Βρέθηκε μέλος του τμήματος με ΑΜ " << idsearch << endl;
				cout << "Τρέχον ονοματεπώνυμο: " << memb->get_onep() << endl;

				memb->set_onep(nonep);
				cout << "Νέο ονοματεπώνυμο: " << memb->get_onep() << endl;
				return;
			}



		}

		cout << "Δεν βρέθηκε εγγεγραμένο μέλος του τμήματος με ΑΜ " << idsearch << endl;



}

void Foititologio::correct_id(const string& idsearch, const string& neoid){

	for (auto memb: eggegramenoi){

			if(strcmp(memb->get_id(),idsearch.c_str() ) == 0 ) //δηλαδη, αν βρω ιδιο μελος  με τον ιδιο ΑΜ
				{
				cout << "Βρέθηκε μέλος του τμήματος με ΑΜ " << idsearch << endl;


				memb->set_id(neoid.c_str());
				cout << "Νέο ΑΜ: " << memb->get_id() << endl;
				return;
			}



		}

		cout << "Δεν βρέθηκε εγγεγραμένο μέλος του τμήματος με ΑΜ " << idsearch << endl;




}

void Foititologio::correct_fylo(const string& idsearch){


	for (auto memb: eggegramenoi){

			if(strcmp(memb->get_id(),idsearch.c_str() ) == 0 ) //δηλαδη, αν βρω ιδιο μελος  με τον ιδιο ΑΜ
				{
				cout << "Βρέθηκε μέλος του τμήματος με ΑΜ " << idsearch << endl;
				if(memb->get_fylo() == 0) {memb->set_fylo(1);}
				else {memb->set_fylo(0);}
				cout << "Αλλαγή φύλου επιτυχής" <<endl;
				return;
			    }



		}

		cout << "Δεν βρέθηκε εγγεγραμένο μέλος του τμήματος με ΑΜ " << idsearch << endl;





}





void Foititologio::correct_eksamino(const string& idsearch, unsigned int neoeks){
	for (auto memb: eggegramenoi){
		if(strcmp(memb->get_id(), idsearch.c_str() ) == 0){
			cout << "Βρέθηκε μέλος του τμήματος με ΑΜ " << idsearch << endl;
			Foititis* foitptr = dynamic_cast<Foititis*>(memb); //εδω κανω dynamic cast με τελικο σκοπο να δω αν το μελος ειναι φοιτητης η καθηγητης. Αν ειναι φοιτητης, αλλαζω εξαμηνο
			if(foitptr !=  nullptr){
				cout << "Επιτυχής αλλαγή του εξαμήνου από " << foitptr->get_eksamino() << "ο εξάμηνο σε " << neoeks << "ο εξάμηνο" << endl;
				foitptr->set_eksamino(neoeks);
			}
			else{
				cout << "Ωστόσο, το εγγεγραμένο μέλος με το συγκεκριμένο ΑΜ είναι καθητητής." << endl;
			}

		return ;


	    }

    }
			cout << "Δεν βρέθηκε εγγεγραμένο μέλος του τμήματος με τον AM " << idsearch << endl;
    

}




void Foititologio::correct_specialty(const string& idsearch, string neospec){

	for (auto memb: eggegramenoi){
		if(strcmp(memb->get_id(), idsearch.c_str()) == 0){
			cout << "Βρέθηκε μέλος του τμήματος με ΑΜ " << idsearch << endl;
			Kathigitis* kathptr = dynamic_cast<Kathigitis*>(memb);//εδω κανω dynamic cast με τελικο σκοπο να δω αν το μελος ειναι φοιτητης η καθηγητης. Αν ειναι καθηγητης, αλλαζω ειδικοτητα
			if(kathptr !=  nullptr){
				cout << "Επιτυχής αλλαγή ειδικότητας σε " <<  neospec << endl;
				kathptr->set_specialty(neospec);
			}
			else{
				cout << "Ωστόσο, το εγγεγραμένο μέλος με το συγκεκριμένο ΑΜ είναι φοιτητής." << endl;
			}



			return; //εφόσον βρήκε το id είτε είναι καθηγητής είτε όχι, να επιστρέφει και να μην συνεχίζει ο βρόγχος παραπάνω
		}

	}

	cout << "Δεν βρέθηκε εγγεγραμένο μέλος του τμήματος με τον AM " << idsearch << endl;
		
}


void Foititologio::email_kathigites(string email){
	int count=0;
	cout << "Μύνημα που αποστάλθηκε: " << email << endl;

	for (auto* memb: eggegramenoi){
		Kathigitis* kathptr = dynamic_cast<Kathigitis*>(memb);
		if(kathptr != nullptr){
			cout << "Αποστολή στον/ην κύριο/α " << kathptr->get_onep() << " με ΑΜ " << kathptr->get_id() << endl;
 			count++;
		}
	}
	cout << "Αποστάλθηκαν μυνήματα σε " << count << " χρήστες." << endl;



}


void Foititologio::email_foitites(string email){
	int count=0;
	cout << "Μύνημα που αποστάλθηκε: " << email << endl;

	for (auto* memb: eggegramenoi){
		Foititis* foitptr = dynamic_cast<Foititis*>(memb);
		if(foitptr != nullptr){
			cout << "Αποστολή στον/ην κύριο/α " << foitptr->get_onep() << " με ΑΜ " << foitptr->get_id() << endl;
 			count++;
		}
	}
	cout << "Αποστάλθηκαν μυνήματα σε " << count << " χρήστες." << endl;



}


void Foititologio::output_foitites_to_csv(const string& filename){

	int count=0;

	ofstream csvfile(filename);

	if (!csvfile.is_open() ) { cout << "Σφάλμα δημιουργίας αρχείου" << endl; return;}

	csvfile << "ΑΜ;Ονοματεπώνυμο;Φύλο;Εξάμηνο\n";

	for(const auto& foit:eggegramenoi){
	Foititis* foitptr = dynamic_cast<Foititis*>(foit);
	if(foitptr!=nullptr){
		csvfile << foitptr->get_id() << ";" << foitptr->get_onep() << ";" << foitptr->get_fylo() << ";"  << foitptr->get_eksamino() << "\n" ;
		++count;
		}
	}

	csvfile.close();

	cout << "Επιτυχής εξαγωγή στοιχείων " << count << " φοιτητών στο αρχείο " << filename  << endl;


}

void Foititologio::output_kathigites_to_csv(const string& filename){

	int count=0;

	ofstream csvfile(filename);

	if (!csvfile.is_open() ) { cout << "Σφάλμα δημιουργίας αρχείου" << endl; return;}

	csvfile << "ΑΜ;Ονοματεπώνυμο;Φύλο;Ειδικότητα\n";

	for(const auto& kath:eggegramenoi){
	Kathigitis* kathptr = dynamic_cast<Kathigitis*>(kath);
	if(kathptr!=nullptr){
		csvfile << kathptr->get_id() << ";" <<  kathptr->get_onep() << ";" <<  kathptr->get_fylo() << ";" <<  kathptr->get_specialty() << "\n";
		++count;


		}
	}

	csvfile.close();

	cout << "Επιτυχής εξαγωγή στοιχείων " << count << " καθηγητών στο αρχείο " << filename  << endl;


}


void Foititologio::output_mathimata_to_csv(const string& filename){

	int count=0;

	ofstream csvfile(filename);

	if (!csvfile.is_open() ) { cout << "Σφάλμα δημιουργίας αρχείου" << endl; return;}

	csvfile << "Κωδικός;Περιγραφή;Εξάμηνο;\n";

	for(const auto& math:mathimata){
	//Mathima* subjptr = dynamic_cast<Mathima*>(math);

		csvfile << math->get_id() << ";" <<  math->get_desc() << ";" <<  math->get_sem() << ";"/* <<  mathptr->get_prof() */<< "\n";
		++count;



	}

	csvfile.close();

	cout << "Επιτυχής εξαγωγή στοιχείων " << count << " μαθημάτων στο αρχείο " << filename  << endl;


}

void Foititologio::import_foitites_from_csv(const string& filename){

	string l; //γραμμή που διαβάζεται
	string am,onep,fylo,eksamino; //αρχικοποίηση ιδιωτήτων για να τις περάσουμε στο φοιτητολόγιο
	int count=0;

	ifstream file(filename);
	if(!file.is_open()) { cout << "Σφάλμα εισαγωγής: Δεν βρέθηκε το αρχείο "<< filename <<endl; return; } 

	getline(file,l); //θα πάρω την πρώτη γραμμή και δεν την αποθηκεύω κάπου

	while(getline(file,l)){
		if(l.empty()) continue; //προσπέραση τυχών κενής γραμμής
		stringstream ss(l); //μετατροπής γραμμής σε stringstream

		//κόλπο με getline: σπάμε κάθε γραμμή σε 4 κομμάτια
		getline(ss, am, ';');
		getline(ss, onep, ';');
		getline(ss, fylo, ';');
		getline(ss, eksamino, ';');

		//κατάλληλες μετατροπές
		//υλοποίηση try-catch
		try{

			int intfylo = stoi(fylo);
			int inteksamino = stoi(eksamino);
			const char * c_str_am = am.c_str();

			//εισαγωγή
			eggegramenoi.push_back(new Foititis(c_str_am, onep, intfylo, inteksamino));
			++count;


		}
		catch(const invalid_argument& e){
			cout << "Σφάλμα δεδομένων για τον ΑΜ: " << am << endl;
		} catch (const out_of_range& e){
			cout << "Υπερβολικά μεγάλος αριθμός του ΑΜ: " << am << endl;
		}




	}
	file.close();
	cout << "Επιτυχής ανάγνωση. Συνολικά φορτώθηκαν " << count << " φοιτητές από το αρχείο " <<filename << endl;

}

void Foititologio::import_kathigites_from_csv(const string& filename){

	string l; //γραμμή που διαβάζεται
	string am,onep,fylo,specialty; //αρχικοποίηση ιδιωτήτων για να τις περάσουμε στο φοιτητολόγιο
	int count=0;

	ifstream file(filename);
	if(!file.is_open()) { cout << "Σφάλμα εισαγωγής: Δεν βρέθηκε το αρχείο "<< filename <<endl; return; } 

	getline(file,l); //θα πάρω την πρώτη γραμμή και δεν την αποθηκεύω κάπου

	while(getline(file,l)){
		if(l.empty()) continue; //προσπέραση τυχών κενής γραμμής
		stringstream ss(l); //μετατροπής γραμμής σε stringstream

		//κόλπο με getline: σπάμε κάθε γραμμή σε 4 κομμάτια
		getline(ss, am, ';');
		getline(ss, onep, ';');
		getline(ss, fylo, ';');
		getline(ss, specialty, ';');

		//κατάλληλες μετατροπές
		//υλοποίηση try catch

		try{
			int intfylo = stoi(fylo);
			const char * c_str_am = am.c_str();

			//εισαγωγή
			eggegramenoi.push_back(new Kathigitis(c_str_am, onep, intfylo, specialty));
			++count;

        }

        
		catch(const invalid_argument& e){
			cout << "Σφάλμα δεδομένων για τον ΑΜ: " << am << endl;
		} catch (const out_of_range& e){
			cout << "Υπερβολικά μεγάλος αριθμός του ΑΜ: " << am << endl;
		}

        

	}
	file.close();
	cout << "Επιτυχής ανάγνωση. Συνολικά φορτώθηκαν " << count << " καθηγητές από το αρχείο " <<filename << endl;




}


void Foititologio::import_mathimata_from_csv(const string& filename){

	string l; //γραμμή που διαβάζεται
	string id,description,semester/*,professor*/; //αρχικοποίηση ιδιoτήτων για να τις περάσουμε στο φοιτητολόγιο
	int count=0;

	ifstream file(filename);
	if(!file.is_open()) { cout << "Σφάλμα εισαγωγής: Δεν βρέθηκε το αρχείο "<< filename <<endl; return; } 

	getline(file,l); //θα πάρω την πρώτη γραμμή και δεν την αποθηκεύω κάπου

	while(getline(file,l)){
		if(l.empty()) continue; //προσπέραση τυχών κενής γραμμής
		stringstream ss(l); //μετατροπής γραμμής σε stringstream

		//κόλπο με getline: σπάμε κάθε γραμμή σε 4 κομμάτια
		getline(ss, id, ';');
		getline(ss, description, ';');
		getline(ss, semester, ';');
		//getline(ss, professor, ';');

		//κατάλληλες μετατροπές

		try{
			int intsemester = stoi(semester);
			const char * c_str_id = id.c_str();

			//εισαγωγή
			mathimata.push_back(new Mathima(c_str_id, description, intsemester/*,professor*/));
			++count;

        
		}
		catch(const invalid_argument& e){
			cout << "Σφάλμα δεδομένων για τον ID: " << id << endl;
		} catch (const out_of_range& e){
			cout << "Υπερβολικά μεγάλος αριθμός του ID: " << id << endl;
		}

        


	}
	file.close();
	cout << "Επιτυχής ανάγνωση. Συνολικά φορτώθηκαν " << count << " μαθήματα από το αρχείο " <<filename << endl;


}


Foititologio::~Foititologio(){

	for (auto* memb : eggegramenoi){delete memb;}
	for (auto* math : mathimata){delete math;}

}
