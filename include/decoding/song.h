// объявление класса и методов песни, мб здесь кстати заюзать шаблонный метод, чекай переписку гпт(т.е. использовать здесь перегруженный метод плей от разных классов типа mp3song wavsong flacsong), опционально добавить закладки(мне для этого отдельный список надо будет реализовать)
#include <string>
#include <SFML/Audio.hpp>
class Song{
    sf::Music music;
    std::string name;
    bool isPlaying;
public:
    Song();
    Song(const std::string &name_);
    Song(const Song &track);

   Song operator=(const Song &track);
   bool operator==(const Song &track);

    bool get_status();
    void set_name(const std::string &name_);
    std::string get_name();
    bool empty();


    void playback();
    void pause();
};