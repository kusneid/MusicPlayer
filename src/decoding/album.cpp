#include "decoding/album.h"
#include "org/additional.h"

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
    std::string extension;
    for (const auto &entry : std::filesystem::directory_iterator(directory))
    {
        extension = entry.path().extension().string();
        if (extension == ".ogg" || extension == ".flac") {
            Song track;
            std::string path = entry.path().string();
            std::replace(path.begin(), path.end(), '\\', '/');
            track.set_path(path);
            track.set_name(entry.path().stem().string());
            list.push_back(track);
        }
    }


}

std::vector<Song> Album::getList()
{
    return list;
}
