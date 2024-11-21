#include "Rungame.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// The lore of the game (skippable)
void introLore1() {
    cout << R"(
    You sit in your room, controller in hand, about to face the final boss in your favorite game, Gemkins.
    Just as your character reaches the castle's doors, ready to bring the adventure to a close, a sudden crack of thunder shakes the house.
    Your console flickers and dies, leaving you in eerie silence. Frustrated but feeling a bit hungry, you decide to walk to the nearby 
    convenience store to grab a snack.
    
    As you step outside, lost in thought, a blinding light catches you off guard. You hear screeching tires, but it's too late. Everything goes dark.

                      _______________________________________________________
                      |                                                      |
                 /    |                                                      |
                /---, |                                                      |
           -----# ==| |                                                      |
           | :) # ==| |                                                      |
      -----'----#   | |______________________________________________________|
      |)___()  '#   |______====____   \___________________________________|
     [_/,-,\"--"------ //,-,  ,-,\\\   |/             //,-,  ,-,  ,-,\\ __#
       ( 0 )|===******||( 0 )( 0 )||-  o              '( 0 )( 0 )( 0 )||
    ----'-'--------------'-'--'-'-----------------------'-'--'-'--'-'--------------
    )" << endl;
}

void introLore2() {
    cout << R"(
    When you open your eyes, you find yourself in a strange, mystical land. Monsters surround you, but they aren't just any monsters. 
    They're Gemkins, the creatures from your game! Confused and disoriented, you begin to wonder... Have I been reincarnated?

    A Gemkin approaches, his eyes filled with worry. "You're here," he says softly, almost in awe. "You're the chosen one."

    He explains that this world was once a peaceful paradise. But then, one day, the earth trembled and cracked open, and a dark castle erupted 
    from the ground. To make things worse, "Aetherion, the Shard King" -- emerged from that crack, likely the source of the castle. A being 
    forged from pure crystal and dark energy, Aetherion embodies the primal essence of all gemstones, wielding power beyond imagination.

    Tales of Aetherion have been passed down through generations -- he was so powerful that our ancestors couldn't kill him. 
    Instead, they were forced to banish and seal him away to prevent him from plunging the world into chaos.

    Over time, however, his seal has weakened, and now Aetherion has awakened once more, determined to bring destruction.
    )" << endl;
}

