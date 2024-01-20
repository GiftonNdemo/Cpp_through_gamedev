#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

int main(){
    int score=0;
    bool playing = true;
    int list=0;
    //welcoming the player to the word_jumble game
    cout<<"Welcome to word jumble!"<<endl;
    cout<<endl<<"You will try to unjumble the words to make up the correct word"<<endl;
    cout<<"To get a hint type 'hint' and to quit type 'quit'."<<endl;
    cout<<"NOTE: using hints deduct 5 points from your score: try not to use them often"<<endl;
    cout<<endl<<"let's go!"<<endl;    
    //defining the words to be scrambled in the game
    enum fields{WORD, HINT, num_fields};    
    const int Num_words = 10;     
    const string word[Num_words][num_fields]{{"penguin","This bird is always dressed for a formal occasion."},
        {"giraffe","This animal has a long neck and spots all over its body"},
        {"sushi","This Japanese dish is made with rice, seaweed, and raw fish"},
        {"kangaroo","This Australian animal has a pouch in which it carries its young"},
        {"taco","This Mexican dish is made with a tortilla filled with meat, cheese, and vegetables"},
        {"pirate", "This person is known for stealing treasure and sailing the seas"},
        {"unicorn", "This mythical creature has a horn on its forehead and is often associated with rainbows"},
        {"ninja","This person is known for their stealth and martial arts skills"},
        {"persistence","Keep at it"},
        {"jumble","It's what the game is all about"}};
    //scarmbling the words
    int chosen[Num_words]={0};

    srand(static_cast<unsigned int>(time(0)));
    while(playing && list < Num_words){
        int choice = (rand() % Num_words);

        // Check if the word is already chosen
        bool alreadyChosen = false;
        for (int i = 0; i < list; ++i) {
            if (chosen[i] == choice) {
                alreadyChosen = true;
                break;
            }
        }

        // If the word is not chosen, add it to the chosen array
        if (!alreadyChosen) {
            chosen[list++] = choice;

            string theWord = word[choice][WORD];
            string theHint = word[choice][HINT];
            string jumble = theWord;
            int length = jumble.size();
            for(int i=0;i<length;i++){
                int index1=(rand()%length);
                int index2=(rand()%length);
                int temp = jumble[index1];
                jumble[index1]=jumble[index2];
                jumble[index2]=temp;
            }
            //asking for players guess/input
            cout<<endl<<"unscramble: "<<jumble<<endl;
            cout<<endl;
            cout<<"Enter  your guess: ";
            string response;
            cin>>response;
            //validating the input
            while(response!=theWord){
                if(response=="quit"){
                    playing=false;
                    break;
                }
                else if(response=="hint"){
                    cout<<theHint<<endl;
                    score-=5;
                    cout<<"Your guess: ";
                    cin>>response;
                }
                else{
                    cout<<"That is not correct, try again!"<<endl;
                    score-=10;
                    cout<<"Your guess: ";
                    cin>>response;
                }
            }
            if(response==theWord){
                cout<<"That is correct!"<<endl;
                score+=100;
            }
            if(list==10)
                playing=false;
        }
    }
    //exiting the game
    if(score<=0){
        score=0;
    }
    cout<<"Your overall score is: "<<score<<endl;
    cout<<"Thanks for playing! Bye bye!"<<endl;

    return 0;
}
