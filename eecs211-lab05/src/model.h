#pragma once

#include <ge211.h>

int const letter_delay = 2;
ge211::Dimensions const scene_dimensions{1024, 768};

enum class State{pending, missed, done}; 

struct Model
{
	///
	/// Constructors
	///
	Model();
	explicit Model(const std::vector<std::string>& words);

    private:
		///
		/// Private member variables
		///        
		std::string current_word;
		std::vector<State> word_state;
        std::vector<std::string> words;
        double last_update = 0;
        size_t word_count = 0;
		///
		/// Private member functions
		///
        size_t first_pending (std::vector<State> const &bubbles);
		
    public: 
		///
		/// Public member functions
		///
        void update(double dt);
        std::string next_word();
        void load_word(std::string const& word);
		std::string &get_word();
        void hit_key(char letter);
        bool is_finished();
        std::vector<State> &get_word_state();
};
