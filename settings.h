//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_SETTINGS_H
#define SNAKE_SETTINGS_H

#define DEFAULT_ROWS 9
#define DEFAULT_COLUMNS 9
#define DEFAULT_GROWTH_LEN 4
#define DEFAULT_TICK_DELAY_MS 200
#define DEFAULT_WALLS_EXIST false
#define DEFAULT_WRAP_BOARD true
#define DEFAULT_START_LENGHT 5;

class Settings {
private:
    int columns;

    int rows;

    int growthLen;

    int tickDelayMs;

    bool wallsExist;

    bool wrapBoard;

    int startLength;

    Settings();
public:
    bool getWallsExist() const;

    void setWallsExist(bool walls);

    bool isWrapBoard() const;

    void setWrapBoard(bool wrapBoard);

    int getColumns() const;

    void setColumns(int columns);

    int getRows() const;

    void setRows(int rows);

    int getGrowthLen() const;

    void setGrowthLen(int growthLen);

    int getTickDelayMs() const;

    void setTickDelayMs(int tickDelayMs);

    int getStartLength() const;

    void setStartLength(int startLength);

    static Settings &getSettings();
};


#endif //SNAKE_SETTINGS_H
