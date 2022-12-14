/*
  Author: Samual van Daal
  Date: 12/6/2022
  
 */

#include <iostream>
#include <cstring>
#include "media.h"
#include "vg.h"
#include "music.h"
#include "movies.h"
#include <vector>

using namespace std;

int main() {
  vector<Media*> database;
  char input[80];
  int type;
  char title[80];
  int year;
  char publisher[80];
  float rating;
  char artist[80];
  int duration;
  char director[80];
  //
  while(true) { // Main Loop
    cin.clear();
    cout << "Do you want to ADD, SEARCH, DELETE, or QUIT?" << endl;
    cin.get(input, 80);
    cin.ignore(10, '\n');
    if (input[0] == 'A' && input[1] == 'D' && input[2] == 'D') {
      cout << "Do you want to add a video game(1), song(2), or movie(3)?" << endl;
      cin >> type;
      cin.ignore(10, '\n');
      if (type == 1) { // Video Game Add
	cout << "What is the title of the game?" << endl;
	cin.get(title, 80);
	cin.ignore(10, '\n');
	cout << "What year did it come out?" << endl;
	cin >> year;
	cin.ignore(10, '\n');
	cout << "Who published the game?" << endl;
	cin.get(publisher, 80);
	cin.ignore(10, '\n');
	cout << "What is the games rating? (x.x / 10)" << endl;
	cin >> rating;
	cin.ignore(10, '\n');
	database.push_back(new VG(type, title, year, publisher, rating));
	cout << "Added to the database!" << endl;
      }
      else if (type == 2) { // Song Add
	cout << "What is the title of the song?" << endl;
	cin.get(title, 80);
	cin.ignore(10, '\n');
	cout << "Who's the artist of the song?" << endl;
	cin.get(artist, 80);
	cin.ignore(10, '\n');
	cout << "What year did it come out?" << endl;
	cin >> year;
	cin.ignore(10, '\n');
	cout << "How long is the song? (in seconds)" << endl;
	cin >> duration;
	cin.ignore(10, '\n');
	cout << "Who published the song?" << endl;
	cin.get(publisher, 80);
	cin.ignore(10, '\n');
	database.push_back(new Music(type, title, year, publisher, duration, artist));
      }
      else if (type == 3) { // Movie Add
	cout << "What is the title of the movie?" << endl;
	cin.get(title, 80);
	cin.ignore(10, '\n');
	cout << "Who is the director?" << endl;
	cin.get(director, 80);
	cin.ignore(10, '\n');
	cout << "What year was it released?" << endl;
	cin >> year;
	cin.ignore(10, '\n');
	cout << "How long is it? (in minutes)" << endl;
	cin >> duration;
	cin.ignore(10, '\n');
	cout << "What is its rating? (_._ / 10)" << endl;
	cin >> rating;
	cin.ignore(10, '\n');
	database.push_back(new Movie(type, title, year, director, duration, rating));
      }
      else {

      }
    }
    else if (input[0] == 'S' && input[1] == 'E' && input[2] == 'A' && input[3] == 'R' && input[4] == 'C' && input[5] == 'H') {
      int choice;
      cout << "Search by title(1) or year(2)?" << endl;
      cin >> choice;
      cin.ignore(10, '\n');
      if (choice == 1) { // Search by Title
	cout << "Keyword: ";
	char keyword[80];
	cin.get(keyword, 80);
	cin.ignore(10, '\n');
	vector<Media*>::iterator itr;
	cout << "- - - - - - - -" << endl;
	for (itr = database.begin(); itr != database.end(); itr++) {
	  char* search;
	  search = strstr((*itr) -> getTitle(), keyword);
	  if (search != NULL) {
	    if ((*itr) -> getType() == 1) {
	      cout << endl;
	      VG* a = static_cast<VG*>(*itr);
	      cout << "Video Game, "
		   << (*itr) -> getTitle() << ", Release Date: "
		   << (*itr) -> getYear() << ", Publisher: "
		   << (a) -> getPublisher() << ", Rating: "
		   << (a) -> getRating() << endl;
	    }
	    else if ((*itr) -> getType() == 2) {
	      cout << endl;
	      Music* a = static_cast<Music*>(*itr);
              cout << "Song, "
                   << (*itr) -> getTitle() << ", Artist: "
		   << (a) -> getArtist() << ", Release Date: "
                   << (*itr) -> getYear() << ", Song Length: "
		   << (a) -> getDuration() << " seconds long, Publisher: "
                   << (a) -> getPublisher() << endl;
	    }
	     else if ((*itr) -> getType() == 3) {
              cout << endl;
              Movie* a = static_cast<Movie*>(*itr);
              cout << "Movie, "
                   << (*itr) -> getTitle() << ", Director: "
                   << (a) -> getDirector() << ", Release Date: "
                   << (*itr) -> getYear() << ", Song Length: "
                   << (a) -> getDuration() << " seconds long, Rating: "
                   << (a) -> getRating() << endl;
            }
	  }
	}
	cout << endl;
	cout << "- - - - - - - -" << endl;
      }
      else if (choice == 2) { // Search games by Year
	cout << "KeyDate: ";
	int keydate;
	cin >> keydate;
	cin.ignore(10, '\n');
	vector<Media*>::iterator itr;
	cout << "- - - - - - - -" << endl;
	for (itr = database.begin(); itr != database.end(); itr++) {
	  char* search;
	  if ((*itr) -> getYear() == keydate) {
	    if ((*itr) -> getType() == 1) {
	      cout << endl;
	      VG* a = static_cast<VG*>(*itr);
	      cout << "Video Game, "
		   << (*itr) -> getTitle() << ", Release Date: "
		   << (*itr) -> getYear() << ", Publisher: "
		   << (a) -> getPublisher() << ", Rating: "
		   << (a) -> getRating() << endl;
	    }
	    else if ((*itr) -> getType() == 2) {
              cout << endl;
              Music* a = static_cast<Music*>(*itr);
              cout << "Song, "
                   << (*itr) -> getTitle() << ", Artist: "
                   << (a) -> getArtist() << ", Release Date: "
                   << (*itr) -> getYear() << ", Song Length: "
                   << (a) -> getDuration() << " seconds long, Publisher: "
                   << (a) -> getPublisher() << endl;
            }
	    else if ((*itr) -> getType() == 3) {
              cout << endl;
              Movie* a = static_cast<Movie*>(*itr);
              cout << "Movie, "
                   << (*itr) -> getTitle() << ", Director: "
                   << (a) -> getDirector() << ", Release Date: "
                   << (*itr) -> getYear() << ", Song Length: "
                   << (a) -> getDuration() << " seconds long, Rating: "
                   << (a) -> getRating() << endl;
            }
	  }
	} 
	cout << endl;
	cout << "- - - - - - - -" << endl;
      }
    }
    else if (input[0] == 'D' && input[1] == 'E' && input[2] == 'L' && input[3] == 'E' && input[4] == 'T' && input[5] == 'E') {
      int choice;
      cout << "Do you want to delete by title(1) or year(2)" << endl;
      cin >> choice;
      cin.ignore(10, '\n');
      if (choice == 1) { // By title
	char keyword[80];
	cout << "Keyword: ";
	cin >> keyword;
	cin.ignore(10, '\n');
	int size = database.size();
	while (size > 0) {
	  vector<Media*>::iterator itr;
	  for (itr = database.begin(); itr != database.end(); itr++) {
	    size--;
	    char* search;
	    search = strstr((*itr) -> getTitle(), keyword);
	    if (search != NULL) {
	      cout << "About to Delete: ";
	      if ((*itr) -> getType() == 1) {
		cout << endl;
		VG* a = static_cast<VG*>(*itr);
		cout << "Video Game, "
		     << (*itr) -> getTitle() << ", Release Date: "
		     << (*itr) -> getYear() << ", Publisher: "
		     << (a) -> getPublisher() << ", Rating: "
		     << (a) -> getRating() << endl;
	      }
	      else if ((*itr) -> getType() == 2) {
		cout << endl;
		Music* a = static_cast<Music*>(*itr);
		cout << "Song, "
		     << (*itr) -> getTitle() << ", Artist: "
		     << (a) -> getArtist() << ", Release Date: "
		     << (*itr) -> getYear() << ", Song Length: "
		     << (a) -> getDuration() << " seconds long, Publisher: "
		     << (a) -> getPublisher() << endl;
	      }
	      else if ((*itr) -> getType() == 3) {
		cout << endl;
		Movie* a = static_cast<Movie*>(*itr);
		cout << "Movie, "
		     << (*itr) -> getTitle() << ", Director: "
		     << (a) -> getDirector() << ", Release Date: "
		     << (*itr) -> getYear() << ", Song Length: "
		     << (a) -> getDuration() << " seconds long, Rating: "
		     << (a) -> getRating() << endl;
	      }
	      else {
		cout << "ERROR" << endl;
	      }
	      cout << "Confirm Deletion? y/n" << endl;
	      char confirm[2];
	      cin.get(confirm, 2);
	      cin.ignore(10, '\n');
	      if (confirm[0] == 'y') {
		database.erase(itr);
		delete (*itr);
		break;
	      }
	      //cin.clear();
	    }
	  }
	}
      }
      if (choice == 2) { // By date
	int keydate;
	cout << "KeyDate: ";
	cin >> keydate;
	cin.ignore(10, '\n');
	int size = database.size();
	while (size > 0) {
	  vector<Media*>::iterator itr;
	  for (itr = database.begin(); itr != database.end(); itr++) {
	    size--;
	    int search;
	    if ((*itr) -> getYear() == keydate) {
	       cout << "About to Delete: ";
	       if ((*itr) -> getType() == 1) {
		 cout << endl;
		 VG* a = static_cast<VG*>(*itr);
		 cout << "Video Game, "
		      << (*itr) -> getTitle() << ", Release Date: "
		      << (*itr) -> getYear() << ", Publisher: "
		      << (a) -> getPublisher() << ", Rating: "
		      << (a) -> getRating() << endl;
	       }
	       else if ((*itr) -> getType() == 2) {
		 cout << endl;
		 Music* a = static_cast<Music*>(*itr);
		 cout << "Song, "
		      << (*itr) -> getTitle() << ", Artist: "
		      << (a) -> getArtist() << ", Release Date: "
		      << (*itr) -> getYear() << ", Song Length: "
		      << (a) -> getDuration() << " seconds long, Publisher: "
		      << (a) -> getPublisher() << endl;
	       }
	       else if ((*itr) -> getType() == 3) {
		 cout << endl;
		 Movie* a = static_cast<Movie*>(*itr);
		 cout << "Movie, "
		      << (*itr) -> getTitle() << ", Director: "
		      << (a) -> getDirector() << ", Release Date: "
		      << (*itr) -> getYear() << ", Song Length: "
		      << (a) -> getDuration() << " seconds long, Rating: "
		      << (a) -> getRating() << endl;
	       }
	       else {
		 cout << "ERROR" << endl;
	       }
	       cout << "Confirm Deletion? y/n" << endl;
	       char confirm[2];
	       cin.get(confirm, 2);
	       cin.ignore(10, '\n');
	       if (confirm[0] == 'y') {
		 database.erase(itr);
		 delete (*itr);
		 break;
	       }
	       //cin.clear();
	    }
	  }
	}
      }
    }
    else if (input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T' ) {
      return false;
    }
  }
}

