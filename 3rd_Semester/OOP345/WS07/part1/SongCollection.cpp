#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include "SongCollection.h"

using namespace std;
namespace sdds
{
	SongCollection::SongCollection(const char* filename) {
    Song song;
    string line;
    fstream file(filename);
    if (!file) {
      throw "Incorrect file name!";
    }
    while (!file.eof()) {
      getline(file, line, '\n');
      song.m_title = line.substr(0, 25);
      line = line.erase(0, 25);
      song.m_artist = line.substr(0, 25);
      line = line.erase(0, 25);
      song.m_album = line.substr(0, 25);
      line = line.erase(0, 25);

      try {
        song.m_year = stoi(line.substr(0, 5));
      }
      catch(...){
        song.m_year = 0;
      }
      line = line.erase(0, 5);

      song.m_length = stoi(line.substr(0, 5));
      line = line.erase(0, 5);
      song.m_price = stod(line.substr(0, 5));
      line = line.erase(0, 5);

      song.m_title.erase(0, song.m_title.find_first_not_of(' '));
      song.m_title.erase(song.m_title.find_last_not_of(' ') + 1);

      song.m_artist.erase(0, song.m_artist.find_first_not_of(' '));
      song.m_artist.erase(song.m_artist.find_last_not_of(' ') + 1);

      song.m_album.erase(0, song.m_album.find_first_not_of(' '));
      song.m_album.erase(song.m_album.find_last_not_of(' ') + 1);
      m_song.push_back(song);
    }
    file.close();
	}

	void SongCollection::display(std::ostream& out) const {
    for_each(m_song.begin(), m_song.end(), [&out](const Song& song) {out << song; });
	}

	ostream& operator<<(std::ostream& out, const Song& theSong) {
    out << "| " << left << setw(20) << theSong.m_title << " | " << left << setw(15) << theSong.m_artist;
    out << " | " << left << setw(20) << theSong.m_album << " | ";
    if (theSong.m_year == 0) {
      out << right << setw(6) << " ";
    }
    else {
      out << right << setw(6) << theSong.m_year;
    }
    out << " | " << theSong.m_length / 60 << ":" << setw(2) << setfill('0') << theSong.m_length % 60 << setfill(' ') << " | " << theSong.m_price << " |" << endl;
    return out;
	}
}