#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#define W_ERROR "para w_ should be 0 (from string) or 1(from file)"


class Json {
private:
    std::string json_str_;
    int w_;// 0 from string, 1 from file
    bool fmt_;
public:
    Json();
    Json(std::string json_str, int w = 0);
    void readJson(std::string json_str, int w = 0);
    bool writeJson(std::string des_str, int w = 0);
    void fmt_json();
};