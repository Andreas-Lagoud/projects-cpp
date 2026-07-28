#include "ergasiaex.h"


//συνάρτηση εισόδου από τον χρήστη
string inputuser(WINDOW* w, int y, int x, string pr){
    //wclear(w);
    //box(w,0,0);
    mvwprintw(w,y,x,"%s",pr.c_str());
    wrefresh(w);

    echo(); //εισαγωγή από πληκτρολόγιο
    curs_set(1); //ορατός κέρσορας

    char inp[100];
    wgetstr(w,inp); //βούτα το buffer

    noecho(); //μην διαβάζεις άλλο
    curs_set(0); //αόρατος κέρσορας

    return string(inp);

}




void gotoviewegg(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"|=ΕΓΓΕΓΡΑΜΕΝΟΙ ΣΤΟ ΤΜΗΜΑ=|");

		f.print_eggegramenoi(w);

		mvwprintw(w,32,2, "Πατήστε οποιοδήποτε κουμπί για επιστροφή");
		wrefresh(w);
		wgetch(w);

}
		
void gotoviewmath(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"|=ΚΑΤΑΛΟΓΟΣ ΜΑΘΗΜΑΤΩΝ=|");

		f.print_mathimata(w);

		mvwprintw(w,32,2, "Πατήστε οποιοδήποτε κουμπί για επιστροφή");
		wrefresh(w);
		wgetch(w);


}

void gotosearchegg(WINDOW* w, Foititologio& f){
	wclear(w);
	box(w,0,0);
	mvwprintw(w,1,2,"ΑΝΑΖΗΤΗΣΗ ΕΓΓΕΓΡΑΜΕΝΩΝ");
	
	wrefresh(w);

	string inp =inputuser(w,3,2,"Εισαγωγή ΑΜ: ");

	f.search_eggegrameno(w,inp.c_str());

	mvwprintw(w,32,2, "Πατήστε οποιοδήποτε κουμπί για επιστροφή");
	wrefresh(w);
	wgetch(w);

}

void gotosearchmath(WINDOW* w, Foititologio& f){
	wclear(w);
	box(w,0,0);
	mvwprintw(w,1,2,"ΑΝΑΖΗΤΗΣΗ ΜΑΘΗΜΑΤΩΝ");
	
	wrefresh(w);

	string inp =inputuser(w,3,2,"Εισαγωγή κωδικού μαθήματος: ");

	f.search_mathima(w,inp.c_str());

	mvwprintw(w,32,2, "Πατήστε οποιοδήποτε κουμπί για επιστροφή");
	wrefresh(w);
	wgetch(w);

}

void gotoaddfoit(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΠΡΟΣΘΗΚΗ ΦΟΙΤΗΤΗ");

		wrefresh(w);

		string tempid;
		string tempname;
		int tempfylo;
		int tempeks;

		tempid = inputuser(w,3,2,"Εισαγωγή ΑΜ: ");
		tempname = inputuser(w,4,2,"Εισαγωγή Ονοματεπύνωμου: ");
		tempfylo = stoi(  inputuser(w,5,2,"Εισαγωγή Φύλου, 0 = Άνδρας | 1 = Γυναίκα: ")  ); //η inputuser πρέπει να επιστρέψει string. Η μόνη λύση είναι το stoi
		tempeks = stoi(inputuser(w,6,2,"Εισαγωγή εξαμήνου: ")  );

		Foititis* foitemp = new Foititis(tempid.c_str(),tempname,tempfylo, tempeks);
		f.add_eggegrameno(foitemp);

		mvwprintw(w,8,2,"Επιτυχής προσθήκη. Πατήστε οποιοδήποτε πλήκτρο για επιστροφή.");
		wrefresh(w);
		wgetch(w);

}

void gotoaddkath(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΠΡΟΣΘΗΚΗ ΚΑΘΗΓΗΤΗ");

		wrefresh(w);

		string tempid;
		string tempname;
		int tempfylo;
		string tempspe;

		tempid = inputuser(w,3,2,"Εισαγωγή ΑΜ: ");
		tempname = inputuser(w,4,2,"Εισαγωγή Ονοματεπύνωμου: ");
		tempfylo = stoi(  inputuser(w,5,2,"Εισαγωγή Φύλου, 0 = Άνδρας | 1 = Γυναίκα: ")  ); //η inputuser πρέπει να επιστρέψει string. Η μόνη λύση είναι το stoi
		tempspe = inputuser(w,6,2,"Εισαγωγή Ειδικότητας: ")  ;

		Kathigitis* kathtemp = new Kathigitis(tempid.c_str(),tempname,tempfylo,tempspe);
		f.add_eggegrameno(kathtemp);

		mvwprintw(w,8,2,"Επιτυχής προσθήκη. Πατήστε οποιοδήποτε πλήκτρο για επιστροφή.");
		wrefresh(w);
		wgetch(w);


}

