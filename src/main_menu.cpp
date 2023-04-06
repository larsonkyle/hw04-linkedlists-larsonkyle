#include "artist.h"
#include "artistList.h"
#include <fstream>
#include <sstream>

//COMPLETED EXTRA CREDIT
int main() {
  //Variables to feed to functions
  std::string artist_id;
  std::string artist_name;
  int total_followers;
  std::string genres[AR_LEN];
  int popularity;

  //artistList pointer
  ArtistList *artistList;
  ArtistEntry *traverseList = nullptr;
  Artist *artist;

  //File object and file name
  std::fstream ioFile; //ioFile = inputoutputFile
  std::string filename = "spotify_daily_charts_artists.csv";

  //CSV input variables
  std::string line; 
  std::string word; 
  std::string temp;

  //Menu input variables
  int choice1;
  char choice2;
  

  ioFile.open(filename.c_str(), ios::in);
  artistList = newArtistList();

  //read entire file contents into linked list
  ioFile.ignore(9999, '\n'); //ignore first line of csv
  while(!(ioFile.eof())){
    std::getline(ioFile, line);
    std::stringstream s(line);

    std::getline(s, word, ',');
    artist_id = word;

    std::getline(s, word, ',');
    artist_name = word;

    std::getline(s, word, ',');
    total_followers = std::stoi(word);

    std::getline(s, temp, ']');
    temp.append(1, ',');
  
    for(int i = 0; temp.length(); i++){
     genres[i] = temp.substr(0, temp.find(',', 0));
     temp.erase(0, (temp.find(',', 0) + 1));
    }

    std::getline(s, word, '\n');
    
    //check if entry was a 1 genre format or multi-genre format(csv file format error?)
   if (word.at(0) == '"'){
      word.erase(0, 2);
   }
   else{
      word.erase(0, 1);
   }
    popularity = std::stoi(word);
    
    appendArtist(artistList, newArtist(artist_id, artist_name, total_followers, genres, popularity));
  }
  
  ioFile.close();
  ioFile.open("updated_spotify_daily_charts_artists.csv", ios::out);


  //start menu
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
                case 'a': 
                          artist_id = "1234testID";
                          artist_name = "John Doe";
                          total_followers = 3245;

                          for(int i = 0; i < AR_LEN; i++)
                            genres[i].clear();

                          genres[0] = "[Pop ";
                          genres[1] = "Rap";
                          popularity = 99;
                          
                          prependArtist(artistList, newArtist(artist_id, artist_name, total_followers, genres, popularity));
                          break;
                        

                case 'b':
                          artist_id = "1234testID";
                          artist_name = "John Doe";
                          total_followers = 3245;

                          for(int i = 0; i < AR_LEN; i++)
                            genres[i].clear();

                          genres[0] = "[Pop ";
                          genres[1] = "Rap";
                          popularity = 99;

                          appendArtist(artistList, newArtist(artist_id, artist_name, total_followers, genres, popularity));
                          break; 

                case 'c': artist_id = "1234testID";
                          artist_name = "John Doe";
                          total_followers = 3245;

                          for(int i = 0; i < AR_LEN; i++)
                            genres[i].clear();

                          genres[0] = "[Pop ";
                          genres[1] = "Rap";
                          popularity = 99;

                          traverseList = artistList->first;
                          insertArtistBefore(traverseList, newArtist(artist_id, artist_name, total_followers, genres, popularity));
                          break;

                case 'd': artist_id = "1234testID";
                          artist_name = "John Doe";
                          total_followers = 3245;

                          for(int i = 0; i < AR_LEN; i++)
                            genres[i].clear();

                          genres[0] = "[Pop ";
                          genres[1] = "Rap";
                          popularity = 99;

                          traverseList = artistList->first;
                          insertArtistAfter(traverseList, newArtist(artist_id, artist_name, total_followers, genres, popularity));
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

                case 'c': artist_name = "John Doe";
                          removeArtistbyName(artistList, artist_name);
                          break; 
                
                default: std::cout << "Invalid input\n";
              }
              break; 

      case 3: std::cout << "a.) Select record to display using artist_name\n";
              std::cout << "b.) Display all records\n";
              std::cin >> choice2;

              switch (choice2){
                case 'a': artist_name = "The Chainsmokers";
                          printArtist(findArtistName(artistList, artist_name));
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


  //Read Linked-List into Updated CSV file
  traverseList = artistList->first;

  while(traverseList != nullptr){
    ioFile << traverseList->artist->artist_id;
    ioFile << ",";
    
    ioFile << traverseList->artist->artist_name;
    ioFile << ",";
    
    ioFile << traverseList->artist->total_followers;
    ioFile << ",";
    
  
    for(int i = 0; i < AR_LEN; i++){
      ioFile << genres[i];
    }
    ioFile << "],";
    
    ioFile << traverseList->artist->popularity;
    ioFile << "\n";
    
    traverseList = traverseList->next;
  }
  ioFile.close();

  deleteArtistList(artistList);
  artistList = nullptr;
  
  return 0;
}