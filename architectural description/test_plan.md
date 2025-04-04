# Game Testing Plan

## Core Functionality Testing

### Key Checks:
- [ ] Input handling functions verification
- [ ] Move function testing
- [ ] Other critical functions testing

### Requirements:
- All possible scenarios must produce correct results
- Special focus on:
  - Edge cases
  - Unusual situations
  - Parameter boundary values

## AI Opponent Testing

### AI Logic:
- [ ] Card selection algorithm verification
- [ ] Difficulty levels testing

### Calculation Checks:
- [ ] Mana expenditure accuracy
- [ ] Health change verification:
  - AI's own health
  - Player's health
- [ ] Turn sequence analysis

## System Integration Testing

### Main Modules:
- [ ] Multi-object interaction testing (e.g. Deck and Hand, Deck and Broken Deck)
- [ ] Mana and card system evaluation
- [ ] Damage and health mechanics verification

### Requirements:
- No conflicts between systems
- Smooth interoperability of all modules

## Final Verification

### Success Criteria:
- [ ] All tests passed successfully
- [ ] No critical issues found
