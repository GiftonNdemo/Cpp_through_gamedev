#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(){
    enum fields{WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS=5;
    const string words[NUM_WORDS][NUM_FIELDS]{{"wall","Do you feel like banging your head against something "},
        {"jumble","that's what the game is all about"},
        {"glasses","these might help you see the answer"},
        {"laboured","going slowly, is it?"},
        {"persistent","Keep at it!"},
    };
    srand(static_cast<unsigned int>(time(0)));
    int choice= (rand()%NUM_WORDS);
    string theword=words[choice][WORD];
    string thehint=words[choice][HINT];

    string jumble=theword;
    int length=jumble.size();
    for(int i=0;i<=length;i++){
        int index1=(rand()%NUM_WORDS);
        int index2=(rand()%NUM_WORDS);
        char temp= jumble[index1];
        jumble[index1]=jumble[index2];
        jumble[index2]=temp;
    }
    cout<<"Welcome to word jumble"<<endl;
    cout<<"unscramble the letters to make a word"<<endl;
    cout<<"enter hint to get a hint"<<endl;
    cout<<"enter quit to quit the game"<<endl;
    cout<<"unscramble: "<<jumble<<endl;
    string guess;
    cin>>guess;
    while(guess!=theword){
        if(guess=="hint"){
            cout<<thehint<<endl;
            cout<<"unscramble: "<<jumble<<endl;
            cin>>guess;
        }
        else if(guess=="quit"){
            break;
        }
        else{
            cout<<"that's not it, try again!"<<endl;
            cout<<"unscramble: "<<jumble<<endl;
            cin>>guess;
        }
        if(guess==theword){
            cout<<"That's it! You guessed it correctly!"<<endl;
        }
    }
    cout<<"Thanks for playing, bye bye!"<<endl;
    return 0;
}
