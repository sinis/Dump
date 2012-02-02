#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <fstream>
#include <string>

#define SETTINGS_MAGIC "DSF"

struct SettingsData
{
    char magic[4]; // "DSF"
    int width;
    int height;
    bool fullscreen;
};

class Settings
{
    Settings();
    ~Settings();
public:
    static Settings *Create();
    static void Destroy();
    static Settings *GetInstance() { return _instance; }

    bool Load();
    bool Save();
    bool AreLoaded();
    void SetToDefaults();

    int GetScreenWidth() { return _data.width; }
    int GetScreenHeight() { return _data.height; }
    bool IsFullscreen() { return _data.fullscreen; }
    void SetResolution(int width, int height);
    void SetFullscreen(bool fullscreen) { _data.fullscreen = fullscreen; }

private:
    static Settings *_instance;
    SettingsData _data;
    std::string _fileName;
    std::fstream _file;
};

#endif // _SETTINGS_H_