void gotoaddmath(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΠΡΟΣΘΗΚΗ ΜΑΘΗΜΑΤΟΣ");

		wrefresh(w);

		string tempid;
		string tempname; //ενναλακτικά tempdesc
		int tempeks=-1;
		string tempamkath;
		tempid = inputuser(w,3,2,"Εισαγωγή Κωδικού: ");
		tempname = inputuser(w,4,2,"Εισαγωγή Ονόματος/Περιγραφή: ");

		while(tempeks <1 || tempeks>10){
			tempeks = stoi(inputuser(w,5,2,"Εισαγωγή εξαμήνου (1ο έως 10ο εξάμηνο): ")  ); //η inputuser πρέπει να επιστρέψει string. Η μόνη λύση είναι το stoi
		}

		tempamkath = inputuser(w,6,2,"Εισαγωγή ΑΜ καθηγητή: ");

		Kathigitis* tempkath = f.getkath(tempamkath); //πάω να βρω τον καθηγητή που αναφέρεται
			
	
		Mathima* mathtemp = new Mathima(tempid.c_str(),tempname, tempeks,tempkath); //είτε ο καθηγητής βρέθηκε είτε όχι (nullptr), φτιάχνουμε το μάθημα 
		f.add_mathima(mathtemp);

		mvwprintw(w,8,2,"Επιτυχής προσθήκη. Πατήστε οποιοδήποτε πλήκτρο για επιστροφή.");
		wrefresh(w);
		wgetch(w);



}

void dioam(WINDOW* w, Foititologio& f ){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΔΙΟΡΘΩΣΗ ΑΜ");

		wrefresh(w);



		string tempid = inputuser(w,3,2,"Εισαγωγή ΑΜ προς αναζήτηση: ");
		string changeto = inputuser(w,4,2,"Να αλλάξει στον ΑΜ: ");

		f.correct_id(w,tempid,changeto);


		wrefresh(w);
		wgetch(w);

}

void dioonep(WINDOW* w, Foititologio& f ){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΔΙΟΡΘΩΣΗ ΟΝΟΜΑΤΕΠΩΝΥΜΟΥ");

		wrefresh(w);

		string tempid = inputuser(w,3,2,"Εισαγωγή ΑΜ προς αναζήτηση: ");
		string changeto = inputuser(w,4,2,"Να αλλάξει στο ονοματεπώνυμο: ");

		f.correct_onep(w,tempid,changeto);

		wrefresh(w);
		wgetch(w);

}

void diofy(WINDOW* w,Foititologio& f){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΔΙΟΡΘΩΣΗ ΦΥΛΟΥ");

		wrefresh(w);

		string tempid = inputuser(w,3,2,"Εισαγωγή ΑΜ προς αναζήτηση: ");
		

		f.correct_fylo(w,tempid);

		wrefresh(w);
		wgetch(w);




}


void dioeks(WINDOW* w, Foititologio& f){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΔΙΟΡΘΩΣΗ ΕΞΑΜΗΝΟΥ");

		wrefresh(w);

		string tempid = inputuser(w,3,2,"Εισαγωγή ΑΜ προς αναζήτηση: ");
		unsigned int tempeks = stoi(inputuser(w,4,2,"Αλλαγή εξαμήνου σε: ")  );
		

		f.correct_eksamino(w,tempid,tempeks);

		wrefresh(w);
		wgetch(w);
}

void diospe(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΔΙΟΡΘΩΣΗ ΕΙΔΙΚΟΤΗΤΑΣ");

		wrefresh(w);

		string tempid = inputuser(w,3,2,"Εισαγωγή ΑΜ προς αναζήτηση: ");
		string tempspe = inputuser(w,4,2,"Αλλαγή ειδικότητας σε: ")  ;
		

		f.correct_specialty(w,tempid,tempspe);

		wrefresh(w);
		wgetch(w);	
	
}

