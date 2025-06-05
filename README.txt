AIdotX
Goal: Create web application that plays tick-tack-toe with an AI, and keeps track of scores through user accounts.

6/5/2025
-Issues with randomness in think_and_act have been resolved, though it seems to exhibit no real strategy to win.
-replaced get_surrounding_spaces with get_empty_neighbors.
-AI now seems to slightly prefer moving to more immediate spaces, though there is variation to be tweeked.

6/1/2025
-Modified Main function for testing.
-Modified get_surrounding_spaces in game_board class.
-Attempting to test gameboard drawing method.
-Modified game_board initialization.
-Fixed draw_board issues.
-Tested ai_player initialization.
-Tested player initialization.
-Modified curr_positions initialization.
-Experiencing issue with the think_and_act method.
-Made corrections to the helper function determine_candidates and other functions it depends on.
-think_and_act is now functional, however, its ability to make random choices is questionable.

5/19/2025
-Removed game_test.cpp
-Implemented main function for testing the game functionality.

5/1/2025
-Implemented basic player class.
-Implemented draw_board function for game_board class.
-Created test file to test the game functions.
-Created Options.html to show gameplay options to player.
-Began implementation of game.play in game.py.
-Began Options.html implementation.
-Began play.html implementation.

4/29/2025
-Began ai implementation.
-Implemented move_to in ai class.
-Began think implementation in ai class.
-Began implementation for determine_candidates in ai class.
-Implemented is_valid_space to check a board space's availability.
-Began implementation of get_surrounding_spaces to get all immediate surrounding spaces of a mark.
-Added curr_positions to ai class to track the locations of its marks on the board.
-Moved method locations in ai class.
-Finished get_surrounding_spaces implementation.
-Finished implementation of determine_candidates.
-Edited get_player_options method. May consider scrapping it.
-Moved explanation comments.
-Changed think function to think_and_act.
-Implemented think_and_act.

4/28/2025
-Implemented base file.
-Implemented db.py.
-Implemented user_login.html.
-Implemented register_new_user.html.
-Added AI.cpp file for later implementation of AI player.
-Added user registry and login implementations.
-Added user loading and logout implementations.
-Made attempt at gameboard implementation.
-Implemented gameboard initialization.
-Added gameboard victory checker methods for later implementation.
-Implemented index page.
-Added files to game directory for later implementation
-Added game.py file.
-Removed ai.cpp file.
-Outlined ai class in game_board.cpp
-Renamed game_board.cpp to game.cpp for simplicity.
-Implemented game_board class getters and setters.
-Implemented victory checker methods for game_board class.
-Added empty methods to ai class for later implementation.
-Developed plan for how the ai will function and act.

4/26/2025
-Established GitHub repo.
-Created README file to track project progress.
-Established project goal.
-Created static and templates folders.
-Implemented SQL database schema for user info.
-Began implementation for user authorization through registery and login.