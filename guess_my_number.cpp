#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int tries=0,guess,secret_number;
    srand(static_cast<unsigned int> (time(0)));
    secret_number = rand()%100 + 1;
    do{
        cout<<"Enter your guess: ";
        cin>>guess;
        ++tries;
        if(guess>secret_number){
            cout<<"Too high!"<<endl;
        }
        else if(guess<secret_number){
            cout<<"Too low!"<<endl;
        }
        else{
            cout<<"You correctly guessed "<<secret_number<< " in "<<tries<< " guesses!"<<endl;
            break;
        }
    }while(guess!=secret_number);
}
