#include "ergasiaex.h"

int main(){

	bool active=true; //πρόγραμμα ενεργό
	int high=0; //highlight
	int chc=-1; //επιλογη
	int i;

	setlocale(LC_ALL, ""); //υποστήριξη ελληνικών
	initscr();	//εκκίνηση ncruses
	noecho();   //μην εκτυπώνεις από πληκτρολόγιο
	cbreak();
	//keypad(stdscr, TRUE);

	

	WINDOW* menu = newwin(35,85,2,4); //παράθυρο
	keypad(menu, TRUE);

	Foititologio fl;

	vector<string>epilog = {"Προβολή Εγγεγραμένων Τμήματος","Αναζήτηση Εγγεγραμένου","Επεξεργασία Εγγεγραμένων","Προβολή Μαθημάτων","Αναζήτηση Μαθήματος","Επεξεργασία Μαθημάτων","Αποστολή Email","Εισαγωγή/Εξαγωγή αρχείου","Έξοδος"};




	while(active){

		wclear(menu);
		box(menu,0,0);
		mvwprintw(menu,1,25,"|=ΦΟΙΤΗΤΟΛΟΓΙΟ=|");

		for(i=0;i <epilog.size() ; i++){
			if(i==high){wattron(menu,A_REVERSE);}

			mvwprintw(menu, 4+i, 2, "%s", epilog[i].c_str());
			wattroff(menu,A_REVERSE);


		}

		wrefresh(menu);
		chc = wgetch(menu);

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
						gotoviewegg(menu,fl);
						break;
					case 1:
						gotosearchegg(menu,fl); 
						break;
					case 2:
						gotoedit(menu,fl); 
						break;
					case 3: 
						gotoviewmath(menu,fl);
						break;
					case 4:
						gotosearchmath(menu,fl);
						break;
					case 5:
						gotoeditmath(menu,fl);
						break;	
					case 6:
						gotoemail(menu,fl);
						break;
					case 7:
						gotoexport(menu,fl);
						break;

					case 8:
					active=false;
					break;

				}
				break;




		}


	}
		refresh();
		endwin();



		cout << endl;
		return 0;

}