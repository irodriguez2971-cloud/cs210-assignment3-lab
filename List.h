//
// Created by Iv123 on 9/22/2026.
//

#ifndef CS210_ASSIGNMENT3_LAB_PDF_LIST_H
#define CS210_ASSIGNMENT3_LAB_PDF_LIST_H

#pragma once
#include <memory>



template <typename T>
class List {
    public:
        /*Virtual on each method picks the real version at run time,
         * ArrayList's or LinkList's, based on what the object really is.
         */
        virtual ~List() = default;

    /* = 0 makes each method pure virtual (just a signature). List has no body for
     * them, and can't be built on its own, only inherited from. That's what
     * makes it an ADT
     */
        virtual void addFront (T*value) = 0;
        virtual void deleteFront () = 0;
        virtual bool search (T*value) const = 0;
        virtual void print() const = 0;
        virtual void addAnywhere(int position, T* value) = 0;
        virtual void deleteAnywhere(int position) = 0;
        virtual void reverse() = 0;
        virtual void concat(List<T>* other) = 0;

};

#include "ArrayList.h"
#include "LinkedList.h"

template <typename T>
std:: unique_ptr<List<T>> makeList () {
    //return std::make_unique<LinkedList<T>>();
    return std::make_unique<ArrayList<T>>();
}

#endif //CS210_ASSIGNMENT3_LAB_PDF_LIST_H
