#include "ergasia3.h"


int main(){

	//demonstration της κλάσης Foititis (Φοιτητής) για την εργασία 2

   	 //κλάση φοιτητής

	cout << "Επίδειξη λειτουργιών της κλάσεως φοιτητής" << endl;

	Foititis** Assignment = new Foititis*[5]; //εργασία που θα ανατεθεί σε 5  φοιτητές. Διπλό pointer επειδή θα δεχτεί 5 pointers σε κλάση Foititis
	Assignment[0]=new Foititis("1312","Χρήστος Κουραμπάς",0,2);
	Assignment[1]=new Foititis("24","Μπρούνο Άλικο",0,2);
	Assignment[2]=new Foititis("2438","Παναγιώτης Αμπάβης",0,14); //αιώνιος φοιτητής
	Assignment[3]=new Foititis("7","Σοφία Κοφσανίδου"); //Δεν έβαλα φύλο ή εξάμηνο
	Assignment[4]=new Foititis("666","Μιχάλης Κατζουράκης ",0,4);

	Foititis* foitNoParams = new Foititis; //Καμία παράμετρος
	Foititis* foit2Params  = new Foititis("77","Γιώργος Κινεβυζίδης"); //δύο παράμετροι
	Foititis* foitAllParams =   new Foititis("12", "Ανδρέας Λαγουδάκος", 0, 2); //όλοι οι παράμετροι

	Foititis* copy   = new Foititis(*foitAllParams); //copy constructor


	cout << "χρήση διάφορων συναρτήσεων της κλάσης φοιτητής " << endl;

	Assignment[3]->printall(); //εκτυπώνει τα χαρακτηριστικά

	*Assignment[2]+=2; //αύξηση κατά δύο εξάμηνα

	-*Assignment[4]; //Αλλαγή φύλου σε γυναίκα

	*Assignment[1]-=(3); //δεν θα λειτουργήσει

	*Assignment[1]++; //Αύξηση εξαμήνων κατά 1



	delete[] Assignment; //διαγραφή του πίνακα


	//το περιεχόμενο από εδώ περιέχει προσθήκες από την εργασία 3
	Foititis* foit1 = new Foititis("7", "Ιωρδάνης Μαμωνάς",0, 4);


	cout << " setters & getters" << endl;


       //επείδειξη συναρτήσεων getter & setter
	cout << "Ονοματεπώνυμο του foit1 " << foit1->get_onep() << endl;
	cout << "Φύλο του foit1 " << foit1->get_fylo() <<endl;
	cout << "ΑΜ του foit1 " << foit1->get_id() << endl;
	cout << "Εξάμηνο του foit1 " << foit1->get_eksamino() << endl;

	Foititis* foit2  = new Foititis(); //κενός constructor
	foit2->set_id("4000");
	foit2->set_eksamino(6);
	foit2->set_onep("Παναγιώτης Αμπάβης");
	foit2->set_fylo(0);

	cout << " εκτύπωση χαρακτηριστικών" << endl;
	foit1->printall();



	//Κλάση καθηγητής

	cout << "Επείδειξη της κλάσεως καθηγητής" << endl;

	Kathigitis* kath1 = new Kathigitis(); //κενός constructor!
	Kathigitis* kath2 = new Kathigitis("60", "Αλέξανδρος Χατζησταματίου",0,"Κατανεμημένα Συστήματα"); // πλήρης constructor

	cout << "setters & getters" << endl;

	//επείδειξη μερικών συναρτήσεων getter και setter
	cout << "id του kath2: "<<kath2->get_id()<<endl; //θα εμφανίσει -1 επειδή δεν το ορίσαμε στον constructor!
	cout << "Ονοματεπώνυμο του kath2 " << kath2->get_onep() << endl;
	cout << "Φύλο του kath2 " << kath2->get_fylo() << endl;
	cout << "Ειδικότητα του kath2 " << kath2->get_specialty() << endl;

	kath1->set_onep("Σοφία Κοφσανίδου");
	kath1->set_id("540");
	kath1->set_specialty("Υλικό Η/Υ");
	kath1->set_fylo(1); //Ήταν από προεπιλογή 1, επανάληψη για σκοπούς παρουσίασης της συνάρτησης

	cout <<  "εκτύπωση στοιχείων καθηγητών" << endl;

	//εκτύπωση στοιχείων
	kath1->printall();
	kath2->printall();

	//constructors
	Kathigitis* kathNoParams= new Kathigitis(); //καμία παράμετρος
	Kathigitis* kath2Params= new Kathigitis("4333","Αλέξανδρος Χατζησταματίου"); //δύο παράμετροι
	Kathigitis* kathAllParams = new Kathigitis("5646", "Βασίλης Κωτσαδάμ",0,"Υλικό Η/Υ"); //τέσσερεις παράμετροι
	Kathigitis* kathCopy = new Kathigitis(*kathNoParams); //copy constructor

	//κλάση μάθημα

	cout << "Επείδειξη κλάσης μαθήματος" << endl;

	//αρχικοποίηση μέσω constructor
	Mathima* networks = new Mathima("5",5);
	Mathima* discrete  = new Mathima("2","Διακριτά Μαθηματικά", 1, kath2);
	Mathima* physics = new Mathima("3",1);
	Mathima* circuits = new Mathima("4",2);

	cout << "getters & setters" << endl;

	//επίδειξη μερικών συναρτήσεων getter & setter
	networks->set_desc("Δίκτυα Η/Υ");
	networks->set_sem(3);
	networks->set_prof(kath2);
	networks->set_id("1");

	//παρατηρούμε ότι άλλαξε και η λίστα μαθημάτων του καθηγητή

	
	cout << "Παρατηρούμε ότι άλλαηξε η λίστα μαθημάτων του καθηγητή με τη χρήση του set_prof της κλάσης Mathima" << endl;
	kath2->print_mathimata();

	cout << "getters κλάσης μαθήματος" << endl;

	cout << "περιγραφή του μαθήματος discrete: " << discrete->get_desc();
	cout << "id μαθήματος διακριτών: " << discrete->get_id() <<endl;
	cout << "Καθηγητής διακριτών: "<< discrete->get_prof() << endl;
	cout << "Εξάμηνο διδασκαλείας: " << discrete->get_sem() << endl;


	circuits->set_desc("Θεωρία Κυκλωμάτων");
	physics->set_desc("Φυσική");

	cout << "εκτύπωση χαρακτηριστικών μαθημάτων" << endl;

	networks->printall();
	discrete->printall();

	//constructors
	Mathima* subjNoParams = new Mathima(); //καμία παράμετρος
	Mathima* subj2Params = new Mathima("54",9); //δύο παράμετροι
	Mathima* subjAllParams = new Mathima("74","Πιθανότητες και Στατιστική", 2, kath2Params); //τέσσερεις παράμετροι
	Mathima* subjCopy = new Mathima(*subj2Params); //copy constructor

	cout << "προσθήκη μαθημάτων στον φοιτητή και εκτύπωση λίστας μαθημάτων φοιτητή" << endl;

	//προσθήκη μαθήματος στην δήλωση φοιτητή
	foit1->add_mathima(*discrete);
	foit1->add_mathima(*circuits);
	foit1->print_mathimata();

	cout << "ομοίως προσθήκη και εκτύπωση μαθημάτων σε καθηγητή" << endl;

	//προσθήκη μαθήματος σε καθηγητή
	kath1->add_mathima(*circuits);
	circuits->set_prof(kath1);
	kath1->print_mathimata();

	//παρατηρούμε ότι άλλαξε και το μάθημα στην παράμετρο Καθηγητής
	cout << circuits->get_prof() << endl;



	cout << "Επίδειξη κλάσης φοιτητολογίου" << endl;


	//αρχικοποίηση φοιτητολογίου
	Foititologio ice;

	//δημιουργία περισσότερων φοιτητών

	Foititis* foit3=new Foititis("435", "Μπροφγφύνο Αλίκο", 0,4); //λάθος όνομα. Θα διορθωθεί μέσω συνάρτησης
	Foititis* foit4=new Foititis("5646","Δήμητρα Δελιπορανίδη",0,8); //φύλο άνδρας εκ παραδρομής. Θα διορθωθεί μέσω συνάρτησης

	//προσθήκη φοιτητών και καθηγητών
	ice.add_eggegrameno(foit1); //περνάμε την διεύθυνση (&) επειδή η συνάρτηση δέχεται δείκτη!
	ice.add_eggegrameno(foit2);
	ice.add_eggegrameno(foit3);
	ice.add_eggegrameno(foit4);
	ice.add_eggegrameno(kath1);
	ice.add_eggegrameno(kath2);

	//προσθήκη μαθημάτων
	ice.add_mathima(networks);
	ice.add_mathima(discrete);
	ice.add_mathima(circuits);
	ice.add_mathima(physics);

	cout << "συναρτήσεις αναζήτησης " << endl;

	//συναρτήσεις αναζήτησης
	ice.search_eggegrameno("435");
	ice.search_mathima("2");


	cout << " συναρτήσεις εκτύπωσης" << endl;
	//συναρτήσεις εκτύπωσης
	ice.print_eggegramenoi();
	ice.print_mathimata();

	//συναρτήσεις διόρθωσης
	ice.correct_onep("435", "Μπρούνο Αλίκο");
	ice.correct_fylo("5646");
	ice.correct_id("540", "530");
	ice.correct_eksamino("4000",7);
	ice.correct_specialty("60","Μαθηματικά");



	cout << "αποστολή email σε φοιτητηές και καθηγητές ξεχωριστά " << endl;


	//συναρτήσεις αποστολής email
	ice.email_foitites("Υποδειγματικό μήνυμα σε φοιτητές");
	ice.email_kathigites("Υποδειγματικό μήνυμα σε καθηγητές");

	cout << " εξαγωγή σε αρχείο" << endl;

	//εξαγωγή σε αρχείο
	ice.output_foitites_to_csv("Φοιτητές_εξαγωγή.csv");
	ice.output_kathigites_to_csv("Καθηγητές_εξαγωγή.csv");
	ice.output_mathimata_to_csv("Μαθήματα_εξαγωγή.csv");

	cout << "εισαγωγή σε αρχείο " << endl;

	//εισαγωγή σε αρχείο
	Foititologio icecopy;

	icecopy.import_foitites_from_csv("Φοιτητές_εξαγωγή.csv");
	icecopy.import_kathigites_from_csv("Καθηγητές_εξαγωγή.csv");
	icecopy.import_mathimata_from_csv("Μαθήματα_εξαγωγή.csv");

	cout << "Συναρτήσεις διαγραφής" << endl;

	//συναρτήσεις διαγραφής
	icecopy.delete_mathima("3");
	icecopy.delete_eggegrameno("5646");

	cout << "\nΕπιτυχής εκτέλεση όλων των συναρτήσεων, constructor, destructor, setter, getter κλπ. του συνόλου των κλάσεων. \n" << endl;

	return 0;
}
