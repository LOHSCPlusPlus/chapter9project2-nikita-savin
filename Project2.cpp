#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//Struct

struct Bird{
  enum {MAX_CHAR_LENGTH=500};
  char name[MAX_CHAR_LENGTH];
  char scientificName[MAX_CHAR_LENGTH];
  char conservationStatus[MAX_CHAR_LENGTH];
  char color[MAX_CHAR_LENGTH];
  char diet[MAX_CHAR_LENGTH];
};




//file reader
const int MAX_BIRDS=200;

Bird readBirdData(ifstream &inFile){
    Bird bird; 
    inFile.get(bird.name, Bird::MAX_CHAR_LENGTH, ';');
    inFile.ignore(100,';');
    inFile.get(bird.scientificName, Bird::MAX_CHAR_LENGTH, ';');
    inFile.ignore(100,';');
    inFile.get(bird.conservationStatus, Bird::MAX_CHAR_LENGTH, ';');
    inFile.ignore(100,';');
    inFile.get(bird.color, Bird::MAX_CHAR_LENGTH, ';');
    inFile.ignore(100,';');
    inFile.get(bird.diet, Bird::MAX_CHAR_LENGTH);
    inFile.ignore(100, '\n');
    
    // If we reached the end of the file while reading, then the entry is not valid
    return bird;
} 

int readBird(Bird bird[]) {
    ifstream birdFile("birds.txt");
    int numBirds = 0;
    while(birdFile.peek() != EOF && numBirds < MAX_BIRDS) {
        bird[numBirds] = readBirdData(birdFile);
        numBirds++;
    }
    return numBirds;
}

Bird readFromUser() {
  Bird bird;
        cout << "Enter Bird name: ";
        cin.ignore(1000, '\n');
        cin.getline(bird.name, Bird::MAX_CHAR_LENGTH);
    
        
        cout << "Enter Scientific Name: ";
        cin.getline(bird.scientificName, Bird::MAX_CHAR_LENGTH);
     

        cout << "Enter conservation status: ";
        cin.getline(bird.conservationStatus, Bird::MAX_CHAR_LENGTH);
    
        
        cout << "Enter color: ";
        cin.getline(bird.color, Bird::MAX_CHAR_LENGTH);
      

        cout << "enter the birds diet: ";
        cin.getline(bird.diet, Bird::MAX_CHAR_LENGTH);

      return bird;
}



//Printing mumbojumbo starts

void printbird(ostream &out, Bird bird){
    out << bird.name << ";";
    out << bird.scientificName << ";";
    out << bird.conservationStatus << ";";
    out << bird.color << ";";
    out << bird.diet << ";" << endl;
}

void printArrayToScreen(Bird birds[], int numbirds) {
    for (int index = 0; index < numbirds; index++) {
        printbird(cout, birds[index]);
    }
}

void printArrayToFile(const char fileName[], Bird birds[], int numbirds) {
    ofstream outFile(fileName);
    for (int index = 0; index < numbirds; index++) {
        cout << index << endl;
        printbird(outFile, birds[index]);
    }
}

//Printing mumbojumbo ends


//Adding and Removing

void addBird(int Index, Bird bird[]) {
  bird[Index] = readFromUser();
}

void removeBird(Bird bird[], int numBirds) {
  //ask index
  int removeIndex;
  cout << "Enter index to remove: ";
  cin >> removeIndex;
  //check if valid index
   while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter index of the car you want to remove: ";
        cin >> removeIndex;
    }
  //loop, start index, copy into bird[i], bird[i+1]
    for (int i = removeIndex; i < numBirds - 1; i++ ) {
      bird[i] = bird[i + 1];
    }
    
}

//search

void searchBird(Bird bird[], int numbirds) {
  cin.ignore(1000, '\n');
  char userName[100];
  cout << "Enter bird name to search: ";
  cin.getline(userName, 100);
  
  for (int index = 0; index < numbirds; index++) {
         if (strcmp(userName, bird[index].name) == 0) {
        printbird(cout, bird[index]);
           }
    }
}

int readInt(const char prompt[]) {
    int temp = 0;
    cout << prompt;
    cin >> temp; 
    while (!cin) {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
  return temp;
}


void displayMenu() {

  Bird bird[MAX_BIRDS];
  int numBirds = readBird(bird);

  int input = 0;

  while(input != 7) {

    cout << "Please select choice (number)" << endl;
    cout << "1. Reload database" << endl;
    cout << "2. Print database" << endl;
    cout << "3. Add new bird" << endl;
    cout << "4. Remove a bird" << endl;
    cout << "5. Search" << endl;
    cout << "6. Save database to file" << endl;
    cout << "7. Quit" << endl;

    input = readInt("Enter choice: ");

    if ( input == 1) {
      numBirds = readBird(bird);
    }

    if (input == 2) {
      printArrayToScreen(bird, numBirds);
    }

    if (input == 3) {
      addBird(numBirds, bird);
      numBirds ++;
    }

    if (input == 4) {
      removeBird(bird, numBirds);
      numBirds --;
    }

    if (input == 5) {
      searchBird(bird, numBirds);
    }

    if (input == 6) {
      printArrayToFile("birds1.txt", bird, numBirds);
    }
    
  }

  
}







  int main() {
    
    displayMenu();
    
    
    
    //rintArrayToScreen(bird, numBirds);
    //searchBird(bird, numBirds);
     
    //printArrayToScreen(bird, numBirds);
    //addBird(numBirds, bird);
    //numBirds ++;
    //printArrayToScreen(bird, numBirds);
    //removeBird(bird, numBirds);
    //numBirds --;
    //printArrayToScreen(bird, numBirds);
  }