void gotoeditegg(WINDOW* w, Foititologio& f){

		bool active=true;
		int high=0;
		int i;
		int chc=-1;

		vector<string> epilog{"Διόρθωση ΑΜ","Διόρθωση Ονοματεπωνύμου","Διόρθωση Φύλου","Διόρθωση Εξαμήνου Φοιτητή","Διόρθωση Ειδικότητας Καθηγητή" ,"Επιστροφή"};
		while(active){
			wclear(w);
			box(w,0,0);
			mvwprintw(w,1,2,"|=ΔΙΟΡΘΩΣΗ ΣΤΟΙΧΕΙΩΝ|");

			for(i=0;i <epilog.size() ; i++){
				if(i==high){wattron(w,A_REVERSE);}

				mvwprintw(w, 4+i, 2, "%s", epilog[i].c_str());
				wattroff(w,A_REVERSE);


			}

			wrefresh(w);
			chc = wgetch(w);

			switch(chc){

				case KEY_UP :
					high--;
					if(high<0){high = epilog.size() - 1;}
					break;
				case KEY_DOWN:
					high++;
					if(high >= epilog.size()){high =0;}
					break;
				case 10 : //enter
					switch(high){
						case 0:
							dioam(w,f);
							break;
						case 1:
							dioonep(w,f);
							break;
						case 2:
							diofy(w,f);
							break;
						case 3:
							dioeks(w,f);
							break; 		
						case 4: 
							diospe(w,f);
							break;
					
						case 5:
							active=false;
							break;

					}
					break;


		
			}


		}



}


void gotodelegg(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΔΙΑΓΡΑΦΗ ΕΓΓΕΓΡΑΜΕΝΟΥ ΜΕΛΟΥΣ");

		wrefresh(w);

		string tempid;

		tempid = inputuser(w,3,2,"Εισαγωγή ΑΜ: ");

		
		f.delete_eggegrameno(w,tempid.c_str());
		wrefresh(w);
		wgetch(w);

}

void gotodelmath(WINDOW* w, Foititologio &f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΔΙΑΓΡΑΦΗ ΜΑΘΗΜΑΤΟΣ");

		wrefresh(w);

		string tempid;

		tempid = inputuser(w,3,2,"Εισαγωγή κωδικού: ");

		
		f.delete_mathima(w,tempid.c_str());
		wrefresh(w);
		wgetch(w);

}

void gotoemailfoit(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΑΠΟΣΤΟΛΗ EMAIL ΣΤΟΥΣ ΦΟΙΤΗΤΕΣ");

		wrefresh(w);

		string tempem;

		tempem = inputuser(w,3,2,"Μήνυμα: ");

		
		f.email_foitites(w,tempem);
		wrefresh(w);
		wgetch(w);

}

void gotoemailkath(WINDOW* w, Foititologio& f){
		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"ΑΠΟΣΤΟΛΗ EMAIL ΣΤΟΥΣ ΚΑΘΗΓΗΤΕΣ");

		wrefresh(w);

		string tempem;

		tempem = inputuser(w,3,2,"Μήνυμα: ");

		
		f.email_kathigites(w,tempem);
		wrefresh(w);
		wgetch(w);

}


void gotoedit(WINDOW* w, Foititologio& f){

		bool active=true;
		int high=0;
		int i;
		int chc=-1;

		vector<string> epilog{"Προσθήκη Φοιτητή", "Προσθήκη Καθηγητή","Διόρθωση Εγγεγραμένου","Διαγραφή Εγγεγραμένου", "Επιστροφή"};
		while(active){
			wclear(w);
			box(w,0,0);
			mvwprintw(w,1,2,"|=ΕΠΕΞΕΡΓΑΣΙΑ ΕΓΓΕΓΡΑΜΕΝΩΝ-|");

			for(i=0;i <epilog.size() ; i++){
				if(i==high){wattron(w,A_REVERSE);}

				mvwprintw(w, 4+i, 2, "%s", epilog[i].c_str());
				wattroff(w,A_REVERSE);


			}

			wrefresh(w);
			chc = wgetch(w);

			switch(chc){

				case KEY_UP :
					high--;
					if(high<0){high = epilog.size() - 1;}
					break;
				case KEY_DOWN:
					high++;
					if(high >= epilog.size()){high =0;}
					break;
				case 10 : //enter
					switch(high){
						case 0:
							gotoaddfoit(w,f);
							break;
						case 1:
							gotoaddkath(w,f);
							break;
						case 2:
							gotoeditegg(w,f);
							break;
						case 3:
							gotodelegg(w,f);
							break; 		
						case 4: 
							active=false;
							break;
					
					
					}
					break;


		
			}


		}


}


