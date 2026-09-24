//
// Created by Iv123 on 9/22/2026.
//

#ifndef CS210_ASSIGNMENT3_LAB_PDF_DATA_H
#define CS210_ASSIGNMENT3_LAB_PDF_DATA_H

#pragma once
#include <ostream>
#include <string>

class Data {
    public:
        Data(int numID, const std::string& name)
            :numID_(numID), name_(name){}

        bool operator==(const Data& other)const {
            return numID_ == other.numID_;
        }

        friend std::ostream& operator<<(std::ostream& out, const Data& d) {
            return out << d.numID_ << " " << d.name_;
        }
    private:
        int numID_;
        std::string name_;
    };

#endif //CS210_ASSIGNMENT3_LAB_PDF_DATA_H
