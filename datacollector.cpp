//Apparently, you can just assign an int to a char (In c++). I'm learning a lot about chars!
//TODO: Figure out resourcescollected flow
//If you ever forget what you were working on last, check the TODO above.

#include <iostream>
#include <vector>
#include "datacollector.h"
using namespace std;

int nop = 0;
string playername;
string playernames[4]; //made need to change these if I adapt the program to 6 players.
string playercolors[4];
string firstplacer;
int numrolled;
vector<int> dicerolls;
string rresponse, resourceletter, playerrresponse; //Stands for resource response
vector<int> now, noco, nos, nowoo, nocl; //# of wheat, coal, sheep, wood, and clay
int wheatnum = 0, coalnum = 0, sheepnum = 0, woodnum = 0, claynum = 0;
string hexdata;
int playerrobbed;
string winner;
string wincauses;
vector<string> windatacollector; //When declaring an array in c++, one must have a size initializer.
string secondplace, thirdplace, fourthplace;
int secondsvps, thirdsvps, fourthsvps, wheatadded, coaladded, sheepadded, woodadded, clayadded;
vector<int> totalwheat, totalcoal, totalsheep, totalwood, totalclay;
//Player one's, two's, three's and four's total resource count. May need to increase numbers in future.
vector<int> pototalwheat, pototalcoal, pototalsheep, pototalwood, pototalclay;
vector<int> pttotalwheat, pttotalcoal, pttotalsheep, pttotalwood, pttotalclay;
vector<int> pthtotalwheat, pthtotalcoal, pthtotalsheep, pthtotalwood, pthtotalclay;
vector<int> pftotalwheat, pftotalcoal, pftotalsheep, pftotalwood, pftotalclay;

int main(int argc, const char * argv[]) {
 
    //printplayerdata();
    //dicerolled();
    //resourcescollected();
    datacollection();
    //eog();
    //totals(playernames);
    return 0;
}

int numofplayers(){
    cout << "How many players are there?" << endl;
    cin >> nop;
    return nop;
}

void printplayerdata(){ //To return an array of a certain type, you just return a pointer to that type?
     //numofplayers();
     for (int i = 0; i < nop; i++){
         cout << "Enter player # " << i+1 << endl;
         cin >> playernames[i];
         cout << "Enter color" << endl;
         cin >> playercolors[i];
    }
     for (int i = 0; i < nop; i++){
         cout << "Player " << i+1 << " is " << playernames[i] << ". Their color is " << playercolors[i] << "." << endl;
     }
}

void dicerolled(){
    //numofplayers();
    bool cont = true;
    cout << "Which player is placing first?" << endl;
    cin >> firstplacer;
    while (cont == true){
         cout << "What number was rolled?" << endl;
         cin >> numrolled;
         dicerolls.push_back(numrolled);
         if(numrolled == 7){
             robberclause();
         }
         if (numrolled == 2590){
             break;
         }
        resourcescollected();
    }
    /* Just made this to check to see if the vector printed out the correct values
    for (int i = 0; i < dicerolls.size(); i++){
        cout << dicerolls[i] << endl;
    }
     */
}

void resourcescollected(){
   // numofplayers();
    cout << "What resources were collected?" << endl;
    for (int i = 0; i < nop; i++){
        cout << "Player " << i+1 << "'s " << "Resources:" << "\n" << "(in the form of a letter)" << endl;
        cin >> playerrresponse;
        if (playerrresponse.compare("SKIP") == 0); //Surprisingly, this works. It works because SKIP is entered and the do loop only executes if SKIP isn't entered. It's just funny that an if statement that doesn't do anything works like this.
        else do{
           cin >> resourceletter;
                //cin >> resourceletter;
                if (resourceletter[0] == 'W'){ //Wow. " " denotes a string while ' ' denotes a char. Makes sense just never knew.
                    cout << "How much Wheat?" << endl;
                    cin >> wheatnum;
                    now.push_back(wheatnum);
                    totalwheat.push_back(wheatnum);
                    totals(i+1, wheatnum, "W");
                }
                else if (resourceletter[0] == 'C' && resourceletter[1] == 'o'){
                    cout << "How much Coal?" << endl;
                    cin >> coalnum;
                    noco.push_back(coalnum);
                    totalwheat.push_back(coalnum);
                    totals(i+1, coalnum, "C");
                }
                else if (resourceletter[0] == 'S'){
                    cout << "How much Sheep?" << endl;
                    cin >> sheepnum;
                    nos.push_back(sheepnum);
                    totalsheep.push_back(sheepnum);
                    totals(i+1, sheepnum, "S");
                }
                else if (resourceletter[0] == 'w'){ //When inputting wood, make sure it's decapital2ized. Otherwise, the program will think you're talking about Wheat.
                    cout << "How much Wood?" << endl;
                    cin >> woodnum;
                    nowoo.push_back(woodnum);
                    totalwood.push_back(woodnum);
                    totals(i+1, woodnum, "Woo");
                }
                else if (resourceletter[1] == 'l'){ //When inputting clay, make sure you type "CL."
                    cout << "How much Clay?" << endl;
                    cin >> claynum;
                    nocl.push_back(claynum);
                    totalclay.push_back(claynum);
                    totals(i+1, claynum, "Cl");
                }
            }
            while(resourceletter.compare("DONE") != 0);
        }
    }