void gotoeditmath(WINDOW* w, Foititologio& f){

		bool active=true;
		int high=0;
		int i;
		int chc=-1;

		vector<string> epilog{"Προσθήκη Μαθήματος","Διαγραφή Μαθήματος" ,"Επιστροφή"};
		while(active){
			wclear(w);
			box(w,0,0);
			mvwprintw(w,1,2,"|=ΕΠΕΞΕΡΓΑΣΙΑ ΜΑΘΗΜΑΤΩΝ-|");

			for(i=0;i <epilog.size() ; i++){
				if(i==high){wattron(w,A_REVERSE);}

				mvwprintw(w, 4+i, 2, "%s", epilog[i].c_str());
				wattroff(w,A_REVERSE);


			}

			wrefresh(w);
			chc = wgetch(w);

			switch(chc){

				case KEY_UP :
					high--;
					if(high<0){high = epilog.size() - 1;}
					break;
				case KEY_DOWN:
					high++;
					if(high >= epilog.size()){high =0;}
					break;
				case 10 : //enter
					switch(high){
						case 0:
							gotoaddmath(w,f);
							break;
						case 1:
							gotodelmath(w,f);
							break;
							
						case 2: 
							active=false;
							break;
					
					
					}
					break;


		
			}


		}


}



void gotoemail(WINDOW* w, Foititologio& f){

		bool active=true;
		int high=0;
		int i;
		int chc=-1;

		vector<string> epilog{"Φοιτητές","Καθηγητές","Επιστροφή"};
		while(active){
			wclear(w);
			box(w,0,0);
			mvwprintw(w,1,2,"Αποστολή email σε όλους τους:");

			for(i=0;i <epilog.size() ; i++){
				if(i==high){wattron(w,A_REVERSE);}

				mvwprintw(w, 4+i, 2, "%s", epilog[i].c_str());
				wattroff(w,A_REVERSE);


			}

			wrefresh(w);
			chc = wgetch(w);

			switch(chc){

				case KEY_UP :
					high--;
					if(high<0){high = epilog.size() - 1;}
					break;
				case KEY_DOWN:
					high++;
					if(high >= epilog.size()){high =0;}
					break;
				case 10 : //enter
					switch(high){
						case 0:
							gotoemailfoit(w,f);
							break;
						case 1:
							gotoemailkath(w,f);
							break;
						case 2: 
							active=false;
							break;
					
					
					}
					break;


		
			}


		}



}


void exportfoit(WINDOW* w, Foititologio& f ){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"Εξαγωγή Φοιτητών από αρχείο csv");

		wrefresh(w);

		string tempfile = inputuser(w,3,2,"Εισαγωγή ονόματος αρχείου (με .csv στο τέλος) για εξαγωγή: ");
	
		
		f.export_foitites_to_csv(w,tempfile);


		wrefresh(w);
		wgetch(w);

}

void exportkath(WINDOW* w, Foititologio& f ){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"Εξαγωγή Καθηγητών από αρχείο csv");

		wrefresh(w);

		string tempfile = inputuser(w,3,2,"Εισαγωγή ονόματος αρχείου (με .csv στο τέλος) για εξαγωγή: ");
	
		
		f.export_kathigites_to_csv(w,tempfile);


		wrefresh(w);
		wgetch(w);

}

void exportmath(WINDOW* w, Foititologio& f ){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"Εξαγωγή Μαθημάτων από αρχείο csv");

		wrefresh(w);

		string tempfile = inputuser(w,3,2,"Εισαγωγή ονόματος αρχείου (με .csv στο τέλος) για εξαγωγή: ");
	
		
		f.export_mathimata_to_csv(w,tempfile);


		wrefresh(w);
		wgetch(w);

}

void importfoit(WINDOW* w, Foititologio& f ){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"Εισαγωγή Φοιτητών από αρχείο csv");

		wrefresh(w);

		string tempfile = inputuser(w,3,2,"Εισαγωγή ονόματος αρχείου (με .csv στο τέλος) προς αναζήτηση: ");
	
		
		f.import_foitites_from_csv(w,tempfile);


		wrefresh(w);
		wgetch(w);

}

