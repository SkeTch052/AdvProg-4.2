#pragma once
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "ListFunc.cpp"
#include <iostream>
#include <exception>

TEST_CASE("list testing", "[Push and Pop]") {
    List list;
    SECTION("PushBack() and PopBack()") {
        list.PushBack(1); list.PushBack(2); list.PushBack(3);
        CHECK(list.Size() == 3);
        CHECK(list.PopBack() == 3);
    }
    SECTION("PushFront() and PopFront()") {
        list.PushFront(4); list.PushFront(5); list.PushFront(6);
        CHECK(list.Size() == 3);
        CHECK(list.PopFront() == 6);
    }
}

TEST_CASE("list testing", "[Pop if list is clear]") {
    List list;
    CHECK_THROWS_AS(list.PopBack(), std::runtime_error);
    CHECK_THROWS_AS(list.PopFront(), std::runtime_error);
}

SCENARIO("list full test") {
    GIVEN("An empty list") {
        List list;
        THEN("The size start at 0") {
            REQUIRE(list.Size() == 0);
        }

        WHEN("PushBack() some values") {
            list.PushBack(100); list.PushBack(200); list.PushBack(300);
            THEN("The size changes") {
                REQUIRE(list.Size() == 3);
            }
            AND_THEN("PopBack() should be equal to the last added value (300)") {
                REQUIRE(list.PopBack() == 300);
            }
        }

        WHEN("PushFront() some values") {
            list.PushFront(400); list.PushFront(500);
            THEN("The size changes") {
                REQUIRE(list.Size() == 2);
            }
            AND_THEN("PopFront() should be equal to the last added value (500)") {
                REQUIRE(list.PopFront() == 500);
            }
        }

        WHEN("Clear() and Empty()") {
            list.Clear();
            THEN("The list should be empty") {
                REQUIRE(list.Empty() == 1);
            }
        }
    }
}

int main() {
	return Catch::Session().run();
}