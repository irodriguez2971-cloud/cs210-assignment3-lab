//
// Created by Iv123 on 10/11/2026.
//

#ifndef CS210_ASSIGNMENT3_LAB_PDF_CARD_H
#define CS210_ASSIGNMENT3_LAB_PDF_CARD_H

#pragma once

#include <iostream>
#include <string>

class Card {
    public:
        Card(const std::string& color, const std::string& rank)
            : color_(color), rank_(rank) {}

    friend std::ostream& operator<< (std::ostream& out, const Card& card) {
            return out << card.color_ << " " << card.rank_;
        }

    private:
    std::string color_;
    std::string rank_;
};



#endif //CS210_ASSIGNMENT3_LAB_PDF_CARD_H
