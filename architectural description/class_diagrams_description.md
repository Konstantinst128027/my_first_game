# Card Game Architecture

## 1. Main Classes (Основные классы)

### `Game` 
- **Controls**: Entire game flow, mode selection (PvP/PvE)  
- **Dependencies**: `Move`, `Deck`, `Player`, `AI`  

### `Move`
- **Handles**: Player moves processing  
- **Dependencies**: `Deck`, `Hand`, `Player`

### `Deck` 
- **Manages**: Card filling/shuffling/restoring  
- **Contains**: Collection of `Card` objects  

### `Player`
- **Manages**: Health, mana, player name  
- **Has**: Single `Hand` object  

### `AI` (AI)
- **Implements**: Computer opponent logic
- **Dependencies**: `Deck`, `Hand`, `Player`

## 2. Card Inheritance (Иерархия карт)

classDiagram
    Card <|-- Additional_Card
    Card <|-- Game_Card
    
    Additional_Card <|-- Swap_My_Card
    Additional_Card <|-- Card_Broken_Deck
    Additional_Card <|-- Manna_Card
    
    Game_Card <|-- Knight
    Game_Card <|-- Magician
    Game_Card <|-- Thief
    Game_Card <|-- Healing_Spell
    Game_Card <|-- Healer
    Game_Card <|-- Berserker
    Game_Card <|-- Attacking_Spell
    Game_Card <|-- Archer
