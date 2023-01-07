#include "json.h"

Json::Json(std::string json_str, int w) : json_str_(json_str), fmt_(false), w_(w) {}
Json::Json() : Json("", 0) {}

void Json::readJson(std::string json_str, int w)
{

    try
    {
        if (w == 0)
        {
            json_str_ = json_str;
            w_ = w;
        }
        else if (w == 1)
        {
            std::ifstream file;
            file.open(json_str);
            std::ostringstream buf;
            char ch;
            while (file.get(ch))
            {
                buf.put(ch);
            }
            json_str_ = buf.str();
        }
        else {
            throw W_ERROR;
        }
    }
    catch(std::string s) {
        std::cout<< s <<std::endl;
    }
    catch(...) {
        std::cout<< "Other ERRORS" << std::endl;
    }
}
bool Json::writeJson(std::string des_str, int w = 0) {
    try {
        if (w == 0)
        {
            des_str = json_str_;
            return true;
        }
        else if (w == 1)
        {
            std::ofstream file;
            file.open(des_str);
            file<< json_str_;
        }
        else {
            throw W_ERROR;
        }

    }
    catch(std::string s) {
        std::cout<<s<<std::endl;
        return false;
    }
    catch(...) {
        std::cout<<"Write with unknown error"<<std::endl;
        return false;
    }
}
void Json::fmt_json() {
    try {
        int level = 0;
        for (int i = 0; i < json_str_.length(); i ++) {
            char c = json_str_[i];
            switch (c)
            {
            case '{':
            case '[':
                json_str_ = json_str_ + c + '\n';
                level ++;
                for (int j = 0; j < level; j++) {
                    json_str_ += '/t';
                }
                break;
            case ',':
                json_str_ = json_str_ + c + '\n';
                for (int j = 0; j < level; j++) {
                    json_str_ += '/t';
                }
            case '}':
            case ']':
                level --;
                for (int j = 0; j < level; j++) {
                    json_str_ += '/t';
                }
                json_str_ += c;
                break;

            default:
                json_str_ += c;
                break;
            }
        }
    
    
        fmt_ = true;
    }
    catch(...) {
        std::cout << "Can't parse the json" <<std::endl;
    }

}