void datacollection(){
    numofplayers();
    printplayerdata();
    dicerolled();
    resourcescollected();
}

void robberclause(){
    
    cout << "What hex and # was the robber put on?" << endl; //Has to be one line with no spaces.
    cin >> hexdata;
    cout << "Which player got robbed?" << endl;
    cin >> playerrobbed;
}

void eog(){
    cout << "Which player won?" << endl;
    cin >> winner;
    cout << "How did they win? Use 'LR' for Longest Road, 'LA' for largest army, and xC and xS where x is any number of cities or settlements." << endl;
    do{
        cin >> wincauses;
        windatacollector.push_back(wincauses);
    }
    while(wincauses.compare("DONE") != 0);
    cout << "Who came in second?" << endl;
    cin >> secondplace;
    cout << "How many VPs?" << endl;
    cin >> secondsvps;
    cout << "Who came in third?" << endl;
    cin >> thirdplace;
    cout << "How many VPs?" << endl;
    cin >> thirdsvps;
    cout << "Who came in fourth?" << endl;
    cin >> fourthplace;
    cout << "How many VPs?" << endl;
    cin >> fourthsvps;
    for(int i = 1; i < 5; i++){
        printtotals(i);
    }
}

int average(){
    return 0;
    //May need to ask Poe about this one. Don't give up on it yet.
}

void totals(int numplayer, int num, string resource){
    if(numplayer == 1){
        if(resource.compare("W") == 0){
            pototalwheat.push_back(num);
        }
        else if (resource.compare("C") == 0){
            pototalcoal.push_back(num);
        }
        else if (resource.compare("S") == 0){
            pototalcoal.push_back(num);
        }
        else if (resource.compare("Woo") == 0){
            pototalcoal.push_back(num);
        }
        else if (resource.compare("Cl") == 0){
            pototalcoal.push_back(num);
        }
    }
    else if(numplayer == 2){
        if(resource.compare("W") == 0){
            pttotalwheat.push_back(num);
        }
        else if (resource.compare("C") == 0){
            pttotalcoal.push_back(num);
        }
        else if (resource.compare("S") == 0){
            pttotalcoal.push_back(num);
        }
        else if (resource.compare("Woo") == 0){
            pttotalcoal.push_back(num);
        }
        else if (resource.compare("Cl") == 0){
            pttotalcoal.push_back(num);
        }
    }
    else if(numplayer == 3){
        if(resource.compare("W") == 0){
            pthtotalwheat.push_back(num);
        }
        else if (resource.compare("C") == 0){
            pthtotalcoal.push_back(num);
        }
        else if (resource.compare("S") == 0){
            pthtotalcoal.push_back(num);
        }
        else if (resource.compare("Woo") == 0){
            pthtotalcoal.push_back(num);
        }
        else if (resource.compare("Cl") == 0){
            pthtotalcoal.push_back(num);
        }
    }
    else if(numplayer == 4){
        if(resource.compare("W") == 0){
            pftotalwheat.push_back(num);
        }
        else if (resource.compare("C") == 0){
            pftotalcoal.push_back(num);
        }
        else if (resource.compare("S") == 0){
            pftotalcoal.push_back(num);
        }
        else if (resource.compare("Woo") == 0){
            pftotalcoal.push_back(num);
        }
        else if (resource.compare("Cl") == 0){
            pftotalcoal.push_back(num);
        }
    }
}

void printtotals(int num){
    if (num == 1){
        for(int i = 0; i < 10; i++){ //Will need to change i later
            cout << pototalwheat[i];
            cout << pototalcoal[i];
            cout << pototalsheep[i];
            cout << pototalwood[i];
            cout << pototalclay[i];
        }
    }
    if (num == 2){
        for(int i = 0; i < 10; i++){ //Will need to change i later
            cout << pttotalwheat[i];
            cout << pttotalcoal[i];
            cout << pttotalsheep[i];
            cout << pttotalwood[i];
            cout << pttotalclay[i];
        }
      }
    if (num == 3){
        for(int i = 0; i < 10; i++){ //Will need to change i later
            cout << pthtotalwheat[i];
            cout << pthtotalcoal[i];
            cout << pthtotalsheep[i];
            cout << pthtotalwood[i];
            cout << pthtotalclay[i];
        }
      }
    if (num == 4){
        for(int i = 0; i < 10; i++){ //Will need to change i later
            cout << pftotalwheat[i];
            cout << pftotalcoal[i];
            cout << pftotalsheep[i];
            cout << pftotalwood[i];
            cout << pftotalclay[i];
        }
    }
}
