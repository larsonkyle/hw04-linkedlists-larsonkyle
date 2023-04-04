// main_menu.cpp: main function (different than the driver provided) that implements
// the menu driven interface as outlined in the directions of the README.md
// MUST COMPLETE FOR FULL CREDIT.

#include "artist.h"
#include "artistList.h"
#include <fstream>

int main() {

//Variables to feed to functions
  std::string artist_id;
  std::string artist_name;
  int total_followers;
  std::string genres[AR_LEN];
  int popularity;

//artistList pointer
  alist *artistList;

//File object and file name
  std::ifstream iFile; //iFile= inputFile
  std::string filename = "spotify_daily_charts_artists.csv";

//CSV input variables
  std::string line; 
  std::string word; 
  std::string temp;
  
//Menu input variables
  int choice1;
  char choice2;

  iFile.open(filename.c_str());


  if (iFile.is_open()){
    iFile.ignore(9999, '\n');    //ignore first line of file
    artistList = newArtistList();

    do {
      std::cout << "Menu - Select:\n";
      std::cout << " 1. Add a Record\n";
      std::cout << " 2. Delete a Record\n";
      std::cout << " 3. Display contents on the screen\n";
      std::cout << " 4. Save and Exit\n";
      std::cin >> choice1;

      //Seperate menu into a (ugly) 2-part menu 
      switch (choice1){
        case 1: std::cout << "a.) Add a record to the beginning of the list\n";
                std::cout << "b.) Add a record to the end of the list\n";
                std::cout << "c.) Add an artist record before another artist\n";
                std::cout << "d.) Add an artist record after another artist\n";
                std::cin >> choice2;

                switch (choice2){
                  case 'a': //Read CSV data into variables
                            std::getline(iFile, line);
                            std::stringstream s(line);

                            std::getline(s, word, ',');
                            artist_id = word;

                            std::getline(s, word, ',');
                            artist_name = word;

                            std::getline(s, word, ',');
                              total_followers = std::stoi(word);

                            s.ignore(1);
                            std::getline(s, temp, '"');
                            temp.append(1, ',');
  
                            for(int i = 0; temp.length(); i++){
                              genres[i] = temp.substr(0, temp.find(',', 0));
                              temp.erase(0, (temp.find(',', 0) + 1));
                            }

                            s.ignore(1);
                            std::getline(s, word, '\n');
                            popularity = std::stoi(word);

                            //Call Linked-List Functions
                            appendArtist(artistList, newArtist(artist_id, artist_name, total_followers, genres[AR_LEN], popularity));
                             break;

                  case 'b': //Read CSV data into variables
                            std::getline(iFile, line);
                            std::stringstream s(line);

                            std::getline(s, word, ',');
                            artist_id = word;

                            std::getline(s, word, ',');
                            artist_name = word;

                            std::getline(s, word, ',');
                              total_followers = std::stoi(word);

                            s.ignore(1);
                            std::getline(s, temp, '"');
                            temp.append(1, ',');
  
                            for(int i = 0; temp.length(); i++){
                              genres[i] = temp.substr(0, temp.find(',', 0));
                              temp.erase(0, (temp.find(',', 0) + 1));
                            }

                            s.ignore(1);
                            std::getline(s, word, '\n');
                            popularity = std::stoi(word);

                            //Call Linked-List Functions
                            prependArtist(artistList, newArtist(artist_id, artist_name, total_followers, genres[AR_LEN], popularity));
                            break; 

                  case 'c': //local variables
                            std::string findName;     //User inputted name
                            artistEntry *traverseList;//temp ptr to find the name in the list

                            std::cout << "Please input an artist name\n";
                            std::cin >> findName; 

                            //find artistEntry/Node (No artistList functions can be used)
                            traverseList = artistList->first; 
                            while(findName != traverseList->artist->artist_name && traverseList != nullptr){
                              traverseList = traverseList->next;
                            }

                            //Read CSV data into variables
                            std::getline(iFile, line);
                            std::stringstream s(line);

                            std::getline(s, word, ',');
                            artist_id = word;

                            std::getline(s, word, ',');
                            artist_name = word;

                            std::getline(s, word, ',');
                              total_followers = std::stoi(word);

                            s.ignore(1);
                            std::getline(s, temp, '"');
                            temp.append(1, ',');
  
                            for(int i = 0; temp.length(); i++){
                              genres[i] = temp.substr(0, temp.find(',', 0));
                              temp.erase(0, (temp.find(',', 0) + 1));
                            }

                            s.ignore(1);
                            std::getline(s, word, '\n');
                            popularity = std::stoi(word);

                            //Call Linked-List functions
                            insertArtistBefore(traverseList, newArtist(artist_id, artist_name, total_followers, genres[AR_LEN], popularity));
                            break; 

                  case 'd': //local variables
                            std::string findName;     //User inputted name
                            artistEntry *traverseList;//temp ptr to find the name in the list

                            std::cout << "Please input an artist name\n";
                            std::cin >> findName; 

                            //find artistEntry/Node (No artistList functions can be used)
                            traverseList = artistList->first; 
                            while(findName != traverseList->artist->artist_name && traverseList != nullptr){
                              traverseList = traverseList->next;
                            }

                            //Read CSV data into variables
                            std::getline(iFile, line);
                            std::stringstream s(line);

                            std::getline(s, word, ',');
                            artist_id = word;

                            std::getline(s, word, ',');
                            artist_name = word;

                            std::getline(s, word, ',');
                              total_followers = std::stoi(word);

                            s.ignore(1);
                            std::getline(s, temp, '"');
                            temp.append(1, ',');
  
                            for(int i = 0; temp.length(); i++){
                              genres[i] = temp.substr(0, temp.find(',', 0));
                              temp.erase(0, (temp.find(',', 0) + 1));
                            }

                            s.ignore(1);
                            std::getline(s, word, '\n');
                            popularity = std::stoi(word);

                            //Call Linked-List functions
                            insertArtistAfter(traverseList, newArtist(artist_id, artist_name, total_followers, genres[AR_LEN], popularity));
                            break; 
                
                  default: std::cout << "Invalid input\n";
                }
                break; 
      
        case 2: std::cout << "a.) Delete the first artist in the record\n";
                std::cout << "b.) Delete the last artist in the record\n";
                std::cout << "c.) Select a record to delete using artist_name\n";
                std::cin >> choice2;

               switch (choice2){
                  case 'a': removeFirstArtist(artistList);
                            break;

                  case 'b': removeLastArtist(artistList);
                            break; 

                  case 'c': //local variables
                            std::string findName;     //User inputted name
                            Artist *artist;           //stores findArtistName() return data

                            std::cout << "Please input an artist name\n";
                            std::cin >> findName; 

                            artist = findArtistName(artistList, string findName);
                            removeArtistbyName(artistList, artist->artist_name);
                            break; 
                
                  default: std::cout << "Invalid input\n";
                }
                break; 

        case 3: std::cout << "a.) Select record to display using artist_name\n";
                std::cout << "b.) Display all records\n";
                std::cin >> choice2;

                switch (choice2){
                  case 'a': //local variables
                            std::string findName;     //User inputted name
                            Artist *artist;           //stores findArtistName() return data

                            std::cout << "Please input an artist name\n";
                            std::cin >> findName; 

                            artist = findArtistName(artistList, string findName);
                            printArtist(artist);
                            break;

                  case 'b': printArtistList(artistList);
                            break; 
                
                  default: std::cout << "Invalid input\n";
                }
                break;

        case 4: break;

        default: std::cout << "Invalid Input\n";
      }
    }while (choice1 != 4);


    iFile.close();

    //DELETE ARTISTLIST;
    deleteArtistList(artistList);
    artistList = nullptr;

  }
  std::cout << "Program Shutting Down..." << std::endl;
  return 0;
}
