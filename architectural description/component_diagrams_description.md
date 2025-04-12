# Card Game System Documentation

## Core Classes

### Game Class
- **Controls**: Entire game flow including mode selection (PvP/PvE) and gameplay execution
- **Dependencies**: Move, Deck, Player, and AI classes

### Move Class
- **Responsible**: For processing player moves
- **Dependencies**: Deck, Hand, and Player classes

### Deck Class
- **Manages**: Card deck operations (shuffling, dealing, restoring)
- **Contains**: Collection of Card objects

### Player Class
- **Represents**: Game player with health, mana, and name attributes
- **Has**: Single Hand instance containing multiple cards

### AI Class (AI)
- **Implements**: Artificial intelligence logic for computer opponents
- **Dependencies**: Deck, Hand, and Player classes

### Hand Class
- **Manages**: Cards in player's hand
- **Contains**: Set of Card objects

### Card Class (Base)
- **Parent class** for all card types
- **Subclasses**: Additional_Card and Game_Card

## Card Inheritance Hierarchy

### Additional_Card (extends Card)
1. **Swap_My_Card**: Card exchange functionality
2. **Card_Broken_Deck**: Discard pile management
3. **Manna_Card**: Mana boost capability

### Game_Card (extends Card)
1. **Characters**:
   - Knight
   - Magician  
   - Thief
2. **Healing Cards**:
   - Healing_Spell
   - Healer
3. **Attack Cards**:
   - Berserker
   - Attacking_Spell
   - Archer

## Class Relationships

| Relationship | Description |
|-------------|-------------|
| 1 Deck → Many Cards | One deck contains multiple cards |
| 1 Player → 1 Hand | Each player has one hand |
| 1 Hand → Many Cards | Each hand holds multiple cards |
| 1 Game → Many Players | Game manages multiple players |
| 1 Game → 1 AI | Game controls one AI opponent |
| 1 Game → 1 Move | Game manages move processing |
| 1 Game → 1 Deck | Game controls one card deck |

## System Workflow

1. **Game Mode Selection**:
   - Game Mode component handles PvP/PvAI selection
   - Interfaces with Deck and Player components

2. **Card Management**:
   - Deck contains and distributes all cards
   - Provides cards to players during gameplay

3. **Player Actions**:
   - Players control their Hands
   - Hands store cards received from Deck

4. **Card System**:
   - All cards inherit from base Card class
   - Two main types: Game Cards and Additional Cards
