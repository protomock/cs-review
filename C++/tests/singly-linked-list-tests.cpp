#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../singly-linked-list.cpp"

SinglyLinkedList<int> *sll = new SinglyLinkedList<int>();

TEST_CASE( "InsertInFront", "[insertInFront]" ) {
    Node<int> *nodeToInsert = new Node<int>(1);
    SECTION("should insert correctly") {
        sll->InsertInFront(nodeToInsert);
        REQUIRE(sll->getHead() == nodeToInsert);
        REQUIRE(sll->getTail() == nodeToInsert);
    }

    SECTION("should set HEAD and TAIL correctly") {
        sll->DeleteAll();
        sll->InsertInFront(nodeToInsert);

        Node<int> *newNode = new Node<int>(2);
        sll->InsertInFront(newNode);
        REQUIRE(sll->getHead() == newNode);
        REQUIRE(sll->getTail() == nodeToInsert);
    }
}

TEST_CASE( "DeleteAll", "[removeAll]" ) {
    sll->DeleteAll();
    sll->InsertInFront(new Node<int>(2));
    REQUIRE(sll->getHead()->value() == 2 );

    SECTION("when linked list has no elements") {
        sll->DeleteAll();
        REQUIRE(sll->getHead() == NULL);
        REQUIRE(sll->getTail() == NULL);
    }
}

TEST_CASE( "DeleteFirst", "[DeleteFirst]" ) {
    SECTION("when linked list has no elements") {
        REQUIRE(!sll->DeleteFirst());
    }

    SECTION("when linked list has 1 element") {
        sll->InsertInFront(new Node<int>(2));
        REQUIRE(sll->DeleteFirst());
        REQUIRE(sll->getHead() == NULL);
        REQUIRE(sll->getTail() == NULL);
    }
    SECTION("when linked list has 2 elements") {
        sll->InsertInFront(new Node<int>(1));
        sll->InsertInFront(new Node<int>(23));
        REQUIRE(sll->DeleteFirst());
        REQUIRE(sll->getHead()->value() == 1);
        REQUIRE(sll->getTail()->value() == 1);
        REQUIRE(sll->DeleteFirst());
    }
}

TEST_CASE( "Delete", "[delete]" ) {
    SECTION("when linked list has no elements") {
        REQUIRE(sll->getHead() == NULL);
        REQUIRE(sll->getTail() == NULL);
        REQUIRE(!sll->Delete(new Node<int>(1)));
    }
    SECTION("when delete is called with NULL") {
        REQUIRE(!sll->Delete(NULL));
    }
    SECTION("when delete is has 1 element") {
        Node<int> *nodeToDelete = new Node<int>(45);
        SECTION("when element is IN the list") {
            sll->InsertInFront(nodeToDelete);
            REQUIRE(sll->getHead() == nodeToDelete);
            REQUIRE(sll->getTail() == nodeToDelete);

            REQUIRE(sll->Delete(nodeToDelete));
            REQUIRE(sll->getHead() == NULL);
            REQUIRE(sll->getTail() == NULL);
        }
         SECTION("when element is NOT IN the list") {
            sll->InsertInFront(nodeToDelete);
            REQUIRE(sll->getHead() == nodeToDelete);
            REQUIRE(sll->getTail() == nodeToDelete);
            
            REQUIRE(!sll->Delete(new Node<int>(3)));
            REQUIRE(sll->getHead() == nodeToDelete);
            REQUIRE(sll->getTail() == nodeToDelete); 
        }
    }
}

TEST_CASE( "InsertAfter", "[insertAfter]" ) {
    SECTION("when linked list has no elements") {
        sll->DeleteAll();
        REQUIRE(sll->getHead() == NULL);
        REQUIRE(sll->getTail() == NULL);
        REQUIRE(!sll->InsertAfter(new Node<int>(2), 1));
    }
    SECTION("when InsertAfter is called with NULL element") {
        REQUIRE(!sll->InsertAfter(NULL, 1));
    }
    SECTION("when linked list has 1 element") {
        Node<int> *nodeToInsertAfter = new Node<int>(45);
        sll->InsertInFront(nodeToInsertAfter);
        
        SECTION("when element is IN the list") {
            REQUIRE(sll->getHead() == nodeToInsertAfter);
            REQUIRE(sll->getTail() == nodeToInsertAfter);

            REQUIRE(sll->InsertAfter(nodeToInsertAfter, 2));
            REQUIRE(sll->getHead() == nodeToInsertAfter);
            REQUIRE(sll->getTail()->value() == 2);
        }
        SECTION("when element is NOT IN the list") {
            sll->DeleteAll();
            nodeToInsertAfter = new Node<int>(12);
            sll->InsertInFront(nodeToInsertAfter);
            REQUIRE(sll->getHead() == nodeToInsertAfter);
            REQUIRE(sll->getTail() == nodeToInsertAfter);
            
            REQUIRE(!sll->InsertAfter(new Node<int>(3), 2));
            REQUIRE(sll->getHead() == nodeToInsertAfter);
            REQUIRE(sll->getTail() == nodeToInsertAfter); 
        }
    }
      SECTION("when linked list is has 2 element") {
        sll->DeleteAll();
        Node<int> *nodeToInsertAfter = new Node<int>(45);
        Node<int> *nodeToInsertAfter2 = new Node<int>(123);
        sll->InsertInFront(nodeToInsertAfter);
        sll->InsertInFront(nodeToInsertAfter2);
        
        SECTION("when element is to insert after is the head") {
            REQUIRE(sll->getHead() == nodeToInsertAfter2);
            REQUIRE(sll->getTail() == nodeToInsertAfter);

            REQUIRE(sll->InsertAfter(sll->getHead(), 2));
            REQUIRE(sll->getHead() == nodeToInsertAfter2);
            REQUIRE(sll->getHead()->getNext()->value() == 2);
            REQUIRE(sll->getTail() == nodeToInsertAfter);
        }
        SECTION("when element is to insert after is the tail") {
            sll->DeleteAll();
            nodeToInsertAfter = new Node<int>(12);
            nodeToInsertAfter2 = new Node<int>(567);
            sll->InsertInFront(nodeToInsertAfter);
            sll->InsertInFront(nodeToInsertAfter2);
            REQUIRE(sll->getHead() == nodeToInsertAfter2);
            REQUIRE(sll->getTail() == nodeToInsertAfter);
            
            REQUIRE(sll->InsertAfter(sll->getTail(), 133));
            REQUIRE(sll->getHead() == nodeToInsertAfter2);
            REQUIRE(sll->getHead()->getNext() == nodeToInsertAfter);
            REQUIRE(sll->getTail()->value() == 133);
        }
    }
}