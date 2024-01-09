#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

    int highest, lowest, guess,num;
int generate_random_number(int high, int low){
    
    srand(static_cast<unsigned int>(time(0)));
    num = rand()%(high-low+1)+low;
return num;
}
int main(){
    cout<<"Welcome to guess my number, version 2!"<<endl;
    cout<<"Here, you will think of a number and I will try to guess it. Let's Go!"<<endl;
    string response;
    int tries=0;
    highest = 100;
    lowest = 1;
    guess = generate_random_number(highest,lowest);
    cout<<guess<<endl;
    cout<<"Is this correct? "<<endl;
    getline(cin, response);
    while(response!="correct"){
        if(response=="Too high"){
            highest=guess;
            guess = generate_random_number(highest,lowest);
            cout<<guess<<endl;
            ++tries;
            cout<<"Is this correct?"<<endl;
            getline(cin,response);
        }
        else if(response=="Too low"){
            lowest=guess;
            guess = generate_random_number(highest,lowest);
            cout<<guess<<endl;
            ++tries;
            cout<<"Is this correct?"<<endl;
            getline(cin,response);
        }
    }
    cout<<"I was able to guess "<<guess<<" in "<<tries<<" tries. Could have been worse :/"<<endl;
}