void introLore3() {
    cout << R"(
    His castle now floats above the land like a storm cloud, spreading a corrupting energy beneath it. Those who wander too close find their 
    cores tainted, transforming them into fearsome Dreadcores... which are Gemkins twisted into monstrous shadows of their former selves.

                                |--__
                                 |
                                 X
                        |-___   / \       |--__
                        |      =====      |
                        X      | .:|      X
                       / \     | O |     / \
                      =====   |:  . |   =====
                      |.: |__| .   : |__| :.|
                      |  :|. :  ...   : |.  |
              __   __W| .    .  ||| .      :|W__  --
            -- __  W  WWWW______"""______WWWW   W -----  --
        -  -     ___  ---    ____     ____----       --__  -
            --__    --    --__     -___        __-   _
            
    -----------------------------------------------------------------------
    )" << endl;
}

void introLore4() {
    cout << R"(
    "The only hope lies in The Voidbreaker," the Gemkin continues, his voice solemn. He tells you of a legendary ship, an ancient battleship 
    the Gemkins used to defeat powerful dark forces and played a large role in sealing Aetherion. The Voidbreaker was built to cut 
    through the deepest darkness, but it has laid dormant for centuries. Now, with the Dreadcores growing in power, it is needed once again.
    .........................................%@@@................................................... 
    ........................=::::.........::=*#*%@@@%+:.........:.:=:...............................  
    ....................==..+:..........-*@@%@@%%%%%%@%+:.......:.-+::..............................  
    ....................:##++:...........:-*%@@#####%%%@%:....=#%%%%%%%@%-..........................  
    .....................*##@*:....:..:::..:+%@######%%@@%-...:-#%%@%#%%%@#.........................  
    ....................:*##%@%#-......::.:::+@#######%%@@#::-..-%%%###%%@@*........................  
    ....................-##%@@@@@%=...:...:::-@#######%%@@@*:...:+#%####%@@%-.......................  
    ...................:*%#*+*:...-:::.:.::::-%+#######%@@@#:...:.#%#####%@@+:......................  
    ...................:...::#::::..:.:..:-::-%=##**###%%@@#:..::.*%%#*##%@@+..:....:...............  
    .................:.:=.:::#::.....:-.:::::-%+##*###%%@@@+...:..#%#*###%@@=...-*#+:...............  
    ...............:::.:++-::%-:.....:::::::::@######%%%@@%:.:.:.:#%#**##%@#:+%@#-..................  
    ................:-+=*%%%%%%%%%#-.:.::::::-@%%%%%%%%%%%:..-::.--*-..:-+%@@%:.....................  
    .....................+#+*#*###%%*--------#@*=-:..:.-*:.:=+++**%%%%%@@@@*:.......................  
    .....................:+#%%#####%%%%@@@@@*=%=====+++++++#@@@%%%%%%@@%%%:.........................  
    ......................:*%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%%%%%@@@@%%%%%#-...........................  
    .......................*%%%%%%#*+#*THE VOIDBREAKER+*=*#+%%%%%%%%%*=.............................  
    ......................:*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#=...............................  
    .......................+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%-..................................  
    .......................=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*:...................................  
    .......................:-------===========++++++++=======-:.....................................                   
    )" << endl;
}

void introLore5() {   
    cout << R"(                                                                                                                                   
    Your mission is clear: Defeat as many Dreadcores as possible to grow stronger. Only then will you be prepared to face the 
    final boss -- Aetherion, the Shard King. To reach his floating castle, you must awaken The Voidbreaker and confront the ancient 
    evil that has returned.

    Realizing that everything in this world mirrors the game you once played, you set off to save the Gemkins. Armed with your chosen 
    starter Gemkin, you prepare to level up, face monstrous foes, and, one by one, gather the gemstones required to conquer the darkness.

    The world is in your hands. 

    Can you rise to the challenge and save the Gemkins from corruption, or will you watch the Gemkins' world fall into despair?

    Congratulations!! You have escaped the lore dump.
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    )" << endl;
}
void fullIntroLore() {
    introLore1();
    this_thread::sleep_for(chrono::seconds(10));
    introLore2();
    this_thread::sleep_for(chrono::seconds(15));
    introLore3();
    this_thread::sleep_for(chrono::seconds(10));
    introLore4();
    this_thread::sleep_for(chrono::seconds(10));
    introLore5();
    this_thread::sleep_for(chrono::seconds(10));
}

// Dialogue portion of starter Gemkins
void startersDialgue() {
    cout << "Chosen One, before you stand three Gemkin eggs, each holding great potential. But you may choose only one." << endl;
    cout << "Nurture it, strengthen it, and together, you may one day have the power to face the darkness that lurks within the castle." << endl;
    cout << R"(
                       .-~-.
                     .'     '.
                    /         \
            .-~-.  :           ;
          .'     '.|           |
         /         \           :
        :           ; .-~""~-,/
        |           /`        `'.
        :          |             \
         \         |             /
          `.     .' \          .'
            `~~~`    '-.____.-'           
    )" << endl;

    cout << "Igneel: Fiery spirit with blazing power." << endl;
    cout << "Cryonox: Calm and icy resolve." << endl;
    cout << "Sylvora: Nature-bound with unexpected strength." << endl;
    cout << "Who will you pick? Igneel (i), Cryonox (c), or Sylvora (s)?" << endl;
}

// Prompt that loops in the executePlayerPrompts() function
void playerPrompts() {
    this_thread::sleep_for(chrono::seconds(2));
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "What would you like to do? Enter [1], [2], [3], [4]" << endl
    << " 1. Enter the wilderness and search for Dreadcores" << endl
    << " 2. Go to the Healing Center" << endl
    << " 3. Get on The Voidbreaker and fight the final boss (WARNING!!! Level 20+ recommended)" << endl
    << " 4. Save and exit" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

// Pic of a healing center
void healingCenterPic() {
    // Picture of a pokemon center
    this_thread::sleep_for(chrono::seconds(2));
    cout << R"(
       ::-===================================================================-::    
      *:::::===============================================================:::::*   
     *:::====++=+++=+++=+++=+++==++==++==+++++++==++==++==+++=+++=+++=+++=++====:::* 
    #++++++==+=============================================================+==++++++#
    #+++==++=++=+++=+++=+++=+++==++==++==++===++==++==++==+++=+++=+++=+++=++=++==+++#
    #+===++++*+===========================================================+*++++===+#
    #==+++++*###############################################################*+++++==#
    #+++++++############################+:.....:=############################+++++++#
    +#+++++###########################-..:-----:..-###########################+++++#+
    ++##++###################*:.......::-+++++++=::.......:*###################++##++
    ++#.:=++++#+++++++#+++++*:-------:=+++=:::=+++=:-------:*+++++#+++++++#++++=:.#++
    ++#...::==#+++++==#++++++-:=-:::::---:=+++=:---::::::=:-*+++++#==+++++#==::...#++
    +#..::..::#====+::#====+*-::::::::-==-=###=-==-::::::::-*+====#::+====#::..::..#+
    +#....-.::*+++++::*+++++*-::::::::=*##+---+##*=::::::::-*+++++*::+++++*::.-....#+
    ++#-....................+=*#####**=:+#######+:-**#####*-+....................-#++
    ++#..-..::::::::::::::::+==========++-:::::-++=========-+::::::::::::::::..-..#++
    ++#....:----------------+::::::=*###############*=::::::+++++++++++++++++:....#++
    +#+....:..----....----..+::::::=**+++++++++++++**=::::::+:::::::::::::::::....+#+
    +#.::..:..++.+:...++::..+::::::=**++++++++++++++*=::::::+:::::::::::::::::..::.#+
    +#::.-::..##**::..##-:..+::::::=*+=============+*+::::::+::::::::::::::::::-.::#+
    +#::::.=..::......::::..+::::::=*+=============+*=::::::+::::::::::::::::=.::::#+
    ++#:::::::::::::::::::::+======+*+=============+*+======+:::::::::::::::::::::#++
     +++#:::----------------+::::::=*=-------------=*=::::::+----------------:::#+++ 
      .+++#:----------------+------+*###############*+-----:+----------------:#+++.  
       :++******************++++++**+++++++++++++++**++++++******************++:    )" << endl;
}

// Pic of trees for wilderness
void wildernessPic() {
    cout << R"(
               ,@@@@@@@,
       ,,,.   ,@@@@@@/@@,  .oo8888o.
    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
   `&%\ ` /%&'    |.|        \ '|8'
       |o|        | |         | |
       |.|        | |         | |
    \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_)" << endl;

    cout << ". . ." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Dreadcore found!" << endl;

}
// Dialogue BEFORE the boss battle begins
void bossDialogue() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "It seems you are ready to face Aetherion, the Shard King. But before you go, you must understand that this battle will be anything but easy." << endl;
    cout << "While you have been preparing, we have readied The Voidbreaker for your journey. Please, chosen one, be safe. The fate of the world rests on you." << endl;
    cout << "Good luck. You are our last hope." << endl;
    cout << endl;
    cout << "You set off on the Voidbreaker." << endl;
    cout << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << ". . ." << endl;
    this_thread::sleep_for(chrono::seconds(3));

    cout << "You land your ship on the floating island. Enormous doors loom ahead, and as if expecting your arrival, they slowly creak open." << endl;
    cout << R"(                                                                                      
                                      .-+**+*+**+++=-..                                       
                                  .--==+*********+*++***=:.                                   
              .......          .-++++==+******##**+++*+*+*++-..         .......               
               .****+=-..    .=+++==+++*##+--::::--+##*++++*++=.      .-+**#**.               
               .**+###*++...-****+++*#=....         ...=**+++*+=-. ..+*#####*#.               
               .***+***#**==***+*+#*:..                ..:**+=+++=:+####*###**.               
               .*****+***#**++***#:.                      .:#+**###*###***##*#.               
               .**+**+****##**+**..                        ..**+*####*#***#**#.               
               .*****+*+***#**+*.                            .**#*#*#*****##**.               
               .**+**+*+****#**:                             ..*#%#*#*****##*#.               
               .*****+*****#**+.                              .*#######***####.               
               .*******#**#**#*:                              .#%#######*###**.               
               .**+****#**#**#*:                             ..#######%#*#***#.               
               .*#***+*****#*#*:                              .########**#*#**.               
               .**#**+**+****#*:                              .####*#*##*#*##*.               
               .*****++*+****#=:                              .+###*#*#**#*#**..              
               .*#**##*%*****#*:                              .*###*##%*##*##*.               
               .**+*#****+***#*:                              .*###**##**#****.                                                      
               .+************#+:                              .+#####*##**##**.               
               .*******#***####:                              .*############**.               
               .***##+*##*####*:..                         ....#####*###*###**.               
               ..........                                              ........                                                                                                                                                                                                
            )" << endl;
    cout << "You step through the massive doors, their weight groaning as they close behind you." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "Suddenly, the ground beneath you starts to tremble, a low rumble echoing through the castle walls." << endl;
    this_thread::sleep_for(chrono::seconds(5));

}

// The boss' dialogue AFTER defeat. Includes a plot twist
void bossDefeatedDialogue() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Aetherion kneels, glowing cracks spreading across his form as the castle begins to shudder." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << R"(
    "So... this is how it ends. Yet... I remember now."

    "You... you are a human from Earth. And THEY are protecting you, aren't they? Let me give you a warning, 'Chosen One.'"

    "Do not trust them. I stood where you are now. I WAS their champion. Their hero. And when I outlived my purpose... they betrayed me. 
    Cast me aside like a broken tool."

    "Now, here I am... twisted into the villain of this story. It seems my time has come."

    "Be careful, 'Chosen One.' Trust no one. Not even those who claim to be your allies. They will use you, as they used me."

    "Good luck... hero..."

    As his energy dissipates, the castle begins crumbling... 

    You rush through the crumbling castle, dodging falling debris whilst racing back to the Voidbreaker.)" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    this_thread::sleep_for(chrono::seconds(15));
}

// The plot twist
void endingDialogue() {
    cout << R"(
    The Voidbreaker begins descending to the ground below. The once corrupted landscape now blossoms with vibrant flowers and lush greenery. 
    Gemkins gather around, their cores shining brightly, free of corruption.

    As you step off the Voidbreaker, the Gemkins cheer, their voices echoing with gratitude.

    Gemkin 1:
    "The corruption is gone!"

    Gemkin 2:
    "You did it! Our savior has returned peace to the land!"

    Gemkin 3:
    "All hail the Chosen One!"
    
    As the crowd of Gemkins closes in, you begin to feel a wave of drowsiness wash over you. Your vision blurs, and your legs grow weak.

    The last thing you see is their smiling faces... but something about their expressions feels off, as if hiding a deeper truth. Your eyes close as you collapse 
    to the ground, the screen fading to black.

    A faint, echoing voice whispers before silence falls.
    "Goodnight... 'Chosen One.'"
    )" << endl;
    this_thread::sleep_for(chrono::seconds(15));
    cout << "TO BE CONTINUED..." << endl;
    
}