#include "decoding/album.h"
#include <filesystem>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

Song &Album::getSong(int i)
{
    if (i >= 0 && i < list.size())
    {
        return list[i];
    }
    throw std::out_of_range("Index out of range");
}

int Album::getSize()
{
    return list.size();
}

void Album::add_track(const Song &track)
{
    list.push_back(track);
}

void Album::delete_track(const Song &track)
{
    list.erase(std::remove(list.begin(), list.end(), track), list.end());
}

void Album::getMusicFiles(const std::string &directory)
{
    list.clear();
    std::string extension, buf;
    for (const auto &entry : fs::directory_iterator(directory))
    {
        if (entry.is_regular_file())
        {
        }
        extension = entry.path().extension().string();
        if (extension == ".ogg" || extension == ".flac")
        { // здесь указываем расширения, с которыми будет работать наш плеер
            Song track;
            track.set_name(entry.path().stem().string());
            // std::cout<<entry.path().string();
            track.set_path(entry.path().string());
            // std::cout<<track.get_path()+"\n";
            list.push_back(track);
        }
    }
}

std::vector<Song> Album::getList()
{
    return list;
}
