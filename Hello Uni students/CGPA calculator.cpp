//grades are calculated by converting the total grade in subject into scale of A+, A-, B+, B, B-, C+, C, C-, D, F.
//points are then calculated by credit hours or ECTs
//First you need to put the total grade. Ex: 100, 93, 84, 66 and so on.
//The scale of A+, A-, B+, B, B-, C+, C, C-, D, F depends on the university 
#include <iostream>
#include <vector>
using namespace std;

float Points(float ECTs, float Grade ); // To get the grade points
float gradeConvert(float total); // to convert the the total of grades to  A+, A-, B+, B, B-, C+, C, C-, D, F form.
int main(){
    string name;
    int a;
    float Total;
    int ECTs;
    float totalPoints, totalECTs;
    int b=1;
        vector<float> points;
    std::cout<<"Welcome to CGPA calculator, where you can you CGPA\n";
    std::cout<<"*\n";
    std::cout<<"*\n";
    std::cout<<"*\n";

    std::cout<<"Can you provide us with your name please\n";
    std::cin>>name;
    std::cout << "\033[2J\033[1;1H"; // Clearing output screen.
    std::cout<<"Weclome Mr/Ms "<<name<<'\n';
    cout<<"How many courses do you have\n";
    cin>>a;
    
    while(a>0){

    std::cout<<"Enter your total grades in the "<<b<<"th course\t\t";
    b++;
    std::cin>>Total;
    std::cout<<"How many ECTs in the course\t\t";
    cin>>ECTs;
    totalECTs+=ECTs;
    float totalC = gradeConvert(Total);
    Points(ECTs, totalC);

    points.push_back(Points(ECTs, totalC));
    a--;
    }
    std::cout << "\033[2J\033[1;1H"; //Clearing the output screen.
    //the Sum of points computing 
    for(int Nam: points){
    totalPoints+=Nam;
   }
   //CGPA Calculation
    float CGPA= totalPoints/totalECTs;
    cout<<"Your CGPA is\t"<<CGPA;
    
    return 0;
    
}
float Points(float ECTs, float Grade ){
    return ECTs*Grade;
}
float gradeConvert(float Total){
	
    if(Total >83 && Total<=100){
        return Total= 4.0;
    }
    else if(Total>80 && Total<=83 ){
       return  Total=3.75;
    }
    else if(Total>75 && Total<=80 ){
        return Total=3.5;
    }
    else if(Total>68 && Total<=75){

        return Total=3.0;
    }
    else if(Total>65 && Total <=68){
       return  Total =2.75;
    }
    else if( Total >60 && Total <=65){
        return Total =2.5;
    }
    else if(Total >50 && Total <=60 ){
        return Total=2.0;

    }
    else if (Total > 45 && Total <=50){
        return Total = 1.75;

    }
    else if (Total >40 && Total <=45){
        return Total =1.0;
    }
    else if  (Total<=40){
        Total =0;
        return Total;
    }
    return Total;
}
