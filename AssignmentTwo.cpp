#include <iostream>
#include <algorithm>
using namespace std;
//Number of operations for each algorithms
int SS=0,BS=0, SS1=0,IS=0;
void MostEfficient();
//The data items for simple sort 
int datalist[7];
void SimpleSort();
void BubbleSort();
void SelectionSort();
void InsertionSort();
void swap(int &a, int &b);
int main(){
	//taking input from the user
	cout<<"Type in 7 random integers:"<<endl;
	int original_datalist[7];
	for(int i =0; i<7; i++){
		cin>>datalist[i];
		original_datalist[i] = datalist[i];
	}
	cout<<"\nThe unsorted array of inputs"<<endl;
	for(int i =0; i<7; i++){
		if(i==0)
			cout<<"[";
		cout<<datalist[i]<<", ";
		if(i==6)
			cout<<"]"<<endl;
	}


	SimpleSort();

	for(int i = 0; i < 7; i++) {
		datalist[i] = original_datalist[i];
	}
	BubbleSort();

	for(int i = 0; i < 7; i++) {
		datalist[i] = original_datalist[i];
	}
	SelectionSort();

	for(int i = 0; i < 7; i++) {
		datalist[i] = original_datalist[i];
	}
	InsertionSort();

	//Display the sorted Array
	cout<<"\nThe Array Sorted: "<<endl;
	for(int i =0; i<7; i++){
		if(i==0)
			cout<<"[";
		cout<<datalist[i]<<", ";
		if(i==6)
			cout<<"]"<<endl;
	}
	MostEfficient();

	return 0;
}
void swap(int &a, int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
void MostEfficient(){
    cout<<"Number of comparsions and Swaps for each algorithms"<<endl;
    cout<<"Simple Sort Algorithm: "<<SS<<endl;
    cout<<"Bubble Sort Algorithm: "<<BS<<endl;
    cout<<"Selection sort Algorithm: "<<SS1<<endl;
    cout<<"Insertion Sort Algorithm: "<<IS<<endl;
    
    int me = (SS+BS<SS1+IS)? min(SS,BS): min(SS1,IS);
    cout<<"Most efficient algorithm is: ";
    if(me==SS)
    cout<<"Simple Sort"<<endl;
    else if(me==BS)
    cout<<"Bubble Sort"<<endl;
    else if(me==SS1)
    cout<<"Selection Sort"<<endl;
    else
    cout<<"Insertion Sort";
    
}
void InsertionSort() {
    for (int i = 1; i < 7; i++) {
        bool ordered = false;
        int j = i;
        while ((j >= 1) && !ordered) {
            if (datalist[j] < datalist[j-1]) {
                swap(datalist[j], datalist[j-1]);
                IS += 2; // Count swap (two operations)
                j--;     // Move left to continue shifting
                IS++;    // Count comparison
            } 
			else {
                ordered = true; // Stop when no more swaps needed
                IS++;           // Count comparison
            }
        }
    }
}
void SelectionSort(){
    for(int i =0; i<6; i++){
        int min_index =i;
        for(int j=(i+1); j<7; j++){
            if(datalist[j]<=datalist[min_index]){
                swap(datalist[j],datalist[min_index]);
                SS1+=2;
            }
            else
            SS1++;
        }
    }
}
void BubbleSort(){
	//Implementing the Bubble Sort Agorithm
	for(int i =0; i<7; i++){

		for(int j=1; j<7-i; j++){
			if(datalist[j]<datalist[j-1]){
				swap(datalist[j],datalist[j-1]);
				BS+=2;
			}
			else
			BS++;
		}
	}
}
void SimpleSort(){
	for(int i=0; i<7;i++){
		
		for(int j= (i+1) ;j<7;j++){
			if(datalist[j]<datalist[i]){
				swap(datalist[j],datalist[i]);
				SS+=2;
			}
		else
			SS++;
		}
	}
}

