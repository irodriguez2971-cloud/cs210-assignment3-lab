#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----

    std::cout << std::endl << "== Uno turn order ==" << std::endl;

    std::unique_ptr<List<Player>> table = makeList<Player>();

    std::cout << "Players join the table:" <<std::endl;
    table ->addFront(new Player(1, "BobbyBoy"));
    table->addFront(new Player(2, "Fortnite"));
    table->addFront(new Player(3, "John"));

    table->print();

    std::cout<< "Diana joins in the middle: " << std::endl;
    table->addAnywhere(1, new Player(4, "Diana"));
    table->print();

    std::cout << "Reverse Card played: " << std::endl;
    std::cout << "Before Reverse Card played: " << std::endl;
    table->print();

    table->reverse();

    std::cout << "After Reverse Card played: " << std::endl;
    table->print();

    std::cout<< "Diana leaves: " << std::endl;
    table->deleteAnywhere(2);
    table->print();

    std::unique_ptr<List<Player>> secondTable = makeList<Player>();

    std::cout << "Second table before combining it:" <<std::endl;
    secondTable->addFront(new Player(5, "LebronRaymondJames"));
    secondTable->addFront(new Player(6, "Spiderman"));
    secondTable->print();

    std::cout << "Merge tables" << std::endl;
    table->concat(secondTable.get());

    std::cout << "First table after combining." << std::endl;
    table->print();

    std::cout << "Second table after combining." << std::endl;
    secondTable->print();

    return 0;
}
