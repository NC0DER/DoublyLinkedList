#include <catch.hpp>
#include <DLL/LinkedList.h>

SCENARIO("Test Linked List") {
  GIVEN("An Linked List") {
    DLL::LinkedList <int> dll;
    WHEN("The Linked List is empty") {
      THEN("Test empty") {
        REQUIRE(dll.empty() == true);
      }
      THEN("Test length") {
        REQUIRE(dll.length() == 0);
      }
      THEN("Test search for a node that does not exist") {
        REQUIRE(dll.search(555) == -1);
      }
      THEN("Test remove"){
        REQUIRE(dll.remove(555) == -1);
      }
    }
    WHEN("The Linked List has one element") {
      dll.append(111);
      THEN("Test empty") {
        REQUIRE(dll.empty() == false);
      }
      THEN("Test length") {
        REQUIRE(dll.length() == 1);
      }
      THEN("Test search for a node that does not exist") {
        REQUIRE(dll.search(555) == 0);
      }
      THEN("Test search for a node that does exist") {
        REQUIRE(dll.search(111) == 1);
      }
      THEN("Test remove for a node that does not exist"){
        REQUIRE(dll.remove(555) == 0);
      }
      THEN("Test remove for a node that does exist") {
        REQUIRE(dll.search(111) == 1);
      }
    }
    WHEN("The Linked List has two elements") {
      dll.append(111);
      dll.append(10);
      THEN("Test empty") {
        REQUIRE(dll.empty() == false);
      }
      THEN("Test length") {
        REQUIRE(dll.length() == 2);
      }
      THEN("Test search for a node that does not exist") {
        REQUIRE(dll.search(555) == 0);
      }
      THEN("Test search for nodes that do exist") {
        REQUIRE(dll.search(10) == 1);
        REQUIRE(dll.search(111) == 1);
      }
      THEN("Test remove for a node that does not exist"){
        REQUIRE(dll.remove(555) == 0);
      }
      THEN("Test remove for nodes that do exist"){
        REQUIRE(dll.remove(10) == 1);
        REQUIRE(dll.remove(111) == 1);
      }
    }
    WHEN("The Linked List has three elements") {
      dll.append(111);
      dll.append(10);
      dll.append(6);
      THEN("Test empty") {
        REQUIRE(dll.empty() == false);
      }
      THEN("Test length") {
        REQUIRE(dll.length() == 3);
      }
      THEN("Test search for a node that does not exist") {
        REQUIRE(dll.search(555) == 0);
      }
      THEN("Test search for nodes that do exist") {
        REQUIRE(dll.search(10) == 1);
        REQUIRE(dll.search(111) == 1);
        REQUIRE(dll.search(6) == 1);
      }
      THEN("Test remove for a node that does not exist") {
        REQUIRE(dll.remove(555) == 0);
      }
      THEN("Test remove for nodes that do exist") {
        REQUIRE(dll.remove(10) == 1);
        REQUIRE(dll.remove(111) == 1);
        REQUIRE(dll.remove(6) == 1);
      }
    }
    WHEN("The Linked List has more than three elements") {
      for (int i = 0; i < 10; ++i) {
        dll.append(i);
      }
      THEN("Test empty") {
        REQUIRE(dll.empty() == false);
      }
      THEN("Test length") {
        REQUIRE(dll.length() == 10);
      }
      THEN("Test search for a node that does not exist") {
        REQUIRE(dll.search(555) == 0);
      }
      THEN("Test search for nodes that do exist") {
        for (int i = 0; i < 10; ++i) {
          REQUIRE(dll.search(i) == 1);
        }
      }
      THEN("Test remove for a node that does not exist") {
        REQUIRE(dll.remove(555) == 0);
      }
      THEN("Test remove for nodes that do exist") {
        for (int i = 0; i < 10; ++i) {
          REQUIRE(dll.remove(i) == 1);
        }
      }
    }
  }
}
