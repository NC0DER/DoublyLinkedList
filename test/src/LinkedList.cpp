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
        auto result = dll.search(555);
        REQUIRE(result == -1);
      }
    }
  }
}