void importkath(WINDOW* w, Foititologio& f ){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"Εισαγωγή Καθηγητών από αρχείο csv");

		wrefresh(w);

		string tempfile = inputuser(w,3,2,"Εισαγωγή ονόματος αρχείου (με .csv στο τέλος) προς αναζήτηση: ");
	
		
		f.import_kathigites_from_csv(w,tempfile);


		wrefresh(w);
		wgetch(w);

}

void importmath(WINDOW* w, Foititologio& f ){

		wclear(w);
		box(w,0,0);
		mvwprintw(w,1,2,"Εισαγωγή Μαθημάτων από αρχείο csv");

		wrefresh(w);

		string tempfile = inputuser(w,3,2,"Εισαγωγή ονόματος αρχείου (με .csv στο τέλος) προς αναζήτηση: ");
	
		
		f.import_mathimata_from_csv(w,tempfile);


		wrefresh(w);
		wgetch(w);

}

void importcsv(WINDOW* w, Foititologio& f){

		bool active=true;
		int high=0;
		int i;
		int chc=-1;

		vector<string> epilog{"Εισαγωγή Φοιτητών","Εισαγωγή Καθηγητών","Εισαγωγή Μαθημάτων","Επιστροφή"};
		while(active){
			wclear(w);
			box(w,0,0);
			mvwprintw(w,1,2,"Εισαγωγή από αρχείο csv:");

			for(i=0;i <epilog.size() ; i++){
				if(i==high){wattron(w,A_REVERSE);}

				mvwprintw(w, 4+i, 2, "%s", epilog[i].c_str());
				wattroff(w,A_REVERSE);


			}

			wrefresh(w);
			chc = wgetch(w);

			switch(chc){

				case KEY_UP :
					high--;
					if(high<0){high = epilog.size() - 1;}
					break;
				case KEY_DOWN:
					high++;
					if(high >= epilog.size()){high =0;}
					break;
				case 10 : //enter
					switch(high){
						case 0:
							importfoit(w,f);
							break;
						case 1:
							importkath(w,f);
							break;
						case 2:
							importmath(w,f);
							break;	
						case 3: 
							active=false;
							break;
					
					
					}
					break;


		
			}


		}



}

void exportcsv(WINDOW* w, Foititologio& f){

		bool active=true;
		int high=0;
		int i;
		int chc=-1;

		vector<string> epilog{"Εξαγωγή Φοιτητών","Εξαγωγή Καθηγητών","Εξαγωγή Μαθημάτων","Επιστροφή"};
		while(active){
			wclear(w);
			box(w,0,0);
			mvwprintw(w,1,2,"Εξαγωγή από αρχείο csv:");

			for(i=0;i <epilog.size() ; i++){
				if(i==high){wattron(w,A_REVERSE);}

				mvwprintw(w, 4+i, 2, "%s", epilog[i].c_str());
				wattroff(w,A_REVERSE);


			}

			wrefresh(w);
			chc = wgetch(w);

			switch(chc){

				case KEY_UP :
					high--;
					if(high<0){high = epilog.size() - 1;}
					break;
				case KEY_DOWN:
					high++;
					if(high >= epilog.size()){high =0;}
					break;
				case 10 : //enter
					switch(high){
						case 0:
							exportfoit(w,f);
							break;
						case 1:
							exportkath(w,f);
							break;
						case 2:
							exportmath(w,f);
							break;	
						case 3: 
							active=false;
							break;
					
					
					}
					break;


		
			}


		}



}


void gotoexport(WINDOW* w, Foititologio& f){

		bool active=true;
		int high=0;
		int i;
		int chc=-1;

		vector<string> epilog{"Εισαγωγή","Εξαγωγή","Επιστροφή"};
		while(active){
			wclear(w);
			box(w,0,0);
			mvwprintw(w,1,2,"Εισαγωγή ή εξαγωγή σε αρχείο csv:");

			for(i=0;i <epilog.size() ; i++){
				if(i==high){wattron(w,A_REVERSE);}

				mvwprintw(w, 4+i, 2, "%s", epilog[i].c_str());
				wattroff(w,A_REVERSE);


			}

			wrefresh(w);
			chc = wgetch(w);

			switch(chc){

				case KEY_UP :
					high--;
					if(high<0){high = epilog.size() - 1;}
					break;
				case KEY_DOWN:
					high++;
					if(high >= epilog.size()){high =0;}
					break;
				case 10 : //enter
					switch(high){
						case 0:
							importcsv(w,f);
							break;
						case 1:
							exportcsv(w,f);
							break;
						case 2: 
							active=false;
							break;
					
					
					}
					break;


		
			}


		}



}




