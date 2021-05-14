#include "../src/model.hxx"
#include <catch.hxx>

TEST_CASE("current_word")
{
    Model model {"word1", "word2"};
    CHECK(model.current_word() == "word1");
}

TEST_CASE("lowercase")
{
    Model model {"WoRd"};
    CHECK(model.current_word() == "word");
}

TEST_CASE("hit_key")
{
    Model model {"hi", "no"};

    CHECK(model.current_word() == "hi");

    model.hit_key('h');
    model.hit_key('i');
    CHECK(model.current_word() == "no");
}

TEST_CASE("game_is_finished")
{
    Model model {"hi", "no"};
    model.hit_key('h');
    model.hit_key('i');
    model.hit_key('n');
    model.hit_key('o');
    CHECK(model.game_is_finished());
}

TEST_CASE("typing_progress")
{
    using O = Model::Letter_outcome;

    Model model {"hello", "bye"};

    auto actual = [&] { return model.typing_progress(); };
    auto expected = actual();

    expected.push_back(O::correct);
    model.hit_key('h');
    CHECK(actual() == expected);

    expected.push_back(O::incorrect);
    model.on_frame(0.1 * model.seconds_remaining());
    model.hit_key('p');
    CHECK(actual() == expected);

    expected.push_back(O::missed);
    model.on_frame(1.5 * model.seconds_remaining());
    CHECK(actual() == expected);

    expected.push_back(O::correct);
    model.hit_key('l');
    CHECK(actual() == expected);

    expected.clear();
    model.hit_key('o');
    CHECK(actual() == expected);
}
