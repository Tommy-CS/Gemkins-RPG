# Gemkins
**Gemkins** is a C++ console-based RPG where players embark on an adventurous journey with their chosen Gemkin creatures. The objective is to level up your Gemkins, battle corrupted enemies, and ultimately defeat the powerful final boss, Aetherion, the Shard King. The game combines turn-based battles, exploration, and rich storytelling with unique ASCII art for an immersive experience.

## Features
- Choose from three starter Gemkins: Igneel, Cryonox, and Sylvora.
- Battle against Dreadcores, which are corrupted versions of Gemkins.
- Explore a rich narrative and lore through dialogue and ASCII art.
- Level up your Gemkin and face tougher foes.
- Engage in an epic boss battle against Aetherion.
- Save and load progress to continue your adventure seamlessly.
- Access pre-saved level 20 files for each starter Gemkin to test the boss fight or jump directly into high-level gameplay.

## Lessons Learned
This project was an incredible learning experience that not only helped me grow as a programmer but also allowed me to strengthen my understanding of C++. With the guidance of someone more experienced, I was able to refine my code and learn many new concepts, particularly in software design and object-oriented programming principles.

### Cohesion: 
- Each class was designed to have a single, well-defined purpose, improving clarity and maintainability. For example, the Gemkin class encapsulates shared traits of all Gemkins, while PlayableGemkin extends this functionality for player-specific actions like leveling up. Initially, I combined the Gemkin and PlayableGemkin classes into one. However, this approach reduced clarity and maintainability, prompting me to refactor them into separate classes with distinct responsibilities. This leads into the next thing I learned about.

### Interface Segregation Principle (ISP)
- While working on this project, I learned the importance of ensuring no class or module depends on methods it doesn’t use. For example: Player-focused methods, like saving/loading data or experience tracking, are only implemented in PlayableGemkin, keeping other classes clean and focused. Before my code was refined, I only had one base Gemkin class and all the starter Gemkins, Dreadcores, and Aetherion were derived from it. However, Dreadcores and Aetherion do not need things such as experience, introducing themselves, and displaying their moves which is why I separated into a base Gemkin class and a PlayableGemkin class.

### Single Responsibility Principle (SRP)
I ensured that each class was responsible for only one part of the program's functionality. For example: 
- **Gemkin**: Handles general Gemkin attributes and behaviors.
- **Dreadcore**: Focuses on enemy-specific logic for corrupted Gemkins.
- **Rungame**: Manages the game's narrative, dialogue, and ASCII art.
Following the SRP ensured the program was well-structured and much easier to debug.

## 🌟 Watch the Showcase Video! 🌟 
### Click the image below ⬇️
[![Gemkin RPG Showcase](https://img.youtube.com/vi/ObiZO-Ur5SQ/0.jpg)](https://youtu.be/ObiZO-Ur5SQ)


