#include "decoding/album.h"
#include <filesystem>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

Song &Album::getSong(int i) {
    if (i < list.size()){
        return list[i];
    }
}
int Album::getSize() {
    return list.size();
}

void Album::add_track(const Song &track) {
    list.push_back(track);
}
void Album::delete_track(const Song &track) {
    list.erase(std::remove(list.begin(), list.end(), track), list.end());
}

void Album::getMusicFiles(const std::string &directory) {
    int i = 0;
    Song track;
    std::string extension, buf;
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            extension = entry.path().extension().string();
            if (extension == ".ogg" || extension == ".flac") { // здесь указываем расширения, с которыми будет работать наш плеер
                buf = entry.path().string().substr(0,size(entry.path().string()) - size(extension));
                track.set_name(buf.substr(size(directory) + 1));
                list.push_back(track);
            }
        }
    }
}

std::vector<Song> Album::getList(){
    return list;
}