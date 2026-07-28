#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Point{
	int x;
	int y;
};

struct fPoint{
	float x;
	float y;
};

Point& FindMax(Point arr[],int N){
	float max=-100.0;
	int maxind=-1;
	int i;
	float d;
	for(i=0;i<N;i++){
		d=sqrt(arr[i].x*arr[i].x+arr[i].y*arr[i].y);
		if (d>max)
		{
			 maxind=i;
			 max=d;
		}


	}

	cout<<"x="<< arr[maxind].x<< "    y=" << arr[maxind].y << endl;
	return arr[maxind];

}



fPoint& FindMax(fPoint arr[],int N){
	float max=-100.0;
	int maxind=-1;
	int i;
	float d;
	for(i=0;i<N;i++){
		d=sqrt(arr[i].x*arr[i].x+arr[i].y*arr[i].y);
		if (d>max)
		{
			 maxind=i;
			 max=d;
		}


	}

	cout<<"x="<< arr[maxind].x<< "    y=" << arr[maxind].y<< endl;

	return arr[maxind];


}

int main(void){

	const int N=10;
	int i=0;

	srand(time(0));
	Point Pointarr[N];
	for(i=0;i<N;i++){
		Pointarr[i].x=rand() % 11;
		Pointarr[i].y=rand() % 11;

	}
	cout<<"Σημείο με μεγαλύτερη απόσταση     ";
	FindMax(Pointarr,N);

	

	fPoint fPointarr[N];
	for(i=0;i<N;i++){
		fPointarr[i].x=rand()%11;
		fPointarr[i].y=rand()%11;
	}

	cout<<"Σημείο με μεγαλύτερη απόσταση     ";
	FindMax(fPointarr,N);


	return 0;


}
