//
// Created by cyryl on 29.11.19.
//

#include "settings.h"

int Settings::getRows() const {
    return rows;
}

void Settings::setRows(int rows) {
    Settings::rows = rows;
}

int Settings::getColumns() const {
    return columns;
}

void Settings::setColumns(int columns) {
    Settings::columns = columns;
}

int Settings::getGrowthLen() const {
    return growthLen;
}

void Settings::setGrowthLen(int growthLen) {
    Settings::growthLen = growthLen;
}

int Settings::getTickDelayMs() const {
    return tickDelayMs;
}

void Settings::setTickDelayMs(int tickDelayMs) {
    Settings::tickDelayMs = tickDelayMs;
}

bool Settings::getWallsExist() const {
    return wallsExist;
}

void Settings::setWallsExist(bool walls) {
    Settings::wallsExist = walls;
}

bool Settings::isWrapBoard() const {
    return wrapBoard;
}

void Settings::setWrapBoard(bool wrapBoard) {
    Settings::wrapBoard = wrapBoard;
}

Settings &Settings::getSettings() {
    static Settings instance = Settings();
    return instance;
}

Settings::Settings() {
    columns = DEFAULT_COLUMNS;
    rows = DEFAULT_ROWS;
    wallsExist = DEFAULT_WALLS_EXIST;
    wrapBoard = DEFAULT_WRAP_BOARD;
    tickDelayMs = DEFAULT_TICK_DELAY_MS;
    growthLen = DEFAULT_GROWTH_LEN;
    startLength = DEFAULT_START_LENGTH;
}

int Settings::getStartLength() const {
    return startLength;
}

void Settings::setStartLength(int startLength) {
    Settings::startLength = startLength;
}
