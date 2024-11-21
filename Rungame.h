#pragma once

#include <string>
using namespace std;

// The lore of the game (skippable)
void introLore1();
void introLore2();
void introLore3();
void introLore4();
void introLore5();
void fullIntroLore();

// Dialogue portion of starter Gemkins
void startersDialgue();

// Prompt that loops in the executePlayerPrompts() function
void playerPrompts();

// Pic of a healing center
void healingCenterPic();

// Pic of trees
void wildernessPic();

// Dialogue BEFORE the boss battle begins
void bossDialogue();

// The boss' dialogue AFTER defeat. Includes a plot twist
void bossDefeatedDialogue();

// The plot twist ending
void endingDialogue();