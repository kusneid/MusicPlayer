//объявление класса и методов альбома
#pragma once

#include "song.h"
#include <vector>

class Album{
private:
    std::vector <Song> list;
public:
    Song &getSong(int i);
    int getSize();

    void add_track(const Song &track);
    void delete_track(const Song &track);

    void getMusicFiles(const std::string &directory);


    std::vector<Song> getList();
};