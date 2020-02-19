#include "../src/model.hxx"
#include <catch.hxx>

TEST_CASE("current_word")
{
    Model model{"word1", "word2"};
    CHECK( model.current_word() == "word1");
}

TEST_CASE("hit_key")
{
    Model model{"hi", "no"};
    CHECK( model.current_word() == "hi");
    model.hit_key('h');
    model.hit_key('i');
    CHECK( model.current_word() == "no");
}

TEST_CASE("game_is_finished")
{
    Model model{"hi", "no"};
    model.hit_key('h');
    model.hit_key('i');
    model.hit_key('n');
    model.hit_key('o');
    CHECK( model.game_is_finished());
}

TEST_CASE("typing_progress")
{
    Model model{"hello", "bye"};
    model.hit_key('h');
    std::vector<bool>  progress = model.typing_progress();
    CHECK( progress.size() == 1 );
    CHECK( progress[0] );
    model.hit_key('p');
    progress = model.typing_progress();
    CHECK( progress.size() == 2 );
    CHECK( progress[0] );
    CHECK( !progress[1] );
    model.hit_key('l');
    model.hit_key('l');
    progress = model.typing_progress();
    CHECK( progress.size() == 4 );
    CHECK( progress[0] );
    CHECK( !progress[1] );
    CHECK( progress[2] );
    CHECK( progress[2] );
    model.hit_key('o');
    progress = model.typing_progress();
    CHECK( progress.size() == 0 );    
} 
