#include "settings.h"
#include <cstring>

Settings *Settings::_instance = 0;

Settings::Settings()
{
    memset(&_data, 0, sizeof(_data));
    _fileName = "Dump.dsf";
}

Settings::~Settings()
{
    if (_file.is_open())
        _file.close();
}

Settings *Settings::Create()
{
    if (!_instance)
        _instance = new Settings;
    return _instance;
}

void Settings::Destroy()
{
    delete _instance;
    _instance = 0;
}

bool Settings::Load()
{
    _file.open(_fileName.c_str(), std::ios_base::in);
    if (!_file.is_open())
        return false;

    _file.read((char*)&_data, sizeof(_data));
    _file.close();

    return AreLoaded();
}

bool Settings::Save()
{
    strncpy(_data.magic, SETTINGS_MAGIC, sizeof(_data.magic));

    _file.open(_fileName.c_str(), std::ios_base::out);
    if (!_file.is_open())
        return false;
    _file.write((char*)&_data, sizeof(_data));
    _file.close();
    return true;
}

bool Settings::AreLoaded()
{
    return (strcmp(_data.magic, SETTINGS_MAGIC) ? false : true);
}

void Settings::SetToDefaults()
{
    strncpy(_data.magic, SETTINGS_MAGIC, sizeof(_data.magic));
    _data.width = 800;
    _data.height = 600;
    _data.fullscreen = false;
}

void Settings::SetResolution(int width, int height)
{
    _data.width = width;
    _data.height = height;
}
