#include "../src/model.h"
#include <catch.h>

TEST_CASE("next_word")
{
    Model model{"word1", "word2"};
    CHECK( model.next_word() == "word1");
    CHECK( model.next_word() == "word2");
    CHECK( model.next_word().empty());
}

//TEST_CASE("create_bubbles get_bubbles")
//{
//    Model model;
//    model.create_bubbles("hi",{100,100},5);
//	std::vector<Bubble> bubbles=model.get_bubbles();
//	CHECK( bubbles.size() == 2);
//	CHECK( bubbles[0].letter == 'h');
//	CHECK( bubbles[0].position.x == 100);
//	CHECK( bubbles[0].position.y == 100);
//	CHECK( bubbles[0].state == Bubble::State::pending);
//	CHECK( bubbles[1].letter == 'i');
//	CHECK( bubbles[1].position.x == 105);
//	CHECK( bubbles[1].position.y == 100);
//	CHECK( bubbles[1].state == Bubble::State::pending);
//}
//
//TEST_CASE("hit_key-hit")
//{
//    Model model;
//    model.create_bubbles("hi",{100,100},5);
//	std::vector<Bubble> bubbles=model.get_bubbles();
//	CHECK( bubbles[0].state == Bubble::State::pending);
//	CHECK( bubbles[1].state == Bubble::State::pending);
//	model.hit_key('h');
//	bubbles=model.get_bubbles();
//	CHECK( bubbles[0].state == Bubble::State::done);
//	CHECK( bubbles[1].state == Bubble::State::pending);
//	model.hit_key('i');
//	bubbles=model.get_bubbles();
//	CHECK( bubbles[0].state == Bubble::State::done);
//	CHECK( bubbles[1].state == Bubble::State::done);
//}
//
//TEST_CASE("hit_key-miss")
//{
//    Model model;
//    model.create_bubbles("hi",{100,100},5);
//	std::vector<Bubble> bubbles=model.get_bubbles();
//	CHECK( bubbles[0].state == Bubble::State::pending);
//	CHECK( bubbles[1].state == Bubble::State::pending);
//	model.hit_key('n');
//	bubbles=model.get_bubbles();
//	CHECK( bubbles[0].state == Bubble::State::missed);
//	CHECK( bubbles[1].state == Bubble::State::pending);
//	model.hit_key('o');
//	bubbles=model.get_bubbles();
//	CHECK( bubbles[0].state == Bubble::State::missed);
//	CHECK( bubbles[1].state == Bubble::State::missed);
//}
//
//TEST_CASE("first_pending")
//{
//    Model model;
//    model.create_bubbles("hi",{100,100},5);
//	std::vector<Bubble> bubbles=model.get_bubbles();
//	CHECK(model.first_pending_(bubbles)==0);
//	model.hit_key('n');
//	bubbles=model.get_bubbles();
//	CHECK(model.first_pending_(bubbles)==1);
//	model.hit_key('o');
//	bubbles=model.get_bubbles();
//	CHECK(model.first_pending_(bubbles)==2);
//}
//
//TEST_CASE("is_finished")
//{
//    Model model;
//    model.create_bubbles("hi",{100,100},5);
//	model.hit_key('h');
//	model.hit_key('i');
//	CHECK(model.is_finished());
//}

