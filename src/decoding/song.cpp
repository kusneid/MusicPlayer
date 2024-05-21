#include "decoding/song.h"

#include <SFML/Audio.hpp>
#include <iostream>

Song::Song() : isPlaying(false), name(""), path("") {}

Song::Song(const std::string &name_) : isPlaying(false), name(name_), path("") {}

Song::Song(const Song &track) : name(track.name), path(track.path), isPlaying(track.isPlaying) {}

Song &Song::operator=(const Song &track) {
    if (this != &track) {
        name = track.name;
        path = track.path;
        isPlaying = track.isPlaying;
    }
    return *this;
}

bool Song::operator==(const Song &track) const {
    return (name == track.name && path == track.path);
}

bool Song::get_status() const {
    return isPlaying;
}
std::string Song::get_name() const {
    return name;
}
sf::Time Song::get_current_time() {
    return music.getPlayingOffset();
}

void Song::set_name(const std::string &name_) {
    name = name_;
}
void Song::set_path(const std::string &path_) {
    path = path_;
}

std::string Song::get_path() const {
    return path;
}


bool Song::empty() const {
    return name.empty();
}

void Song::playback(sf::Time current_time) {
    if (!music.openFromFile(path)) {
        std::cout << "Song not found!\n";
        return;
    }
    music.setPlayingOffset(current_time);
    std::cout << "Playing offset set to: " <<music.getPlayingOffset().asSeconds() << " seconds " << music.getDuration().asSeconds()<< std::endl;
    music.play();
    std::cout << "Playing offset set to: " <<music.getPlayingOffset().asSeconds() << " seconds " << music.getDuration().asSeconds()<< std::endl;
    isPlaying = true;
}

void Song::pause() {
    music.pause();
    isPlaying = false;
}

sf::Music &Song::get_sfMusic() {
    return music;
}